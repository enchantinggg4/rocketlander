//
// Created by Yuri Stiopin on 10.05.2021.
//

#ifndef ROCKETLANDER_ROCKET_H
#define ROCKETLANDER_ROCKET_H

#include "iostream"

using namespace std;


#ifdef __APPLE__

#include "mac.h"

#else
#include "windows.h"
#endif


const float windowWidth = 1600;
const float windowHeight = 800;

struct Vector {
    float x, y;
};


class Rocket {
public:
    Vector position;
    Vector acceleration;
    Vector velocity;

    float angle;
    float mass = 50;

    float width;
    float height;

    float maxThrust = 10000.0;


    void update(float timedelta) {
        float G = -9.8;

        this->velocity.x += (this->acceleration.x) / this->mass * timedelta;
        this->velocity.y += (this->acceleration.y + G) / this->mass * timedelta;

        this->position.x += this->velocity.x * timedelta;
        this->position.y += this->velocity.y * timedelta;


        if (this->position.x < -10 || this->position.x > windowWidth || this->position.y > windowHeight) {
            cout << "Rocket lost " << this->position.x << endl;
            exit(-1);
        }
        if (this->position.y < 0) {
            if (abs(this->velocity.y) > 10) {
                cout << "Rocket lost: landing too fast " << this->velocity.y << endl;
                exit(-1);
            }
        }
    }


};

class ProcessUnit {
public:
    float thrust;
    float angle;
};


// Vector stuff
Vector add(Vector v1, Vector v2);

Vector sub(Vector v1, Vector v2);

float magnitude(Vector v1);
Vector normalized(Vector v1);

ProcessUnit tick(Rocket r, float timedelta);

#endif //ROCKETLANDER_ROCKET_H


