
// we need a battery.glb file
// we need red .glb for battery died
#ifndef RECHARGE_STATION_H_
#define RECHARGE_STATION_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief represents a recharge station in the simulation model.
 *
 */
class RechargeStation : public IEntity {
 public:
  /**
   * @brief Recharge Station are created with a name
   *
   * @param[in] obj details about the recharge station
   */
  RechargeStation(JsonObject& obj);

  /**
   * @brief Destructor
   *
   */
  ~RechargeStation() override = default;

  /**
   * @brief Gets the position of the recharge station
   *
   * @return position of the recharge station
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the recharge station
   *
   * @return direction of the recharge station
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destination of the recharge station
   *
   * @return destination of the recharge station
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the availability of the recharge station
   *
   * @return availability of the recharge station
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the recharge station details
   *
   * @return details about the recharche JsonObject
   */
  JsonObject GetDetails() const override;

  /**
   * @brief Get the Speed of the recharge station
   *
   * @return the speed of the recharge station
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the Strategy Name of the recharge station
   *
   * @return the recharge station re
   */
  std::string GetStrategyName() { return strategyName; }

  /**
   * @brief Set the Availability object
   *
   * @param choice
   */
  void SetAvailability(bool choice);

  /**
   * @brief Set the Position object
   *
   * @param pos_
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set the Direction object
   *
   * @param dir_
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Set the Destination object
   *
   * @param des_
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Set the Strategy Name object
   *
   * @param strategyName_
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }

  /**
   * @brief
   *
   * @param angle
   */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif
