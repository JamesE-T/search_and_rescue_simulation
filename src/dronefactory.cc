/**
 * @file dronefactory.cc
 *
 * @copyright 2021 3081W, All rights reserved.
 */

 /*******************************************************************************
* Includes
******************************************************************************/
#include "dronefactory.h"
#include "web_app.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 //this function simply uses what was originally given to us in the WebApp to create drones in local memory.
Entity* DroneFactory::CreateEntity(picojson::object& entityData, ICameraController& cameraController){
    // camaraController is a WebApp object, we just need to cast it to WebApp 
    // to have accesss to functions provided in WebApp class.
    Drone* currentDrone = new Drone(dynamic_cast<WebApp*>(&cameraController));  
    currentDrone->id = entityData["entityId"].get<double>();
    currentDrone->speed = entityData["speed"].get<double>();

    // Get the position as an array
    picojson::array position = entityData["position"].get<picojson::array>();
    currentDrone->pos[0] = position[0].get<double>();
    currentDrone->pos[1] = position[1].get<double>();
    currentDrone->pos[2] = position[1].get<double>();

    // Get the direction as an array
    picojson::array dir = entityData["direction"].get<picojson::array>();
    currentDrone->dir[0] = dir[0].get<double>();
    currentDrone->dir[1] = dir[1].get<double>();
    currentDrone->dir[2] = dir[1].get<double>();

    picojson::array cameras = entityData["cameras"].get<picojson::array>();

        for (int i = 0; i < cameras.size(); i++) {
            Camera* camera = new Camera(cameras[i].get<double>(), &cameraController);
            currentDrone->cameras.push_back(camera);
                std::cout << "loop test \n" << std::endl;

        }
    

    return currentDrone;
}