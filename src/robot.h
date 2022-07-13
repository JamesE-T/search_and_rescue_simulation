/**
 * @file robot.h
 * @author Jack Haussner
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ROBOT
#define ROBOT

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Robot entity, the child of the entity class.
 *
 *  Calls both Update and FinishUpdate, but do nothing because the robot does not move.
 *  
 */
class Robot : public Entity {

    public:
        /**
         * @brief Construct a new Robot object
         * 
         */
        Robot(){
        }
        /**
         * @brief Destroy the Robot object
         * 
         */
        ~Robot(){}
        /**
         * @brief Get the Location object
         * 
         * @return double* 
         */
        double* getLocation(){
            return pos;
        }
        /**
         * @brief Set the Location object
         * 
         * @param location 
         */
        void setLocation(double* location){
            pos[0] = location[0];
            pos[1] = location[1];
            pos[2] = location[2];
        }
        /**
         * @brief get entity id number
         * 
         * @return int 
         */
        int getID(){
            return id;
        }
        /**
         * @brief set entity id number
         * 
         * @param id 
         */
        void setID(int id){
            this->id = id;
        }
        /**
         * @brief update robot, does nothing because robot will not move
         * 
         * @param dt 
         */
        void Update(double dt){
            
        }
        /**
         * @brief finishUpdate robot, does nothing because robot will not move
         * 
         * @param returnValue 
         */
        void FinishUpdate(picojson::object& returnValue){
            
        }

    private:
        int id; 
        double pos[3]; 
};
#endif //ROBOT