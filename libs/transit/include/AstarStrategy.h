#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the Astar path to move an entity in the simulation.
 */
class AstarStrategy : public IStrategy {
 public:
  /**
   * @brief Using the Astar path finding algorithm, it calculates the
   * path to follow to get to the specified destination.
   *
   * @param[in] position the starting position of the entity
   * @param[in] destination the destination of the entity
   * @param[in] graph map of the simulation. Provides the path to move around.
   */
  AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);

  /**
   * @brief Destructor
   *
   */
  ~AstarStrategy();

  /**
   * @brief Moves entity toward next node/position using the Astar path
   * @param[in] entity the entity being moved in every frame
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
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // ASTAR_STRATEGY_H_
