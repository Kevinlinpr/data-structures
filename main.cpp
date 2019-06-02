#include <iostream>
#include "PracticeLinearList.h"
int main(){
    int a[7]={122,29,30,564,699,998,699};
    PracticeLinearList<int> practiceLinearList(a,7);
    practiceLinearList.DeleteTargetValue(699);
    practiceLinearList.PrintList();
}