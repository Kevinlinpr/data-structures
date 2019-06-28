#include <iostream>
#include <cstring>

class Person{
public:
    Person(char* name,int age){
        auto len = strlen(name);
        this->name = new char[len+1];
        std::strcpy(this->name,name);
        this->age = age;
        ++amount;
    }
    ~Person(){
        delete [] this->name;
    }
    char* name;
    int age;
    static int amount;
};

int Person::amount = 0;

int main(){
    char name[] = "chen";
    Person person(name,10);
    std::cout<<person.name<<":"<<person.age<<":"<< Person::amount<<std::endl;
}