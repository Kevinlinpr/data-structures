cmake_minimum_required(VERSION 3.12)
project(STLLearn)

set(CMAKE_CXX_STANDARD 17)

add_executable(STLLearn main.cpp LinearList/LinearList.h LinearList/PracticeLinearList.h LinkList/LNode.h LinkList/LinkList.h LinkList/DNode.h LinkList/DLinkList.h LinkList/LLinkList.h LinkList/LDLinkList.h Stack/SqStack.h Stack/ShareStack.h Stack/LinkStack.h Queue/SqQueue.h Queue/LQueue.h Queue/LinkQueue.h STLPractice/VectorPractice.cpp STLPractice/VectorPractice.h RandomAccessFile/Personal.cpp RandomAccessFile/Personal.h RandomAccessFile/Student.cpp RandomAccessFile/Student.h RandomAccessFile/Database.cpp RandomAccessFile/Database.h Queue/DeQueue.h Algorithm/PutQueen/ChessBoard.cpp Algorithm/PutQueen/ChessBoard.h BinaryTree/BST/BST.cpp BinaryTree/BST/BST.h BinaryTree/TBT/TBT.h BinaryTree/BT/BT.h)