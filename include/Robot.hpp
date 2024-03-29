/**
 * @file Robot.hpp
 * @author Rishabh Mukund (rmukund@umd.edu)
 * @author Prannoy Namala (pnamala@umd.edu)
 * @brief Header file for Robot Class
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
#include <array>

class Robot{
 public:
    /**
     * @brief Construct a new Robot object
     *
     * @param max_acc (double) - Maximum Acceleration
     * @param wheel_base (double) - Wheel base
     * @param track_width (double) - Track Width
     */
    Robot(double max_acc, double wheel_base,
          double track_width, double max_heading_angle);

    /**
    * @brief Get the max_acc parameter
    *
    * @return double
    */
    double getMaxAcc();

    /**
    * @brief Get the wheel_base parameter
    *
    * @return double
    */
    double getWheelBase();

    /**
    * @brief Get the track_width parameter
    *
    * @return double
    */
    double getTrackWidth();

    /**
    * @brief Get the curr_pos parameter
    *
    * @return pos
    */
    std::array<double, 2> getCurrPos();

    /**
    * @brief Set the curr_pos parameter
    *
    * @param curr_pos (pos) - Current Position (x,y,th)
    */
    void setCurrPos(std::array<double, 2> curr_pos);

    /**
    * @brief Get the curr_vel parameter
    *
    * @return double
    */
    double getCurrVel();

    /**
    * @brief Set the curr_vel parameter
    *
    * @param curr_vel (double) - Current Velocity
    */
    void setCurrVel(double velocity);

    /**
    * @brief Get the final_pos parameter
    *
    * @return pos
    */
    std::array<double, 2> getFinalPos();

    /**
    * @brief Set the final_pos parameter
    *
    * @param final_pos (pos) - Final Position (x,y,th)
    */
    void setFinalPos(std::array<double, 2> final_pos);

    /**
    * @brief Get the max_pivot_angle parameter
    *
    * @return double
    */
    double getMaxHeadingAngle();

 private:
    double max_acc_, wheel_base_, track_width_, max_heading_angle_;
    double curr_vel_{};
    std::array<double, 2> final_pos_ = {1, 1}, curr_pos_ = {0, 0};
};
