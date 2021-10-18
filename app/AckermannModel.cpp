/**
 * @file AckremannModel.cpp
 * @author Rishabh Mukund (rmukund@umd.edu)
 * @author Prannoy Namala (pnamala@umd.edu)
 * @brief Source file for Ackermann Model Class
 * @version 0.1
 * @date 10-15-2021
 *
 * Copyright (c) 2021 Group 808X-MT14
 *
 * Licensed under the MIT License (the "License")
 *
 */


#include <AckermannModel.hpp>
#include <math>
#include <iostream>

/**
* @brief Constructs the AckermannModel object with user defined values
*/
AckermannModel::AckermannModel(Robot *r, pos target)
: r_(r),
  target_(target) {
    std::cout << "AckermannModel initialized" << std::endl;
}

/**
* @brief Computing the angle to turn the wheels
*/
void AckermannModel::ComputeWheelAngles() {
  return void;
}

/**
* @brief Computing the velocities for each driving wheel
*/
void AckermannModel::ComputeWheelVelocities() {
  return void;
}
