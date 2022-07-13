/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hospitalfactory.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

Entity* HospitalFactory::CreateEntity(picojson::object& entityData, ICameraController& cameraController){
    //takes all information from picjson object, and sets the fields of a new hospital object to this parameters. Then returns a pointer to object.
    Hospital* hospital = new Hospital();
    hospital->setID(entityData["entityId"].get<double>());

    picojson::array position = entityData["position"].get<picojson::array>();
    double pos[3];
    pos[0] = position[0].get<double>();
    pos[1] = position[1].get<double>();
    pos[2] = position[1].get<double>();
    hospital->setLocation(pos);
    return hospital;
}
