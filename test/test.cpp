#include <gtest/gtest.h>
#include <Robot.hpp>
#include <AckermannModel.hpp>
#include <Controller.hpp>

test_robot = Robot(5, 0.2, 0.1);// Initialize values here
test_model = AckermannModel();
test_controller = Controller(0.5,0.6,0.7,0.1);
// Robot Class Test
TEST(RobotTest, gettingMaxAcc) {
  ASSERT_EQ(test_robot.getMaxAcc(), 5);
}

TEST(RobotTest, gettingWheelBase) {
  ASSERT_EQ(test_robot.getWheelBase(), 0.2);
}

TEST(RobotTest, gettingTrackWidth) {
  ASSERT_EQ(test_robot.getTrackWidth(), 0.1);
}

TEST(RobotTest, gettingCurrentPosition) {
  ASSERT_EQ(test_robot.getCurrPos(), {0,0,0});
}

TEST(RobotTest, settingCurrentPosition) {
  test_robot.setCurrPos({1,1,1});
  ASSERT_EQ(test_robot.getCurrPos(), {1,1,1});
}

TEST(RobotTest, gettingCurrentVelocity) {
  ASSERT_EQ(test_robot.getCurrVel(), 0);
}

TEST(RobotTest, settingCurrentVelocity) {
  test_robot.setCurrVel(2);
  ASSERT_EQ(test_robot.getCurrVel(), 2);
}

TEST(RobotTest, gettingFinalPosition) {
  ASSERT_EQ(test_robot.getFinalPos(), {0,0,0});
}

TEST(RobotTest, settingFinalPosition) {
  test_robot.setFinalPos({1,1,1});
  ASSERT_EQ(test_robot.getFinalPos(), {1,1,1});
}
// Ackermann Model Class Test
TEST(AckermannModelTest, boundedOutput) {
  
}

TEST(AckermannModelTest, wheelAngleValidity) {
  
}

TEST(AckermannModelTest, validateAngles) {
  
}

TEST(AckermannModelTest, validateVelocity) {
  
}
// Controller Class Tests
TEST(ControllerTest, testKp) {
  ASSERT_EQ(test_controller.getKp(), 0.5);
}

TEST(ControllerTest, testKi) {
  ASSERT_EQ(test_controller.getKi(), 0.6); 
}

TEST(ControllerTest, testKd) {
  ASSERT_EQ(test_controller.getKd(), 0.7);
}

TEST(ControllerTest, validateIntegralError) {
  
}

TEST(ControllerTest, validateDerivativeError) {
  
}

TEST(ControllerTest, validateComputeOutput) {
  
}

TEST(ControllerTest, testdt) {
  ASSERT_GT(test_controller.getKd(),0)
}
