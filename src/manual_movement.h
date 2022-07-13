/**
 * @file manual_movement.h
 * @author Mengsang Korn (korn0086@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MANUAL_H_
#define MANUAL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "movement.h"
#include "web_app.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Manaul Movement takes the keyCode value returned 
 * from JSON and move the drone based on boolean based direction
 * ,whether -1, 1, 0, 
 * eg: if 'w' and 's' key are pressed at the same time
 * the boolean direction will be 0 and drone stays. etc. 
 * 
 */


class ManualMovement : public Movement{
    public:

        /**
         * @brief Construct a new Manual Movement object
         * 
         */
        ManualMovement(WebApp* webapp_, double* dir_, double* pos_, double speed_, double dt_);

        /**
            * @brief Destroy the Manual Movement object
            * 
            */
        ~ManualMovement(){}

        /**
         * @brief Move() function for ManualMovement class.
         * 
         * @param webapp_ 
         * @param dir_ 
         * @param pos_ 
         * @param speed_ 
         * @param dt_ 
         */
        void Move();

        /**
         * @brief Set the Joystick object for handling 
         * keyboard's value receive from the simulator.
         * 
         * @param x 
         * @param y 
         * @param z 
         * @param a 
         */
        void SetJoystick(double x, double y, double z, double a);

        /**
         * @brief Get the web app object
         * 
         * @return WebApp* 
         */
        WebApp* get_web_app(){ return this->webapp; }

        /**
         * @brief Get the dir object
         * 
         * @return double* 
         */
        double* get_dir(){ return this->dir; }

        /**
         * @brief Get the pos object
         * 
         * @return double* 
         */
        double* get_pos(){ return this->pos; }

        /**
         * @brief Get the speed object
         * 
         * @return double 
         */
        double get_speed(){ return this->speed; }

        /**
         * @brief Get the dt object
         * 
         * @return double 
         */
        double get_dt(){ return this->dt; }

        /**
         * @brief Set the dir object
         * 
         * @param new_dir 
         */
        void set_dir(double* dir_){ this->dir = dir_; }

        /**
         * @brief 
         * 
         * @param new_pos
         */
        void set_pos(double* pos_) { this->pos = pos_; }


        double* dir;
        double* pos;
    private:
        WebApp* webapp;
        double speed;
        double dt;
};


#endif //MANUAL_H_