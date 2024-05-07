#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a drone in a physical system. Drones move using euler
 * integration based on a specified velocity and direction. The main
 * responsibility Drones have is to pick up or drop off the robot entity type.
 *
 */
class Drone : public IEntity {
 public:
  /**
   * @brief Drones are created with a name
   *
   * @param[in] obj drones name set among other Drone attributes
   */
  Drone(JsonObject& obj);

  /**
   * @brief Destructor
   *
   */
  ~Drone();

  /**
   * @brief Gets the drones speed
   *
   * @return speed of the drone
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the drone position
   *
   * @return position of the drone
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the drone direction
   *
   * @return direction of the drone
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the drone destination
   *
   * @return current destination of the drone
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the drone details
   *
   * @return drone details
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Get the Availability of drone
   *
   * @return availability of drone
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the Nearest Entity to the drone and makes
   *
   * @param[in] scheduler a vector of entity objects currently in the simulation
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the drone's task/position. If the drone is on a trip, then
   * it continues that trip, otherwise it calls the drone's GetNearestEntity()
   * to schedule a trip with the newarst robot entity.
   *
   * @param[in] dt the change in time
   * @param[in] scheduler a vector of all the enities in the simulation
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets the drone's position
   *
   * @param[in] pos_ new drone positon
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the drone's direction
   *
   * @param[in] dir_ new drone direction
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the Drones Destination
   *
   * @param[in] des_ new drone destination
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotates a drone about a given angle
   *
   * @param[in] angle to rotate the drone
   */
  void Rotate(double angle);

  /**
   * @brief make a drone jump to a given height
   *
   * @param[in] height at which to make the drone jump
   */
  void Jump(double height);

  /* Removing the copy constructor and assignment operator
  so that drones cannot be coppied. */
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif
