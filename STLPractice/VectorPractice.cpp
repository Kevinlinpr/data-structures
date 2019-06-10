//
// Created by Kevinlinpr on 2019/6/10.
//

#include "VectorPractice.h"

void VectorPractice::aboutAssign() {
    std::vector<int> vec1{10, 20, 30, 40, 50,};
    std::vector<int> vec2;
    vec2.assign(vec1.begin() + 2, vec1.end() - 1);
    vec2.assign(5,100);
    std::cout<<"Assign Finished."<<std::endl;
}

void VectorPractice::aboutAt() {
    std::vector<int> vec{10,20,30,40,50};
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(static_cast<unsigned long long int>(i)) << std::endl;
    }
}

void VectorPractice::aboutBack() {
    std::vector<int> vec{10,20,30,40,50};
    std::cout<<"The last elem value: "<<vec.back()<<std::endl;
}

void VectorPractice::aboutIterator() {
    std::vector<int> vec1{10, 20, 30, 40, 50};
    std::vector<int> vec2;
    vec2.assign(vec1.begin() + 2, vec1.end() - 1);
}

void VectorPractice::aboutCapacity() {
    std::vector<int> vec1;
    std::cout<<"amount can be save in vec1: "<<vec1.capacity()<<std::endl;
    std::vector<int> vec2{10, 20, 30, 40, 50};
    std::cout<<"amount can be save in vec2: "<<vec2.capacity()<<std::endl;
}

void VectorPractice::aboutClear() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::cout<<"amount can be save in vec: "<<vec.capacity()<<std::endl;
    vec.clear();
    std::cout<<"AFTER clear ,amount can be save in vec: "<<vec.capacity()<<std::endl;
    std::cout<<"But there are no values anymore."<<std::endl;
}

void VectorPractice::aboutErase() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    vec.erase(vec.begin()+3);
    vec.erase(vec.begin()+1,vec.end()-1);
    std::cout<<"erase finished."<<std::endl;
}

void VectorPractice::aboutFront() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::cout<<"First elem value: "<<vec.front()<<std::endl;
}

void VectorPractice::aboutInsert() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    vec.insert(vec.begin()+1,100);
    vec.insert(vec.begin()+2,5,200);
    std::vector<int> vec2{333,123,543,234,222};
    vec.insert(vec.end()-2,vec2.begin()+1,vec2.end()-2);
    std::cout<<"end insert"<<std::endl;
}

void VectorPractice::aboutMaxSize() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::cout<<"MaxSize: "<<vec.max_size()<<std::endl;
}

void VectorPractice::aboutOperator() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    int INDEX = 2;
    std::cout<<"Index "<<INDEX<<" VALUE:"<<vec.operator[]((unsigned long long int)INDEX)<<std::endl;
}

void VectorPractice::aboutPopback() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::cout<<"before pop:"<<std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout<<vec.at((unsigned long long int)i)<<std::endl;
    }
    vec.pop_back();
    std::cout<<"after pop:"<<std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout<<vec.at((unsigned long long int)i)<<std::endl;
    }
}

void VectorPractice::aboutPushback() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::cout<<"before push:"<<std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout<<vec.at((unsigned long long int)i)<<std::endl;
    }
    vec.push_back(23);
    std::cout<<"after push:"<<std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout<<vec.at((unsigned long long int)i)<<std::endl;
    }
}

void VectorPractice::aboutRIterator() {
    std::cout<<"Have problem."<<std::endl;
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::cout<<(vec.rbegin()+2).operator[](0)<<std::endl;
    std::cout<<(vec.rend()+1).operator[](1)<<std::endl;
}

void VectorPractice::aboutReserve() {
    std::cout<<"Have problem."<<std::endl;
    std::vector<int> vec{10, 20, 30, 40, 50};
    vec.reserve(2);
    std::cout<<"reserved."<<std::endl;
}

void VectorPractice::aboutResize() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    vec.resize(10);
    vec.resize(8,20);
    vec.resize(12,20);
    std::cout<<"finish resize."<<std::endl;
}

void VectorPractice::aboutSize() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::cout<<"Now Size:"<<vec.size()<<std::endl;
}

void VectorPractice::aboutSwap() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::vector<int> vec2{33,22,412,2};
    vec2.swap(vec);
    std::cout<<"finish swap."<<std::endl;
}

void VectorPractice::aboutConstructor() {
    std::vector<int> vec{10, 20, 30, 40, 50};
    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> vec3(5,100);
    std::vector<int> vec4(vec.begin()+1,vec.end()-2);
    std::vector<int> vec5(vec4);
    std::cout<<"end initialization."<<std::endl;
}
