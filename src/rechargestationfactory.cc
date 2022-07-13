/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rechargestationfactory.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Entity* RechargeStationFactory::CreateEntity(picojson::object& entityData, ICameraController& cameraController){
    //this class and robot both do the exact same thing that the hospital factory does.
    RechargeStation* rechargestation = new RechargeStation();
    rechargestation->setID(entityData["entityId"].get<double>());

    picojson::array position = entityData["position"].get<picojson::array>();
    double pos[3];

    pos[0] = position[0].get<double>();
    pos[1] = position[1].get<double>();
    pos[2] = position[2].get<double>();\
    rechargestation->setLocation(pos);
    return rechargestation;
}