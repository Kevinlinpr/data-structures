//
// Created by Kevinlinpr on 3/6/19.
//

#ifndef STLLEARN_LINKLIST_H
#define STLLEARN_LINKLIST_H

#include "LNode.h"
#include "../LinearList/PracticeLinearList.h"

template <class DataType>
class LinkList {
public:
    LinkList();
    LinkList<DataType> HeadInsertCreateList(const PracticeLinearList<DataType>& linearList);
    LinkList<DataType> EndInsertCreateList(const PracticeLinearList<DataType>& linearList);
    void PrintList() const;
    LNode<DataType>* GetElem(int loc) const;
    LNode<DataType>* LocateElem(int value) const;
    void BeforeInsert(int insertLoc,LNode<DataType>& newNode);
    void AfterInsert(int insertLoc,LNode<DataType>& newNode);
    void DeleteElem(int elem);
private:
    LNode<DataType>* head;
    int link_list_length{};
};


template<class DataType>
LinkList<DataType>::LinkList() {
    head = new LNode(0);
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
template<class DataType>
LinkList<DataType> LinkList<DataType>::HeadInsertCreateList(const PracticeLinearList<DataType>& linearList) {
    LNode<DataType> *tmpNode = nullptr,*newNode = nullptr;
    this->link_list_length = linearList.linear_list_length;
    for (int i = 0; i < this->link_list_length; ++i) {
        newNode = new LNode(0);
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
template<class DataType>
LinkList<DataType> LinkList<DataType>::EndInsertCreateList(const PracticeLinearList<DataType>& linearList) {
    LNode<DataType> *tmpNode = nullptr,*newNode = nullptr;
    this->link_list_length = linearList.linear_list_length;
    tmpNode = head;
    for (int i = 0; i < this->link_list_length; ++i) {
        newNode = new LNode(0);
        newNode->data = linearList.list[i];
        newNode->next = nullptr;
        tmpNode->next = newNode;
        tmpNode = newNode;
    }
    std::cout<<"Finish EndInsert Creation"<<std::endl;
    return *this;
}

template<class DataType>
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
template<class DataType>
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
template<class DataType>
LNode<DataType> *LinkList<DataType>::LocateElem(int value) const {
    LNode<DataType>* copNode = this->head->next;
    for (int i = 0; i < this->link_list_length; ++i) {
        if(copNode->data==value)
            return copNode;
        copNode = copNode->next;
    }
    return nullptr;
}

/// 前插
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//LinkList<int> linkList;
//linkList.EndInsertCreateList(practiceLinearListA);
//linkList.PrintList();
//LNode<int> node(38);
//linkList.BeforeInsert(3,node);
//linkList.PrintList();
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param insertLoc
/// \param newNode
template<class DataType>
void LinkList<DataType>::BeforeInsert(int insertLoc,LNode<DataType>& newNode) {
    LNode<DataType>* leftNode = this->GetElem(insertLoc-1);
    LNode<DataType>* rightNode = leftNode->next;
    leftNode->next = &newNode;
    newNode.next = rightNode;
    ++this->link_list_length;
}

/// 后插
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//LinkList<int> linkList;
//linkList.EndInsertCreateList(practiceLinearListA);
//linkList.PrintList();
//LNode<int> node(38);
//linkList.AfterInsert(5,node);
//linkList.PrintList();
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param insertLoc
/// \param newNode
template<class DataType>
void LinkList<DataType>::AfterInsert(int insertLoc, LNode<DataType> &newNode) {
    LNode<DataType>* leftNode = this->GetElem(insertLoc);
    LNode<DataType>* rightNode = leftNode->next;
    leftNode->next = &newNode;
    newNode.next = rightNode;
    ++this->link_list_length;
}

/// 删除
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//LinkList<int> linkList;
//linkList.EndInsertCreateList(practiceLinearListA);
//linkList.PrintList();
//LNode<int> node(38);
//linkList.AfterInsert(5,node);
//linkList.PrintList();
//linkList.DeleteElem(6);
//linkList.PrintList();
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param elem
template<class DataType>
void LinkList<DataType>::DeleteElem(int elem) {
    if(elem>this->link_list_length)
        throw "Wrong elem";
    LNode<DataType>* LeftNode = this->GetElem(elem-1);
    LNode<DataType>* waite_to_delete_node = LeftNode->next;
    LNode<DataType>* RightNode = waite_to_delete_node->next;
    LeftNode->next = RightNode;
    --this->link_list_length;
}

#endif //STLLEARN_LINKLIST_H
