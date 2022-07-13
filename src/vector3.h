/**
 * @file vector3.h
 * 
 */
#ifndef VECTOR3_H_
#define VECTOR3_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "math.h"

#include <iostream>
using namespace std;


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The 3-dimensional Vector class
 *
 *  This class allows us to process data in the form of three dimensional vectors
 */
class Vector3 {

  public:
    /**
     * @brief Construct a new Vector 3 object
     * 
     */
    Vector3();

    /**
     * @brief Construct a new Vector 3 object
     * 
     * @param x 
     * @param y 
     * @param z 
     */
    Vector3(double x, double y, double z);

    /**
     * @brief Destroy the Vector 3 object
     * 
     */
    ~Vector3();                     
    
    /**
     * @brief Prints the vector contents
     * 
     */
    void Print();

    /**
     * @brief assignment operator
     * 
     * @param vec 
     * @return Vector3 
     */
    Vector3 operator=(Vector3 vec);

    /**
     * @brief addition and subtraction operators
     * 
     * @param Vector3 vec 
     * @return Vector3 object
     */
    Vector3 operator+(Vector3 vec);
    Vector3 operator-(Vector3 vec);

    /**
     * @brief 
     * 
     * @param double value 
     * @return resultant vector3 object
     */
    Vector3 operator*(double value);
    Vector3 operator/(double value);

    /**
     * @brief set x, y, z values of vector3 object
     * 
     * @param x, y, z
     */
    void setX(double x){this->x = x;}
    void setY(double y){this->y = y;}
    void setZ(double z){this->z = z;}

    /**
     * @brief get x, y, z values of vector3 object
     * 
     * @return double value from vector
     */
    double getX(){return this->x;}
    double getY(){return this->y;}
    double getZ(){return this->z;}

    /**
     * @brief normalize the vector to get a point vector
     * 
     * @return Vector3 
     */
    Vector3 Normalize();

  private:
    double x, y, z;


}; //end of class

#endif // VECTOR3_H_
