/**
 * @file patrol.h
 * @author Mengsang Korn (korn0086@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PATROL_H_
#define PATROL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "movement.h"
#include "beeline.h"
#include <math.h>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Patrol will randomly move the drone within the boundary.
 * 
 */
class Patrol : public Movement{

    public:
        /**
         * @brief Construct a new Patrol object
         * 
         */
        Patrol(double* pos_, double* dir_, double speed, double dt_);

        /**
         * @brief Destroy the Patrol object
         * 
         */
        ~Patrol(){}

        /**
         * @brief Move function for patrol strategy.
         * 
         * @param pos 
         * @param dir 
         */
        void Move();

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
         * @brief Get the robot loc object
         * 
         * @return double 
         */
        double* get_robot_loc(){ return this->robot_loc; }

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

        /**
         * @brief Set the robot loc object
         * 
         * @param loc_found 
         */
        void set_robot_loc(double* loc_found){ this->robot_loc = loc_found;};

        double time = 0.0;
        double* dir;
        double* pos;
    private:
        double* robot_loc;  // location where robot is found
        double speed;
        double dt;
};

#endif //PATROL_H_