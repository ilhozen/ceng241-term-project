cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project main.cpp
        projectfun.h
        Item.h
        ExperimentMaterial.h
        Box.h
        Page.h
        Plants.h
        Lock.h
        DoorLock.cpp
        DoorLock.h
        ComputerLock.cpp
        ComputerLock.h
        Note.h
        projectfun.cpp)
