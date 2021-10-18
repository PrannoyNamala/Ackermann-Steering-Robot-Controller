/**
 * @file AckremannModel.hpp
 * @author Rishabh Mukund (rmukund@umd.edu)
 * @author Prannoy Namala (pnamala@umd.edu)
 * @brief Header file for Ackermann Model Class
 * @version 0.1
 * @date 10-15-2021
 *
 * Copyright (c) 2021 Group 808X-MT14
 *
 * Licensed under the MIT License (the "License")
 *
 */
#pragma once
#include <iostream>
#include <Robot.hpp>


class AckermannModel {
 public:
  double radius_icc_{}, left_wheel_angle_{}, right_wheel_angle_{};
  double left_wheel_vel_{}, right_wheel_vel_{};

    /**
     * @brief Construct a new AckremannModel object
     *
     * @param r (Robot) - object of Robot class
     * @param target (pos) - target coordinates (x,y,th)
     */
  AckermannModel(Robot r, pos target);

  /**
   * @brief Computing the angle to turn the wheels
   *
   * @param curr_pos (pos) - current position coordinates (x,y,th)
   * @param target (pos) - target coordinates (x,y,th)
   * @param wheel_base (double) - wheel base defined in the Robot class
   * @param track_width (double) - track width defined in the Robot class
   */
  void ComputeWheelAngles();

  /**
   * @brief Computing the velocities for each driving wheel
   *
   * @param left_wheel_angle (double) - pivot angle of the left wheel
   * @param right_wheel_angle (double) - pivot angle of the right wheel
   * @param wheel_base (double) - wheel base defined in the Robot class
   */
  void ComputeWheelVelocities();

 private:
    Robot r_;
    pos target_;
};


