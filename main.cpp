#include <iostream>
#include "PracticeLinearList.h"
int main(){
    int a[9]={12,29,30,564,699,998,1200,1300,2900};
    PracticeLinearList<int> practiceLinearList(a,9);
    practiceLinearList.DeleteOrderedRangeValue(28,999);
    practiceLinearList.PrintList();
}