#include <iostream>
#include "LinkList/DLinkList.h"
#include "LinkList/DNode.h"

int main(){
    int a[3]={12,29,30};
    PracticeLinearList<int> practiceLinearListA(a,3);
    auto * dLinkList = new DLinkList<int>;
    dLinkList->HeadInsertCreateList(practiceLinearListA);
    std::cout<<"hi"<<std::endl;
    //dl.PrintList();
}
