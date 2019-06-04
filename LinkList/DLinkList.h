//
// Created by Kevinlinpr on 2019/6/5.
//

#ifndef STLLEARN_DLINKLIST_H
#define STLLEARN_DLINKLIST_H

#include "DNode.h"
#include "LinkList.h"

template <class DataType>
class DLinkList {
public:
    DLinkList();
    ~DLinkList();
    DLinkList<DataType> HeadInsertCreateList(const PracticeLinearList<DataType>& linearList);
    DLinkList<DataType> EndInsertCreateList(const PracticeLinearList<DataType>& linearList);
    void PrintList() const;
    DNode<DataType>* GetElem(int loc) const;
    DNode<DataType>* LocateElem(int value) const;
    void BeforeInsert(int insertLoc,DNode<DataType>& newNode);
    void AfterInsert(int insertLoc,DNode<DataType>& newNode);
    void DeleteElem(int elem);

private:
    DNode<DataType>* head;
    int dlink_list_length{};
};

template<class DataType>
DLinkList<DataType>::DLinkList() {
    this->head = nullptr;
    this->dlink_list_length = 0;
}

template<class DataType>
DLinkList<DataType>::~DLinkList() {
    delete this->head;
    this->head = nullptr;
}

template<class DataType>
DLinkList<DataType> DLinkList<DataType>::HeadInsertCreateList(const PracticeLinearList<DataType> &linearList) {
    DNode<DataType>* tmpNode = new DNode(0), *newNode = new DNode(0);
    this->dlink_list_length = linearList.linear_list_length;
    for (int i = 0; i < 2; ++i) {
        newNode = new DNode(0);
        head->next = newNode;
        newNode->next = tmpNode;
        newNode->data = linearList.list[i];
        tmpNode->prior = newNode;
        tmpNode = newNode;
    }
    std::cout<<this->dlink_list_length<<std::endl;

    return *this;
}

template<class DataType>
void DLinkList<DataType>::PrintList() const {
    DNode<DataType>* copeNode = this->head;
    for (int i = 0; i < this->dlink_list_length; ++i) {
        std::cout<<"INDEX: "<<i<<" VALUE: "<<copeNode->data<<std::endl;
        copeNode = copeNode->next;
    }
    std::cout<<"AMOUNT: "<<this->dlink_list_length<<std::endl;
}


#endif //STLLEARN_DLINKLIST_H
