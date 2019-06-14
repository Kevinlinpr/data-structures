//
// Created by Kevinlinpr on 13/6/19.
//

#ifndef STLLEARN_BST_H
#define STLLEARN_BST_H

#include "../LinearList/PracticeLinearList.h"

template <class T>
class BSTNode{
public:
    explicit BSTNode(T value);
    T data;
    BSTNode<T>* left_child_node;
    BSTNode<T>* right_child_node;
};

template<class T>
BSTNode<T>::BSTNode(T value) {
    this->data = value;
    this->left_child_node = nullptr;
    this->right_child_node = nullptr;
}

template <class T>
class BST {
public:
    BST();
    BST<T>* InitBST(PracticeLinearList<T> linearList);
private:
    BSTNode<T>* root_node;
};

template<class T>
BST<T>::BST() {
    this->root_node = nullptr;
}


template<class T>
BST<T> *BST<T>::InitBST(PracticeLinearList<T> linearList) {
    this->root_node = new BSTNode<T>(linearList.list[0]);
    auto * comparedNode = this->root_node;
    for (int i = 1; i < linearList.linear_list_length; ++i) {
        auto * copeNode = new BSTNode<T>(linearList.list[i]);
        bool locate = false;
        while(!locate){
            if(copeNode->data<comparedNode->data){
                if(comparedNode->left_child_node){
                    comparedNode = comparedNode->left_child_node;
                } else{
                    comparedNode->left_child_node = copeNode;
                    comparedNode = this->root_node;
                    locate = true;
                }
            } else{
                if(comparedNode->right_child_node){
                    comparedNode = comparedNode->right_child_node;
                } else{
                    comparedNode->right_child_node = copeNode;
                    comparedNode = this->root_node;
                    locate = true;
                }
            }
        }
    }
    return this;
}



#endif //STLLEARN_BST_H
