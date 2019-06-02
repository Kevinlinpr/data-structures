//
// Created by Kevinlinpr on 1/6/19.
//

#ifndef STLLEARN_PRACTICELINEARLIST_H
#define STLLEARN_PRACTICELINEARLIST_H

#include "LinearList.h"
template <typename DataType>
class PracticeLinearList : public LinearList<DataType> {
public:
    PracticeLinearList(DataType data[],int length):LinearList<DataType>(data,length){};
    DataType DeleteMinValue();
    void Reverse();
    void DeleteTargetValue(DataType target);

};

/// 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值。空出的位置由最后一个元素填补，
/// 若顺序表为空则现实出错信息并退出运行
//测试代码
//int a[8]={1223,2923,30,564,699,998,222,110};
//PracticeLinearList<int> practiceLinearList(a,8);
//std::cout<<practiceLinearList.DeleteMinValue()<<std::endl;
//practiceLinearList.PrintList();
/// \tparam DataType 线性表数据类型
/// \return 返回被删除的值
template <typename DataType>
DataType PracticeLinearList<DataType>::DeleteMinValue() {
    if(this->linear_list_length<=0)
        throw "Underflow";
    int minValueIndex = 0;
    DataType minValue = this->list[minValueIndex];
    for (int i = 0; i < this->linear_list_length; ++i) {
        if(this->list[i]<=minValue){
            minValue = this->list[i];
            minValueIndex = i;
        }
    }
    this->list[minValueIndex] = this->list[this->linear_list_length-1];
    return minValue;
}


/// 设计一个高效的算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O(1)
//int a[6]={122,29,30,564,699,998};
//PracticeLinearList<int> practiceLinearList(a,6);
//practiceLinearList.Reverse();
//practiceLinearList.PrintList();
/// \tparam DataType
template<typename DataType>
void PracticeLinearList<DataType>::Reverse() {
    for (int i = 0; i < this->linear_list_length / 2; ++i) {
        DataType tmp = this->list[(this->linear_list_length - 1) - i];
        this->list[(this->linear_list_length - 1) - i] = this->list[i];
        this->list[i] = tmp;
    }
    std::cout<<"Reserved..."<<std::endl;
}


/// 长度为n的顺序表L，编写一个时间复杂度为o(n),空间复杂度为o(1)的算法，该算法删除线性表中所有值为x的数据元素
//int a[7]={122,29,30,564,699,998,699};
//PracticeLinearList<int> practiceLinearList(a,7);
//practiceLinearList.DeleteTargetValue(699);
//practiceLinearList.PrintList();
/// \tparam DataType 删除的数据元素
/// \param target
template<typename DataType>
void PracticeLinearList<DataType>::DeleteTargetValue(DataType target) {
    int not_target_amount = 0;
    for (int i = 0; i < this->linear_list_length; ++i) {
        if(this->list[i]!=target){
            this->list[not_target_amount] = this->list[i];
            ++not_target_amount;
        }
    }
    this->linear_list_length = not_target_amount;
}


#endif //STLLEARN_PRACTICELINEARLIST_H
