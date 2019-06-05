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
private:
    LNode<DataType>* tail;
};


template<class DataType>
LinkList<DataType> LLinkList<DataType>::HeadInsertCreateList(const PracticeLinearList<DataType> &linearList){
    LinkList<DataType>::HeadInsertCreateList(linearList);
    tail = LinkList<DataType>::GetElem(this->link_list_length);
    tail->next = this->head;
    return *this;
}


#endif //STLLEARN_LLINKLIST_H
