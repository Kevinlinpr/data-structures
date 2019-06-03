//
// Created by Kevinlinpr on 3/6/19.
//

#ifndef STLLEARN_LNODE_H
#define STLLEARN_LNODE_H

template <class DataType>
class LNode {
public:
    LNode();
    explicit LNode(DataType value);
    DataType data;
    LNode* next;
};

template<class DataType>
LNode<DataType>::LNode(DataType value) {
    data = value;
    next = nullptr;
}

template<class DataType>
LNode<DataType>::LNode() {
    data = 0;
    next = nullptr;
}


#endif //STLLEARN_LNODE_H
