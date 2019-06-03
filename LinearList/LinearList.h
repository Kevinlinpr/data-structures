//
// Created by Kevinlinpr on 2019/6/1.
//

#ifndef STLLEARN_LINEARLIST_H
#define STLLEARN_LINEARLIST_H

#include <iostream>
const int MAXSIZE = 100;
template <class DataType>
class LinearList {
public:
    LinearList() = default;   //初始化线性表
    ~LinearList() = default;    //析构线性表
    LinearList(DataType data[],int length); //带参数初始化线性表
    inline int Length(){ return linear_list_length;}    //线性表长度
    int LocateElem(DataType value);  //按值查找线性表数据元素，返回序列号下标
    DataType GetElem(int elem);  //按序列号下标查找线性表数据元素，返回值
    void ListInsert(int elem,DataType value); //插入数据元素
    DataType ListDelete(int elem); //删除数据元素，返回操作结果bool
    void PrintList();   //打印线性表
    static void PrintList(LinearList<DataType> list);
    constexpr bool ListEmpty(){ return linear_list_length==0;}   //线性表是否为空
    DataType list[MAXSIZE];
    int linear_list_length = 0;
};

template<class DataType>
LinearList<DataType>::LinearList(DataType *data, int length) {
    if(length>MAXSIZE)
        throw "wrong parameter";
    for (int i = 0; i < length; ++i) {
        list[i] = data[i];
    }
    linear_list_length = length;
}

template<class DataType>
DataType LinearList<DataType>::GetElem(int elem) {
    if(elem<1||elem>linear_list_length)
        throw "wrong location";
    else
        return list[elem-1];
}

template<class DataType>
int LinearList<DataType>::LocateElem(DataType value) {
    for (int i = 0; i < linear_list_length; ++i) {
        if(value==list[i])
            return i+1;
    }
    return 0;
}

template<class DataType>
void LinearList<DataType>::ListInsert(int elem, DataType value) {
    if(linear_list_length>=MAXSIZE)
        throw "Overflow";
    if(elem<1||elem>linear_list_length+1)
        throw "Wrong Location";
    for (int i = linear_list_length; i >= elem ; --i) {
        list[i] = list[i-1];
    }
    list[elem-1] = value;
    linear_list_length++;
}

template<class DataType>
DataType LinearList<DataType>::ListDelete(int elem) {
    DataType delete_value;
    if(linear_list_length<=0)
        throw "Underflow";
    if(elem<1||elem>linear_list_length)
        throw "Wrong Location";
    delete_value = list[elem-1];
    for (int i = elem; i < linear_list_length; ++i) {
        list[i-1] = list[i];
    }
    linear_list_length--;
    return delete_value;
}

template<class DataType>
void LinearList<DataType>::PrintList() {
    for (int i = 0; i < linear_list_length; ++i) {
        std::cout<<"INDEX: "<<i<<" VALUE: "<<list[i]<<std::endl;
    }
}

template<class DataType>
void LinearList<DataType>::PrintList(LinearList<DataType> list) {
    for (int i = 0; i < list.linear_list_length; ++i) {
        std::cout<<"INDEX: "<<i<<" VALUE: "<<list.list[i]<<std::endl;
    }
}

#endif //STLLEARN_LINEARLIST_H
