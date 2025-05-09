// ödünc ve iade listeleyici,raporlayıcı
#ifndef PersonelLoadList_hpp
#define PersonelLoadList_hpp

#include "BookManager.hpp"
#include "LoadStack.hpp"

#include <string>
#include <ctime>

using namespace std;

// node yapisini gene structla kurucma git gitde kafam karismaya basladi ondna

struct Node
{
    int bookId;
    string bookTitle;
    time_t borrowTime;
    time_t returnTime;

    Node *next;

    Node(int id, const string &title, time_t borrowT, time_t returnT = 0);
};

class PersonelLoadList
{
private:
    Node* head;
    
public:
    PersonelLoadList(); 
    ~PersonelLoadList();

    void addLoan(int bookId,const string& bookTitle,time_t borrowTime);//odunc alinan kitaplari ekliyoruz
    void addReturn(int bookId,const string& bookTitle,time_t borrowTime,time_t returnTime);//iade edilen ktiaplari ekliyoruz

    void listLoans()const; //odunc alinanlari lsiteliyoruz
    void listReturns()const; //iade edilenleri listeliyoruz.
    void listAvailableBooks(const BookManager& bookManager,const LoadStack& loadStack)const;
    //boş olanlari lsiteliyoruz.

};



#endif