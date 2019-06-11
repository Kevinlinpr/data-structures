//
// Created by Kevinlinpr on 2019/6/11.
//

#ifndef STLLEARN_DATABASE_H
#define STLLEARN_DATABASE_H

#include <fstream>

template <class T>
class Database {
public:
    Database();
    void run();

private:
    std::fstream database;
    char fName[20];
    std::ostream& print(std::ostream&);
    void add(T&);
    bool find(const T&);
    void modify(const T&);
    friend std::ostream&operator<<(std::ostream& out,Database& db){
        return db.print(out);
    }
};


#endif //STLLEARN_DATABASE_H
