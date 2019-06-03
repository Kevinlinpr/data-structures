//
// Created by 唐茂凡 on 3/6/19.
//

#ifndef STLLEARN_LINKLIST_H
#define STLLEARN_LINKLIST_H

#include "LNode.h"
#include "../LinearList/PracticeLinearList.h"

template <typename DataType>
class LinkList {
public:
    LinkList();
    LinkList<DataType> HeadInsertCreateList(PracticeLinearList<DataType> linearList);
    LinkList<DataType> EndInsertCreateList(PracticeLinearList<DataType> linearList);
    void PrintList() const;
private:
    LNode<DataType>* head;
};


template<typename DataType>
LinkList<DataType>::LinkList() {
    head = new LNode<DataType>;
    head->data = 0;
    head->next = nullptr;
}
/// 头查法创建单链表
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//LinkList<int> linkList;
//linkList.HeadInsertCreateList(practiceLinearListA);
//linkList.PrintList();
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param linearList
/// \return
template<typename DataType>
LinkList<DataType> LinkList<DataType>::HeadInsertCreateList(PracticeLinearList<DataType> linearList) {
    LNode<DataType> *tmpNode = nullptr,*newNode = nullptr;
    for (int i = 0; i < linearList.linear_list_length; ++i) {
        newNode = new LNode<DataType>;
        head->next = newNode;
        newNode->next = tmpNode;
        newNode->data = linearList.list[i];
        tmpNode = newNode;
    }
    std::cout<<"Finish HeadInsert Creation"<<std::endl;
    return *this;
}

/// 尾插法创建单链表
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//LinkList<int> linkList;
//linkList.EndInsertCreateList(practiceLinearListA);
//linkList.PrintList();
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param linearList
/// \return
template<typename DataType>
LinkList<DataType> LinkList<DataType>::EndInsertCreateList(PracticeLinearList<DataType> linearList) {
    LNode<DataType> *tmpNode = nullptr,*newNode = nullptr;
    tmpNode = head;
    for (int i = 0; i < linearList.linear_list_length; ++i) {
        newNode = new LNode<DataType>;
        newNode->data = linearList.list[i];
        newNode->next = nullptr;
        tmpNode->next = newNode;
        tmpNode = newNode;
    }
    std::cout<<"Finish EndInsert Creation"<<std::endl;
    return *this;
}

template<typename DataType>
void LinkList<DataType>::PrintList() const {
    int amount = 0;
    LNode<DataType>* copeNode = this->head->next;
    while(true){
        ++amount;
        std::cout<<"NO."<<amount<<"  data: "<<copeNode->data<<std::endl;
        copeNode = copeNode->next;
        if(copeNode->next== nullptr){
            ++amount;
            std::cout<<"NO."<<amount<<"  data: "<<copeNode->data<<" THIS IS FINAL NODE"<<std::endl;
            break;
        }
    }
    std::cout<<"Amount: "<<amount<<std::endl;
}

#endif //STLLEARN_LINKLIST_H
