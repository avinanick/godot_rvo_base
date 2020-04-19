#include "RVOServer.h"

using namespace godot;

void RVOServer::_register_methods() {
    register_method("_process", &RVOServer::_process);
}

RVOServer::RVOServer() {

}

RVOServer::~RVOServer() {

}

void RVOServer::_init() {
    obstacle_number = 0;
}