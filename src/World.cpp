#include "World.h"

World::World(vec2D gravity, Integrator* integrator)
    : gravity(gravity), integrator(integrator) {}

void World::addBody(RigidBody* body) {
    bodies.push_back(body);
}

void World::step(float dt) {
    for (RigidBody* body : bodies) {
        body->applyForce(vec2D(gravity.x * body->getMass(), gravity.y * body->getMass()));
        integrator->step(*body, dt);
        body->clearForces();
    }
}
