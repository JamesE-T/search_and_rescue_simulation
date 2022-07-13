/**
 * @file compositeentityfactory.cc
 *
 * @copyright 2021 3081W, All rights reserved.
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "compositeentityfactory.h"


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void CompositeEntityFactory::addFactory(EntityFactory* factory){
     std::string type = factory->getName();        //call factory->getname to get string of factory type.
    inputs[type] = std::unique_ptr<EntityFactory>(factory); //add the factory and string to map.
}
        
Entity* CompositeEntityFactory::CreateEntity(picojson::object& entityData, ICameraController& cameraController){
    std::string type = entityData["name"].get<std::string>(); //call the picojson entity name and set it to a string.
    Entity* entity;                                           //create a new pointer of entity.
    entity = inputs[type]->CreateEntity(entityData, cameraController); //set that new entity pointer to the match of the entity and factory type using the map.
    return entity;
}