cmake_minimum_required(VERSION 3.26)
project(variadic)

set(CMAKE_CXX_STANDARD 20)

add_executable(variadic main.cpp
        src/engine/Engine.h
        src/subject/Subject.h
        src/wrapper/Wrapper.h
)
