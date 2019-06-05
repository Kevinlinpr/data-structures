#include <iostream>
#include "LinkList/DLinkList.h"
#include "LinkList/DNode.h"
#include "LinkList/LLinkList.h"
int main(){
    int a[3]={12,29,30};
    PracticeLinearList<int> practiceLinearListA(a,3);
    std::cout<<"In heap"<<std::endl;
    auto * dLinkListInHeap = new DLinkList<int>;
    dLinkListInHeap->EndInsertCreateList(practiceLinearListA);
    dLinkListInHeap->PrintList();
    DNode<int> newNode(99);
    dLinkListInHeap->BeforeInsert(1,newNode);
    dLinkListInHeap->PrintList();
    dLinkListInHeap->DeleteElem(2);
    dLinkListInHeap->PrintList();
}
