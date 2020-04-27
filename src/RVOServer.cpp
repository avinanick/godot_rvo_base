#include "RVOServer.h"

using namespace godot;

void RVOServer::_register_methods() {
    register_method("_process", &RVOServer::_process);
    register_method("add_collision_agent", &RVOServer::add_collision_agent);
    register_method("set_agent_preferred_velocity", &RVOServer::set_agent_preferred_velocity);
    register_method("get_agent_position", &RVOServer::get_agent_position);

    register_signal<RVOServer>((char *)"simulation_updated");
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
    emit_signal("simulation_updated");
}

int RVOServer::add_collision_agent(float x_position, float y_position, float agent_radius, float agent_speed) {
    int new_agent_num = sim->addAgent(RVO::Vector2(x_position, y_position));
    sim->setAgentRadius(new_agent_num, agent_radius);
    sim->setAgentMaxSpeed(new_agent_num, agent_speed);
    return new_agent_num;
}

void RVOServer::set_agent_preferred_velocity(int agent_num, float x_direction, float y_direction) {
    sim->setAgentPrefVelocity(agent_num, RVO::Vector2(x_direction, y_direction));
}

Vector2 RVOServer::get_agent_position(int agent_num) {
    RVO::Vector2 agent_position = sim->getAgentPosition(agent_num);
    godot::Vector2 godot_vector_position = godot::Vector2(agent_position.x(), agent_position.y());
    return godot_vector_position;
}