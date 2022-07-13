/**
 * @file drone.h
 * @author Jack Haussner & Mengsang Korn
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DRONE
#define DRONE


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include "vector3.h"
#include <vector>
#include "web_app.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Drone Entity Class.
 * 
 */
class Drone : public Entity {
    public:

        /**
         * @brief Construct a new Drone object
         * 
         */
        Drone(WebApp* webapp_){
            webapp = webapp_;
        }

        /**
         * @brief Destroy the Drone object
         * 
         */
        ~Drone(){}

        /**
         * @brief Will be called multiple times and keep updating the simulation.
         * Movement strategy will be call in this function for the drone to be updated and moved
         * to the desired position.
         * 
         * @param dt 
         */
        void Update(double dt);

        /**
         * @brief Determine which movement strategy to use in the simulation.
         * 
         * @param dt 
         */
        void movement_controller(double* loc, double* dir, double speed, double dt);

        /**
         * @brief  Called after all updating is done.  Entity should be returned to the UI.
         * 
         * @param returnValue 
         */
        void FinishUpdate(picojson::object& returnValue);

        /**
         * @brief Get the Location of the drone.
         * 
         * @return double* 
         */
        double* getLocation();

        /**
         * @brief Get the Direction of the drone.
         * 
         * @return double* 
         */
        double* getDirection();

        /**
         * @brief Set the Direction of the drone.
         * 
         * @param newDirection 
         */
        void setDirection(double* newDirection);

        /**
         * @brief Get the Speed of the drone.
         * 
         * @return double 
         */
        double getSpeed();

        /**
         * @brief Set the Speed of the drone.
         * 
         * @param newSpeed 
         */
        void setSpeed(double newSpeed);

        /**
         * @brief get the drone ID.
         * 
         * @return int 
         */
        int getID();


        int id; 
        double pos[3]; 
        double dir[3]; 
        double speed;
        ICameraResult* result;
        std::vector<Camera*> cameras;
        float lastPictureTime = 0.0;
        float time = 0.0;
        WebApp* webapp;
};


#endif //DRONE
