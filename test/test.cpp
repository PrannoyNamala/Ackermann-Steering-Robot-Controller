/**
 * @file AckremannModel.hpp
 * @author Rishabh Mukund (rmukund@umd.edu)
 * @author Prannoy Namala (pnamala@umd.edu)
 * @brief Test file to check the classes
 * @version 0.1
 * @date 10-15-2021
 *
 * Copyright (c) 2021 Group 808X-MT14
 *
 * Licensed under the MIT License (the "License")
 *
 */


#include <gtest/gtest.h>
#include <Robot.hpp>
#include <AckermannModel.hpp>
#include <Controller.hpp>

/**
 * Initializing the classes
 */
test_robot = Robot(5, 0.2, 0.1);
test_model = AckermannModel(test_robot,{0,1,0});
test_controller = Controller(0.5,0.6,0.7,0.1, 1);

/**
 * Robot Class Test
 */

/**
 * @brief Check for the get maximum acceleration method
 */
TEST(RobotTest, GettingMaxAcc) {
  ASSERT_EQ(test_robot.GetMaxAcc(), 5);
}

/**
 * @brief Check for the get wheel base method
 */
TEST(RobotTest, GettingWheelBase) {
  ASSERT_EQ(test_robot.GetWheelBase(), 0.2);
}

/**
 * @brief Check for the get track width method
 */
TEST(RobotTest, GettingTrackWidth) {
  ASSERT_EQ(test_robot.GetTrackWidth(), 0.1);
}

/**
 * @brief Check for the get current position method
 */
TEST(RobotTest, GettingCurrentPosition) {
  ASSERT_EQ(test_robot.GetCurrPos(), {0,0,0});
}

/**
 * @brief Check for the set current position method
 */
TEST(RobotTest, SettingCurrentPosition) {
  test_robot.setCurrPos({1,1,1});
  ASSERT_EQ(test_robot.GetCurrPos(), {1,1,1});
}

/**
 * @brief Check for the get current velocity method
 */
TEST(RobotTest, GettingCurrentVelocity) {
  ASSERT_EQ(test_robot.GetCurrVel(), 0);
}

/**
 * @brief Check for the set current velocity method
 */
TEST(RobotTest, SettingCurrentVelocity) {
  test_robot.SetCurrVel(2);
  ASSERT_EQ(test_robot.getCurrVel(), 2);
}

/**
 * @brief Check for the get final position method
 */
TEST(RobotTest, SettingFinalPosition) {
  ASSERT_EQ(test_robot.GetFinalPos(), {0,0,0});
}

/**
 * @brief Check for the set final position method
 */
TEST(RobotTest, SettingFinalPosition) {
  test_robot.SetFinalPos({1,1,1});
  ASSERT_EQ(test_robot.GetFinalPos(), {1,1,1});
}

/**
 * Ackermann Model Class Test
 *
 */

/**
 * @brief Check for the bounded angle of left wheel
 */
TEST(AckermannModelTest, boundedOutputLeftAngle) {
  test_model.ComputeWheelAngles();
  ASSERT_EQ(left_wheel_angle_,0.785)
}

/**
 * @brief Check for the bounded angle of right wheel
 */
TEST(AckermannModelTest, boundedOutputRightAngle) {
  test_model.ComputeWheelAngles();
  ASSERT_EQ(right_wheel_angle_,0.785)
}

/**
 * @brief Check for the wheel angle of right wheel
 */
TEST(AckermannModelTest, wheelAngleValidityRight) {
  test_model.SetTarget({1,0,0});
  test_model.ComputeWheelAngles();
  ASSERT_EQ(right_wheel_angle,0);
}

/**
 * @brief Check for the wheel angle of left wheel
 */
TEST(AckermannModelTest, wheelAngleValidityLeft) {
  test_model.setTarget({1,0,0});
  test_model.ComputeWheelAngles();
  ASSERT_EQ(left_wheel_angle,0);
}


/**
 * @brief Check for the velocity of left wheel
 */
TEST(AckermannModelTest, validateVelocity) {
  test_model.setTarget({1,0,0});
  test_robot.SetCurrVel(2);
  test_model.ComputeWheelAngles();
  test_model.ComputeWheelVelocities();
  ASSERT_EQ(left_wheel_vel_,2);
}

/**
 * @brief Check for the velocity of right wheel
 */
TEST(AckermannModelTest, validateVelocity) {
  test_model.setTarget({1,0,0});
  test_robot.SetCurrVel(2);
  test_model.ComputeWheelAngles();
  test_model.ComputeWheelVelocities();
  ASSERT_EQ(right_wheel_vel_,2);
}

/**
 * Controller Class Tests
 */

/**
 * @brief Check for the get Kp method
 */
TEST(ControllerTest, testKp) {
  ASSERT_EQ(test_controller.GetKp(), 0.5);
}

/**
 * @brief Check for the get Ki method
 */
TEST(ControllerTest, testKi) {
  ASSERT_EQ(test_controller.GetKi(), 0.6);
}

/**
 * @brief Check for the get Kd method
 */
TEST(ControllerTest, testKd) {
  ASSERT_EQ(test_controller.GetKd(), 0.7);
}

/**
 * @brief Check for the get dt method
 */
TEST(ControllerTest, testDt) {
  ASSERT_EQ(test_controller.GetDt(), 0.1);
}

/**
 * @brief Check for the get threshold method
 */
TEST(ControllerTest, testThreshold) {
  ASSERT_EQ(test_controller.GetThreshold(), 1);
}

/**
 * @brief Check for the Integral error method
 */
TEST(ControllerTest, validateIntegralError) {
  ASSERT_EQ(test_controller.CalculateErrorIntegral(5.0),0.5);
}

/**
 * @brief Check for the derivative error method
 */
TEST(ControllerTest, validateDerivativeError) {
  ASSERT_EQ(test_controller.CalculateErrorDerivative(5.0),0.5);
}

/**
 * @brief Check for the compute output method
 */
TEST(ControllerTest, validateComputeOutput) {
  controller = Controller(0.5, 0.4, 0.6, 1.0, 1.0);

  double output = controller.ComputeOutput(0, 5);
  ASSERT_NEAR(7.5, output, 0.5);

  output = controller.ComputeOutput(output, 5);
  ASSERT_NEAR(-4.75, output, 0.5);

  output = controller.ComputeOutput(output, 5);
  ASSERT_NEAR(17.125, output, 0.5);
}
