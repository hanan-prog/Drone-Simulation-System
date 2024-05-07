#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/**
 * @brief Simulation Model handling the transit simulation.  The model can
 * communicate with the controller.
 */
class SimulationModel {
 public:
  /**
   * @brief Construct a new Simulation Model
   *
   * @param[in] controller SimulationModel is created with
   */
  SimulationModel(IController& controller);

  /**
   * @brief Sets graph of transit simulation
   *
   * @param[in] graph transit simulation.
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Creates a simulation entity
   *
   * @param[in] entity details about the simulation entity to be added to the
   * system.
   */
  void CreateEntity(JsonObject& entity);

  /**
   * @brief Schedules a trip for an object in the scene
   *
   * @param[in] details the objects details
   */
  void ScheduleTrip(JsonObject& details);

  /**
   * @brief Updates the simulation
   *
   * @param[in] dt the change in time
   */
  void Update(double dt);

  /**
   * @brief Adds a new entity type to the simulation and the compFactory vector
   *
   * @param[in] factory the factory of the new entity type
   */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif
