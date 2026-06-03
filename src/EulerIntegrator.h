#pragma once
#include "Integrator.h"

class EulerIntegrator : public Integrator {
public:
    void step(RigidBody& body, float dt) override;
};
