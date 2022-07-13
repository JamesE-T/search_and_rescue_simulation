#include "vector3.h"

Vector3::Vector3()
  :x(0), y(0), z(0){
  }

Vector3::Vector3(double xVal, double yVal, double zVal) 
  : x(xVal), y(yVal), z(zVal) {
}

Vector3::~Vector3() {
}

void Vector3::Print() {
  cout << "[" << x << ", " << y << ", " << z<< "]" << endl;
}

Vector3 Vector3::operator = (Vector3 vec){
    // Checking for self assignment
    if(this->getX() == vec.x && this->getY() == vec.y && this->getZ() == vec.z){
        return Vector3(this->getX(), this->getY(), this->getZ());
    }else{
        this->setX(vec.x);
        this->setY(vec.y);
        this->setZ(vec.z);
        return Vector3(this->getX(), this->getY(), this->getZ());
    }
}

Vector3 Vector3::operator + (Vector3 vec) {
  return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

Vector3 Vector3::operator - (Vector3 vec) {
  return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3 Vector3::operator*(double v) {
  return Vector3(x * v, y * v, z * v);
}

Vector3 Vector3::operator/(double v) {
  return Vector3(x / v, y / v, z / v);
}

Vector3 Vector3::Normalize(){
    double magnitude = sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
    setX(this->getX()/magnitude);
    setY(this->getY()/magnitude);
    setZ(this->getZ()/magnitude);

    return Vector3(this->getX(), this->getY(), this->getZ());
}
