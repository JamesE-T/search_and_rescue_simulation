/**
 * @file EntityFactory.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */


#ifndef ENTITYFACTORY
#define ENTITYFACTORY

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <picojson.h>
#include "entity.h"
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main virtual class for the generation of entities.
 *
 *  Calls to CreateEntity function to get a new instance of an entity.
 *  
 */

class EntityFactory {
    public:

        /**
        * @brief Virtual call to CreateEntity, will be used all factories that inherit from EntityFactory. Takes in a picojson obect and a cameracontroller if it has one.
        *
        * @return An Entity* to reference the location of the newly made entity, this value is pushed back to the facade that keeps track of all entities.
        */

        virtual Entity* CreateEntity(picojson::object& entityData, ICameraController& cameraController) = 0;
        
        /**
        * @brief Virtual call to GetName, will be used all factories that inherit from EntityFactory for mapping composite factory to different calls of other factories.
        *
        * @return An String to reference add to the composite factory map of factory types.
        */

        virtual std::string getName() = 0;


};
#endif //EntityFactory
