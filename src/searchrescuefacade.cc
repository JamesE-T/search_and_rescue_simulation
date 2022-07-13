/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "searchrescuefacade.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SearchAndRescue::CreateEntity(picojson::object& entityData, ICameraController& cameraController){
    // Creates an entity based on JSON data stored as an object.

    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;
    CompositeEntityFactory* composite = new CompositeEntityFactory();
    EntityFactory* df = new DroneFactory();
    EntityFactory* hs = new HospitalFactory();
    EntityFactory* rc = new RechargeStationFactory();
    composite->addFactory(df);
    composite->addFactory(hs);
    composite->addFactory(rc);
    Entity* createdEntity;
    createdEntity = composite->CreateEntity(entityData, cameraController);
    entities.push_back(createdEntity);
}

void SearchAndRescue::Update(double dt){
    for(int i = 0; i < entities.size(); i++){
        entities[i]->Update(dt);
    }
}


void SearchAndRescue::FinishUpdate(picojson::object& returnValue){
    for(int i = 0; i < entities.size(); i++){
        entities[i]->FinishUpdate(returnValue);
    }
}