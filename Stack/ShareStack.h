//
// Created by Kevinlinpr on 2019/6/8.
//

#ifndef STLLEARN_SHARESTACK_H
#define STLLEARN_SHARESTACK_H

#include <iostream>

template <class DataType,int MAXSIZE = 50>
class ShareStack{
public:
    inline ShareStack(){InitStack();};
    inline void InitStack(){ this->lTop = -1;  this->rTop = MAXSIZE;}
    inline bool StackEmpty(){ return this->lTop==-1&&this->rTop==MAXSIZE;}
    inline bool StackFull(){ return this->rTop-this->lTop==1;}
    inline bool StackLEmpty(){ return this->lTop==-1;}
    inline bool StackREmpty(){ return this->rTop==MAXSIZE;}
    bool PushLStack(DataType value);
    bool PushRStack(DataType value);
    bool PopLStack();
    bool PopRStack();
    inline bool GetLTop(){ return this->data[this->lTop];}
    inline bool GetRTop(){ return this->data[this->rTop];}
    inline void ClearStack(){ this->lTop = -1;  this->rTop = MAXSIZE;}
    void PrintL();
    void PrintR();

private:
    DataType data[MAXSIZE];
    int lTop{};
    int rTop{};
};

template<class DataType, int MAXSIZE>
bool ShareStack<DataType, MAXSIZE>::PushLStack(DataType value) {
    if(this->StackFull()){
        std::cout<<"THE SHARE STACK IS FULL:"<<std::endl;
        return false;
    }
    this->data[++this->lTop] = value;
    if(this->StackFull())
        std::cout<<"THIS SHARE STACK WILL BE FULL NEXT TIME, PLEASE DO NOT PUSH AGAIN!"<<std::endl;
    return true;
}

template<class DataType, int MAXSIZE>
bool ShareStack<DataType, MAXSIZE>::PushRStack(DataType value) {
    if(this->StackFull()){
        std::cout<<"THE SHARE STACK IS FULL:"<<std::endl;
        return false;
    }
    this->data[--this->rTop] = value;
    if(this->StackFull())
        std::cout<<"THIS SHARE STACK IS FULL NOW, PLEASE DO NOT PUSH AGAIN!"<<std::endl;
    return true;
}

template<class DataType, int MAXSIZE>
bool ShareStack<DataType, MAXSIZE>::PopLStack() {
    if(this->StackLEmpty()){
        std::cout<<"THIS LEFT STACK IS EMPTY! PLEASE PUSH BEFORE POP"<<std::endl;
        return false;
    }
    --this->lTop;
    if(this->StackLEmpty())
        std::cout<<"THIS LEFT STACK IS EMPTY NOW, PLEASE DO NOT POP LEFT STACK AGAIN!"<<std::endl;
    return true;
}

template<class DataType, int MAXSIZE>
bool ShareStack<DataType, MAXSIZE>::PopRStack() {
    if(this->StackREmpty()){
        std::cout<<"THIS RIGHT STACK IS EMPTY! PLEASE PUSH BEFORE POP"<<std::endl;
        return false;
    }
    ++this->rTop;
    if(this->StackREmpty())
        std::cout<<"THIS RIGHT STACK IS EMPTY NOW, PLEASE DO NOT POP RIGHT STACK AGAIN!"<<std::endl;
    return true;
}

template<class DataType, int MAXSIZE>
void ShareStack<DataType, MAXSIZE>::PrintL() {
    if(this->StackLEmpty()){
        std::cout<<"THIS LEFT STACK IS EMPTY, PRINT FAILED!";
        return;
    }
    for (int i = 0; i < this->lTop + 1; ++i) {
        std::cout<<"PRINT: INDEX: "<<i<<" VALUE: "<<this->data[i]<<std::endl;
    }
    std::cout<<"PRINT FINISHED!"<<std::endl;
}

template<class DataType, int MAXSIZE>
void ShareStack<DataType, MAXSIZE>::PrintR() {
    if(this->StackREmpty()){
        std::cout<<"THIS RIGHT STACK IS EMPTY, PRINT FAILED!";
        return;
    }
    for (int i = MAXSIZE - 1; i > this->rTop -1; --i) {
        std::cout<<"PRINT: INDEX: "<<i<<" VALUE: "<<this->data[i]<<std::endl;
    }
    std::cout<<"PRINT FINISHED!"<<std::endl;
}

/// example
//ShareStack<int,10> shareStack;
//shareStack.PushLStack(1);
//shareStack.PushRStack(2);
//shareStack.PushLStack(3);
//shareStack.PushLStack(4);
//shareStack.PushLStack(5);
//shareStack.PushLStack(6);
//shareStack.PushRStack(7);
//shareStack.PushRStack(8);
//shareStack.PushRStack(9);
//shareStack.PushRStack(10);
//shareStack.PrintL();
//shareStack.PrintR();
//shareStack.PopLStack();
//shareStack.PopLStack();
//shareStack.PopLStack();
//shareStack.PrintL();
//shareStack.PrintR();
//shareStack.PopRStack();
//shareStack.PopRStack();
//shareStack.PopRStack();
//shareStack.PopRStack();
//shareStack.PopRStack();
//shareStack.PopRStack();
//shareStack.PrintL();
//shareStack.PrintR();
#endif //STLLEARN_SHARESTACK_H
