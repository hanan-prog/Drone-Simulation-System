#ifndef RECHARGE_STATION_FACTORY_H_
#define RECHARGE_STATION_FACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RechargeStation.h"

/**
 * @brief factory method for the recharge stations
 *
 */
class RechargeStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor
   *
   */
  virtual ~RechargeStationFactory() {}

  /**
   * @brief Create recharge station entity
   *
   * @param[in] entity details about the recharge station entity
   * @return A recharge station entity if the json object constructor argument
   * is a recharge station, otherwise it returns a null pointer
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
