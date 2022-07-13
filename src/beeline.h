/**
 * @file beeline.h
 * @author Mengsang Korn (korn0086@umn.edu)
 * @brief Beeline class for beeline movement strategy.
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef BEELINE_H_
#define BEELINE_H_

#include "movement.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief Beeline take in the current position, speed of the drone, 
 * and time since drone was last moved, dt. It then uses calulate
 * the position of where the drone supposed to go and use
 * Eularian Integration to update the new position of the drone.
 * 
 */
class Beeline : public Movement{
    public:
        /**
         * @brief Construct a new Beeline object
         * 
         * @param target 
         */
        Beeline(Vector3 target_, double* pos_, double speed_, double dt_);

        /**
         * @brief Destroy the Beeline object
         * 
         */
        ~Beeline(){}

        /**
         * @brief Move function for beeline strategy.
         * 
         */
        void Move();

        /**
         * @brief Get the goal pos object
         * 
         * @return Vector3 
         */
        Vector3 get_goal_pos(){
            return this->goal_pos;
        }

        /**
         * @brief Get the pos object
         * 
         * @return double* 
         */
        double* get_pos(){
            return this->pos;
        }

        /**
         * @brief Get the speed object
         * 
         * @return double 
         */
        double get_speed(){
            return this->speed;
        }

        /**
         * @brief Get the dt object
         * 
         * @return double 
         */
        double get_dt(){
            return this->dt;
        }

    private:
        double* pos;
        double speed;
        double dt;
        Vector3 goal_pos;   // Placeholder for goal position/target.

};
#endif //BEELINE_H_
