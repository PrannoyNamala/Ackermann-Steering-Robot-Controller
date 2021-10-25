/**
 * @file main.cpp
 * @author Rishabh Mukund (rmukund@umd.edu)
 * @author Prannoy Namala (pnamala@umd.edu)
 * @brief main file of project
 * @version 0.1
 * @date 10-18-2021
 *
 * Copyright (c) 2021 Group 808X-MT14
 *
 * Licensed under the MIT License (the "License")
 *
 */


#include <iostream>
#include <Robot.hpp>
#include <AckermannModel.hpp>
#include <Controller.hpp>

int main() {
    double wb{};
    double tw{};
    double maxheadingangle{};
    std::array<double, 2> target{};
    double curr_vel{};

    /* Accepting inputs from the users */
    std::cout << "Enter Wheel base" << std::endl;
    std::cin >> wb;
    std::cout << "Enter track width" << std::endl;
    std::cin >> tw;
    std::cout << "Enter maximum heading angle for the robot" << std::endl;
    std::cin >> maxheadingangle;
    std::cout<< "Enter Final position x coordinate" << std::endl;
    std::cin >> target[0];
    std::cout << "Enter Final position y coordinate" << std::endl;
    std::cin >> target[1];
    std::cout << "Enter current speed of the robot" << std::endl;
    std::cin >> curr_vel;

    /* Initializing the classes */
    Robot robot(5.0, wb, tw, maxheadingangle);
    robot.setFinalPos(target);
    robot.setCurrVel(curr_vel);
    Controller right_vel_controller(0.5, 0.6, 0.7, 0.1);
    Controller left_vel_controller(0.5, 0.6, 0.7, 0.1);
    AckermannModel model(robot, right_vel_controller, left_vel_controller);

    model.GoTotarget(0.1);

    return 0;
}
