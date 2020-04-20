#include "RVOServer.h"

using namespace godot;

void RVOServer::_register_methods() {
    register_method("_process", &RVOServer::_process);
    register_signal<RVOServer>((char *)"simulation_updated", "node", GODOT_VARIANT_TYPE_OBJECT);
}

RVOServer::RVOServer() {

}

RVOServer::~RVOServer() {

}

void RVOServer::_init() {
    sim = new RVO::RVOSimulator();
    sim->setAgentDefaults(15.0f, 10, 10.0f, 5.0f, 2.0f, 2.0f);
}

void RVOServer::_process(float delta) {
    sim->setTimeStep(delta);
    sim->doStep();
    emit_signal("simulation_updated", this);
}

int RVOServer::add_collision_agent(float x_position, float y_position) {
    return sim->addAgent(RVO::Vector2(x_position, y_position));
}

void RVOServer::set_agent_preferred_velocity(int agent_num, float x_direction, float y_direction) {
    sim->setAgentPrefVelocity(agent_num, RVO::Vector2(x_direction, y_direction));
}

Vector2 RVOServer::get_agent_position(int agent_num) {
    RVO::Vector2 agent_position = sim->getAgentPosition(agent_num);
    Vector2 *godot_vector_position = new Vector2(agent_position.x, agent_position.y);
    return *godot_vector_position;
}