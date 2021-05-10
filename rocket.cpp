//
// Created by Yuri Stiopin on 10.05.2021.
//

#include "rocket.h"


Vector path[] = {
        Vector { 600, 500},
        Vector { 800, 0}
};
// s = (a * t^2) / 2
// s = (v_final - v0) * (v_final - v0) / (2 * a)
ProcessUnit tick(Rocket r, float timedelta) {
    ProcessUnit pu{};
    float targetX = 800, targetY = 0;

    Vector rTarget = sub(Vector { 800, 0}, r.position);
    Vector direction = normalized(rTarget);

    dist_x = dx * a_mag
    dist_y = dy * a_mag

    dx = 2 * dist_x / 1
    dy = 2 * dist_y / 1


    pu.thrust = 0;

    pu.thrust = .5;
    pu.angle = 0;

    return pu;
}

