cmake_minimum_required(VERSION 3.14)
project(AIIdiotNe C)

set(CMAKE_C_STANDARD 99)

add_executable(AIIdiotNe main.c FIR.h material.h hlibrary.h Game.c Stack.c ACautomaton.c AI.c ControlMove.c Evaluate.c)