#ifndef HashEntry_hpp
#define HashEntry_hpp

#include <string>
#include <iostream>
using namespace std;
//Her bir giriş bir ödünç alınan kitabı temsil edecek.
// aslinda bizim dugum sinifimiz gibi dusunebiliriz.
// biz acik adresleme ile yapiyoruz

// Her HashEntry nesnesi bir kitabı temsil eder ve aynı hash index’ine denk 
// gelen diğer kitaplarla zincirleme (linked list) şeklinde bağlanır.

class HashEntry
{
private:
    int bookId;
    string title;
    string category;
    int rating; // 1–5 arası kullanıcı puanı

    HashEntry *next;

public:
    HashEntry(int id, string t, string c, int r = -1);

    int getId();
    string getTitle();
    string getCategory();
    int getRating();

    void setRating(int r);
    HashEntry *getNext();
    void setNext(HashEntry *n);
};

#endif