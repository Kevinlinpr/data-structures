//
// Created by Kevinlinpr on 13/6/19.
//

#ifndef STLLEARN_BST_H
#define STLLEARN_BST_H

#include "../LinearList/PracticeLinearList.h"
#include "../Queue/LinkQueue.h"
#include <queue>
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
    BSTNode<T>* SearchBST(const T& value);
    static void PrintNodeInfo(BSTNode<T>* node);
    void DepthFirstPrint() const;
private:
    BSTNode<T>* root_node;
};

template<class T>
BST<T>::BST() {
    this->root_node = nullptr;
}

/// 二叉搜索树构造
//int data[5] = {11,1,24,2,32};
//PracticeLinearList<int> practiceLinearList(data,5);
//BST<int> bst;
//bst.InitBST(practiceLinearList);
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

/// 二叉搜索树查询
//int data[16] = {11,1,24,2,32,90,58,34,22,13,99,47,12,13,5,8};
//PracticeLinearList<int> practiceLinearList(data,16);
//BST<int> bst;
//bst.InitBST(practiceLinearList);
//auto result = bst.SearchBST(12);
/// \tparam T
/// \param value
/// \return
template<class T>
BSTNode<T> *BST<T>::SearchBST(const T &value) {
    BSTNode<T>* copeNode = this->root_node;
    while(copeNode){
        if(value<copeNode->data){
            copeNode = copeNode->left_child_node;
        } else{
            if(value == copeNode->data){
                std::cout<<"FIND VALUE IN THIS BST."<<std::endl;
                return copeNode;
            } else{
                copeNode = copeNode->right_child_node;
            }
        }
    }
    std::cout<<"NO VALUE IN THIS BST."<<std::endl;
    return nullptr;
}

/// 打印树节点
//int data[16] = {11,1,24,2,32,90,58,34,22,13,99,47,12,13,5,8};
//PracticeLinearList<int> practiceLinearList(data,16);
//BST<int> bst;
//bst.InitBST(practiceLinearList);
//auto result = bst.SearchBST(12);
//if(result){
//BST<typeof(result->data)>::PrintNodeInfo(result);
//}
/// \tparam T
/// \param node
template<class T>
void BST<T>::PrintNodeInfo(BSTNode<T> *node) {
    std::cout<<"=== START PRINT BST NODE ==="<<std::endl;
    std::cout<<"THIS NODE VALUE: "<<node->data<<std::endl;
    if(node->left_child_node)
        std::cout<<"LEFT CHILD VALUE: "<<node->left_child_node->data<<std::endl;
    else
        std::cout<<"LEFT CHILD VALUE: "<<"NULL"<<std::endl;
    if(node->left_child_node)
        std::cout<<"RIGHT CHILD VALUE: "<<node->right_child_node->data<<std::endl;
    else
        std::cout<<"RIGHT CHILD VALUE: "<<"NULL"<<std::endl;
    std::cout<<"=== END PRINT BST NODE ==="<<std::endl;
}

/// 深度优先遍历，从上到下，从左到右
//int data[16] = {11,1,24,2,32,90,58,34,22,13,99,47,12,13,5,8};
//PracticeLinearList<int> practiceLinearList(data,16);
//BST<int> bst;
//bst.InitBST(practiceLinearList);
//bst.DepthFirstPrint();
/// \tparam T
template<class T>
void BST<T>::DepthFirstPrint() const {
    std::cout<<"=== START DEPTH FIRST PRINT ==="<<std::endl;
    std::queue<BSTNode<T>*> waiteQueue;
    waiteQueue.push(this->root_node);
    while(!waiteQueue.empty()){
        BSTNode<T>* copeNode = nullptr;
        copeNode = waiteQueue.front();
        waiteQueue.pop();
        if(copeNode->left_child_node)
            waiteQueue.push(copeNode->left_child_node);
        if(copeNode->right_child_node)
            waiteQueue.push(copeNode->right_child_node);
        std::cout<<copeNode->data<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"=== END DEPTH FIRST PRINT ==="<<std::endl;
}


#endif //STLLEARN_BST_H
