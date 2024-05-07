#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/**
 * Abstract controller class used in the Transit Service.  Uses the Model View
 * Controller Pattern. Represents an entity in the simulation/
 **/
class IEntity {
 public:
  /**
   * @brief constructor for entity object
   *
   */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }

  /**
   * @brief Destructor
   *
   */
  virtual ~IEntity() {}

  /**
   * @brief Gets the entity id
   *
   * @return the entity id
   */
  virtual int GetId() const { return id; }

  /**
   * @brief Get the Position object
   *
   * @return positoin of entity
   */
  virtual Vector3 GetPosition() const = 0;

  /**
   * @brief Gets the entity direction
   *
   * @return Direction of entity
   */
  virtual Vector3 GetDirection() const = 0;

  /**
   * @brief Gets the Destination of entity object
   *
   * @return vector representing the entity object
   */
  virtual Vector3 GetDestination() const = 0;

  /**
   * @brief Get the Details
   *
   * @return jsonObject that has details about an entity object
   */
  virtual JsonObject GetDetails() const = 0;

  /**
   * @brief Gets the Speed of an entity object
   *
   * @return float representing the speed of the entity object
   */
  virtual float GetSpeed() const = 0;

  /**
   * @brief Gets the Availability of an entity object
   *
   * @return bool val representing the entity object
   */
  virtual bool GetAvailability() const {}

  /**
   * @brief Gets the path Strategy Name
   *
   * @return string representing the strategy name
   */
  virtual std::string GetStrategyName() {}

  /**
   * @brief Sets the Availability of an entity object
   *
   * @param[in] choice
   */
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief updates the entity object.
   *
   * @param[in] dt change in time??
   * @param[in] scheduler vec
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

  /**
   * @brief Sets the graph of transit simulation in which entity objects exist
   *
   * @param[in] graph of the transit simulation
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Set the Position of the entity object
   *
   * @param[in] pos_ updated positoin of the enitity object
   */
  virtual void SetPosition(Vector3 pos_) {}

  /**
   * @brief Set the Direction of the entity object
   *
   * @param[in] dir_ updated direction of the entity object
   */
  virtual void SetDirection(Vector3 dir_) {}

  /**
   * @brief Set the Destination of the entity object
   *
   * @param[in] des_ updated destination of the entity object
   */
  virtual void SetDestination(Vector3 des_) {}

  /**
   * @brief Set the Strategy Name of the entity object
   *
   * @param[in] strategyName_ updated strategyName of the entity object
   */
  virtual void SetStrategyName(std::string strategyName_) {}

  /**
   * @brief makes an entity object rotate about a given angle
   *
   * @param[in] angle to rotate the entity object
   */
  virtual void Rotate(double angle) {}

  /**
   * @brief makes an entity object jump to a pecific height.
   *
   * @param[in] height to make the entity object
   */
  virtual void Jump(double height) {}

 protected:
  int id;
  const IGraph* graph;
};

#endif
