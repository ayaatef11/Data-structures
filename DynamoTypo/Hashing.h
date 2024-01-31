
#pragma once
#include <vector>
#include <iostream>
using namespace std;
template<typename T>
class HashTable {
    static const int table_size = 10;
    vector<vector<T>> hash_table;
    int size;
    const unsigned int z = 2654435769;
    const int w = 32;
    const int d = 10;

public:
  
    HashTable();

    int hash(int id);

    bool insert(int id,T key);

    T remove(int id);

    T find(int id);

    size_t getSize() const;

    void printTable();

    void printItemsInIndex(int index);

    bool contains(int id);

    bool operator==(const HashTable<T>& other) const;

    bool operator!=(const HashTable<T>& other) const;
};

