/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "robotfactory.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Entity* RobotFactory::CreateEntity(picojson::object& entityData, ICameraController& cameraController){

    Robot* robot = new Robot();
    robot->setID(entityData["entityId"].get<double>());

    picojson::array position = entityData["position"].get<picojson::array>();
    double pos[3];

    pos[0] = position[0].get<double>();
    pos[1] = position[1].get<double>();
    pos[2] = position[2].get<double>();
    robot->setLocation(pos);
    return robot;
}