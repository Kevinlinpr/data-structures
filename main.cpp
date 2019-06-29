#include <iostream>
#include <cstring>

class Clone{
public:
    Clone(char* _name,int _id,float _hei,float _wei,int _age){
        auto len = std::strlen(_name);
        name = new char[len+1];
        std::strcpy(name,_name);
        identity = _id;
        height = _hei;
        weight = _wei;
        age = _age;
        ++population;
    }
    Clone(const Clone& clone){
        auto len = std::strlen(clone.name);
        name = new char[len+1];
        std::strcpy(name,clone.name);
        identity = clone.identity;
        height = clone.height;
        weight = clone.weight;
        age = clone.age;
        ++population;
    }
    Clone&operator=(const Clone& clone){
        delete [] name;
        auto len = std::strlen(clone.name);
        name = new char[len+1];
        std::strcpy(name,clone.name);
        identity = clone.identity;
        height = clone.height;
        weight = clone.weight;
        age = clone.age;
        return *this;
    }
    ~Clone(){
        delete [] name;
        --population;
    }
    char* name;
    int identity;
    float height;
    float weight;
    int age;
    static int population;
};
void PrintA(Clone clone){
    std::cout<<"PrintA clone.name: "<<clone.name<<std::endl;
    std::cout<<"PrintA Clone::population: "<<Clone::population<<std::endl;
}
void PrintB(const Clone& clone){
    std::cout<<"PrintB clone.name: "<<clone.name<<std::endl;
    std::cout<<"PrintB Clone::population: "<<Clone::population<<std::endl;
}
int Clone::population = 0;
int main(){
    Clone clone1(const_cast<char *>("chen"), 1, 175, 135, 19);
    Clone clone2(clone1);
    std::strcpy(clone2.name,"qiqi");
    Clone clone3(clone2);
    clone3 = clone1;
    PrintA(clone1);
    std::cout<<"main Clone::population: "<<Clone::population<<std::endl;
    PrintB(clone1);
    std::cout<<"main Clone::population: "<<Clone::population<<std::endl;
}