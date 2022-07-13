/**
 * @file movement.h
 * @author Mengsang Korn (korn0086@umn.edu)
 * @brief Movement class, base class.
 * @version 0.1
 * @date 2021-12-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "vector3.h"
#include "drone.h"
#include "web_app.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief Movement base class for other movement strategies to inherit from.
 * 
 */
class Movement{
    public:
        /**
         * @brief Destroy the Movement object
         * 
         */
        ~Movement(){}


        /**
         * @brief Move function to be implemented by inherinted class.
         * 
         */
        virtual void Move() = 0;

};

#endif //MOVEMENT_H_
