#ifndef RVOSERVER_H
#define RVOSERVER_H

#include <Godot.hpp>
#include <Node.hpp>
#include "../RVO.h"

namespace godot {

class RVOServer: public Node {
    GODOT_CLASS(RVOServer, Node)

private:
    int obstacle_number = 0; //pretty sure this isn't a thing

public:
    static void _register_methods();

    RVOServer();
    ~RVOServer();

    void _init();

    void _process(float delta);
};

}

#endif