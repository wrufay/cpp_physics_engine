#pragma once

class RigidBody;

class Integrator {
public:
    virtual void step(RigidBody& body, float dt) = 0;
    virtual ~Integrator() = default;
};
