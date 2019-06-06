//
// Created by Kevinlinpr on 5/6/19.
//

#ifndef STLLEARN_LLINKLIST_H
#define STLLEARN_LLINKLIST_H

#include "LinkList.h"

template <class DataType>
class LLinkList : public LinkList<DataType>{
public:
    LLinkList():LinkList<DataType>(){};
    LinkList<DataType> HeadInsertCreateList(const PracticeLinearList<DataType>& linearList) override;
    LinkList<DataType> EndInsertCreateList(const PracticeLinearList<DataType>& linearList) override;
private:
    LNode<DataType>* tail;
};

/// 循环单链表头插法创建
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * lLinkListInHeap = new LLinkList<int>;
//lLinkListInHeap->HeadInsertCreateList(practiceLinearListA);
//lLinkListInHeap->PrintList();
//std::cout<<lLinkListInHeap->GetElem(3)->next->next->
//next->next->next->next->next->next->next->next->
//next->next->next->next->next->next->next->next->data<<std::endl;
/// \tparam DataType
/// \param linearList
/// \return
template<class DataType>
LinkList<DataType> LLinkList<DataType>::HeadInsertCreateList(const PracticeLinearList<DataType> &linearList){
    LinkList<DataType>::HeadInsertCreateList(linearList);
    tail = LinkList<DataType>::GetElem(this->link_list_length);
    tail->next = this->head;
    return *this;
}

/// 循环单链表尾插入法创建
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * lLinkListInHeap = new LLinkList<int>;
//lLinkListInHeap->EndInsertCreateList(practiceLinearListA);
//lLinkListInHeap->PrintList();
//std::cout<<lLinkListInHeap->GetElem(3)->next->next->
//next->next->next->next->next->next->next->next->
//next->next->next->next->next->next->next->next->data<<std::endl;
/// \tparam DataType
/// \param linearList
/// \return
template<class DataType>
LinkList<DataType> LLinkList<DataType>::EndInsertCreateList(const PracticeLinearList<DataType> &linearList) {
    LinkList<DataType>::EndInsertCreateList(linearList);
    tail = LinkList<DataType>::GetElem(this->link_list_length);
    tail->next = this->head;
    return *this;
}


#endif //STLLEARN_LLINKLIST_H
