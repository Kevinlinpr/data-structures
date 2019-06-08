#include <iostream>
#include "Stack/ShareStack.h"

int main(){
    ShareStack<int,10> shareStack;
    shareStack.PushLStack(1);
    shareStack.PushRStack(2);
    shareStack.PushLStack(3);
    shareStack.PushLStack(4);
    shareStack.PushLStack(5);
    shareStack.PushLStack(6);
    shareStack.PushRStack(7);
    shareStack.PushRStack(8);
    shareStack.PushRStack(9);
    shareStack.PushRStack(10);
    shareStack.PrintL();
    shareStack.PrintR();
    shareStack.PopLStack();
    shareStack.PopLStack();
    shareStack.PopLStack();
    shareStack.PrintL();
    shareStack.PrintR();
    shareStack.PopRStack();
    shareStack.PopRStack();
    shareStack.PopRStack();
    shareStack.PopRStack();
    shareStack.PopRStack();
    shareStack.PopRStack();
    shareStack.PrintL();
    shareStack.PrintR();
}
