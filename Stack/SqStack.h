//
// Created by Kevinlinpr on 2019/6/7.
//

#ifndef STLLEARN_SQSTACK_H
#define STLLEARN_SQSTACK_H

#include <iostream>

template <class DataType,int MAXSIZE = 10>
class SqStack{
public:
    inline SqStack(){InitStack();}
    void InitStack();
    bool StackEmpty();
    bool Push(DataType value);
    bool Pop();
    bool GetTop(DataType& topValue);
    void ClearStack();
    void Print();
private:
    DataType data[MAXSIZE];
    int top{};
};

template<class DataType,int MAXSIZE>
void SqStack<DataType,MAXSIZE>::InitStack() {
    this->top = -1;
}

template<class DataType,int MAXSIZE>
bool SqStack<DataType,MAXSIZE>::StackEmpty() {
    return this->top == -1;
}

template<class DataType,int MAXSIZE>
bool SqStack<DataType,MAXSIZE>::Push(DataType value) {
    if(this->top+1==MAXSIZE){
        std::cout<<"Stack Overflow! Now this Stack Size is : "<<this->top+1<<std::endl;
        return false;
    } else{
        ++this->top;
        this->data[this->top] = value;
        std::cout<<"PUSH: index: "<<this->top<<" value: "<<value<<std::endl;
    }
    return true;
}

template<class DataType,int MAXSIZE>
bool SqStack<DataType,MAXSIZE>::Pop() {
    if(StackEmpty()){
        std::cout<<"Stack empty!"<<std::endl;
        return false;
    } else{
        std::cout<<"POP: index: "<<this->top<<" value: "<<this->data[this->top]<<std::endl;
        --this->top;
    }
    return true;
}

template<class DataType,int MAXSIZE>
void SqStack<DataType,MAXSIZE>::ClearStack() {
    this->top = -1;
    std::cout<<"Clear Stack"<<std::endl;
}

template<class DataType,int MAXSIZE>
void SqStack<DataType,MAXSIZE>::Print() {
    if(this->top==-1){
        std::cout<<"Could not print, No Value in Empty Stack"<<std::endl;
    }else{
        for (int i = 0; i < this->top+1; ++i) {
            std::cout<<"PRINT: Index: "<<i<<" VALUE: "<<this->data[i]<<std::endl;
        }
    }

}

template<class DataType, int MAXSIZE>
bool SqStack<DataType, MAXSIZE>::GetTop(DataType &topValue) {
    if(StackEmpty()){
        std::cout<<"Stack empty!"<<std::endl;
        return false;
    } else{
        topValue = this->data[this->top];
        return true;
    }
}

/// example
//SqStack<int,10> sqStack{};
//sqStack.Push(20);
//sqStack.Push(2);
//sqStack.Push(24);
//sqStack.Push(222);
//sqStack.Push(76);
//sqStack.Push(231);
//sqStack.Push(22);
//sqStack.Push(333);
//sqStack.Push(21);
//sqStack.Push(21);
//sqStack.Print();
//sqStack.Push(33343);
//sqStack.Print();
//int topValue;
//if(sqStack.GetTop(topValue)){
//std::cout<<"GET TOP VALUE: "<<topValue<<std::endl;
//} else{
//std::cout<<"EMPTY STACK"<<std::endl;
//}
//sqStack.Pop();
//sqStack.Print();
//sqStack.Pop();
//sqStack.Print();
//sqStack.Push(33343);
//sqStack.Print();
//sqStack.ClearStack();
//sqStack.Print();
//int topValue2;
//if(sqStack.GetTop(topValue2)){
//std::cout<<"GET TOP VALUE: "<<topValue2<<std::endl;
//} else{
//std::cout<<"EMPTY STACK"<<std::endl;
//}

#endif //STLLEARN_SQSTACK_H
