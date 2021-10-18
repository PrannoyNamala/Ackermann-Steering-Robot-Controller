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

#include <iostream>

typedef double pos[3];

class Robot{
 public:
    /**
     * @brief Construct a new Robot object
     *
     * @param max_acc (double) - Maximum Acceleration
     * @param wheel_base (double) - Wheel base
     * @param track_width (double) - Track Width
     */
    Robot(double max_acc, double wheel_base, double track_width);

    /**
    * @brief Get the max_acc parameter
    *
    * @return double
    */
    double GetMaxAcc();

    /**
    * @brief Get the wheel_base parameter
    *
    * @return double
    */
    double GetWheelBase();

    /**
    * @brief Get the track_width parameter
    *
    * @return double
    */
    double GetTrackWidth();

    /**
    * @brief Get the curr_pos parameter
    *
    * @return pos
    */
    pos GetCurrPos();

    /**
    * @brief Set the curr_pos parameter
    *
    * @param curr_pos (pos) - Current Position (x,y,th)
    */
    void SetCurrPos(pos curr_pos);

    /**
    * @brief Get the curr_vel parameter
    *
    * @return double
    */
    double GetCurrVel();

    /**
    * @brief Set the curr_vel parameter
    *
    * @param curr_vel (double) - Current Velocity
    */
    void SetCurrVel(double velocity);

    /**
    * @brief Get the final_pos parameter
    *
    * @return pos
    */
    pos GetFinalPos();

    /**
    * @brief Set the final_pos parameter
    *
    * @param final_pos (pos) - Final Position (x,y,th)
    */
    void SetFinalPos(pos final_pos);

 private:
    double max_acc_, wheel_base_, track_width_;
    double curr_vel_{};
    pos final_pos_ = {0,0,0}, curr_pos_ = {0,0,0};
};


