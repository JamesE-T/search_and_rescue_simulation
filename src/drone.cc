/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "drone.h"
#include "vector3.h"
#include "beeline.h"
#include "patrol.h"
#include "manual_movement.h"
#include "hospital.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Drone::Update(double dt){
    this->movement_controller(this->getLocation(), this->getDirection(), this->getSpeed(), dt);

    // Take a picture every 5 seconds with front camera
       time += dt;
       if (time-lastPictureTime > 5.0) {
           cameras[0]->TakePicture();
           lastPictureTime = time;
       }
}

void Drone::movement_controller(double* loc, double* dir, double speed, double dt){
    // Target where the drone need to go to
    // Vector3 target(-60, 5, 50);     
    // Vector3 target(1550,264,900);     
    // Beeline* beeline = new Beeline(target, loc, speed, dt);
    // beeline->Move();

    // Patrol* patrol = new Patrol(loc, dir, speed, dt);
    // patrol->Move();
    
    ManualMovement* manual = new ManualMovement(webapp, dir, loc, speed, dt);
    manual->Move();
}

double* Drone::getLocation(){
    return this->pos;
}


double* Drone::getDirection(){
    return this->dir;
}

void Drone::setDirection(double* newDir){
    this->dir[0] = newDir[0];
    this->dir[1] = newDir[1];
    this->dir[2] = newDir[2];
}


double Drone::getSpeed(){
    return this->speed;
}

void Drone::setSpeed(double newSpeed){
    this->speed = newSpeed;
}

int Drone::getID(){
    return this->id;
}


void Drone::FinishUpdate(picojson::object& returnValue){
    picojson::object entity;
    entity["entityId"] = picojson::value((double)0);
    
    // Save the position as an array
    picojson::array pos;
    pos.push_back(picojson::value(this->pos[0]));
    pos.push_back(picojson::value(this->pos[1]));
    pos.push_back(picojson::value(this->pos[2]));
    entity["pos"] = picojson::value(pos);
    // Save the direction as an array
    picojson::array dir;
    dir.push_back(picojson::value(this->dir[0]));
    dir.push_back(picojson::value(this->dir[1]));
    dir.push_back(picojson::value(this->dir[2]));
    entity["dir"] = picojson::value(dir);
    // Send the compile picojson data to the UI in the returnValue variable
    returnValue["entity"+std::to_string(this->id)] = picojson::value(entity);
}


// setter & geter for key value