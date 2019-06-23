//
// Created by Kevinlinpr on 2019/6/23.
//

#ifndef STLLEARN_TBT_H
#define STLLEARN_TBT_H

template <class T>
class TBTNode{
    T data;
    TBTNode<T>* leftNode,*rightNode;
    unsigned int leftFlag,rightFlag;
};


template <class T>
class TBT{

private:
    TBTNode<T>* root_node;
};
#endif //STLLEARN_TBT_H
