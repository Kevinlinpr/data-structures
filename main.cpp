#include <iostream>
#include "PracticeLinearList.h"
int main(){
    int a[9]={12,29,30,35,998,998,1200,1200,2900};
    PracticeLinearList<int> practiceLinearListA(a,9);
    PracticeLinearList<int>::ExchangeMNList(practiceLinearListA,5,4);
    practiceLinearListA.PrintList();
    std::cout<<"end"<<std::endl;
}