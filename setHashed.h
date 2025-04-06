#ifndef SETHASHED_H
#define SETHASHED_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>

class setHashed{
private:
    std::vector<std::list<int>> table;
    size_t size;
    int hash(int key){
        return key % size;
    }

public:
    explicit setHashed(size_t rozmiar_tablicy) : size(rozmiar_tablicy){
        table.resize(size);
    }

    void insert(int value){
        int index = hash(value);

        for(const auto &element : table[index]){
            if(element == value){
                return;
            }
        }
        table[index].push_back(value);

    }
    void contains(std::pair<int, int>);
    void removing(std::pair<int, int>);

    setHashed operator+(const setHashed& other);
    setHashed operator-(const setHashed& other);
    setHashed operator&(const setHashed& other);


};



#endif