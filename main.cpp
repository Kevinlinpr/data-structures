#include <iostream>
#include "PracticeLinearList.h"
int main(){
    int a[9]={12,29,30,35,998,998,1200,1200,2900};
    PracticeLinearList<int> practiceLinearListA(a,9);
    practiceLinearListA.PrintList();
    PracticeLinearList<int>::SpeedFind(practiceLinearListA,30);
    practiceLinearListA.PrintList();
    std::cout<<"end"<<std::endl;
}