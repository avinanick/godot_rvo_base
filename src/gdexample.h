

#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include "RVO.h"

namespace godot {

class GDExample : public Sprite {
    GODOT_CLASS(GDExample, Sprite)

private:
    float time_passed;
    RVO::RVOSimulator* sim;

public:
    static void _register_methods();

    GDExample();
    ~GDExample();

    void _init(); // our initializer called by Godot

    void _process(float delta);

    void start_rvo();

    void setup_scenario(RVO::RVOSimulator* sim);
};

}

#endif

