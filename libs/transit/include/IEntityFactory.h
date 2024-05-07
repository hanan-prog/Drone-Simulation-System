#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "util/json.h"

/**
 * @brief Provides an interface entites in the factor
 *
 */
class IEntityFactory {
 public:
  /**
   * @brief Destructor
   *
   */
  virtual ~IEntityFactory() {}

  /**
   * @brief Declares a generic entity creation. Should be overwritten by
   *
   * @param[in] entity details about what type of entity to create
   * @return
   */
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif
