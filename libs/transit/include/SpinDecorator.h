#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 * @brief This class inherits from CelebrationDecorator. Implements having
 * entities celebrate by spinning around after getting to their destination.
 */
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Spin decorators are created with the
   * basic functionality of a celebration decorator
   *
   * @param[in] strategy_ the previous strategy of the entity
   */
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

  /**
   * @brief checks if the current celebration strategy has completed.
   *
   * @return true if current celebration strategy has completed, otherwise returns false
   */
  bool IsCompleted();

  /**
   * @brief Checks if previous strategy has completed, if so, do 
   * a spin strategy movement, if not, do the previous strategy movement.
   *
   * @param[in] entity the current entity
   * @param[in] dt the delta time.
   */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // SPIN_DECORATOR_H_
