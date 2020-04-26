#include "CollisionAgent.h"

using namespace godot;

void CollisionAgent::_register_methods() {
    register_method("_process", &CollisionAgent::_process);
    register_method("set_goal", &CollisionAgent::set_goal);
    register_method("setup_agent", &CollisionAgent::setup_agent);

    register_signal<CollisionAgent>((char *)"position_updated", "new_position", GODOT_VARIANT_TYPE_VECTOR2);
    register_signal<CollisionAgent>((char *)"goal_reached");
}

CollisionAgent::CollisionAgent() {

}

CollisionAgent::~CollisionAgent() {

}

void CollisionAgent::_init() {
    agent_number = 0;
    Object* MyScriptSingleton = get_tree()->get_root()->get_node(NodePath("CollisionServer"));
    collision_server = static_cast<RVOServer *>(MyScriptSingleton);

}

void CollisionAgent::_process(float delta) {
    update_agent_position();
}

void CollisionAgent::set_goal(float x_position, float y_position) {
    agent_goal = Vector2(x_position, y_position);
}

void CollisionAgent::setup_agent(float x_position, float y_position, float agent_radius, float agent_speed) {
    agent_number = collision_server->add_collision_agent(x_position, y_position, agent_radius, agent_speed);
    agent_position = Vector2(x_position, y_position);
}

void CollisionAgent::update_agent_position() {
    agent_position = collision_server->get_agent_position(agent_number);
    emit_signal("position_updated", agent_position);
    float dist_to_goal = agent_position.distance_squared_to(agent_goal);
    if(dist_to_goal < (agent_radius * agent_radius)) {
        // reached the goal
        emit_signal("goal_reached");
        collision_server->set_agent_preferred_velocity(agent_number, 0.0, 0.0);
    }
    else {
        Vector2 preferred_velocity = (agent_position - agent_goal).normalized();
        collision_server->set_agent_preferred_velocity(agent_number, preferred_velocity.x, preferred_velocity.y);
    }
}