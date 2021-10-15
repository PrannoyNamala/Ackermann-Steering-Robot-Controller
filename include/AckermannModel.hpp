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
 */

#include <iostream>
#include <Robot.hpp>

typedef double pos[3];

class AckremannModel {
 public:
  double _radius_icc{}, _left_wheel_angle{}, _right_wheel_angle{};
  double _left_wheel_vel{}, _right_wheel_vel{};

    /**
     * @brief Construct a new AckremannModel object
     *
     * @param r (Robot) - object of Robot class
     * @param target (pos) - target coordinates (x,y,th)
     */
  AckremannModel(Robot r, pos target);

  /**
   * @brief Computing the angle to turn the wheels
   *
   * @param curr_pos (pos) - current position coordinates (x,y,th)
   * @param target (pos) - target coordinates (x,y,th)
   * @param wheel_base (double) - wheel base defined in the Robot class
   * @param track_width (double) - track width defined in the Robot class
   */
  void computeWheelAngles(pos curr_pos, pos target, double wheel_base, double track_width);

  /**
   * @brief Computing the velocities for each driving wheel
   *
   * @param left_wheel_angle (double) - pivot angle of the left wheel
   * @param right_wheel_angle (double) - pivot angle of the right wheel
   * @param wheel_base (double) - wheel base defined in the Robot class
   */
  void computeWheelVelocities(double left_wheel_angle, double right_wheel_angle, double wheel_base);

 private:
    Robot _r;
    pos _target;
};


