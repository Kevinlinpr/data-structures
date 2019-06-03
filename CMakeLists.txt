cmake_minimum_required(VERSION 3.12)
project(STLLearn)

set(CMAKE_CXX_STANDARD 17)

add_executable(STLLearn main.cpp LinearList/LinearList.cpp LinearList/LinearList.h LinearList/PracticeLinearList.cpp LinearList/PracticeLinearList.h LinkList/LNode.cpp LinkList/LNode.h LinkList/LinkList.cpp LinkList/LinkList.h)