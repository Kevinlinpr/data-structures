//
// Created by Kevinlinpr on 2019/6/6.
//

#ifndef STLLEARN_LDLINKLIST_H
#define STLLEARN_LDLINKLIST_H

#include "DLinkList.h"

template <class DataType>
class LDLinkList:public DLinkList<DataType>{
public:
    LDLinkList():DLinkList<DataType>(){};
    DLinkList<DataType> HeadInsertCreateList(const PracticeLinearList<DataType>& linearList) override;
    DLinkList<DataType> EndInsertCreateList(const PracticeLinearList<DataType>& linearList) override;
private:
    DNode<DataType>* tail;
};

/// 循环双链表头插法创建
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new LDLinkList<int>;
//dLinkListInHeap->HeadInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
//std::cout<<"head point to tail(prior): "<<dLinkListInHeap->GetElem(1)->prior->prior->data<<std::endl;
//std::cout<<"tail point to head(next): "<<dLinkListInHeap->GetElem(3)->next->next->data<<std::endl;
/// \tparam DataType
/// \param linearList
/// \return
template<class DataType>
DLinkList<DataType> LDLinkList<DataType>::HeadInsertCreateList(const PracticeLinearList<DataType> &linearList) {
    DLinkList<DataType>::HeadInsertCreateList(linearList);
    tail = this->GetElem(this->dlink_list_length);
    tail->next = this->head;
    this->head->prior = tail;
    return *this;
}

/// 循环双链表尾插法创建
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new LDLinkList<int>;
//dLinkListInHeap->EndInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
//std::cout<<"head point to tail(prior): "<<dLinkListInHeap->GetElem(1)->prior->prior->data<<std::endl;
//std::cout<<"tail point to head(next): "<<dLinkListInHeap->GetElem(3)->next->next->data<<std::endl;
/// \tparam DataType
/// \param linearList
/// \return
template<class DataType>
DLinkList<DataType> LDLinkList<DataType>::EndInsertCreateList(const PracticeLinearList<DataType> &linearList) {
    DLinkList<DataType>::EndInsertCreateList(linearList);
    tail = this->GetElem(this->dlink_list_length);
    tail->next = this->head;
    this->head->prior = tail;
    return *this;
}


#endif //STLLEARN_LDLINKLIST_H
