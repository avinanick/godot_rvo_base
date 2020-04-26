#ifndef RVOSERVER_H
#define RVOSERVER_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Vector2.hpp>
#include "RVO.h"

namespace godot {

class RVOServer: public Node {
    GODOT_CLASS(RVOServer, Node)

private:
    RVO::RVOSimulator* sim;

public:
    static void _register_methods();

    RVOServer();
    ~RVOServer();

    void _init();

    void _process(float delta);

    int add_collision_agent(float x_position, float y_position, float agent_radius, float agent_speed);

    void set_agent_preferred_velocity(int agent_num, float x_direction, float y_direction);

    Vector2 get_agent_position(int agent_num);
};

}

#endif