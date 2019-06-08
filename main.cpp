#include <iostream>
#include "Stack/LinkStack.h"

int main(){
    LinkStack<int> linkStack;
    linkStack.Push(1);
    linkStack.Push(2);
    linkStack.Push(3);
    linkStack.Push(4);
    linkStack.Pop();
    linkStack.Pop();
    int topValue;
    linkStack.GetTop(topValue);
    std::cout<<"TOP VALUE: "<<topValue<<std::endl;
    linkStack.Print();
    linkStack.ClearStack();
    linkStack.Print();
}
