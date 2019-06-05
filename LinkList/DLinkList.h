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

/// 头插法创建双链表（请不要随便使用析构函数，在动态内存分配时）
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new DLinkList<int>;
//dLinkListInHeap->HeadInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
/// \tparam DataType
/// \param linearList
/// \return
template<class DataType>
DLinkList<DataType> DLinkList<DataType>::HeadInsertCreateList(const PracticeLinearList<DataType> &linearList) {
    this->dlink_list_length = linearList.linear_list_length;

    auto * firstNode = new DNode<DataType>;
    DNode<DataType> * tmpNode = nullptr;

    this->head = firstNode;
    firstNode->data = linearList.list[0];
    firstNode->prior = nullptr;
    firstNode->next = nullptr;
    tmpNode = firstNode;

    for (int i = 1; i < this->dlink_list_length; ++i) {
        auto * newNode = new DNode<DataType>;
        this->head = newNode;
        newNode->data = linearList.list[i];
        newNode->next = tmpNode;
        tmpNode->prior = newNode;
        tmpNode = newNode;
    }
    return *this;
}

template<class DataType>
void DLinkList<DataType>::PrintList() const {
    DNode<DataType>* copeNode = this->head;
    for (int i = 0; i < this->dlink_list_length; ++i) {
        std::cout<<"NO."<<i+1<<" VALUE: "<<copeNode->data<<std::endl;
        copeNode = copeNode->next;
    }
    std::cout<<"AMOUNT: "<<this->dlink_list_length<<std::endl;
}


#endif //STLLEARN_DLINKLIST_H
