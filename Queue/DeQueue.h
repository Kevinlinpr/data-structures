//
// Created by Kevinlinpr on 2019/6/11.
//

#ifndef STLLEARN_DEQUEUE_H
#define STLLEARN_DEQUEUE_H

#include <iostream>

template <class DataType,int MAXSIZE = 50>
class DeQueue{
public:
    inline DeQueue(){InitDeQueue();}
    void InitDeQueue();
    inline bool Empty(){ return this->length==0; }
    inline void Clear(){ this->front = this->rear; this->length = 0;}
    void PushFront(DataType pushValue);
    inline void PushBack(DataType pushValue){this->data[++this->rear] = pushValue;++this->length;}
    bool PopFront(DataType& popValue);
    bool PopBack(DataType& popValue);
    inline bool GetFront(DataType& frontValue);
    inline bool GetBack(DataType& backValue);
    inline int Size(){return this->length;}
    void Print();
private:
    DataType data[MAXSIZE];
    int front{},rear{};
    int length{};
};

template<class DataType, int MAXSIZE>
void DeQueue<DataType, MAXSIZE>::InitDeQueue() {
    this->front = 0;
    this->rear = 0;
    this->length = 0;
}

template<class DataType, int MAXSIZE>
void DeQueue<DataType, MAXSIZE>::PushFront(DataType pushValue) {
    if(this->Size()!=0){
        ++this->rear;
        for (int i = length; i > 0; --i) {
            this->data[i] = this->data[i-1];
        }
    }
    this->data[this->front] = pushValue;
    ++this->length;
}


template<class DataType, int MAXSIZE>
bool DeQueue<DataType, MAXSIZE>::PopFront(DataType &popValue) {
    if(this->Empty()){
        std::cout<<"DEQUEUE IS EMPTY.POPFRONT FAILED."<<std::endl;
        return false;
    }
    popValue = this->data[this->front];
    --this->rear;
    --this->length;
    for (int i = 0; i < length; ++i) {
        this->data[i] = this->data[i+1];
    }
    return true;
}

template<class DataType, int MAXSIZE>
bool DeQueue<DataType, MAXSIZE>::PopBack(DataType &popValue) {
    if(this->Empty()){
        std::cout<<"DEQUEUE IS EMPTY.POPBACK FAILED."<<std::endl;
        return false;
    }
    popValue = this->data[this->rear];
    --this->rear;
    --this->length;
    return true;
}

template<class DataType, int MAXSIZE>
bool DeQueue<DataType, MAXSIZE>::GetFront(DataType &frontValue) {
    if(this->Empty()){
        std::cout<<"DEQUEUE IS EMPTY.GETFRONT FAILED."<<std::endl;
        return false;
    }
    frontValue = this->data[this->front];
    return true;
}

template<class DataType, int MAXSIZE>
bool DeQueue<DataType, MAXSIZE>::GetBack(DataType &backValue) {
    if(this->Empty()){
        std::cout<<"DEQUEUE IS EMPTY.GETBACK FAILED."<<std::endl;
        return false;
    }
    backValue = this->data[this->rear];
    return true;
}

template<class DataType, int MAXSIZE>
void DeQueue<DataType, MAXSIZE>::Print() {
    if(this->Empty()){
        std::cout<<"DEQUEUE IS EMPTY.PRINT FAILED."<<std::endl;
        return;
    }
    for (int i = this->front; i <= this->rear; ++i) {
        std::cout<<"PRINT VALUE: "<<this->data[i]<<std::endl;
    }
}

/// example
//DeQueue<int,10> deQueue;
//deQueue.PushFront(5);
//deQueue.PushFront(6);
//deQueue.PushFront(7);
//deQueue.PushFront(8);
//deQueue.PushBack(9);
//deQueue.PushBack(10);
//deQueue.PushBack(11);
//deQueue.Print();
//int popFrontValue;
//for (int i = 0; i < 4; ++i) {
//if(deQueue.PopFront(popFrontValue))
//std::cout<<"POP FRONT VALUE: "<<popFrontValue<<std::endl;
//}
//deQueue.Print();
//int backValue;
//deQueue.GetBack(backValue);
//std::cout<<"BACK VALUE: "<<backValue<<std::endl;
//int frontValue;
//deQueue.GetFront(frontValue);
//std::cout<<"FRONT VALUE: "<<frontValue<<std::endl;
//int popBackValue;
//for (int i = 0; i < 4; ++i) {
//if(deQueue.PopBack(popBackValue))
//std::cout<<"POP BACK VALUE: "<<popBackValue<<std::endl;
//}
//deQueue.Print();
//deQueue.PushBack(3);
//deQueue.Print();
//deQueue.Clear();
//deQueue.Print();
#endif //STLLEARN_DEQUEUE_H
