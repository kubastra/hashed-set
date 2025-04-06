#ifndef SETHASHED_H
#define SETHASHED_H

#include <iostream>
#include <vector>
#include <list>

class setHashed{
private:
    std::vector<std::list<std::pair<int, int>>> table;
    size_t size;
    int hash(int key){
        return key % table.size();
    }
public:
    setHashed(){}
    setHashed(std::vector<std::list<std::pair<int, int>>>);

    void insert(std::pair<int, int>){
        int index = hash(table.size());
        if(table[index].empty()){
            table[index].push_back(std::pair<int, int>());
        }else{

        }
    }
    void contain(std::pair<int, int>);
    void removing(std::pair<int, int>);

    setHashed operator+(const setHashed& other);
    setHashed operator-(const setHashed& other);
    setHashed operator&(const setHashed& other);


};



#endif