/**
 * @file hospitalfactory.h
 * @author Jack Haussner
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef HOSPITALFACTORY
#define HOSPITALFACTORY

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entityfactory.h"
#include "hospital.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Hospitalfactory, the child of the factory class.
 *
 *  Calls both CreateEntity and getName, from factory.
 *  
 */

class HospitalFactory : public EntityFactory {
    public:
        /**
         * @brief Construct a new Hospital Factory object
         * 
         */
        HospitalFactory(){}

        /**
         * @brief Destroy the Hospital Factory object
         * 
         */

        ~HospitalFactory(){}

        /**
         * @brief Create a Entity object
         * 
         * @param entityData 
         * @param cameraController 
         * @return Entity* 
         */

        Entity* CreateEntity(picojson::object& entityData, ICameraController& cameraController);
        /**
         * @brief Get the Name of the type of entity the factory creates
         * 
         * @return std::string 
         */
        std::string getName(){
            return "hospital";
        }

};
#endif //HOSPITALFACTORY