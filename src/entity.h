/**
 * @file Entity.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */
#ifndef ENTITY 
#define ENTITY 

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "camera.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main abstract class for entities.
 *
 *  Calls both Update and FinishUpdate for all entities that are being kept track of by the facade enitity vector.
 *  
 */
class Entity {
    public:
        
        /**
        * @brief Entity Constructor
        *
        */

        Entity(){}

        /**
        * @brief Entity destructor.
        */
        ~Entity(){}

        /**
        * @brief Virtual call to Update, is purely virtual and is redefined by different inheriting entities depending on the object.
        *
        * @return Void.
        */
        virtual void Update(double dt) = 0;
        /**
        * @brief Virtual call to FinishUpdate, is purely virtual and is redefined by different inheriting entities depending on the object.
        *
        * @return Void, returns picojson objects to the simulation UI within the functions.
        */
        virtual void FinishUpdate(picojson::object& returnValue) = 0;

    private:
        int id;

};


#endif //ENTITY
