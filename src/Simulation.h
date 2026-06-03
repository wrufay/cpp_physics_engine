#pragma once
#include <vector>
#include "RigidBody.h"
#include "Integrator.h"

class Simulation {
private:
    float G;
    float softening;
    int substeps;
    Integrator* integrator;

public:
    std::vector<RigidBody*> bodies;

    Simulation(Integrator* integrator, float G = 1.0f, float softening = 0.05f, int substeps = 100);
    void addBody(RigidBody* body);
    void step(float dt);
};
