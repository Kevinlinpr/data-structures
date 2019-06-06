#include <iostream>
#include "LinkList/DLinkList.h"
#include "LinkList/LDLinkList.h"
#include "LinkList/DNode.h"
#include "LinkList/LLinkList.h"
int main(){
    int a[3]={12,29,30};
    PracticeLinearList<int> practiceLinearListA(a,3);
    std::cout<<"In heap"<<std::endl;
    auto * dLinkListInHeap = new LDLinkList<int>;
    dLinkListInHeap->HeadInsertCreateList(practiceLinearListA);
    dLinkListInHeap->PrintList();
    std::cout<<"head point to tail(prior): "<<dLinkListInHeap->GetElem(1)->prior->prior->data<<std::endl;
    std::cout<<"tail point to head(next): "<<dLinkListInHeap->GetElem(3)->next->next->data<<std::endl;
}
