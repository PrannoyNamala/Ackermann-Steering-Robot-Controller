/**
 * @file Controller.hpp
 * @author Rishabh Mukund (rmukund@umd.edu)
 * @author Prannoy Namala (pnamala@umd.edu)
 * @brief Header file for PID Controller for the velocities
 * @version 0.1
 * @date 10-15-2021
 *
 * Copyright (c) 2021 Group 808X-MT14
 *
 * Licensed under the MIT License (the "License")
 *
 */

#include <iostream>

class Controller {
 public:
    /**
     * @brief Construct a new PID Controller object
     * 
     * @param Kp (double) - Proportional constant
     * @param Ki (double) - Integral constant
     * @param Kd (double) - Derivative constant
     * @param dt (double) - time
     */
    Controller(double Kp, double Ki, double Kd, double dt, double threshold);
    
    /**
     * @brief Calculates the error integral
     * 
     * @param error (double) - error value
     * 
     * @return double
     */
    double CalculateErrorIntegral(double error);
    
    /**
     * @brief Calculates the error derivative
     * 
     * @param error (double) - error value
     *
     * @return double
     */
    double CalculateErrorDerivative(double error);
    
    /**
     * @brief calculates the velocity output
     * 
     * @param initial_state (double) - initial state
     * @param final_state (double) - final state
     *
     * @return double
     */
    double ComputeOutput(double initial_state, double final_state);
    
    /**
     * @brief Get the kp parameter
     * 
     * @return double 
     */
    double getKp();
    
    /**
     * @brief Get the kd parameter
     * 
     * @return double 
     */
    double getKd();
    
    /**
     * @brief Get the ki parameter
     * 
     * @return double 
     */
    double getKi();
    
    /**
     * @brief Get the dt parameter
     * 
     * @return double 
     */
    double getDt();

    /**
     * @brief Get the threshold parameter
     *
     * @return double
     */
    double getThreshold();

 private:
    double kp_, ki_, kd_, dt_, threshold_;
    double previous_error_ {}, integral_sum_{};
};
