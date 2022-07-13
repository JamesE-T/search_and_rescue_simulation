/**
 * @file searchrescuefacade.h
 * @author Mengsang Korn, Jack Haussner
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SEARCHRESCUEFACADE
#define SEARCHRESCUEFACADE

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <picojson.h>
#include <string>
#include "entityfactory.h"
#include "compositeentityfactory.h"
#include "hospitalfactory.h"
#include "dronefactory.h"
#include "rechargestationfactory.h"

#include "entity.h"
#include "drone.h"
#include "robot.h"
#include "rechargestation.h"
#include "hospital.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief Facade for simulation.
 * 
 */
class SearchAndRescue {
    public:
        /**
         * @brief Construct a new Search And Rescue object
         * 
         */
        SearchAndRescue(){}

        /**
         * @brief Destroy the Search And Rescue object
         * 
         */
        ~SearchAndRescue(){
            for(int i = 0; i < entities.size(); i++){
                delete entities[i];
            }
        }

        /**
         * @brief Construct a new Search And Rescue object
         * 
         * @param search 
         */
        SearchAndRescue(const SearchAndRescue& search)= delete;

        /**
         * @brief overwrite assignment operatro for dynamic mem. allocation, (one of the Big3)
         * 
         * @param search 
         * @return SearchAndRescue& 
         */
        SearchAndRescue& operator=(const SearchAndRescue& search)= delete;

        /**
         * @brief Create a Entity object
         * 
         * @param entityData 
         * @param cameraController 
         */
        void CreateEntity(picojson::object& entityData, ICameraController& cameraController);

        /**
         * @brief Updates the simulation. 
         * 
         * @param dt 
         */
        void Update(double dt);

        /**
         * @brief Called after all updating is done.  Entity should be returned to the UI.
         * 
         * @param returnValue 
         */
        void FinishUpdate(picojson::object& returnValue);

        std::vector<Entity*> entities;
};
#endif //SearchandRescue