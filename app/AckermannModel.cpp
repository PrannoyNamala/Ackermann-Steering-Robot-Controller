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
#include <cmath>
#include <iostream>

/**
* @brief Constructs the AckermannModel object with user defined values
*/
AckermannModel::AckermannModel(Robot &r,Controller &right_vel_controller,Controller &left_vel_controller)
: r_(r),
  right_vel_controller_(right_vel_controller),
  left_vel_controller_(left_vel_controller) {
    std::cout << "AckermannModel initialized" << std::endl;
}

/**
* @brief Computing the angle to turn the wheels
*/
void AckermannModel::ComputeWheelAngles() {
   // Target angle
  double wheel_base = r_.getWheelBase();
  double track_width = r_.getTrackWidth();

  std::array<double,3> curr_pos = r_.getCurrPos();
  std::array<double,3> final_pos = r_.getFinalPos();
  std::cout << "Start Pose" << curr_pos[1]<< std::endl;
  std::cout << "Final Pose" << final_pos[1]<< std::endl;

  delta_ = atan2(final_pos[1]-curr_pos[1],final_pos[0]-curr_pos[0]);
  if (delta_ < -0.785) {
    delta_ = -0.785;
  }
  else if (delta_ > 0.785) {
    delta_ = 0.785;
  }


  std::cout<< "Delta "<<delta_<< std::endl;
  double radius_icc_ = wheel_base/tan(delta_);

    if (delta_>0){
      right_wheel_angle_ = atan2(wheel_base,(radius_icc_-(0.5*track_width)));
      left_wheel_angle_ = atan2(wheel_base,(radius_icc_+(0.5*track_width)));
    }
    else{
      left_wheel_angle_ = atan2(wheel_base,(radius_icc_-(0.5*track_width)));
      right_wheel_angle_ = atan2(wheel_base,(radius_icc_+(0.5*track_width)));
    }
}

/**
* @brief Computing the velocities for each driving wheel
*/
void AckermannModel::ComputeWheelVelocities() {
  double wheel_base = r_.getWheelBase();
  double curr_vel = r_.getCurrVel();
  std::cout<<"Current Velocity"<<curr_vel;
  right_wheel_vel_ = curr_vel*sin(right_wheel_angle_)/wheel_base;
  left_wheel_vel_ = curr_vel*sin(left_wheel_angle_)/wheel_base;
}

void AckermannModel::GoTotarget() {


//   while(curr_pos not in treshold){
//     computeangles
//     computewheelvelocities
//     computeOutputforRightWheel
//     conputeOutputforleftwheel
//     updatePosition // Think which one here
//     print status
//   }
  return;

}
