#include <iostream>
#include "PracticeLinearList.h"
int main(){
    int a[9]={12,29,30,30,998,998,1200,1200,2900};
    PracticeLinearList<int> practiceLinearList(a,9);
    practiceLinearList.DeleteOrderedRepeatValue();
    practiceLinearList.PrintList();
}