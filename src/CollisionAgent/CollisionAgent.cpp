#include "CollisionAgent.h"

using namespace godot;

void CollisionAgent::_register_methods() {
    register_method("_process", &CollisionAgent::_process);
    register_method("set_goal", &CollisionAgent::set_goal);

    register_signal<CollisionAgent>((char *)"position_updated", "new_position", GODOT_VARIANT_TYPE_VECTOR2);
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

void CollisionAgent::set_goal(float x_position, float y_position) {
    agent_goal = Vector2(x_position, y_position);
}