//
// Created by Kevinlinpr on 3/6/19.
//

#ifndef STLLEARN_DNODE_H
#define STLLEARN_DNODE_H

#include "LNode.h"
template <class DataType>
class DNode :public LNode<DataType> {
public:
    DNode():LNode<DataType>(){};
    explicit DNode(DataType value):LNode<DataType>(value){};
    LNode<DataType>* prior;
};


#endif //STLLEARN_DNODE_H
