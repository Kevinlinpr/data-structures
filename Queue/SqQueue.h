//
// Created by Kevinlinpr on 2019/6/9.
//

#ifndef STLLEARN_SQQUEUE_H
#define STLLEARN_SQQUEUE_H

#include <iostream>

template <class DataType,int MAXSIZE = 50>
class SqQueue{
public:
    inline SqQueue(){InitQueue();}
    void InitQueue();
    inline bool QueueEmpty(){ return this->front == this->rear;}
    inline bool QueueIsFull(){ return this->rear == MAXSIZE&&this->front == 0;}
    inline bool QueueOverflowing(){ return this->rear == MAXSIZE;}
    bool EnQueue(DataType value);
    bool DeQueue(DataType& value);
    bool GetHead(DataType& value);
    void Print();
private:
    DataType data[MAXSIZE];
    int front{},rear{};
};

template<class DataType, int MAXSIZE>
void SqQueue<DataType, MAXSIZE>::InitQueue() {
    this->front = 0;
    this->rear = 0;
}

template<class DataType, int MAXSIZE>
bool SqQueue<DataType, MAXSIZE>::EnQueue(DataType value) {
    bool overflowing_flag = this->QueueOverflowing();
    bool full_flag = this->QueueIsFull();
    if(full_flag){
        std::cout<<"QUEUE IS FULL. ENQUEUE FAILED."<<std::endl;
        return false;
    } else{
        if(overflowing_flag){
            std::cout<<"QUEUE IS OVERFLOW BUT NOT FULL. ENQUEUE FAILED."<<std::endl;
            return false;
        }
    }
    this->data[this->rear] = value;
    ++this->rear;
    std::cout<<"INSERT SUCCESSFULLY."<<std::endl;
    return true;
}

template<class DataType, int MAXSIZE>
bool SqQueue<DataType, MAXSIZE>::DeQueue(DataType &value) {
    if(this->QueueEmpty()){
        std::cout<<"QUEUE IS EMPTY. DEQUEUE FAILED."<<std::endl;
        return false;
    }
    value = this->data[this->front];
    ++this->front;
    std::cout<<"OUTLET SUCCESSFULLY."<<std::endl;
    return true;
}

template<class DataType, int MAXSIZE>
void SqQueue<DataType, MAXSIZE>::Print() {
    if(this->QueueEmpty()){
        std::cout<<"THIS QUEUE IS EMPTY. PRINT FAILED."<<std::endl;
        return;
    }
    for (int i = this->front; i < this->rear; ++i) {
        std::cout<<"PRINT: INDEX: "<<i<<" VALUE: "<<this->data[i]<<std::endl;
    }
}

template<class DataType, int MAXSIZE>
bool SqQueue<DataType, MAXSIZE>::GetHead(DataType &value) {
    if(this->QueueEmpty()){
        std::cout<<"THIS QUEUE IS EMPTY. GET HEAD VALUE FAILED."<<std::endl;
        return false;
    }
    value = this->data[this->front];
    return true;
}

/// example
//SqQueue<int,10> sqQueue;
//for (int j = 0; j < 7; ++j) {
//sqQueue.EnQueue(j+1);
//}
//sqQueue.Print();
//for (int i = 0; i < 3; ++i) {
//int deValue;
//sqQueue.DeQueue(deValue);
//std::cout<<"DELETE VALUE: "<<deValue<<std::endl;
//}
//sqQueue.Print();
//int headValue;
//sqQueue.GetHead(headValue);
//std::cout<<"HEAD VALUE: "<<headValue<<std::endl;

#endif //STLLEARN_SQQUEUE_H
