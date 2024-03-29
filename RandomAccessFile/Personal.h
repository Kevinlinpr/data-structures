//
// Created by Kevinlinpr on 2019/6/11.
//

#ifndef STLLEARN_PERSONAL_H
#define STLLEARN_PERSONAL_H

#include <fstream>
#include <string.h>
class Personal {
public:
    Personal();
    Personal(char*,char*,char*,int,long);
    void writeToFile(std::fstream&) const;
    void readFromFile(std::fstream&);
    void readKey();
    int size() const {
        return 9+nameLen+cityLen+ sizeof(year)+ sizeof(salary);
    }
    bool operator==(const Personal& pr) const{
        return strcmp(pr.SSN,SSN) == 0;
    }

protected:
    const int nameLen,cityLen;
    char SSN[10],*name,*city;
    int year;
    long salary;
    std::ostream& writeLegibly(std::ostream&);
    friend std::ostream&operator<<(std::ostream& out,Personal& pr){
        return pr.writeLegibly(out);
    }
    std::istream& readFromConsole(std::istream&);
    friend std::istream&operator>>(std::istream& in,Personal& pr){
        return pr.readFromConsole(in);
    }
};


#endif //STLLEARN_PERSONAL_H
