#ifndef COLLISIONAGENT_H
#define COLLISIONAGENT_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Object.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>
#include "../RVO.h"
#include "../RVOServer/RVOServer.h"

namespace godot {

class CollisionAgent: public Node {
    GODOT_CLASS(CollisionAgent, Node)

private:
    int agent_number = 0;
    Vector2 agent_position;
    Vector2 agent_goal;
    RVOServer *collision_server;

public:
    static void _register_methods();

    CollisionAgent();
    ~CollisionAgent();

    void _init();

    void _process(float delta);

    void set_goal(float x_position, float y_position);

    void setup_agent(float x_position, float y_position, float agent_radius, float agent_speed);

    void update_agent_position();
};

}

#endif