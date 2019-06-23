#include <iostream>
#include <vector>
#include "LinearList/PracticeLinearList.h"
#include "BinaryTree/BT/BT.h"


int main(){
    int pre[11]={3,88,10,12,9,73,11,32,99,1,2};
    int in[11]={10,12,88,9,3,11,99,32,73,1,2};
    BT<int> bt(pre,in,11);
    std::cout<<"END CONSTRUCT."<<std::endl;
}
