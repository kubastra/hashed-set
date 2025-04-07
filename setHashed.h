#ifndef SETHASHED_H
#define SETHASHED_H

#include <iostream>
#include <vector>
#include <list>

class setHashed{
private:
    std::vector<std::list<int>> table;
    size_t size;
    
    int hash(int key) const{
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

    bool contains(int value) const {
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

    setHashed operator+(const setHashed& other){
        setHashed nowy(this->size);

        for(const auto &bucket : this->table){
            for(int elem : bucket){
                nowy.insert(elem);
            }
        }

        for(const auto &bucket : other.table){
            for(int elem : bucket){
                nowy.insert(elem);
            }
        }

        return nowy;
    }


    setHashed operator-(const setHashed &other){
        setHashed nowy(this -> size);

        for(const auto &bucket : this->table){
            for(int elem : bucket){
                if(!other.contains(elem)) nowy.insert(elem);
            }
        }
        return nowy;
    }

    setHashed operator&(const setHashed& other){
        setHashed nowy(this->size);

        for(const auto &bucket : this->table){
            for(int elem : bucket){
                if(other.contains(elem)) nowy.insert(elem);
            }
        }
        return nowy;
    }

    bool operator==(const setHashed& other) const {
        for(const auto &bucket : this->table){
            for(int elem : bucket){
                if(!other.contains(elem)) return false;
            }
        }
        return true;
    }


};

#endif
