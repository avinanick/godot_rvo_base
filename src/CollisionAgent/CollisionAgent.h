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
    RVOServer *collision_server;

public:
    static void _register_methods();

    CollisionAgent();
    ~CollisionAgent();

    void _init();

    void _process(float delta);

    void set_goal(float x_position, float y_position);

    void update_agent_position();
};

}

#endif