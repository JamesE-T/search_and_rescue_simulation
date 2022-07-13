/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "beeline.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

Beeline::Beeline(Vector3 target_, double* pos_, double speed_, double dt_){
    this->goal_pos = target_;
    this->pos = pos_;
    this->speed = speed_;
    this->dt = dt_;
}

void Beeline::Move(){
    // 0. Where the drone is currently at 
    Vector3 current_pos(this->get_pos()[0], this->get_pos()[1], this->get_pos()[2]);

    // 1. Calculate Direction 
    Vector3 direction = this->get_goal_pos() - current_pos;

    // 2. Normalize the Direction 
    direction = direction.Normalize();    

    // 3. Calculate the velocity of the drone
    Vector3 velocity = direction * this->get_speed();

    // 4. Calculate the distance traveled over this time step 
    Vector3 distance_traveled =  velocity * this->get_dt();

    // 5. Move the drone using Eularian Integration
    current_pos = current_pos + distance_traveled;
    this->get_pos()[0] = current_pos.getX();
    this->get_pos()[1] = current_pos.getY();
    this->get_pos()[2] = current_pos.getZ();
    std::cout << current_pos.getX() << ", " << current_pos.getY() << ", " << current_pos.getZ() << ", " << endl;
}