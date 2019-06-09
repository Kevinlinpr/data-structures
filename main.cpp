#include <iostream>
#include "Queue/SqQueue.h"

int main(){
    SqQueue<int,10> sqQueue;
    for (int j = 0; j < 7; ++j) {
        sqQueue.EnQueue(j+1);
    }
    sqQueue.Print();
    for (int i = 0; i < 3; ++i) {
        int deValue;
        sqQueue.DeQueue(deValue);
        std::cout<<"DELETE VALUE: "<<deValue<<std::endl;
    }
    sqQueue.Print();
    int headValue;
    sqQueue.GetHead(headValue);
    std::cout<<"HEAD VALUE: "<<headValue<<std::endl;
}
