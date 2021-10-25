# Ackermann Steering Robot Controller   
[![Build Status](https://app.travis-ci.com/PrannoyNamala/Ackermann-Steering-Robot-Controller.svg?branch=master)](https://app.travis-ci.com/PrannoyNamala/Ackermann-Steering-Robot-Controller)
[![Coverage Status](https://coveralls.io/repos/github/PrannoyNamala/Ackermann-Steering-Robot-Controller/badge.svg?branch=master)](https://coveralls.io/github/PrannoyNamala/Ackermann-Steering-Robot-Controller?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/umdjs/mit/blob/master/LICENSE.md)
---

## Overview

The  aim  of  the  project  is  to  implement  an  Ackermann Steering Controller for the newly developed rover by Acme Robotics. We have chosen to implement Ackermann steering for many of its advantages. The most important one is that it does not slip in higher velocities, this is achieved by steering the  inside  wheel at a greater angle than the outside wheel.This is very crucial as it ensures longevity of the the wheels and that the rover is stable and controllable.

The following assumptions are made while developing this project :-

  1. All vehicle parameters are taken from a robot class.
  2. The initial position, orientation and velocity of the vehicle are taken as user inputs.
  3. Desired position, orientation and velocity of the vehicle are taken from a path planner class.
  4. Friction, Wheel slippage and actuator saturation is minimal.
  5. The initial velocity is set to be zero i.e v = 0.
  6. The maximum steering angle is 45 degrees.

## Agile Iterative Process (AIP)
This project will be completed using AIP with the involvement of 2 programmers using Pair-programming in turns. The detailed Product Backlog, Iteration Backlogs and Work Log are mentioned in the link given below :

[Agile Iterative Process](https://docs.google.com/spreadsheets/d/1AjvU3cSXfIWPZ6afr97VVqBkIVaQo5zX0YGwdS3gu78/edit?usp=sharing)


## Important Links

[Proposal Phase-0](https://drive.google.com/file/d/1umYMgm8mL1ALpWycH2YrRFYiQv6a0TN-/view?usp=sharing)

[Proposal Phase-1 Update](https://drive.google.com/file/d/1YsaQfGZgOE7c7Dwa6bHzNXLxi3fZrg2r/view)

[Proposal Phase-2 Update](https://drive.google.com/file/d/1H7cM33AkOMfr0ANB2vwNEoRtOkwhLxyO/view?usp=sharing)

[Quad Chart Phase-0](https://drive.google.com/file/d/1-h-sLWbmNeX7z31qwRXdcSlXcgGUWfXG/view?usp=sharing)

[UML Diagram](https://drive.google.com/file/d/1Zu3fTrS95gYpkMdT5xp2CJ424eM1xON7/view?usp=sharing)

[UML Diagram Phase 1](https://drive.google.com/file/d/183aDx3iQR4v4fukx3KLp-rI0bn9yGZ4i/view?usp=sharing)

[UML Diagram Phase 2](https://drive.google.com/file/d/1sYCCHkBEKD8TA1m3nXA8TqwH6car5CTh/view?usp=sharing)

[Google Doc Link forDesign and Planning notes(Updated with notes for phase 2)](https://docs.google.com/document/d/17IL55ZwxBDhujGnLBym4Dkk1ct6glk5DNWoQ6naqwEU/edit?usp=sharing)

[ Youtube link to the Proposal](https://youtu.be/cgePebQyXTI)

[ Youtube link to the Phase 1](https://youtu.be/n60_Hbyo3_k)

[ Youtube link to the Phase 2](https://youtu.be/ieRox915Phw)

## Standard install via command-line
```
git clone --recursive https://github.com/PrannoyNamala/Ackermann-Steering-Robot-Controller
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/PrannoyNamala/Ackermann-Steering-Robot-Controller
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p ackermann-eclipse
cd ackermann-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../Ackermann-Steering-Robot-Controller/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "ackermann-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold ackermann-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project.
