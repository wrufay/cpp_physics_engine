#pragma once
#include <vector>
#include "RigidBody.h"
#include "Integrator.h"

class World {
private:
    vec2D gravity;
    Integrator* integrator;

public:
    std::vector<RigidBody*> bodies;

    World(vec2D gravity, Integrator* integrator);
    void addBody(RigidBody* body);
    void step(float dt);
};
