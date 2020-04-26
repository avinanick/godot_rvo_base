#include "gdexample.h"

using namespace godot;

void GDExample::_register_methods() {
    register_method("_process", &GDExample::_process);
}

GDExample::GDExample() {
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_init() {
    // initialize any variables here
    time_passed = 0.0;
    GDExample::start_rvo();
}

void GDExample::_process(float delta) {
    time_passed += delta;

    Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

    set_position(new_position);
}

void GDExample::start_rvo() {
    RVO::RVOSimulator* sim = new RVO::RVOSimulator();
    setup_scenario(sim);
}

void GDExample::setup_scenario(RVO::RVOSimulator* sim) {
    sim->setTimeStep(0.25f);

    sim->setAgentDefaults(15.0f, 10, 10.0f, 5.0f, 2.0f, 2.0f);
}