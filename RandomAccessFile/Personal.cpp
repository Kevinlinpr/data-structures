//
// Created by Kevinlinpr on 2019/6/11.
//

#include <iostream>
#include "Personal.h"

Personal::Personal() : cityLen(10), nameLen(10) {
    name = new char[nameLen+1];
    city = new char[cityLen+1];
}

Personal::Personal(char *ssn, char *n, char *c, int y, long s) : cityLen(10), nameLen(10) {
    name = new char[nameLen+1];
    city = new char[cityLen+1];
    strcpy(SSN,ssn);
    strcpy(name,n);
    strcpy(city,c);
    year = y;
    salary = s;
}

void Personal::writeToFile(std::fstream & out) const {
    out.write(SSN,9);
    out.write(name,nameLen);
    out.write(city,cityLen);
    out.write(reinterpret_cast<const char*>(&year), sizeof(int));
    out.write(reinterpret_cast<const char*>(&salary), sizeof(int));
}

void Personal::readFromFile(std::fstream & in) {
    in.read(SSN,9);
    in.read(name,nameLen);
    in.read(city,cityLen);
    in.read(reinterpret_cast<char *>(&year), sizeof(int));
    in.read(reinterpret_cast<char *>(&salary), sizeof(int));
}

void Personal::readKey() {
    char s[80];
    std::cout<<"Enter SSN: ";
    std::cin.getline(s,80);
    strncpy(SSN,s,9);
}

std::ostream &Personal::writeLegibly(std::ostream & out) {
    SSN[9] = name[nameLen] = city[cityLen] = '\0';
    out<<"SSN = "<<SSN<<", name = "<<name
    <<", city = "<<city<<", year = "<<year
    <<", salary = "<<salary;
    return out;
}

std::istream &Personal::readFromConsole(std::istream &in) {
    char s[80];
    std::cout<<"SSN: ";
    in.getline(s,80);
    strncpy(SSN,s,9);
    std::cout<<"Name: ";
    in.getline(s,80);
    strncpy(name, s, (size_t) nameLen);
    std::cout<<"City: ";
    in.getline(s,80);
    strncpy(city, s, (size_t) cityLen);
    std::cout<<"Birthyear: ";
    in>>year;
    std::cout<<"Salary: ";
    in>>salary;
    in.ignore();
    return in;
}




