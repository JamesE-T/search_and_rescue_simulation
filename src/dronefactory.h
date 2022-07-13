/**
 * @file dronefactory.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef DRONEFACTORY
#define DRONEFACTORY

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entityfactory.h"
#include "drone.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Drone Factory Class
 *
 *  DroneFactory inherits EntityFactory and overloads the CreateEntity and getName functions based on the picojson object.
 */

class DroneFactory : public EntityFactory {
    public:

        /**
        * @brief DroneFactory constructor.
        *
        */
        DroneFactory(){}

        /**
        * @brief DroneFactory destructor.
        *
        */
        ~DroneFactory(){}
        /**
        * @brief overloads the Factory CreateEntity function, calls the picojson obect entitydata and cameracontroller and sets them equal to variables in the drone class.
        *
        * @return Entity*
        */
        Entity* CreateEntity(picojson::object& entityData, ICameraController& cameraController);

        /**
        * @brief overloads the Factory Getname function, simply returns "drone"
        *
        * @return String
        */
        std::string getName(){
            return "drone";
        }
};
#endif //DRONEFACTORY