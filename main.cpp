#include <iostream>
#include "Queue/LQueue.h"

int main(){
    LQueue<int,10> lQueue;
    for (int j = 0; j < 10; ++j) {
        lQueue.EnLQueue(j+1);
    }

    lQueue.Print();
    for (int j = 0; j < 2; ++j) {
        int deValue;
        lQueue.DeLQueue(deValue);
        std::cout<<"DELETE VALUE: "<<deValue<<std::endl;
    }
    lQueue.EnLQueue(10);
    lQueue.EnLQueue(11);
    lQueue.Print();
    for (int j = 0; j < 5; ++j) {
        int deValue;
        lQueue.DeLQueue(deValue);
        std::cout<<"DELETE VALUE: "<<deValue<<std::endl;
    }
    for (int j = 0; j < 7; ++j) {
        lQueue.EnLQueue(j+12);
    }
    lQueue.Print();

}
