//
// Created by Kevinlinpr on 2019/6/23.
//

#ifndef STLLEARN_BT_H
#define STLLEARN_BT_H

#include <stack>
#include <iostream>
struct ConstructMethod{
    static int PREORDER_AND_INORDER,POSTORDER_AND_INORDER;
};
int ConstructMethod::PREORDER_AND_INORDER = 0;
int ConstructMethod::POSTORDER_AND_INORDER = 1;

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
    BT(T* order,T* inOrder,int len, int method);
    void PreOrderPrint() const;
    void InOrderPrint() const;
    void PostOrderPrint() const;
private:
    BTNode<T>* ConstructPreInMethod(T* preOrder,T* inOrder,int len);
    BTNode<T>* ConstructPostInMethod(T* postOrder,T* inOrder,int len);
    BTNode<T>* rootNode;
};

/// 二叉树构造（前序中序构造）
//int pre[11]={3,88,10,12,9,73,11,32,99,1,2};
//int in[11]={10,12,88,9,3,11,99,32,73,1,2};
//int post[11]={12,10,9,88,99,32,11,2,1,73,3};
//BT<int> bt_pre(pre,in,11,ConstructMethod::PREORDER_AND_INORDER);
//BT<int> bt_pst(post,in,11,ConstructMethod::POSTORDER_AND_INORDER);
//std::cout<<"END CONSTRUCT."<<std::endl;
/// \tparam T
/// \param preOrder
/// \param inOrder
/// \param len
template<class T>
BT<T>::BT(T *order, T *inOrder, int len,int method) {
    switch (method){
        case 0:
            this->rootNode = this->ConstructPreInMethod(order,inOrder,len);
            break;
        case 1:
            this->rootNode = this->ConstructPostInMethod(order,inOrder,len);
            break;
        default:
            break;
    }
}

template<class T>
BTNode<T>* BT<T>::ConstructPreInMethod(T *preOrder, T *inOrder, int len) {
    if(!preOrder||!inOrder||len==0)
        return nullptr;
    auto * newNode = new BTNode<T>(preOrder[0]);
    int leftAmount = 0;
    T* rootIndex = inOrder;
    while(*rootIndex!=newNode->data&&rootIndex<=(inOrder+len-1)){
        ++rootIndex;
        ++leftAmount;
    }
    if(leftAmount>0)
        newNode->leftNode = this->ConstructPreInMethod(preOrder+1,inOrder,leftAmount);
    if(len-leftAmount-1>0)
        newNode->rightNode = this->ConstructPreInMethod(preOrder+leftAmount+1,rootIndex+1,len-leftAmount-1);
    return newNode;
}

template<class T>
BTNode<T> *BT<T>::ConstructPostInMethod(T *postOrder, T *inOrder, int len) {
    if(!postOrder||!inOrder||len==0)
        return nullptr;
    auto * newNode = new BTNode<T>(postOrder[len-1]);
    int leftAmount = 0;
    T* rootInOrder = inOrder;
    while(*rootInOrder!=newNode->data&&rootInOrder<=(inOrder+len-1)){
        ++rootInOrder;
        ++leftAmount;
    }
    if(leftAmount>0)
        newNode->leftNode = this->ConstructPostInMethod(postOrder,inOrder,leftAmount);
    if(len-leftAmount-1)
        newNode->rightNode = this->ConstructPostInMethod(postOrder+leftAmount,inOrder+leftAmount+1,len-leftAmount-1);
    return newNode;
}

template<class T>
void BT<T>::PreOrderPrint() const {
    std::stack<BTNode<T>*> adjustStack;
    adjustStack.push(this->rootNode);
    while(!adjustStack.empty()){
        BTNode<T>* father = adjustStack.top();
        adjustStack.pop();
        std::cout<<father->data<<" ";
        if(father->rightNode)
            adjustStack.push(father->rightNode);
        if(father->leftNode)
            adjustStack.push(father->leftNode);
    }
    std::cout<<std::endl;
}

template<class T>
void BT<T>::InOrderPrint() const {
    std::stack<BTNode<T>*> adjustStack;
    BTNode<T>* root = this->rootNode;
    while(!adjustStack.empty()||root){
        while(root){
            adjustStack.push(root);
            root = root->leftNode;
        }
        if(!adjustStack.empty()){
            root = adjustStack.top();
            adjustStack.pop();
            std::cout<<root->data<<" ";
            root = root->rightNode;
        }
    }
    std::cout<<std::endl;
}

template<class T>
void BT<T>::PostOrderPrint() const {
    std::stack<BTNode<T>*> adjustStack;
    BTNode<T>* preNode = nullptr;
    BTNode<T>* root = this->rootNode;
    while(root){
        adjustStack.push(root);
        root = root->leftNode;
    }
    while(!adjustStack.empty()){
        root = adjustStack.top();
        adjustStack.pop();
        if(root->rightNode == nullptr||root->rightNode == preNode){
            std::cout<<root->data<<" ";
            preNode = root;
        }else{
            adjustStack.push(root);
            root = root->rightNode;
            while(root){
                adjustStack.push(root);
                root = root->leftNode;
            }
        }
    }
    std::cout<<std::endl;
}


#endif //STLLEARN_BT_H
