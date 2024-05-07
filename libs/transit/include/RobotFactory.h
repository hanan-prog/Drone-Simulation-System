#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"
/**
 * @brief The component factory that is responsible for creating robot entities
 * in the simulation.
 */
class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief creates a robot entity.
   *
   * @param[in] entity details about what type of entity to create
   * @return A robot entity if the json object constructor argument is a robot,
   * otherwise returns a null pointer
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
