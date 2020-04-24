#include "CollisionObstacle.h"

using namespace godot;

void CollisionObstacle::_register_methods() {
    register_method("_process", &CollisionObstacle::_process);
}

CollisionObstacle::CollisionObstacle() {

}

CollisionObstacle::~CollisionObstacle() {

}

void CollisionObstacle::_init() {
    obstacle_number = 0;
    Object* MyScriptSingleton = get_tree()->get_root()->get_node(NodePath("CollisionServer"));
    RVOServer *collision_server = static_cast<RVOServer *>(MyScriptSingleton);

}