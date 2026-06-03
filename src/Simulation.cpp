#include "Simulation.h"

Simulation::Simulation(Integrator* integrator, float G, float softening, int substeps)
    : integrator(integrator), G(G), softening(softening), substeps(substeps) {}

void Simulation::addBody(RigidBody* body) {
    bodies.push_back(body);
}

void Simulation::step(float dt) {
    float sub_dt = dt / substeps;

    for (int s = 0; s < substeps; s++) {
        for (int i = 0; i < (int)bodies.size(); i++) {
            for (int j = i + 1; j < (int)bodies.size(); j++) {
                vec2D diff = bodies[j]->getPosition() - bodies[i]->getPosition();
                float r2 = diff.dot(diff);
                float denom = r2 + softening * softening;
                float force_mag = G * bodies[i]->getMass() * bodies[j]->getMass() / denom;
                vec2D force = diff.normalize() * force_mag;
                bodies[i]->applyForce(force);
                bodies[j]->applyForce(force * (-1.0f));
            }
        }
        for (RigidBody* body : bodies) {
            integrator->step(*body, sub_dt);
            body->clearForces();
        }
    }
}
