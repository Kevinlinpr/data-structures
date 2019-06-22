#include "BST/BST.h"
#include <stdexcept>
int main(){
    int data[10] = {53,17,9,45,78,23,65,94,81,88};
    PracticeLinearList<int> practiceLinearList(data,10);
    BST<int> bst;
    bst.InitBST(practiceLinearList);
    bst.InOrderPrint();
    auto * node = new BSTNode<int>(78);
    bst.Delete(node);
    bst.InOrderPrint();
}
