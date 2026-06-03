#include "RigidBody.h"

RigidBody::RigidBody(float mass, vec2D startPos)
    : mass(mass), position(startPos), velocity(vec2D()), acceleration(vec2D()) {}

vec2D RigidBody::getPosition() const     { return position; }
vec2D RigidBody::getVelocity() const     { return velocity; }
vec2D RigidBody::getAcceleration() const { return acceleration; }
float RigidBody::getMass() const         { return mass; }

void RigidBody::setPosition(vec2D pos) { position = pos; }
void RigidBody::setVelocity(vec2D vel) { velocity = vel; }

void RigidBody::applyForce(vec2D force) {
    acceleration += force * (1.0f / mass);
}

void RigidBody::clearForces() {
    acceleration = vec2D();
}
