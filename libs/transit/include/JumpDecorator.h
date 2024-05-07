#ifndef JUMP_DECORATOR_H_
#define JUMP_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 * @brief This class inherits from CelebrationDecorator. Implements having
 * entities celebrate by jumping around after getting to their destination.
 */
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief jump decorators are created with the
   * basic functionality of a celebration decorator
   *
   * @param[in] strategy_ the previous strategy of the entity
   */
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

  /**
   * @brief checks if the current celebration strategy has completed.
   *
   * @return true if current celebration strategy has completed, otherwise
   * returns false
   */
  bool IsCompleted();

  /**
   * @brief Checks if previous strategy has completed, if so, do
   * a jump strategy movement, if not, do the previous strategy movement.
   *
   * @param[in] entity the current entity
   * @param[in] dt the delta time.
   */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // JUMP_DECORATOR_H_
