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
AckermannModel::AckermannModel(Robot &r, Controller &right_vel_controller,
                               Controller &left_vel_controller)
: r_(r),
  right_vel_controller_(right_vel_controller),
  left_vel_controller_(left_vel_controller) {
    std::cout << "AckermannModel initialized" << std::endl;
}

/**
* @brief Computing the angle to turn the wheels
*/
void AckermannModel::ComputeWheelAngles() {
  double wheel_base = r_.getWheelBase();
  double track_width = r_.getTrackWidth();

  std::array<double, 2> curr_pos = r_.getCurrPos();
  std::array<double, 2> final_pos = r_.getFinalPos();

  //* Calculating the steering angle
  delta_ = atan2(final_pos[1]-curr_pos[1], final_pos[0]-curr_pos[0]);
  if (delta_ < -0.785) {
    delta_ = -0.785;
  } else if (delta_ > 0.785) {
    delta_ = 0.785;
  }

  double radius_icc_ = wheel_base/tan(delta_);

    if (delta_> 0) {
      right_wheel_angle_ = atan2(wheel_base, (radius_icc_-(0.5*track_width)));
      left_wheel_angle_ = atan2(wheel_base, (radius_icc_+(0.5*track_width)));
    } else {
      left_wheel_angle_ = atan2(wheel_base, (radius_icc_-(0.5*track_width)));
      right_wheel_angle_ = atan2(wheel_base, (radius_icc_+(0.5*track_width)));
    }
}

/**
* @brief Computing the velocities for each driving wheel
*/
void AckermannModel::ComputeWheelVelocities() {
  double wheel_base = r_.getWheelBase();
  double curr_vel = r_.getCurrVel();
  right_wheel_vel_ = curr_vel*sin(right_wheel_angle_)/wheel_base;
  left_wheel_vel_ = curr_vel*sin(left_wheel_angle_)/wheel_base;
}

/**
* @brief Computing the inputs for each front wheel. Check for convergence to target
*/
int AckermannModel::GoTotarget(double threshold) {
  std::array<double, 2> final_pos = r_.getFinalPos();
  double dist = sqrt(pow(final_pos[0], 2)+pow(final_pos[1], 2));

  double curr_right_vel{};
  double curr_left_vel{};
  double dt = right_vel_controller_.getDt();
  double curr_vel = r_.getCurrVel();

  int i = 0;
  while (dist > threshold) {
    double prev_dist = dist;

    //* Calculating the Steering Angle
    ComputeWheelAngles();

    //* Calculating the Driving wheel Velocities
    ComputeWheelVelocities();

    //* PID Controller for right wheel velocity
    curr_right_vel += right_vel_controller_.
        ComputeOutput(curr_right_vel, right_wheel_vel_);

    //* PID Controller for left wheel velocity
    curr_left_vel += left_vel_controller_.
        ComputeOutput(curr_left_vel, left_wheel_vel_);

    //* Updating final position
    final_pos[0] -= curr_vel*cos(delta_)*dt;
    final_pos[1] -= curr_vel*sin(delta_)*dt;
    r_.setFinalPos(final_pos);

    dist = sqrt(pow(final_pos[0], 2) +pow(final_pos[1], 2));

    //* Checking for convergence
    if (prev_dist < dist) {
      std::cout << "Starting to diverge. Achieved the closest point to target"
          << std::endl;
      break;
    }

    std::cout << "\n Wheel Angles L and R: " << left_wheel_angle_
        << " , " << right_wheel_angle_<< std::endl;
    std::cout << "Wheel Velocities L and R: " << left_wheel_vel_
        << " , " << right_wheel_vel_<< std::endl;
    std::cout << "Distance to cover: " << dist << " , Steering Angle"
        << delta_ << std::endl;
    i++;
  }

  std::cout << "\n Target Reached in "<< i << " steps"<< std::endl;
  return 1;
}
