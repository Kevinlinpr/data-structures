//
// Created by Kevinlinpr on 2019/6/8.
//

#ifndef STLLEARN_LINKSTACK_H
#define STLLEARN_LINKSTACK_H

#include <iostream>
#include "../LinkList/LNode.h"

template <class DataType>
class LinkStack{
public:
    inline LinkStack(){InitStack();}
    void InitStack();
    bool StackEmpty(){return this->head == nullptr;}
    void Push(DataType value);
    bool Pop();
    bool GetTop(DataType& topValue);
    void ClearStack();
    void Print();
private:
    LNode<DataType>* head;
    int length{};
};

template<class DataType>
void LinkStack<DataType>::InitStack() {
    this->head = nullptr;
    this->length = 0;
}

template<class DataType>
void LinkStack<DataType>::Push(DataType value) {
    LNode<DataType>* newNode = new LNode<DataType>(value);
    LNode<DataType>* tmpNode = this->head;
    this->head = newNode;
    newNode->next = tmpNode;
    ++this->length;
}

template<class DataType>
bool LinkStack<DataType>::Pop() {
    if(this->StackEmpty()){
        std::cout<<"THIS LINK STACK IS EMPTY. POP FAILED."<<std::endl;
        return false;
    }
    this->head = this->head->next;
    --this->length;
    return true;
}

template<class DataType>
bool LinkStack<DataType>::GetTop(DataType &topValue) {
    if(this->StackEmpty()){
        std::cout<<"THIS LINK STACK IS EMPTY. NO TOP VALUE."<<std::endl;
        return false;
    }
    topValue = this->head->data;
    return true;
}

template<class DataType>
void LinkStack<DataType>::ClearStack() {
    this->head = nullptr;
    this->length = 0;
}

template<class DataType>
void LinkStack<DataType>::Print() {
    if(this->head== nullptr){
        std::cout<<"PRINT: THIS LINK STACK IS EMPTY.PRINT FAILED."<<std::endl;
        return;
    }
    LNode<DataType>* copeNode = this->head;
    for (int i = 0; i < this->length; ++i) {
        std::cout<<"VALUE: "<<copeNode->data<<std::endl;
        copeNode = copeNode->next;
    }
    std::cout<<"PRINT: FINISH PRINT."<<std::endl;
}

//LinkStack<int> linkStack;
//linkStack.Push(1);
//linkStack.Push(2);
//linkStack.Push(3);
//linkStack.Push(4);
//linkStack.Pop();
//linkStack.Pop();
//int topValue;
//linkStack.GetTop(topValue);
//std::cout<<"TOP VALUE: "<<topValue<<std::endl;
//linkStack.Print();
//linkStack.ClearStack();
//linkStack.Print();
#endif //STLLEARN_LINKSTACK_H
