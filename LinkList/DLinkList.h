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

    virtual DLinkList<DataType> HeadInsertCreateList(const PracticeLinearList<DataType>& linearList);

    virtual DLinkList<DataType> EndInsertCreateList(const PracticeLinearList<DataType>& linearList);
    void PrintList() const;
    DNode<DataType>* GetElem(int loc) const;
    DNode<DataType>* LocateElem(int value) const;
    void BeforeInsert(int insertLoc,DNode<DataType>& newNode);
    void AfterInsert(int insertLoc,DNode<DataType>& newNode);
    void DeleteElem(int elem);

protected:
    DNode<DataType>* head;
    int dlink_list_length{};
};

template<class DataType>
DLinkList<DataType>::DLinkList() {
    this->head = new DNode(0);
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
    DNode<DataType> * tmpNode = nullptr,*newNode;
    for (int i = 0; i < this->dlink_list_length; ++i) {
        newNode = new DNode(0);
        this->head->next = newNode;
        newNode->prior = this->head;
        newNode->next = tmpNode;
        if(newNode->next!= nullptr)
            newNode->next->prior = newNode;
        newNode->data = linearList.list[i];
        tmpNode = newNode;
    }
    std::cout<<"Finish HeadInsert Creation"<<std::endl;
    return *this;
}

template<class DataType>
void DLinkList<DataType>::PrintList() const {
    DNode<DataType>* copeNode = this->head->next;
    for (int i = 0; i < this->dlink_list_length; ++i) {
        std::cout<<"NO."<<i+1<<" VALUE: "<<copeNode->data<<std::endl;
        copeNode = copeNode->next;
    }
    std::cout<<"AMOUNT: "<<this->dlink_list_length<<std::endl;
}

/// 尾插法创建双向链表
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new DLinkList<int>;
//dLinkListInHeap->EndInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
/// \tparam DataType
/// \param linearList
/// \return
template<class DataType>
DLinkList<DataType> DLinkList<DataType>::EndInsertCreateList(const PracticeLinearList<DataType> &linearList) {
    this->dlink_list_length = linearList.linear_list_length;
    DNode<DataType> * tmpNode = nullptr,*newNode;
    tmpNode = this->head;
    for (int i = 0; i < this->dlink_list_length; ++i) {
        newNode = new DNode(0);
        newNode->data = linearList.list[i];
        newNode->next = nullptr;
        tmpNode->next = newNode;
        newNode->prior = tmpNode;
        tmpNode = newNode;
    }
    std::cout<<"Finish EndInsert Creation"<<std::endl;
    return *this;
}

/// 按位置查找
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new DLinkList<int>;
//dLinkListInHeap->EndInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
//std::cout<<"GETELEM VALUE: "<<dLinkListInHeap->GetElem(3)->data<<std::endl;
/// \tparam DataType
/// \param loc
/// \return
template<class DataType>
DNode<DataType> *DLinkList<DataType>::GetElem(int loc) const {
    if(loc<=0&&loc>this->dlink_list_length)
        throw "Wrong loc";
    DNode<DataType>* copeNode = this->head->next;
    for (int i = 0; i < loc - 1; ++i) {
        copeNode = copeNode->next;
    }
    return copeNode;
}

/// 按值查询
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new DLinkList<int>;
//dLinkListInHeap->EndInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
//std::cout<<"LOCATEELEM VALUE: "<<dLinkListInHeap->LocateElem(29)->data<<std::endl;
/// \tparam DataType
/// \param value
/// \return
template<class DataType>
DNode<DataType> *DLinkList<DataType>::LocateElem(int value) const {
    DNode<DataType>* copeNode = this->head->next;
    for (int i = 0; i < this->dlink_list_length; ++i) {
        if(copeNode->data==value)
            return copeNode;
        copeNode = copeNode->next;
    }
    return nullptr;
}

/// 前插入
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new DLinkList<int>;
//dLinkListInHeap->EndInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
//DNode<int> newNode(99);
//dLinkListInHeap->BeforeInsert(3,newNode);
//dLinkListInHeap->PrintList();
/// \tparam DataType
/// \param insertLoc
/// \param newNode
template<class DataType>
void DLinkList<DataType>::BeforeInsert(int insertLoc, DNode<DataType> &newNode) {
    DNode<DataType>* copeNode = this->GetElem(insertLoc);
    if(insertLoc==1){
        this->head->next = &newNode;
        newNode.prior = nullptr;
    }else{
        copeNode->prior->next = &newNode;
        newNode.prior = copeNode->prior;
    }
    newNode.next = copeNode;
    copeNode->prior = &newNode;
    ++this->dlink_list_length;
}

/// 后插入
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new DLinkList<int>;
//dLinkListInHeap->EndInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
//DNode<int> newNode(99);
//dLinkListInHeap->AfterInsert(1,newNode);
//dLinkListInHeap->PrintList();
/// \tparam DataType
/// \param insertLoc
/// \param newNode
template<class DataType>
void DLinkList<DataType>::AfterInsert(int insertLoc, DNode<DataType> &newNode) {
    DNode<DataType>* copeNode = this->GetElem(insertLoc);
    if(insertLoc==this->dlink_list_length){
        newNode.next = nullptr;
    }else{
        copeNode->next->prior = &newNode;
        newNode.next = copeNode->next;
    }
    copeNode->next = &newNode;
    newNode.prior = copeNode;
    ++this->dlink_list_length;
}

/// 删除元素
//int a[3]={12,29,30};
//PracticeLinearList<int> practiceLinearListA(a,3);
//std::cout<<"In heap"<<std::endl;
//auto * dLinkListInHeap = new DLinkList<int>;
//dLinkListInHeap->EndInsertCreateList(practiceLinearListA);
//dLinkListInHeap->PrintList();
//DNode<int> newNode(99);
//dLinkListInHeap->BeforeInsert(1,newNode);
//dLinkListInHeap->PrintList();
//dLinkListInHeap->DeleteElem(2);
//dLinkListInHeap->PrintList();
/// \tparam DataType
/// \param elem
template<class DataType>
void DLinkList<DataType>::DeleteElem(int elem) {
    DNode<DataType>* copeNode = this->GetElem(elem);
    if(elem==1){
        this->head->next = copeNode->next;
        copeNode->next->prior = this->head;
    }
    else if(elem==this->dlink_list_length){
        copeNode->prior->next = nullptr;
        copeNode->prior = nullptr;
    }
    else{
        copeNode->prior->next = copeNode->next;
        copeNode->next->prior = copeNode->prior;
        copeNode->prior = nullptr;
        copeNode->next = nullptr;
    }
    --this->dlink_list_length;
}




#endif //STLLEARN_DLINKLIST_H
