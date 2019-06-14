#include "BST/BST.h"

int main(){
    int data[5] = {11,1,24,2,32};
    PracticeLinearList<int> practiceLinearList(data,5);
    BST<int> bst;
    bst.InitBST(practiceLinearList);
}
