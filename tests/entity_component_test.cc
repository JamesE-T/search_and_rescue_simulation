#include "gtest/gtest.h"
#include "drone.h"
#include "searchrescuefacade.h"

#include <iostream>

// project::Drone ? should we have another facade here?
using project::SearchAndRescue;
using project::Entity;
using project::Drone;

class FactoryTest : public ::testing::Test{
    protected:
     virtual void SetUp() {
         system = SearchAndRescue();
     }
    
    virtual void TearDown() {}

    SearchAndRescue* system;    //this isn't right. ?
};


TEST_F(FactoryTest, DroneCreated) {
    picojson::object obj;
    obj["type"] = picojson::value("drone");
    Entity* entity = system->CreateEntity(obj); //needs camera?
    ASSERT_NE(entity, nullptr);
    Drone* drone = entity->AsType<Drone>();
    ASSERT_NE(drone, nullptr);
    ASSERT_EQ(system->GetEntities().size(), 0);
    system->AddEntity(drone);
    ASSERT_EQ(system->GetEntities().size(), 1);
    ASSERT_EQ(system->GetEntities()[0]->GetDetails(), obj);
}
//note that our current implementation does not allow for 
//usage of functions like GetEntity, or GetDetails, we will
//need to create the getter functions. Also entity creation
//requires a camera object in our implementation...?
