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
#include <AckermannModel.hpp>
#include <Controller.hpp>
#include <array>

/**
 * Initializing the class objects
 */
Robot test_robot(5.0, 0.2, 0.1, 0.785);
Controller right_vel_test_controller(0.5,0.6,0.7,0.1);
Controller left_vel_test_controller(0.5,0.6,0.7,0.1);
AckermannModel test_model(test_robot, right_vel_test_controller, left_vel_test_controller);
Controller test_controller(0.5,0.6,0.7,0.1);


/**
 * Robot Class Test
 */

/**
 * @brief Check for the get maximum acceleration method
 */
TEST(RobotTest, GettingMaxAcc) {
  ASSERT_EQ(test_robot.getMaxAcc(), 5);
}

/**
 * @brief Check for the get wheel base method
 */
TEST(RobotTest, GettingWheelBase) {
  ASSERT_EQ(test_robot.getWheelBase(), 0.2);
}

/**
 * @brief Check for the get track width method
 */
TEST(RobotTest, GettingTrackWidth) {
  ASSERT_EQ(test_robot.getTrackWidth(), 0.1);
}

/**
 * @brief Check for the get current position method
 */
TEST(RobotTest, GettingCurrentPosition) {
  std::array<double,2> pos = {0,0};
  ASSERT_EQ(test_robot.getCurrPos(), pos);
}

/**
 * @brief Check for the set current position method
 */
TEST(RobotTest, SettingCurrentPosition) {
  std::array<double,2> pos = {1,1};
  test_robot.setCurrPos(pos);
  ASSERT_EQ(test_robot.getCurrPos(), pos);
}

/**
 * @brief Check for the get current velocity method
 */
TEST(RobotTest, GettingCurrentVelocity) {
  ASSERT_EQ(test_robot.getCurrVel(), 0);
}

/**
 * @brief Check for the set current velocity method
 */
TEST(RobotTest, SettingCurrentVelocity) {
  test_robot.setCurrVel(2);
  ASSERT_EQ(test_robot.getCurrVel(), 2);
}

/**
 * @brief Check for the get final position method
 */
TEST(RobotTest, GettingFinalPosition) {
  std::array<double,2> pos = {1,1};
  ASSERT_EQ(test_robot.getFinalPos(), pos);
}

/**
 * @brief Check for the set final position method
 */
TEST(RobotTest, SettingFinalPosition) {
  std::array<double,2> pos = {2,2};
  test_robot.setFinalPos(pos);
  ASSERT_EQ(test_robot.getFinalPos(), pos);
}

/**
 * @brief Check for the get max heading angle method
 */
TEST(RobotTest, getMaxHeadingAngle) {
  ASSERT_EQ(test_robot.getMaxHeadingAngle(), 0.785);
}


/**
 * Ackermann Model Class Test
 *
 */

/**
 * @brief Check for the bounded angle of left wheel
 */
TEST(AckermannModelTest, wheelAngleValidityLeft) {
  test_model.ComputeWheelAngles();
  ASSERT_NEAR(test_model.left_wheel_angle_,0.674,0.01);
}

/**
 * @brief Check for the bounded angle of right wheel
 */
TEST(AckermannModelTest, wheelAngleValidityRight) {
  test_model.ComputeWheelAngles();
  ASSERT_NEAR(test_model.right_wheel_angle_,0.927,0.01);
}

/**
 * @brief Check for the wheel angle of right wheel
 */
TEST(AckermannModelTest, checkmaxAngle) {
  test_robot.setFinalPos({1.0,2.0});
  test_model.ComputeWheelAngles();
  ASSERT_GT(test_model.delta_, -0.786);
  ASSERT_LT(test_model.delta_,0.786);
}

/**
 * @brief Check for the wheel angle of left wheel
 */
TEST(AckermannModelTest, checkingInnerAnglevOuterAngle) {
  if (test_model.delta_<0) {
    ASSERT_TRUE(test_model.left_wheel_angle_>test_model.right_wheel_angle_);
  }
  if (test_model.delta_>0) {
    ASSERT_TRUE(test_model.left_wheel_angle_<test_model.right_wheel_angle_);
  }
}


/**
 * @brief Check for the velocity of left wheel
 */
TEST(AckermannModelTest, validateVelocityLeft) {
  test_robot.setFinalPos({1,1});
  test_model.r_.setCurrVel(2);
  test_model.ComputeWheelAngles();
  test_model.ComputeWheelVelocities();
  ASSERT_NEAR(test_model.left_wheel_vel_,6.24,0.01);
}

/**
 * @brief Check for the velocity of right wheel
 */
TEST(AckermannModelTest, validateVelocityRight) {
  test_robot.setFinalPos({1,1});
  test_model.r_.setCurrVel(2);
  test_model.ComputeWheelAngles();
  test_model.ComputeWheelVelocities();
  ASSERT_NEAR(test_model.right_wheel_vel_,7.99,0.01);
}

/**
 * Controller Class Tests
 */

/**
 * @brief Check for the get Kp method
 */
TEST(ControllerTest, testKp) {
  ASSERT_EQ(test_controller.getKp(), 0.5);
}

/**
 * @brief Check for the get Ki method
 */
TEST(ControllerTest, testKi) {
  ASSERT_EQ(test_controller.getKi(), 0.6);
}

/**
 * @brief Check for the get Kd method
 */
TEST(ControllerTest, testKd) {
  ASSERT_EQ(test_controller.getKd(), 0.7);
}

/**
 * @brief Check for the get dt method
 */
TEST(ControllerTest, testDt) {
  ASSERT_EQ(test_controller.getDt(), 0.1);
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
  Controller controller(0.5, 0.4, 0.6, 1.0);

  double output = controller.ComputeOutput(0, 5);
  ASSERT_NEAR(7.5, output, 0.5);

  output = controller.ComputeOutput(output, 5);
  ASSERT_NEAR(-4.75, output, 0.5);

  output = controller.ComputeOutput(output, 5);
  ASSERT_NEAR(17.125, output, 0.5);
}

TEST(SystemTest, ConvergenceTest) {
  Robot sys_robot(5.0, 0.2, 0.1, 0.785);
  sys_robot.setFinalPos({5,5});
  sys_robot.setCurrVel(2);
  Controller right_vel_sys_controller(0.5,0.6,0.7,0.1);
  Controller left_vel_sys_controller(0.5,0.6,0.7,0.1);
  AckermannModel sys_model(sys_robot, right_vel_sys_controller, left_vel_sys_controller);

  ASSERT_TRUE(sys_model.GoTotarget(0.1)==1);
}
