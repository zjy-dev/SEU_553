#ifndef _CAR_H_
#define _CAR_H_

#include "Brake.h"
#include "SteeringWheel.h"
#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle { // ??????????????????????????????��??
public:
  Car(std::string brakeName, std::string steeringWheelName, int speed)
      : Vehicle(speed) {
    b.setName(brakeName);
    s.setName(steeringWheelName);
  }
  ~Car() {}
  void showInfo() const {
    std::cout << "Brake Name: " << b.getName() << std::endl;
    std::cout << "Steering Wheel: " << s.getName() << std::endl;
    std::cout << "Speed: " << getSpeed() << std::endl;
  }

private:
  Brake b; // ????????????????????????????????????
  SteeringWheel s;
};

#endif // !_CAR_H_
