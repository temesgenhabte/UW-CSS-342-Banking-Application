cmake_minimum_required(VERSION 3.15)
project(HW6_Banking)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW6_Banking Bank.cpp Bank.h BSTree.cpp BSTree.h Account.cpp Account.h BankDriver.cpp)