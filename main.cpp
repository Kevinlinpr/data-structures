#include <iostream>
#include "PracticeLinearList.h"
int main(){
    int a[9]={12,29,30,30,998,998,1200,1200,2900};
    int b[6]={40,55,209,333,1000,3000};
    int c[15];
    PracticeLinearList<int> practiceLinearListA(a,9);
    PracticeLinearList<int> practiceLinearListB(b,6);
    PracticeLinearList<int> practiceLinearListC(c,15);
    PracticeLinearList<int>::PrintList(PracticeLinearList<int>::MergeTwoOrderedLinearList(practiceLinearListA,practiceLinearListB,practiceLinearListC));
    std::cout<<"end"<<std::endl;
}