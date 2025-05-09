#include "HashTable.hpp"
#include <iostream>
using namespace std;

HashTable::HashTable(int size)
{
    tableSize = size;
    table = new HashEntry *[tableSize];
    for (int i = 0; i < tableSize; ++i)
        table[i] = nullptr;
}

HashTable::~HashTable()
{
    for (int i = 0; i < tableSize; ++i)
    {
        HashEntry *current = table[i];
        while (current != nullptr)
        {
            HashEntry *toDelete = current;
            current = current->getNext();
            delete toDelete;
        }
    }
    delete[] table;
}

int HashTable::hashFunction(int id)
{
    return id % tableSize;
}

void HashTable::insert(int id, string title, string category)
{
    int index = hashFunction(id);

    // Önce: ID daha önce eklenmiş mi?
    HashEntry *current = table[index];
    while (current != nullptr)
    {
        if (current->getId() == id)
        {
            return; // zaten varsa tekrar ekleme
        }
        current = current->getNext();
    }

    // Yeni giriş oluştur
    HashEntry *newEntry = new HashEntry(id, title, category);

    // Liste başı boşsa doğrudan yerleştir
    if (table[index] == nullptr)
    {
        table[index] = newEntry;
    }
    else
    {
        // Sona ekleme yap (zincirin ucuna)
        HashEntry *temp = table[index];
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(newEntry);
    }
}

void HashTable::rateBook(int id, int rating)
{
    int index = hashFunction(id);
    HashEntry *current = table[index];

    while (current != nullptr)
    {
        if (current->getId() == id)
        {
            current->setRating(rating);
            cout << "Kitap puanlandi." << endl;
            return;
        }
        current = current->getNext();
    }

    cout << "Kitap bulunamadi." << endl;
}

void HashTable::listRatedBooks()
{
    for (int i = 0; i < tableSize; ++i)
    {
        HashEntry *current = table[i];
        while (current != nullptr)
        {
            if (current->getRating() >= 0)
                cout << "ID: " << current->getId() << ", Title: " << current->getTitle() << ", Rating: " << current->getRating() << endl;
            current = current->getNext();
        }
    }
}

void HashTable::listHighRatedBooks()
{
    for (int i = 0; i < tableSize; ++i)
    {
        HashEntry *current = table[i];
        while (current != nullptr)
        {
            if (current->getRating() >= 4)
                cout << "ID: " << current->getId() << ", Title: " << current->getTitle() << ", Rating: " << current->getRating() << endl;
            current = current->getNext();
        }
    }
}

void HashTable::recommendByCategory(string category)
{
    cout << "\n--- '" << category << "' kategorisindeki kitaplar ---\n";
    for (int i = 0; i < tableSize; ++i)
    {
        HashEntry *current = table[i];
        while (current != nullptr)
        {
            if (current->getCategory() == category)
                cout << "ID: " << current->getId() << ", Title: " << current->getTitle() << endl;
            current = current->getNext();
        }
    }
}
