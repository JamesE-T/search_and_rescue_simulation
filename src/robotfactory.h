#ifndef ROBOTFACTORY
#define ROBOTFACTORY

#include "entityfactory.h"
#include "robot.h"

class RobotFactory : public EntityFactory {
    public:
        /**
         * @brief Construct a new Robot Factory object
         * 
         */
        RobotFactory(){}
        /**
         * @brief Destroy the Robot Factory object
         * 
         */
        ~RobotFactory(){}
        /**
         * @brief Create a Entity object
         * 
         * @param entityData 
         * @param cameraController 
         * @return Entity* 
         */
        Entity* CreateEntity(picojson::object& entityData, ICameraController& cameraController);
        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string getName(){
            return "robot";
        }
};
#endif //ROBOTFACTORY