#include "CollisionAgent.h"

using namespace godot;

void CollisionAgent::_register_methods() {
    register_method("_process", &CollisionAgent::_process);
}

CollisionAgent::CollisionAgent() {

}

CollisionAgent::~CollisionAgent() {

}

void CollisionAgent::_init() {
    agent_number = 0;
}