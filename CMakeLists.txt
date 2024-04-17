cmake_minimum_required(VERSION 3.8)
project(Mario-Kart-AI-Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mario_Kart main.cpp Game/Game.cpp
        Game/Game.cpp
        Game/Track/Track.cpp
        Game/Character/Character.cpp
        Game/Character/Vehicle/Bike.cpp
        Game/Character/Vehicle/Car.cpp
        Game/Character/Vehicle/Vehicle.cpp
        Game/Character/Vehicle/Wheel/Wheel.cpp)

add_executable(Testing_Mario_Kart testing.cpp
        Game/Game.cpp
        Game/Track/Track.cpp
        Game/Character/Character.cpp
        Game/Character/Vehicle/Bike.cpp
        Game/Character/Vehicle/Car.cpp
        Game/Character/Vehicle/Vehicle.cpp
        Game/Character/Vehicle/Wheel/Wheel.cpp)