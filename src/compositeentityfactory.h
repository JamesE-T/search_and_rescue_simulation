/**
 * @file compositeentityfactory.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef COMPOSITEENTITYFACTORY
#define COMPOSITEENTITYFACTORY

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entityfactory.h"
#include <vector>
#include <map>
#include <memory>
#include <string>
#include "robotfactory.h"
#include "rechargestationfactory.h"
#include "dronefactory.h"
#include "hospitalfactory.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The composite Entity Class
 *
 *  Creates a CompositeEntityFactory that has a map holding all types of added factories to the simulation. When the user wants to add a new factory,
 *  just add your factory to the map in the searchimage facade. They then can create entities of a new type based off of the factory pattern.
 */

class CompositeEntityFactory : public EntityFactory {
    public:
        
        /**
        * @brief CompositeEntityFactory constructor.
        *
        */
        CompositeEntityFactory(){}

        /**
        * @brief CompositeEntityFactory destructor.
        *
        */

        ~CompositeEntityFactory(){}

         /**
        * @brief AddFactory takes in an EntityFactory*, and adds the new type of factory to the inputs map for use in CreateEntity.
        *
        * @return Void
        */

        void addFactory(EntityFactory* factory);

        /**
        * @brief CreateEntity function from composite is the one called by the search facade, 
        * it then uses the map to call the other versions of create entity depending on the type of factory and entity needed to make.
        * @return Void
        */
        
        Entity* CreateEntity(picojson::object& entityData, ICameraController& cameraController);


        /**
        * @brief getName function to return the type of factory, helpful for debugging as well as mapping factorys from string to Entityfactory*
        *
        * @return String
        */
        std::string getName(){
            return "CompositeEntityFactory";
        }
        
    private:
        /**
        * @brief Map variable of strings using getname to unique pointers of type entityfactory.
        */
        std::map<std::string, std::unique_ptr<EntityFactory>> inputs;
};
#endif //COMPOSITEENTITYFACTORY