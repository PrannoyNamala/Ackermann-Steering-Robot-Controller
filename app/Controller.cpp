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
* @brief Construct a new PID Controller object
*/
Controller::Controller(double Kp, double Ki, double Kd, double dt)
: kp_(Kp),
  ki_(Ki),
  kd_(Kd),
  dt_(dt) {
  std::cout << "Controller initialized with " << "Kp: " << kp_ << " Ki: "
            << ki_ << " Kd: " << kd_ << " dt: " << dt_<<std::endl;
}

/**
* @brief Calculates the error integral
*/
double Controller::CalculateErrorIntegral(double error) {
  integral_sum_ += (error * dt_);
  return integral_sum_;
}

/**
* @brief Calculates the error derivative
*/
double Controller::CalculateErrorDerivative(double error) {
  return (error - previous_error_) * dt_;
}

/**
* @brief calculates the velocity output
*/
double Controller::ComputeOutput(double initial_state, double final_state) {
  double error = final_state - initial_state;
  double pid_gains = (kp_ * error * dt_)
      + (ki_ * CalculateErrorIntegral(error))
      + (kd_ * CalculateErrorDerivative(error));
  previous_error_ = error;
  return pid_gains;
}

/**
* @brief Get the kp parameter
*/
double Controller::getKp() {
  return kp_;
}

/**
* @brief Get the ki parameter
*/
double Controller::getKi() {
  return ki_;
}

/**
* @brief Get the kd parameter
*/
double Controller::getKd() {
  return kd_;
}

/**
* @brief Get the dt parameter
*/
double Controller::getDt() {
  return dt_;
}

/**
* @brief Get the threshold parameter
*/
double Controller::getThreshold() {
  return threshold_;
}
