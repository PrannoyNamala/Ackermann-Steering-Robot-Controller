/**
 * @file Controller.cpp
 * @author Rishabh Mukund (rmukund@umd.edu)
 * @author Prannoy Namala (pnamala@umd.edu)
 * @brief source file for Controller Class
 * @version 0.1
 * @date 10-15-2021
 *
 * Copyright (c) 2021 Group 808X-MT14
 *
 * Licensed under the MIT License (the "License")
 *
 */


#include <Controller.hpp>
#include <iostream>

/**
* @brief Construct a new PID Controller objec
*/
Controller::Controller(double Kp, double Ki, double Kd, double dt, double threshold)
	: kp_(Kp),
      ki_(Ki),
      kd_(Kd),
      dt_(dt)
      threshold_(threshold){
  std::cout << "Controller initialized with " << "Kp: " << kp_ << " Ki: "
            << ki_ << " Kd: " << kd_ << " dt: " << dt_
            << "threshold: " << threshold_ << std::endl;
}

/**
* @brief Calculates the error integral
*/
double Controller::CalculateErrorIntegral(double error) {
	return 0;
}

/**
* @brief Calculates the error derivative
*/
double Controller::CalculateErrorDerivative(double error) {
	return 0;
}

/**
* @brief calculates the velocity output
*/
double Controller::ComputeOutput(double initial_state, double final_state) {
	return 0;
}

/**
* @brief Get the kp parameter
*/
double Controller::GetKp() {
	return kp_;
}

/**
* @brief Get the ki parameter
*/
double Controller::GetKi() {
	return ki_;
}

/**
* @brief Get the kd parameter
*/
double Controller::GetKd() {
	return kd_;
}

/**
* @brief Get the dt parameter
*/
double Controller::GetDt() {
	return dt_;
}

/**
* @brief Get the threshold parameter
*/
double Controller::GetThreshold() {
  return threshold_;
}
