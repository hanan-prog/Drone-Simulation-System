#include "BatteryBaseDecorator.h"

Vector3 BatteryBaseDecorator::GetPosition() const {
  return entity->GetPosition();
}

Vector3 BatteryBaseDecorator::GetDirection() const {
  return entity->GetDirection();
}

JsonObject BatteryBaseDecorator::GetDetails() const {
  return entity->GetDetails();
}

float BatteryBaseDecorator::GetSpeed() const { return entity->GetSpeed(); }

Vector3 BatteryBaseDecorator::GetDestination() const {
  return entity->GetDestination();
}

void BatteryBaseDecorator::Update(double dt, std::vector<IEntity *> scheduler) {
  entity->Update(dt, scheduler);
}
