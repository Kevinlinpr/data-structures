//
// Created by Kevinlinpr on 2019/6/8.
//

#ifndef STLLEARN_LINKSTACK_H
#define STLLEARN_LINKSTACK_H

#include "../LinkList/LNode.h"

template <class DataType>
class LinkStack{
public:
    inline LinkStack(){InitStack();}
    void InitStack();
    bool StackEmpty();
    bool Push(DataType value);
    bool Pop();
    bool GetTop(DataType& topValue);
    void ClearStack();
    void Print();
private:
    LNode<DataType>* head;
};
#endif //STLLEARN_LINKSTACK_H
