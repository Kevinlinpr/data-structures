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
    LinkList<DataType> HeadInsertCreateList(const PracticeLinearList<DataType>& linearList);
    LinkList<DataType> EndInsertCreateList(const PracticeLinearList<DataType>& linearList);
    void PrintList() const;
    LNode<DataType>* GetElem(int loc) const;
    LNode<DataType>* LocateElem(int value) const;
private:
    LNode<DataType>* head;
    int link_list_length;
};


template<typename DataType>
LinkList<DataType>::LinkList() {
    head = new LNode<DataType>;
    head->data = 0;
    head->next = nullptr;
    this->link_list_length = 0;
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
LinkList<DataType> LinkList<DataType>::HeadInsertCreateList(const PracticeLinearList<DataType>& linearList) {
    LNode<DataType> *tmpNode = nullptr,*newNode = nullptr;
    this->link_list_length = linearList.linear_list_length;
    for (int i = 0; i < this->link_list_length; ++i) {
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
LinkList<DataType> LinkList<DataType>::EndInsertCreateList(const PracticeLinearList<DataType>& linearList) {
    LNode<DataType> *tmpNode = nullptr,*newNode = nullptr;
    this->link_list_length = linearList.linear_list_length;
    tmpNode = head;
    for (int i = 0; i < this->link_list_length; ++i) {
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
    LNode<DataType>* copeNode = this->head->next;
    for (int i = 0; i < this->link_list_length; ++i) {
        std::cout<<"NO."<<i+1<<"  data: "<<copeNode->data<<std::endl;
        copeNode = copeNode->next;
    }
    std::cout<<"Amount: "<<this->link_list_length<<std::endl;
}

/// 按位置查找单链表节点
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//LinkList<int> linkList;
//linkList.EndInsertCreateList(practiceLinearListA);
//linkList.PrintList();
//LNode<int>* node = linkList.GetElem(9);
//std::cout<<"find node data: "<<node->data<<std::endl;
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param loc
/// \return
template<typename DataType>
LNode<DataType> *LinkList<DataType>::GetElem(int loc) const {
    LNode<DataType>* copeNode = this->head;
    if(loc>this->link_list_length||loc<0)
        throw "Wrong elem";
    if(loc==0)
        return copeNode;
    for (int i = 1; i < loc + 1; ++i) {
        copeNode = copeNode->next;
    }
    return copeNode;
}

/// 按值查找单链表节点
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//LinkList<int> linkList;
//linkList.EndInsertCreateList(practiceLinearListA);
//linkList.PrintList();
//LNode<int>* node = linkList.LocateElem(13);
//if(node)
//std::cout<<"find it"<<std::endl;
//else
//std::cout<<"isn't there"<<std::endl;
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param value
/// \return
template<typename DataType>
LNode<DataType> *LinkList<DataType>::LocateElem(int value) const {
    LNode<DataType>* copNode = this->head->next;
    for (int i = 0; i < this->link_list_length; ++i) {
        if(copNode->data==value)
            return copNode;
        copNode = copNode->next;
    }
    return nullptr;
}

#endif //STLLEARN_LINKLIST_H
