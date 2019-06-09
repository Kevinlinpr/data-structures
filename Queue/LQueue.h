//
// Created by Kevinlinpr on 2019/6/9.
//

#ifndef STLLEARN_LQUEUE_H
#define STLLEARN_LQUEUE_H

#include <iostream>

template <class DataType,int MAXSIZE = 50>
class LQueue{
public:
    inline LQueue(){InitLQueue();}
    void InitLQueue();
    bool LQueueEmpty();
    bool LQueueIsFull();
    bool EnLQueue(DataType value);
    bool DeLQueue(DataType& deValue);
    bool GetHead(DataType& headValue);
    void Print();
private:
    DataType data[MAXSIZE];
    int front{},rear{};
};

template<class DataType, int MAXSIZE>
void LQueue<DataType, MAXSIZE>::InitLQueue() {
    this->front = 0;
    this->rear = 0;
}

template<class DataType, int MAXSIZE>
bool LQueue<DataType, MAXSIZE>::LQueueEmpty() {
    return this->rear==this->front;
}

template<class DataType, int MAXSIZE>
bool LQueue<DataType, MAXSIZE>::LQueueIsFull() {
    return (this->rear+1)%MAXSIZE==this->front;
}

template<class DataType, int MAXSIZE>
bool LQueue<DataType, MAXSIZE>::EnLQueue(DataType value) {
    if(this->LQueueIsFull()){
        std::cout<<"THIS LQUEUE IS FULL. INSERT FAILED."<<std::endl;
        return false;
    }
    this->data[this->rear] = value;
    this->rear = (this->rear+1)%MAXSIZE;
    std::cout<<"INSERTED VALUE: "<<value<<std::endl;
    return true;
}

template<class DataType, int MAXSIZE>
bool LQueue<DataType, MAXSIZE>::DeLQueue(DataType &deValue) {
    if(this->LQueueEmpty()){
        std::cout<<"THIS LQUEUE IS EMPTY. DEQUEUE FAILED."<<std::endl;
        return false;
    }
    deValue = this->data[this->front];
    this->front = (this->front+1)%MAXSIZE;
    return false;
}

template<class DataType, int MAXSIZE>
bool LQueue<DataType, MAXSIZE>::GetHead(DataType &headValue) {
    if(this->LQueueEmpty()){
        std::cout<<"THIS LQUEUE IS EMPTY. GETHEAD FAILED."<<std::endl;
        return false;
    }
    headValue = this->data[this->front];
    return true;
}

template<class DataType, int MAXSIZE>
void LQueue<DataType, MAXSIZE>::Print() {
    if(this->LQueueEmpty()){
        std::cout<<"THIS LQUEUE IS EMPTY. PRINT FAILED."<<std::endl;
        return;
    }
    int printedAmount = 0;
    int amount = (this->rear + MAXSIZE - this->front)%MAXSIZE;
    for (int i = this->front; i <this->front+amount && printedAmount < amount; i = (i+1)%MAXSIZE) {
        std::cout<<"PRINT: INDEX: "<<i<<" VALUE: "<<this->data[i]<<std::endl;
        ++printedAmount;
    }
    std::cout<<"front: "<<this->front<<" rear: "<<this->rear<<std::endl;
}

/// example
//LQueue<int,10> lQueue;
//for (int j = 0; j < 10; ++j) {
//lQueue.EnLQueue(j+1);
//}
//
//lQueue.Print();
//for (int j = 0; j < 2; ++j) {
//int deValue;
//lQueue.DeLQueue(deValue);
//std::cout<<"DELETE VALUE: "<<deValue<<std::endl;
//}
//lQueue.EnLQueue(10);
//lQueue.EnLQueue(11);
//lQueue.Print();
//for (int j = 0; j < 5; ++j) {
//int deValue;
//lQueue.DeLQueue(deValue);
//std::cout<<"DELETE VALUE: "<<deValue<<std::endl;
//}
//for (int j = 0; j < 7; ++j) {
//lQueue.EnLQueue(j+12);
//}
//lQueue.Print();

#endif //STLLEARN_LQUEUE_H
