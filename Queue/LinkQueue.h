//
// Created by Kevinlinpr on 2019/6/9.
//

#ifndef STLLEARN_LINKQUEUE_H
#define STLLEARN_LINKQUEUE_H

#include "../LinkList/LNode.h"
#include <iostream>

template <class DataType>
class LinkQueue{
public:
    inline LinkQueue(){InitLinkQueue();}
    void InitLinkQueue();
    inline bool LinkQueueIsEmpty(){return this->front == nullptr && this->rear == nullptr;}
    bool EnLinkQueue(DataType value);
    bool DeLinkQueue(DataType& value);
    bool GetHead(DataType& value);
    void Print();
private:
    LNode<DataType>* head,*front,*rear;
};

template<class DataType>
void LinkQueue<DataType>::InitLinkQueue() {
    this->head = new LNode<DataType>;
    this->head->next = nullptr;
    this->front = this->head;
    this->rear = this->head;
}

template<class DataType>
bool LinkQueue<DataType>::EnLinkQueue(DataType value) {
    this->rear->next = new LNode(value);
    this->rear = this->rear->next;
    this->rear->next = nullptr;
    return true;
}

template<class DataType>
bool LinkQueue<DataType>::DeLinkQueue(DataType &value) {
    if(this->LinkQueueIsEmpty()){
        std::cout<<"THIS LINKQUEUE IS EMPTY."<<std::endl;
        return false;
    }
    value = this->front->next->data;
    this->head->next = this->front->next->next;
    return true;
}

template<class DataType>
bool LinkQueue<DataType>::GetHead(DataType &value) {
    if(this->LinkQueueIsEmpty()){
        std::cout<<"THIS LINKQUEUE IS EMPTY."<<std::endl;
        return false;
    }
    value = this->front->next->data;
    return true;
}

template<class DataType>
void LinkQueue<DataType>::Print() {
    if(this->LinkQueueIsEmpty()){
        std::cout<<"THIS LINKQUEUE IS EMPTY."<<std::endl;
        return;
    }
    LNode<DataType>* copeNodeP = this->front->next;
    while(copeNodeP){
        std::cout<<"VALUE: "<<copeNodeP->data<<std::endl;
        copeNodeP = copeNodeP->next;
    }
    std::cout<<"PRINT FINISHED."<<std::endl;
}

/// example
//LinkQueue<int> linkQueue;
//for (int i = 0; i < 5; ++i) {
//linkQueue.EnLinkQueue(i+1);
//}
//linkQueue.Print();
//for (int j = 0; j < 2; ++j) {
//int deValue;
//linkQueue.DeLinkQueue(deValue);
//std::cout<<"DeValue: "<<deValue<<std::endl;
//}
//linkQueue.Print();
//int frontValue;
//linkQueue.GetHead(frontValue);
//std::cout<<"Front Value: "<<frontValue<<std::endl;
#endif //STLLEARN_LINKQUEUE_H
