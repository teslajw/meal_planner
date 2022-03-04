# CMakeList.txt : CMake project for meal_planner, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("meal_planner")
set (CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (meal_planner meal_planner.cpp meal_planner.h)

# TODO: Add tests and install targets if needed.
