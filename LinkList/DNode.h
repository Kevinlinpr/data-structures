//
// Created by Kevinlinpr on 3/6/19.
//

#ifndef STLLEARN_DNODE_H
#define STLLEARN_DNODE_H

template <class DataType>
class DNode {
public:
    DNode();
    explicit DNode(DataType value);
    DataType data;
    DNode* next;
    DNode* prior;
};

template<class DataType>
DNode<DataType>::DNode(DataType value) {
    this->data = value;
    this->next = nullptr;
    this->prior = nullptr;
}

template<class DataType>
DNode<DataType>::DNode() {
    this->data = 0;
    this->next = nullptr;
    this->prior = nullptr;
}


#endif //STLLEARN_DNODE_H
