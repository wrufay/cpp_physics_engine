#pragma once
#include "vector2D.h"

class RigidBody {
private:
    vec2D position;
    vec2D velocity;
    vec2D acceleration;
    float mass;

public:
    RigidBody(float mass, vec2D startPos);

    vec2D getPosition() const;
    vec2D getVelocity() const;
    vec2D getAcceleration() const;
    float getMass() const;

    void setPosition(vec2D pos);
    void setVelocity(vec2D vel);

    void applyForce(vec2D force);
    void clearForces();
};
