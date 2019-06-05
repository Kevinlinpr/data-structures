#include <iostream>
#include "LinkList/DLinkList.h"
#include "LinkList/DNode.h"

int main(){
    int a[3]={12,29,30};
    PracticeLinearList<int> practiceLinearListA(a,3);
    std::cout<<"In heap"<<std::endl;
    auto * dLinkListInHeap = new DLinkList<int>;
    dLinkListInHeap->HeadInsertCreateList(practiceLinearListA);
    dLinkListInHeap->PrintList();
}
