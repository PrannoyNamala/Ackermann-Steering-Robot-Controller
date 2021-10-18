add_executable(shell-app main.cpp Robot.cpp Controller.cpp AckermannModel.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
