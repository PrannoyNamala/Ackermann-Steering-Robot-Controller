/**
 * @file Robot.cpp
 * @author Rishabh Mukund (rmukund@umd.edu)
 * @author Prannoy Namala (pnamala@umd.edu)
 * @brief source file for Robot Class
 * @version 0.1
 * @date 10-15-2021
 *
 * Copyright (c) 2021 Group 808X-MT14
 *
 * Licensed under the MIT License (the "License")
 *
 */


#include <Robot.hpp>
#include <iostream>

/**
* @brief Constructs the Robot object with user defined values
*/
Robot::Robot(double max_acc, double wheel_base, double track_width)
	: max_acc_(max_acc),
	  wheel_base_(wheel_base),
	  track_width_(track_width) {
	std::cout<<"Robot Initialized with Maximum Acceleration:"<<max_acc
			<<"m/s^2, Wheel Base:"<<wheel_base<<"m, Track Width:"
			<<track_width<<"m"<<std::endl;
}

/**
* @brief Get the max_acc parameter
*/
double Robot::GetMaxAcc() {
	return max_acc_;
}

/**
* @brief Get the wheel_base parameter
*/
double Robot::GetWheelBase() {
	return wheel_base_;
}

/**
* @brief Get the track width parameter
*/
double Robot::GetTrackWidth() {
	return track_width_;
}

/**
* @brief Get the curr_pos parameter
*/
pos Robot::GetCurrPos() {
	return curr_pos_;
}

/**
* @brief Set the curr_pos parameter
*/
void Robot::SetCurrPos(pos position) {
	curr_pos_ = position;
}

/**
* @brief Get the final_pos parameter
*/
pos Robot::GetFinalPos() {
	return final_pos_;
}

/**
* @brief Set the final_pos parameter
*/
void Robot::SetFinalPos(pos position) {
	final_pos_ = position;
}

/**
* @brief Set the current velocity parameter
*/
void Robot::SetCurrVel(double velocity) {
  curr_vel_ = velocity;
}
