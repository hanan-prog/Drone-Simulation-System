#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"

/**
 * @brief The component factory that is responsible
 * for creating drone entities in the simulation.
 */
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor
   *
   */
  virtual ~DroneFactory() {}

  /**
   * @brief creates a Drone entity.
   *
   * @param[in] entity details about what type of entity to create
   * @return A Drone entity if the json object constructor argument is a
   * Drone, otherwise returns a null pointer
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
