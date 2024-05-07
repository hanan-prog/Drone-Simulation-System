#ifndef BATTERY_H_
#define BATTERY_H_

#include <vector>

#include "BatteryBaseDecorator.h"
#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief battery entity thats wrapped around the drone. Represents the battery
 * percent of a drone.
 *
 */
class Battery : public BatteryBaseDecorator {
 public:
  /**
   * @brief Construct a new Battery entity. Calls the BatteryBaseDecorator
   * constructor.
   *
   * @param[in] entity
   */
  Battery(IEntity *entity);

  /**
   * @brief Destructor
   *
   */
  ~Battery() {}

  /**
   * @brief gets the position of the drone
   *
   * @return position of the drone
   */
  Vector3 GetPosition() const;

  /**
   * @brief gets the direction of the drone
   *
   * @return the direction of the drone as a vector value
   */
  Vector3 GetDirection() const;

  /**
   * @brief gets the destination of the drone
   *
   * @return the destination of the drone as a vector
   */
  Vector3 GetDestination() const;

  /**
   * @brief gets the detials about a drone
   *
   * @return details about the drone.
   */
  JsonObject GetDetails() const;

  /**
   * @brief Gets the speead of the drone/entity object
   *
   * @return speed of the drone
   */
  float GetSpeed() const;

  /**
   * @brief updates the battery life based on weather the drone is moving or
   * not.
   *
   * @param[in] dt
   * @param[in] scheduler
   */
  void Update(double dt, std::vector<IEntity *> scheduler);

  /**
   * @brief Gets the Battery Life
   *
   * @return battery life
   */
  float GetBatteryLife();

  /**
   * @brief Gets the Distance To the Robot
   *
   * @return the distance to the robot as a float value
   */
  float GetDistance_FromDrone_ToRobot(std::vector<IEntity *> scheduler);

  /**
   * @brief Get the Distance From Station To Robot object
   *
   * @return float
   */
  float GetDistance_FromStation_ToRobot(std::vector<IEntity *> scheduler);

  /**
   * @brief Get the Distance From Robot To it's Destination
   *
   * @return float
   */
  float GetDistance_FromRobot_ToDestination(std::vector<IEntity *> scheduler);

  /**
   * @brief Get the Distance From Robot destination To recharge station
   *
   * @return float
   */
  float GetDistance_FromRobotDest_ToStation(std::vector<IEntity *> scheduler);

  /**
   * @brief Get the Nearest Entity from scheduler
   *
   * @return IEntity*
   */
  IEntity *GetNearestEntity(std::vector<IEntity *> scheduler);

  /**
   * @brief Get the Nearest Station object
   *
   * @param location
   * @return Vector3 postion of the nearest station
   */
  Vector3 GetNearestStation(Vector3 location);

  /**
   * @brief
   *
   * @param scheduler
   */
  void PrepareForTrip(double dt, std::vector<IEntity *> scheduler);

 private:
  const float BATTERY_MAX = 100.0;
  float batteryLife;
  IStrategy *toRechargeStation = NULL;
  std::vector<Vector3> RechargeStations;
  float TotalTrip = 0;
  bool checkForTrip = false;
};

#endif
