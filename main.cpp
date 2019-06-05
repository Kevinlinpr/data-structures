#include <iostream>
#include "LinkList/DLinkList.h"
#include "LinkList/DNode.h"
#include "LinkList/LLinkList.h"
int main(){
    int a[3]={12,29,30};
    PracticeLinearList<int> practiceLinearListA(a,3);
    std::cout<<"In heap"<<std::endl;
    auto * lLinkListInHeap = new LLinkList<int>;
    lLinkListInHeap->HeadInsertCreateList(practiceLinearListA);
    lLinkListInHeap->PrintList();
    std::cout<<lLinkListInHeap->GetElem(3)->next->next->
    next->next->next->next->next->next->next->next->
    next->next->next->next->next->next->next->next->data<<std::endl;
}
