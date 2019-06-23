#include <iostream>
#include <vector>
#include "LinearList/PracticeLinearList.h"
#include "BinaryTree/BT/BT.h"


int main(){
    int pre[11]={3,88,10,12,9,73,11,32,99,1,2};
    int in[11]={10,12,88,9,3,11,99,32,73,1,2};
    int post[11]={12,10,9,88,99,32,11,2,1,73,3};
    BT<int> bt_pre(pre,in,11,ConstructMethod::PREORDER_AND_INORDER);
    BT<int> bt_pst(post,in,11,ConstructMethod::POSTORDER_AND_INORDER);
    bt_pre.PreOrderPrint();
    bt_pre.InOrderPrint();
    std::cout<<"END CONSTRUCT."<<std::endl;
}
