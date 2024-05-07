#include "RechargeStation.h"

RechargeStation::RechargeStation(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {0, 0, 0};

  speed = obj["speed"];
  available = true;
}

JsonObject RechargeStation::GetDetails() const { return details; }

void RechargeStation::SetAvailability(bool choice) { available = choice; }

void RechargeStation::Rotate(double angle) {}
