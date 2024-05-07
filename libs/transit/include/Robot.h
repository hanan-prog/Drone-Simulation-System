#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Represents a robot in the drone simulation system.
 * Robot are dropped off and picked by the drone entity object.
 * the simulation model schedules the robot to get picked up at certain location
 * and dropped off at another location.
 */
class Robot : public IEntity {
 public:
  /**
   * @brief robots are created with a name and various other details that
   * describe a robot entity
   *
   * @param[in] obj JsonObject containing various details that describe a robot
   * entity
   */
  Robot(JsonObject& obj);

  /**
   * @brief Destructor
   *
   */
  ~Robot() override = default;

  /**
   * @brief Gets the robot position.
   *
   * @return Position of the robot.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the robot direction.
   *
   * @return Direction of the robot.
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the robot destination.
   *
   * @return Destination of the robot.
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the availability of the robot.
   *
   * @return Availability of the robot.
   **/
  bool GetAvailability() const { return available; }

  /**
   * @brief Get the robot Details
   *
   * @return JsonObject that has the robots name, position, directoin, etc
   */
  JsonObject GetDetails() const override;

  /**
   * @brief Gets robot speed.
   *
   * @return Speed of the robot.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Get the Strategy Name of the robot
   *
   * @return std::string the Strategy Name of the robot
   */
  std::string GetStrategyName() { return strategyName; }

  /**
   * @brief Set the Availability of the robot
   *
   * @param[in] choice the new robot availabiltiy
   */
  void SetAvailability(bool choice);

  /**
   * @brief Set the Position of the robot
   *
   * @param[in] pos_ the new position of the robot
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set the Direction of the robot to the specified value
   *
   * @param[in] dir_ the robots new direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Set the Destination of the robot to the specified value
   *
   * @param[in] des_ the new robot destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Set the Strategy Name of the robot
   *
   * @param[in] strategyName_ the new Strategy Name for the rebot
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }

  /**
   * @brief rotates the robot at a specificed angle
   *
   * @param[in] angle robot will get rotated
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

#endif  // ROBOT_H
