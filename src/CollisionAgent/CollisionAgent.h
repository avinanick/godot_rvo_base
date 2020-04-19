#ifndef COLLISIONAGENT_H
#define COLLISIONAGENT_H

#include <Godot.hpp>
#include <Node.hpp>
#include "../RVO.h"

namespace godot {

class CollisionAgent: public Node {
    GODOT_CLASS(CollisionAgent, Node)

private:
    int agent_number = 0;

public:
    static void _register_methods();

    CollisionAgent();
    ~CollisionAgent();

    void _init();

    void _process(float delta);
};

}

#endif