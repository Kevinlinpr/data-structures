cmake_minimum_required(VERSION 3.12)
project(STLLearn)

set(CMAKE_CXX_STANDARD 17)

add_executable(STLLearn main.cpp LinearList/LinearList.h LinearList/PracticeLinearList.h LinkList/LNode.h LinkList/LinkList.h LinkList/DNode.h LinkList/DLinkList.h LinkList/LLinkList.h LinkList/LDLinkList.h Stack/SqStack.h Stack/ShareStack.h Stack/LinkStack.h)