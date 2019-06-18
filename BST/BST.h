//
// Created by Kevinlinpr on 13/6/19.
//

#ifndef STLLEARN_BST_H
#define STLLEARN_BST_H

#include "../LinearList/PracticeLinearList.h"
#include <queue>
#include <stack>

template <class T>
class BSTNode{
public:
    explicit BSTNode(T value);
    T data;
    BSTNode<T>* left_child_node;
    BSTNode<T>* right_child_node;
    bool operator==(BSTNode<T>* bstNode);
    bool operator!=(BSTNode<T>* bstNode);
    bool operator>(BSTNode<T>* bstNode);
};

template<class T>
BSTNode<T>::BSTNode(T value) {
    this->data = value;
    this->left_child_node = nullptr;
    this->right_child_node = nullptr;
}

template<class T>
bool BSTNode<T>::operator==(BSTNode<T> *bstNode) {
    if(bstNode == nullptr)
        return false;
    return this->data == bstNode->data
           &&this->left_child_node == bstNode->left_child_node
           &&this->right_child_node == bstNode->right_child_node;
}

template<class T>
bool BSTNode<T>::operator!=(BSTNode<T> *bstNode) {
    if(bstNode == nullptr)
        return false;
    return this->data != bstNode->data
           ||this->left_child_node != bstNode->left_child_node
           ||this->right_child_node != bstNode->right_child_node;
}

template<class T>
bool BSTNode<T>::operator>(BSTNode<T> *bstNode) {
    if(bstNode == nullptr)
        return true;
    return this->data>bstNode->data;
}


template <class T>
class BST {
public:
    BST();
    BST<T>* InitBST(PracticeLinearList<T> linearList);
    BSTNode<T>* SearchBST(const T& value);
    static void PrintNodeInfo(BSTNode<T>* node);
    void DepthFirstPrint() const;
    void PreOrderPrint() const;
    void InOrderPrint() const;
    void PostOrderPrint() const;
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

/// 广度优先遍历，从上到下，从左到右
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
    std::cout<<"=== END DEPTH FIRST PRINT ==="<<std::endl<<std::endl;
}

/// 前序遍历（栈实现）
//int data[16] = {11,1,24,2,32,90,58,34,22,13,99,47,12,13,5,8};
//PracticeLinearList<int> practiceLinearList(data,16);
//BST<int> bst;
//bst.InitBST(practiceLinearList);
//bst.PreOrderPrint();
/// \tparam T
template<class T>
void BST<T>::PreOrderPrint() const {
    std::stack<BSTNode<T>*> adjustStack;
    if(this->root_node)
        adjustStack.push(this->root_node);
    if(adjustStack.size()<=0){
        std::cout<<"PLEASE CHECK IF THIS IS A BST"<<std::endl;
        return;
    }
    std::cout<<"=== START PRE ORDER PRINT ==="<<std::endl;
    while(!adjustStack.empty()){
        //解压节点
        //按照VLR（NLR）的逆序进栈，（右节点）-》（左节点）-》（父节点），因为栈的特点LIFO
        BSTNode<T>* fatherNode = adjustStack.top();
        adjustStack.pop();
        BSTNode<T>* rightNode = fatherNode->right_child_node;
        BSTNode<T>* leftNode = fatherNode->left_child_node;
        //右节点无条件进栈
        if(rightNode)
            adjustStack.push(rightNode);
        //左节点无条件进栈
        if(leftNode)
            adjustStack.push(leftNode);
        //父节点无条件进栈
        adjustStack.push(fatherNode);
        //若栈顶等于解压节点，打印出栈
        BSTNode<T>* topNodeAfterDecompression = adjustStack.top();
        if(topNodeAfterDecompression->operator==(fatherNode)){
            std::cout<<topNodeAfterDecompression->data<<" ";
            adjustStack.pop();
        }
    }
    std::cout<<std::endl;
    std::cout<<"=== END PRE ORDER PRINT ==="<<std::endl<<std::endl;
}

/// 中序遍历（栈实现）
//int data[16] = {11,1,24,2,32,90,58,34,22,13,99,47,12,13,5,8};
//PracticeLinearList<int> practiceLinearList(data,16);
//BST<int> bst;
//bst.InitBST(practiceLinearList);
//bst.InOrderPrint();
/// \tparam T
template<class T>
void BST<T>::InOrderPrint() const {
    std::stack<BSTNode<T>*> adjustStack;
    if(this->root_node)
        adjustStack.push(this->root_node);
    if(adjustStack.size()<=0){
        std::cout<<"PLEASE CHECK IF THIS IS A BST"<<std::endl;
        return;
    }
    std::cout<<"=== START IN ORDER PRINT ==="<<std::endl;
    BSTNode<T>* historyPrintNode = nullptr;//历史打印节点
    while(!adjustStack.empty()){
        //解压节点，按照（右子节点）-》（父节点）-》（左子节点）的顺序进行放入，因为栈是LIFO
        BSTNode<T>* fatherNode = adjustStack.top();
        adjustStack.pop();
        BSTNode<T>* leftNode = fatherNode->left_child_node;
        BSTNode<T>* rightNode = fatherNode->right_child_node;
        //当栈顶元素与右子节点不等时，加入右子节点
        if(adjustStack.empty()){
          if(rightNode)
              adjustStack.push(rightNode);
        } else{
            BSTNode<T>* topNode = adjustStack.top();
            if(rightNode&&topNode->operator!=(rightNode))
                adjustStack.push(rightNode);
        }
        //加入父节点
        adjustStack.push(fatherNode);
        //当左节点数值大于历史打印节点数值时，加入左节点
        if(leftNode&&leftNode->operator>(historyPrintNode))
            adjustStack.push(leftNode);
        //当栈顶元素等于父节点，打印并更新历史打印节点
        BSTNode<T>* topNodeAfterDecompression = adjustStack.top();
        if(topNodeAfterDecompression->operator==(fatherNode)){
            std::cout<<topNodeAfterDecompression->data<<" ";
            historyPrintNode = topNodeAfterDecompression;
            adjustStack.pop();
        }
    }
    std::cout<<std::endl;
    std::cout<<"=== END IN ORDER PRINT ==="<<std::endl<<std::endl;
}

/// 后序遍历（栈实现）
//int data[16] = {11,1,24,2,32,90,58,34,22,13,99,47,12,13,5,8};
//PracticeLinearList<int> practiceLinearList(data,16);
//BST<int> bst;
//bst.InitBST(practiceLinearList);
//bst.PostOrderPrint();
/// \tparam T
template<class T>
void BST<T>::PostOrderPrint() const {
    std::stack<BSTNode<T>*> adjustStack;
    if(this->root_node)
        adjustStack.push(this->root_node);
    if(adjustStack.size()<=0){
        std::cout<<"PLEASE CHECK IF THIS IS A BST"<<std::endl;
        return;
    }
    std::cout<<"=== START POST ORDER PRINT ==="<<std::endl;
    BSTNode<T>* historyHighestPrintNode = nullptr;//历史最高值打印节点
    while(!adjustStack.empty()){
        //解压栈顶节点
        //根据栈的LIFO的原则，按照反序的LRV（LRN）进行进栈，（父节点）-》（右节点）-》（左节点）进栈
        BSTNode<T>* fatherNode = adjustStack.top();
        adjustStack.pop();
        BSTNode<T>* rightNode = fatherNode->right_child_node;
        BSTNode<T>* leftNode = fatherNode->left_child_node;
        //父节点无条件进栈
        adjustStack.push(fatherNode);
        //右节点大于historyHighestPrintNode时进栈
        if(rightNode&&rightNode->operator>(historyHighestPrintNode))
            adjustStack.push(rightNode);
        //左节点大于historyHighestPrintNode时进栈
        if(leftNode&&leftNode->operator>(historyHighestPrintNode))
            adjustStack.push(leftNode);
        //当栈顶元素等于父节点时，打印出栈并跟新historyHighestPrintNode
        BSTNode<T>* topNodeAfterDecompression = adjustStack.top();
        if(topNodeAfterDecompression->operator==(fatherNode)){
            std::cout<<topNodeAfterDecompression->data<<" ";
            if(topNodeAfterDecompression->operator>(historyHighestPrintNode))
                historyHighestPrintNode = topNodeAfterDecompression;
            adjustStack.pop();
        }
    }
    std::cout<<std::endl;
    std::cout<<"=== END POST ORDER PRINT ==="<<std::endl<<std::endl;
}


#endif //STLLEARN_BST_H
