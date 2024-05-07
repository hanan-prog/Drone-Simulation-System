#ifndef BEELINE_H_
#define BEELINE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the beeline path that the drone will take to get to the drone.
 */
class BeelineStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor for the beeline strategy
   *
   * @param[in] position the current position of the drone
   * @param[in] destination the postion of the robot
   */
  BeelineStrategy(Vector3 position, Vector3 destination);

  /**
   * @brief Destructor
   *
   */
  ~BeelineStrategy();

  /**
   * @brief move from one point to another using a linear movement direction.
   *
   * @param[in] entity the entity being moved
   * @param[in] dt the change in time between each frame
   */
  void Move(IEntity* entity, double dt);

  /**
   * @brief determines weather the position/node has arrived to destination.
   *
   * @return true: position/node has arrived to destination, false: it has not
   */
  bool IsCompleted();

 private:
  Vector3 position;
  Vector3 destination;
};      // end class
#endif  // BEELINE_H_
