#include <iostream>
#include <vector>
#include "LinearList/PracticeLinearList.h"
#include "BST/BST.h"


int main(){
    int data[16] = {11,1,24,2,32,90,58,34,22,13,99,47,12,13,5,8};
    PracticeLinearList<int> practiceLinearList(data,16);
    BST<int> bst;
    bst.InitBST(practiceLinearList);
    bst.InOrderPrint();
    auto * node = new BSTNode<int>(50);
    bst.Insert(node);
    bst.InOrderPrint();
}
