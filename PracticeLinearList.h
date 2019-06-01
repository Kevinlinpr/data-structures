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

};

/// 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值。空出的位置由最后一个元素填补，
/// 若顺序表为空则现实出错信息并退出运行
//测试代码
//int a[8]={1223,2923,30,564,699,998,222,110};
//PracticeLinearList<int> practiceLinearList(a,8);
//std::cout<<practiceLinearList.DeleteMinValue()<<std::endl;
//practiceLinearList.PrintList();
/// \tparam DataType 线性表数据类型
/// \return 返回被删除的值，若删除失败返回0
template<typename DataType>
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


#endif //STLLEARN_PRACTICELINEARLIST_H
