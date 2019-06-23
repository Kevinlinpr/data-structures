//
// Created by Kevinlinpr on 2019/6/23.
//

#ifndef STLLEARN_BT_H
#define STLLEARN_BT_H

template <class T>
class BTNode{
public:
    explicit BTNode(T value);
    T data;
    BTNode<T>* leftNode,*rightNode;
};

template<class T>
BTNode<T>::BTNode(T value) {
    this->data = value;
    this->leftNode = nullptr;
    this->rightNode = nullptr;
}

template <class T>
class BT{
public:
    BT(T* preOrder,T* inOrder,int len);

private:
    BTNode<T>* Construct(T* preOrder,T* inOrder,int len);
    BTNode<T>* rootNode;
};

/// 二叉树构造（前序中序构造）
//int pre[11]={3,88,10,12,9,73,11,32,99,1,2};
//int in[11]={10,12,88,9,3,11,99,32,73,1,2};
//BT<int> bt(pre,in,11);
//std::cout<<"END CONSTRUCT."<<std::endl;
/// \tparam T
/// \param preOrder
/// \param inOrder
/// \param len
template<class T>
BT<T>::BT(T *preOrder, T *inOrder, int len) {
    this->rootNode = this->Construct(preOrder,inOrder,len);
}

template<class T>
BTNode<T>* BT<T>::Construct(T *preOrder, T *inOrder, int len) {
    if(!preOrder||!inOrder||len==0)
        return nullptr;
    auto * newNode = new BTNode<T>(preOrder[0]);
    int leftAmount = 0;
    int* rootIndex = inOrder;
    while(*rootIndex!=newNode->data&&rootIndex<=(inOrder+len-1)){
        ++rootIndex;
        ++leftAmount;
    }
    if(leftAmount>0)
        newNode->leftNode = this->Construct(preOrder+1,inOrder,leftAmount);
    if(len-leftAmount-1>0)
        newNode->rightNode = this->Construct(preOrder+leftAmount+1,rootIndex+1,len-leftAmount-1);
    return newNode;
}



#endif //STLLEARN_BT_H
