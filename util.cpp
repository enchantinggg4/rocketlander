//
// Created by Yuri Stiopin on 10.05.2021.
//


#include "rocket.h"

Vector add(Vector v1, Vector v2) {
    return Vector{
            v1.x + v2.x,
            v1.y + v2.y
    };
}

Vector sub(Vector v1, Vector v2) {
    return Vector{
            v1.x - v2.x,
            v1.y - v2.y
    };
}

float magnitude(Vector v1){
    return sqrt(v1.x * v1.x + v1.y * v1.y);
}

Vector normalized(Vector v1){
    float mag = magnitude(v1);
    return Vector {
        v1.x / mag,
        v1.y / mag
    };
}