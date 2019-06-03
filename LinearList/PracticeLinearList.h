//
// Created by Kevinlinpr on 1/6/19.
//

#ifndef STLLEARN_PRACTICELINEARLIST_H
#define STLLEARN_PRACTICELINEARLIST_H

#include "LinearList.h"
template <class DataType>
class PracticeLinearList : public LinearList<DataType> {
public:
    PracticeLinearList(DataType data[],int length):LinearList<DataType>(data,length){};
    DataType DeleteMinValue();
    void Reverse();
    void Reverse(int firstIndex, int secondIndex);
    void DeleteTargetValue(DataType targetValue);
    void DeleteOrderedRangeValue(DataType lowerBoundValue,DataType upperBoundValue);
    void DeleteDisorderedRangeValue(DataType lowerBoundValue,DataType upperBoundValue);
    void DeleteOrderedRepeatValue();
    static PracticeLinearList<DataType>& MergeTwoOrderedLinearList(const PracticeLinearList<DataType>& listA,
            const PracticeLinearList<DataType>& listB,PracticeLinearList<DataType>& resultList);
    static void ExchangeMNList(PracticeLinearList<DataType>& list,int firstHalfAmount,int secondHalfAmount);
    static void SpeedFind(PracticeLinearList& list,DataType targetValue);

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
template <class DataType>
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
template<class DataType>
void PracticeLinearList<DataType>::Reverse() {
    for (int i = 0; i < this->linear_list_length / 2; ++i) {
        DataType tmp = this->list[(this->linear_list_length - 1) - i];
        this->list[(this->linear_list_length - 1) - i] = this->list[i];
        this->list[i] = tmp;
    }
}


/// 长度为n的顺序表L，编写一个时间复杂度为o(n),空间复杂度为o(1)的算法，该算法删除线性表中所有值为x的数据元素
//int a[7]={122,29,30,564,699,998,699};
//PracticeLinearList<int> practiceLinearList(a,7);
//practiceLinearList.DeleteTargetValue(699);
//practiceLinearList.PrintList();
/// \tparam DataType 删除的数据元素
/// \param target
template<class DataType>
void PracticeLinearList<DataType>::DeleteTargetValue(DataType targetValue) {
    int not_targetValue_amount = 0;
    for (int i = 0; i < this->linear_list_length; ++i) {
        if(this->list[i]!=targetValue){
            this->list[not_targetValue_amount] = this->list[i];
            ++not_targetValue_amount;
        }
    }
    this->linear_list_length = not_targetValue_amount;
}

/// 从有序顺序表中删除其值在给定s与t之间（要求s<t）的所有元素，如果s和t不合理或者顺序表为空则显示出错信息并退出运行
//int a[9]={12,29,30,564,699,998,1200,1300,2900};
//PracticeLinearList<int> practiceLinearList(a,9);
//practiceLinearList.DeleteOrderedRangeValue(28,999);
//practiceLinearList.PrintList();
/// \tparam DataType
/// \param lowerBoundValue
/// \param upperBoundValue
template<class DataType>
void PracticeLinearList<DataType>::DeleteOrderedRangeValue(DataType lowerBoundValue, DataType upperBoundValue) {
    if(this->linear_list_length<=0)
        throw "Underflow";
    if(lowerBoundValue>=upperBoundValue)
        throw "Wrong Bound";
    int upperNear_lowerBoundValue_index = 0;
    for (int i = 0; i < this->linear_list_length; ++i) {
        if(lowerBoundValue<this->list[i]){
            upperNear_lowerBoundValue_index = i;
            break;
        }
    }
    int remainAmount = this->linear_list_length - upperNear_lowerBoundValue_index;
    int moveAmount = 0;
    for (int j = upperNear_lowerBoundValue_index; j < this->linear_list_length; ++j) {
        if(upperBoundValue<=this->list[j]){
            this->list[upperNear_lowerBoundValue_index] = this->list[j];
            ++upperNear_lowerBoundValue_index;
            ++moveAmount;
        }
    }
    int deleteValue_amount = remainAmount - moveAmount;
    this->linear_list_length -= deleteValue_amount;
}
/// 从顺序表中删除其值在给定s与t之间（包含s和t，要求s<t）的所有元素，如果s和t不合理或者顺序表为空则显示出错信息并退出运行
//int a[7]={122,29,30,564,699,998,699};
//PracticeLinearList<int> practiceLinearList(a,7);
//practiceLinearList.DeleteRangeValue(33,1000);
//practiceLinearList.PrintList();
/// \tparam DataType
/// \param lowerBoundValue
/// \param upperBoundValue
template<class DataType>
void PracticeLinearList<DataType>::DeleteDisorderedRangeValue(DataType lowerBoundValue, DataType upperBoundValue) {
    if(this->linear_list_length<=0)
        throw "Underflow";
    if(lowerBoundValue>=upperBoundValue)
        throw "Wrong Bound";
    int not_rangeValue_amount = 0;
    for (int i = 0; i < this->linear_list_length; ++i) {
        if(this->list[i]<lowerBoundValue||upperBoundValue<this->list[i]){
            this->list[not_rangeValue_amount] = this->list[i];
            ++not_rangeValue_amount;
        }
    }
    this->linear_list_length = not_rangeValue_amount;
}

/// 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
/// \tparam DataType
template<class DataType>
void PracticeLinearList<DataType>::DeleteOrderedRepeatValue() {
    int i , j;
    for (i = 0 , j = 1; j < this->linear_list_length; ++j) {
        if(this->list[i]!=this->list[j])
            this->list[++i] = this->list[j];
    }
    this->linear_list_length = i + 1;
}

/// 将两个有序顺序表合并成一个新的有序顺序表，并由函数返回结果顺序表。
//int a[9]={12,29,30,30,998,998,1200,1200,2900};
//int b[6]={40,55,209,333,1000,3000};
//int c[15];
//PracticeLinearList<int> practiceLinearListA(a,9);
//PracticeLinearList<int> practiceLinearListB(b,6);
//PracticeLinearList<int> practiceLinearListC(c,15);
//PracticeLinearList<int>::PrintList(PracticeLinearList<int>::MergeTwoOrderedLinearList(practiceLinearListA,practiceLinearListB,practiceLinearListC));
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param listA
/// \param listB
/// \param resultList
/// \return
template<class DataType>
PracticeLinearList<DataType>&
PracticeLinearList<DataType>::MergeTwoOrderedLinearList(const PracticeLinearList<DataType> &listA,
                                                             const PracticeLinearList<DataType> &listB,
                                                             PracticeLinearList<DataType> &resultList) {
    int i = 0,j = 0,k = 0;
    while(i<listA.linear_list_length&&j<listB.linear_list_length){
        if(listA.list[i]<=listB.list[j]){
            resultList.list[k++] = listA.list[i++];
        } else{
            resultList.list[k++] = listB.list[j++];
        }
    }
    while(i<listA.linear_list_length){
        resultList.list[k++] = listA.list[i++];
    }
    while(j<listB.linear_list_length){
        resultList.list[k++] = listB.list[j++];
    }
    return resultList;
}


/// 换位一个顺序表中前后两个区间内的元素
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//PracticeLinearList<int>::ExchangeMNList(practiceLinearListA,5,4);
//practiceLinearListA.PrintList();
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param list
/// \param firstHalfAmount
/// \param secondHalfAmount
template<class DataType>
void PracticeLinearList<DataType>::ExchangeMNList(PracticeLinearList<DataType> &list, int firstHalfAmount,
                                                  int secondHalfAmount) {
    if(firstHalfAmount+secondHalfAmount>list.linear_list_length)
        throw "Wrong Size";
    list.Reverse(0,firstHalfAmount-1);
    list.Reverse(firstHalfAmount,firstHalfAmount+secondHalfAmount-1);
    list.Reverse();
}

/// 倒置顺序表区间内（包含边界）
//list.Reverse(0,firstHalfAmount-1);
//list.Reverse(firstHalfAmount,firstHalfAmount+secondHalfAmount-1);
/// \tparam DataType
/// \param firstIndex
/// \param secondIndex
template<class DataType>
void PracticeLinearList<DataType>::Reverse(int firstIndex, int secondIndex) {
    if((firstIndex>=secondIndex)
    ||firstIndex<0
    ||secondIndex>(this->linear_list_length-1))
        throw "Wrong index";
    for (int i = firstIndex; i < (secondIndex - firstIndex + 1) / 2 + firstIndex; ++i) {
        DataType tmp = this->list[secondIndex-i+firstIndex];
        this->list[secondIndex-i+firstIndex] = this->list[i];
        this->list[i] = tmp;
    }
}

/// 线性表中元素递增有序且按顺序存储于计算机内。要求设计一算法完成用最少时间在表中查找数值为x的元素，若找到将其与后继元素位置相交换，
/// 若找不到将其插入表中并使表元素仍递增有序。
//int a[9]={12,29,30,35,998,998,1200,1200,2900};
//PracticeLinearList<int> practiceLinearListA(a,9);
//practiceLinearListA.PrintList();
//PracticeLinearList<int>::SpeedFind(practiceLinearListA,30);
//practiceLinearListA.PrintList();
//std::cout<<"end"<<std::endl;
/// \tparam DataType
/// \param list
/// \param targetValue
template<class DataType>
void PracticeLinearList<DataType>::SpeedFind(PracticeLinearList& list, DataType targetValue) {
    std::cout<<"Speed Find"<<std::endl;
    int beginIndex = 0,endIndex = list.linear_list_length - 1,mid = 0;
    while(beginIndex<=endIndex){
        mid = (beginIndex+endIndex)/2;
        if(list.list[mid]==targetValue)
            break;
        else if(targetValue<list.list[mid])
            endIndex = mid - 1;
        else if(list.list[mid]<targetValue)
            beginIndex = mid + 1;

    }
    if(list.list[mid]==targetValue&&mid!=(list.linear_list_length-1)){
        DataType tmp = list.list[mid+1];
        list.list[mid+1] = list.list[mid];
        list.list[mid] = tmp;
    }

    if(endIndex<beginIndex){
        ++list.linear_list_length;
        int i;
        for (i = list.linear_list_length - 1; i > endIndex ; --i) {
            list.list[i+1] = list.list[i];
        }
        list.list[i+1] = targetValue;
    }
}


#endif //STLLEARN_PRACTICELINEARLIST_H
