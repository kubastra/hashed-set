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

    bool contains(int value){
        int index = hash(value);

        for(auto const &element : table[index]){
            if(element == value) return true;
        }
        return false;
    }

    void removing(int value){
        int index = hash(value);

        auto &bucket = table[index];
        for(auto it = bucket.begin(); it != bucket.end(); it++){
            if(*it == value) bucket.erase(it);
            return;
        }
    }

    setHashed operator+(const setHashed& other);
    setHashed operator-(const setHashed& other);
    setHashed operator&(const setHashed& other);


};



#endif