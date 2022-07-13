#include "patrol.h"


Patrol::Patrol(double* pos_, double* dir_, double speed, double dt_){
    this->pos = pos_;
    this->dir = dir_;
    this->speed = speed;
    this->dt = dt_;
}

void Patrol::Move(){
    // supposed map's boundaries
    // double center[3] = {0, 264, 0};
    // double min[3] = {-1450,264,-900};
    // double max[3] = {1550,264,900};

    // actual map's boundaries
    double min[3] = {-110, 0,-60};
    double max[3] = {110, 0,60};

    // change drone's direction to left if it goes out of right wall.
    if(pos[0] > max[0]){ dir[0] = -1;}
    // change drone's direction to right if it goes out of left wall.
    if(pos[0] < min[0]){ dir[0] = 1;}
    // move drone to -Z to move drone to goes out of Z wall.
    if(pos[2] > max[2]){ dir[2] = -1;}
    // move drone to Z to move drone to goes out of Z wall.
    if(pos[2] < min[2]){ dir[2] = 1; }

    time+= this->get_dt();

    Vector3 current_pos(this->pos[0], this->pos[1], this->pos[2]);
    Vector3 direction(std::sin(time/100.0 + M_PI/2.0), 0 , 30.0*std::sin(time/20.0 + M_PI/2.0));
    direction = direction.Normalize();
    Vector3 velocity = direction * this->get_speed();
    Vector3 distance_traveled =  velocity * this->get_dt();
    current_pos = current_pos + distance_traveled;
    this->pos[0] = current_pos.getX();
    this->pos[1] = current_pos.getY();
    this->pos[2] = current_pos.getZ();

};

