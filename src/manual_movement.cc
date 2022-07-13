/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "manual_movement.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

ManualMovement::ManualMovement(WebApp* webapp_, double* dir_, double* pos_, double speed_, double dt_){
    this->webapp  = webapp_;
    this->dir     = dir_;
    this->pos     = pos_;
    this->speed   = speed_;
    this->dt      = dt_;
}

void ManualMovement::Move(){
    // Listenign to keyboard commands and specify boolean based Direction depending on keyboards pressed.
    this->SetJoystick(
        this->get_web_app()->IsKeyDown("ArrowRight") ? 1 : (this->get_web_app()->IsKeyDown("ArrowLeft") ? -1 : 0),
        this->get_web_app()->IsKeyDown("w") ? 1          : (this->get_web_app()->IsKeyDown("s") ? -1 : 0),
        this->get_web_app()->IsKeyDown("ArrowUp") ? -1   : (this->get_web_app()->IsKeyDown("ArrowDown") ? 1 : 0),
        this->get_web_app()->IsKeyDown("a") ? 1          : (this->get_web_app()->IsKeyDown("d") ? -1 : 0));

    // Updating position based on the new direction.
    for (int i = 0; i < 3; i++) {
        pos[i] += this->get_speed() * dir[i] * this->get_dt();
    } 
}

void ManualMovement::SetJoystick(double x, double y, double z, double a){
    dir[0] = x; 
    dir[1] = y; 
    dir[2] = z;
}