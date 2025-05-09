#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "HashEntry.hpp"

class HashTable {
private:
    int tableSize;
    HashEntry** table;

    int hashFunction(int id);

public:
    HashTable(int size = 10);
    ~HashTable();

    void insert(int id, string title, string category);
    void rateBook(int id, int rating);
    void listRatedBooks();
    void listHighRatedBooks();
    void recommendByCategory(string category);
};

#endif
