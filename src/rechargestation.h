/**
 * @file rechargestation.h
 * @author Jack Haussner
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef RECHARGESTATION
#define RECHARGESTATION

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Rechargestation entity, the child of the entity class.
 *
 *  Calls both Update and FinishUpdate, but do nothing because the rechargestation does not move.
 *  
 */
class RechargeStation : public Entity {

    public:
        /**
         * @brief Construct a new Recharge Station object
         * 
         */
        RechargeStation(){}
        
        /**
         * @brief Destroy the Recharge Station object
         * 
         */
        ~RechargeStation(){}

        /**
         * @brief Get the Location object
         * 
         * @return double* 
         */
        double* getLocation(){
            return pos;
        }
        /**
         * @brief Set the Location object
         * 
         * @param location 
         */
        void setLocation(double* location){
            pos[0] = location[0];
            pos[1] = location[1];
            pos[2] = location[2];
        }
        /**
         * @brief get the ID number
         * 
         * @return int 
         */
        int getID(){
            return id;
        }
        /**
         * @brief set the ID number
         * 
         * @param id 
         */
        void setID(int id){
            this->id = id;
        }
        /**
         * @brief Update object given amount of time passed since last update
         * 
         * @param dt 
         */
        void Update(double dt){
            
        }
        /**
         * @brief FinishUpdate by returning new updated objects to UI
         * 
         * @param returnValue 
         */
        void FinishUpdate(picojson::object& returnValue){
            
        }
    private:
        int id; 
        double pos[3]; 
};
#endif //RECHARGESTATION