#include <iostream>
#include "PracticeLinearList.h"
int main(){
    int a[8]={1223,2923,30,564,699,998,222,110};
    PracticeLinearList<int> practiceLinearList(a,8);
    std::cout<<practiceLinearList.DeleteMinValue()<<std::endl;
    practiceLinearList.PrintList();
}