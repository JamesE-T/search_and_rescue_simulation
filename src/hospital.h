/**
 * @file hospital.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef HOSPITAL
#define HOSPITAL

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Hospital entity, the child of the entity class.
 *
 *  Calls both Update and FinishUpdate, but do nothing because the hospital does not move.
 *  
 */
class Hospital : public Entity {
    public:

        /**
        * @brief Hospital Constructor
        *
        */
        
        Hospital(){}

        /**
        * @brief Hospital destructor
        *
        */

        ~Hospital(){}

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
         * @brief get the id number of entity
         * 
         * @return int 
         */

        int getID(){
            return id;
        }
        /**
         * @brief set the id number of an entity 
         * 
         * @param id 
         */

        void setID(int id){
            this->id = id;
        }

        /**
         * @brief update inherited from entity, does nothing because a hospital will not update
         * 
         * @param dt time in seconds passed since last update;
         */

        void Update(double dt){

        }
        /**
         * @brief FinishUpdate inherited from entity, does nothing because a hospital does not need to update
         * 
         * @param returnValue 
         */

        void FinishUpdate(picojson::object& returnValue){
            
        }
    private:
        int id; 
        double pos[3]; 
};
#endif //HOSPITAL