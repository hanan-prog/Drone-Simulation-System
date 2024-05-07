#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"

using namespace routing;

/**
 * @brief provides an interface for the entity movement stratgies.
 *
 */
class IStrategy {
 public:
  /**
   * @brief moves the entity towards the next node/position.
   *
   * @param[in] entity the entity being moved
   * @param[in] dt the change in time between each frame
   */
  virtual void Move(IEntity* entity, double dt) = 0;

  /**
   * @brief determines weather the position/node has arrived to destination.
   *
   * @return true: position/node has arrived to destination, false: it has not
   */
  virtual bool IsCompleted() = 0;

 protected:
  // IGraph object to be used in the simulation.
  const IGraph* graph;
};  // close class

#endif  // ISTRATEGY_H_
