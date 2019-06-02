#include <iostream>
#include "PracticeLinearList.h"
int main(){
    int a[6]={122,29,30,564,699,998};
    PracticeLinearList<int> practiceLinearList(a,6);
    practiceLinearList.Reverse();
    practiceLinearList.PrintList();
}