#include "EulerIntegrator.h"
#include "RigidBody.h"

void EulerIntegrator::step(RigidBody& body, float dt) {
    body.setVelocity(body.getVelocity() + body.getAcceleration() * dt);
    body.setPosition(body.getPosition() + body.getVelocity() * dt);
}
