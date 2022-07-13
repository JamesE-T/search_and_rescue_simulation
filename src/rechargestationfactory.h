/**
 * @file rechargestationfactory.h
 * @author Jack Haussner
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef RECHARGESTATIONFACTORY
#define RECHARGESTATIONFACTORY

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entityfactory.h"
#include "rechargestation.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief RechargeStation factory, the child of the factory class.
 *
 *  Calls both CreateEntity and getName, from factory.
 *  
 */
class RechargeStationFactory : public EntityFactory {
    
    public:
        /**
         * @brief Construct a new Recharge Station Factory object
         * 
         */
        RechargeStationFactory(){}
        /**
         * @brief Destroy the Recharge Station Factory object
         * 
         */
        ~RechargeStationFactory(){}

        /**
         * @brief Create a Entity object
         * 
         * @param entityData 
         * @param cameraController 
         * @return Entity* 
         */
        Entity* CreateEntity(picojson::object& entityData, ICameraController& cameraController);
        /**
         * @brief Get the Name of entity being created
         * 
         * @return std::string 
         */
        std::string getName(){
            return "recharge station";
        }

};
#endif //RECHARGESTATIONFACTORY