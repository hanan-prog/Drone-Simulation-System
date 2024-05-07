#include "Battery.h"

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "routing/astar.h"
#include "routing/depth_first_search.h"
#include "routing/dijkstra.h"

Battery::Battery(IEntity *entity) : BatteryBaseDecorator(entity) {
  batteryLife = BATTERY_MAX;
  RechargeStations.push_back(Vector3(35, 255, -92));
  RechargeStations.push_back(Vector3(1000, 255, 8));
  RechargeStations.push_back(Vector3(980, 255, 700));
  RechargeStations.push_back(Vector3(-900, 255, 460));
  RechargeStations.push_back(Vector3(-900, 255, -30));
}

Vector3 Battery::GetPosition() const {
  return BatteryBaseDecorator::GetPosition();
}

Vector3 Battery::GetDirection() const {
  return BatteryBaseDecorator::GetDirection();
}

Vector3 Battery::GetDestination() const {
  return BatteryBaseDecorator::GetDestination();
}

JsonObject Battery::GetDetails() const {
  return BatteryBaseDecorator::GetDetails();
}

float Battery::GetSpeed() const { return BatteryBaseDecorator::GetSpeed(); }

float Battery::GetBatteryLife() { return batteryLife; }

IEntity *Battery::GetNearestEntity(std::vector<IEntity *> scheduler) {
  if (scheduler.size() == 0) {
    return entity;
  }
  return scheduler.at(scheduler.size() - 1);
}

float Battery::GetDistance_FromDrone_ToRobot(std::vector<IEntity *> scheduler) {
  if (scheduler.size() == 0) {
    return 0.0;
  }
  return GetNearestEntity(scheduler)->GetPosition().Distance(
      entity->GetPosition());
}

float Battery::GetDistance_FromRobot_ToDestination(
    std::vector<IEntity *> scheduler) {
  if (scheduler.size() == 0) {
    return 0.0;
  }
  std::string strategy = GetNearestEntity(scheduler)->GetStrategyName();

  std::vector<float> positionV;
  positionV.push_back(GetNearestEntity(scheduler)->GetPosition().x);
  positionV.push_back(GetNearestEntity(scheduler)->GetPosition().y);
  positionV.push_back(GetNearestEntity(scheduler)->GetPosition().z);

  std::vector<float> destinationV;
  destinationV.push_back(GetNearestEntity(scheduler)->GetDestination().x);
  destinationV.push_back(GetNearestEntity(scheduler)->GetDestination().y);
  destinationV.push_back(GetNearestEntity(scheduler)->GetDestination().z);

  std::vector<std::vector<float> > robotNodes;

  if (strategy.compare("astar") == 0) {
    robotNodes = graph->GetPath(positionV, destinationV, AStar::Default());
  } else if (strategy.compare("dfs") == 0) {
    robotNodes =
        graph->GetPath(positionV, destinationV, DepthFirstSearch::Default());
  } else if (strategy.compare("dijkstra") == 0) {
    robotNodes = graph->GetPath(positionV, destinationV, Dijkstra::Default());
  }

  float robotDistance = 0;
  Vector3 currentVector, nextVector;

  for (int i = 0; i < robotNodes.size() - 1; i++) {
    currentVector.x = robotNodes.at(i).at(0);
    currentVector.y = robotNodes.at(i).at(1);
    currentVector.z = robotNodes.at(i).at(2);

    nextVector.x = robotNodes.at(i + 1).at(0);
    nextVector.y = robotNodes.at(i + 1).at(1);
    nextVector.z = robotNodes.at(i + 1).at(2);

    robotDistance += nextVector.Distance(currentVector);
  }

  return robotDistance;
}

float Battery::GetDistance_FromStation_ToRobot(
    std::vector<IEntity *> scheduler) {
  if (scheduler.size() == 0) {
    return 0.0;
  }
  return GetNearestEntity(scheduler)->GetPosition().Distance(
      GetNearestStation(GetNearestEntity(scheduler)->GetPosition()));
}

float Battery::GetDistance_FromRobotDest_ToStation(
    std::vector<IEntity *> scheduler) {
  if (scheduler.size() == 0) {
    return 0.0;
  }
  Vector3 recharge =
      this->GetNearestStation(GetNearestEntity(scheduler)->GetDestination());
  return GetNearestEntity(scheduler)->GetDestination().Distance(recharge);
}

Vector3 Battery::GetNearestStation(Vector3 location) {
  Vector3 nearestStation = RechargeStations.at(0);
  float smallestDistance = nearestStation.Distance(location);
  for (int i = 1; i < RechargeStations.size(); i++) {
    if (RechargeStations.at(i).Distance(location) < smallestDistance) {
      nearestStation = RechargeStations.at(i);
    }
  }
  return nearestStation;
}

void Battery::PrepareForTrip(double dt, std::vector<IEntity *> scheduler) {
  TotalTrip = GetDistance_FromDrone_ToRobot(scheduler) +
              GetDistance_FromRobot_ToDestination(scheduler) +
              GetDistance_FromRobotDest_ToStation(scheduler);

  if ((this->batteryLife * 75) <= TotalTrip) {
    checkForTrip = true;
    Vector3 nearDroneStation = GetNearestStation(entity->GetPosition());
    toRechargeStation =
        new BeelineStrategy(entity->GetPosition(), nearDroneStation);
  }
}

void Battery::Update(double dt, std::vector<IEntity *> scheduler) {
  if (entity->GetAvailability() && !checkForTrip) {
    PrepareForTrip(dt, scheduler);
  }
  if (toRechargeStation) {
    std::cout << "BATTERY: " << this->batteryLife << std::endl;
    std::cout << "TOTAL TRIP: " << TotalTrip << std::endl;
    toRechargeStation->Move(entity, dt);
    this->batteryLife -= 0.004;
    if (toRechargeStation->IsCompleted()) {
      sleep(2);
      this->batteryLife = BATTERY_MAX;
      delete toRechargeStation;
      toRechargeStation = NULL;
    }
  }
  if (toRechargeStation == NULL) {
    std::cout << "BATTERY: " << this->batteryLife << std::endl;
    std::cout << "TOTAL TRIP: " << TotalTrip << std::endl;
    entity->Update(dt, scheduler);
    checkForTrip = false;
  }
  if (!entity->GetAvailability()) {  // if drone is not steady and moving
    this->batteryLife -= 0.004;
  }
}