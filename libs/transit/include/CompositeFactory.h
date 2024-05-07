#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief A composite factory containing different component factories.
 * Responsible for creating different types of entites in the simulation.
 */
class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief Loops through componentFactories and calls their CreateEntity()
   * @param[in] entity details about the entity being created
   * @return IEntity pointer to the new entity object or a null ptr if the
   * factory type and the called CreateEntity() type do not match
   */
  IEntity* CreateEntity(JsonObject& entity);

  /**
   * @brief Add the factory into componentFactories
   *
   * @param[in] factoryEntity the new factory to be added to the
   * componentFactories
   */
  void AddFactory(IEntityFactory* factoryEntity);

  /**
   * @brief Destructor
   *
   */
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif
