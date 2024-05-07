#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IStrategy.h"

/**
 * @brief Implements IStrategy and the base functionality 
 * of how entites celebrate after finishing their trip.
 */
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief initializes the time count and the Istrategy currently being decorated
   *
   * @param[in] strategy_ The IStrategy the current decorator will be added onto
   */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }

  /**
   * @brief Checks if the current celebration strategy has
   * completed by checking if the time has lived for 1.5 sec
   * @return true if time has lived for 1.5 sec, otherwise returns false
   */
  void Move(IEntity *entity, double dt);

  /**
   * @brief Checks if the current strategy has completed 
   * @return true if current strategy has completed, otherwise returns false
   */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_
