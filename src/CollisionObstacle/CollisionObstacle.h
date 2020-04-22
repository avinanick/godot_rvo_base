#ifndef COLLISIONOBSTACLE_H
#define COLLISIONOBSTACLE_H

#include <Godot.hpp>
#include <Node.hpp>
#include "../RVO.h"

namespace godot {

class CollisionObstacle: public Node {
    GODOT_CLASS(CollisionObstacle, Node)

private:
    int obstacle_number = 0; //pretty sure this isn't a thing
    // I need to figure out some way to store the object verts

public:
    static void _register_methods();

    CollisionObstacle();
    ~CollisionObstacle();

    void _init();

    void _process(float delta);
};

}

#endif