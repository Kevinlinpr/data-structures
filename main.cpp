#include "Queue/DeQueue.h"
int main(){
    DeQueue<int,10> deQueue;
    deQueue.PushFront(5);
    deQueue.PushFront(6);
    deQueue.PushFront(7);
    deQueue.PushFront(8);
    deQueue.PushBack(9);
    deQueue.PushBack(10);
    deQueue.PushBack(11);
    deQueue.Print();
    int popFrontValue;
    for (int i = 0; i < 4; ++i) {
        if(deQueue.PopFront(popFrontValue))
            std::cout<<"POP FRONT VALUE: "<<popFrontValue<<std::endl;
    }
    deQueue.Print();
    int backValue;
    deQueue.GetBack(backValue);
    std::cout<<"BACK VALUE: "<<backValue<<std::endl;
    int frontValue;
    deQueue.GetFront(frontValue);
    std::cout<<"FRONT VALUE: "<<frontValue<<std::endl;
    int popBackValue;
    for (int i = 0; i < 4; ++i) {
        if(deQueue.PopBack(popBackValue))
            std::cout<<"POP BACK VALUE: "<<popBackValue<<std::endl;
    }
    deQueue.Print();
    deQueue.PushBack(3);
    deQueue.Print();
    deQueue.Clear();
    deQueue.Print();
}
