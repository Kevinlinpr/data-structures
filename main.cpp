#include <iostream>
#include "LinkList/LinkList.h"


int main(){
    int a[9]={12,29,30,35,998,998,1200,1200,2900};
    PracticeLinearList<int> practiceLinearListA(a,9);
    LinkList<int> linkList;
    linkList.EndInsertCreateList(practiceLinearListA);
    linkList.PrintList();
    LNode<int>* node = linkList.LocateElem(13);
    if(node)
        std::cout<<"find it"<<std::endl;
    else
        std::cout<<"isn't there"<<std::endl;
    std::cout<<"end"<<std::endl;
}