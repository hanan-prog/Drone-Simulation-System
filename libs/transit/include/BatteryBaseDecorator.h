#ifndef BATTERY_BASE_DECORATOR_H_
#define BATTERY_BASE_DECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "SimulationModel.h"

/**
 * @brief Implements IEntity as well as the
 * basic functionality of a battery decorator
 */
class BatteryBaseDecorator : public IEntity {
 public:
  /**
   * @brief Initializes the IEntity being wrapped with a battery decorator
   *
   * @param[in] entity_ The IEntity to wrap battery decorator around
   */
  BatteryBaseDecorator(IEntity *entity_) { entity = entity_; }

  /**
   * @brief Destructor
   *
   */
  ~BatteryBaseDecorator() {}

  /**
   * @brief calls the GetPosition() implementation of the wrapped entity
   *
   * @return the position of the wrapped entity
   */
  Vector3 GetPosition() const;

  /**
   * @brief calls the GetDirection() implementation of the wrapped entity
   *
   * @return the direction of the wrapped entity
   */
  Vector3 GetDirection() const;

  /**
   * @brief calls the GetDestination() implementation of the wrapped entity
   *
   * @return the destination of the wrapped entity
   */
  Vector3 GetDestination() const;

  /**
   * @brief calls the GetDetails() implementation of the wrapped entity
   *
   * @return the details of the wrapped entity
   */
  JsonObject GetDetails() const;

  /**
   * @brief calls the GetSpeed() implementation of the wrapped entity
   *
   * @return the speed of the wrapped entity
   */
  float GetSpeed() const;

  /**
   * @brief update the battery_life when near recharge station. It also
   * decrements the batteryLife when drone is moving.
   *
   * @param[in] dt
   * @param[in] scheduler
   */
  void Update(double dt, std::vector<IEntity *> scheduler);
  //!< not sure if we need to declare a different
  //!< update method specific to batterys

 protected:
  IEntity *entity;
};

#endif
