#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/**
 * @brief Abstract controller class used in the Transit Service.  Uses the Model
 * View Controller Pattern
 *
 */
class IController {
 public:
  /**
   * @brief Destructor
   *
   */
  virtual ~IController() {}

  /**
   * @brief Adds an entity to the simulation
   *
   * @param[in] entity the entity to add to the simulation
   */
  virtual void AddEntity(const IEntity& entity) = 0;

  /**
   * @brief updates an entity in the simulation
   *
   * @param[in] entity the entity to be updated in the simulation
   * @return the updated entity
   */
  virtual void UpdateEntity(const IEntity& entity) = 0;

  /**
   * @brief Removes an entity from the simulation
   *
   * @param[in] id the id of the entity that is getting removed from the
   * simulation
   */
  virtual void RemoveEntity(int id) = 0;

  /**
   * @brief Adds a path to the simulation
   *
   * @param[in] id the id of the path being added to the simulation
   * @param[in] path vector reresent the path to be added to the simulaiton
   */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;

  /**
   * @brief removes a path from the simulation model
   *
   * @param[in] id the id of the path that will be removed from the simulation
   * model
   */
  virtual void RemovePath(int id) = 0;

  /**
   * @brief Allows messages to be passed back to the view
   *
   * @param[in] event string "TripScheduled"
   * @param[in] details The details about the scheduled trip.
   */
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif
