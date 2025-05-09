#include "LoadStack.hpp"
using namespace std;
#include <string>
#include <iostream>

StackNode::StackNode(int id, const string &title)
{
    this->bookId = id;
    this->bookTitle = title;
    this->borrowTime = time(0); // suanki zamani aldik, odunc aldigi tarihi vs bulalim diye.
    this->next = nullptr;       // ilk başta biliyosun bir sonraki yok zaten,
}

LoadStack::LoadStack()
{
    top = nullptr; // baslangicta stack bos,kontrolleri buna göre yapcaz bazen
}

LoadStack::~LoadStack()
{
    // burayı hatırla, bitane gecici silinecek atiyoruzsonra kaydiriyruz topu. cunku top en sonkini gostercek.biz de en sondakini silince mecburen topu kaydiriyoruz
    while (top != nullptr)
    {
        StackNode *temp = top;
        top = top->next;
        delete temp;
    }
}

void LoadStack::push(int bookId, const string &bookTitle) // odunc listemize,yani stackimize aslında kitap ekledik.
{
    StackNode *newBook = new StackNode(bookId, bookTitle);

    if (top != nullptr)
    {
        newBook->next = top; // gorselli bir sekilde notion hesabinda bu var,anlayamazsan orayı kontrol et.
    } // aslidna burada yaptigimiz islem ile next , bironceki ktiabi gostermis oluyor.top'u oynatiyoruz cunku.

    top = newBook;
}

StackNode *LoadStack::pop() // odunc lsitemden kitaplari geri iade ediyorum.
{
    if (top == nullptr)
    {
        cout << "Stack bos,iade edilecek kitap yok." << endl;
        return nullptr;
    }
    StackNode *temp = top;

    top = top->next;

    temp->next = nullptr; // bagi kopardik,
    return temp;
}

void LoadStack::display() const
{
    if (top == nullptr)
    {
        cout << "Odunc alinan kitap yok" << endl;
        return;
    }

    StackNode *temp = top;
    cout << "--- Odunc Alinan Kitaplar ---" << endl;

    while (temp != nullptr)
    {
        cout << "ID: " << temp->bookId
             << " -- Kitap Adi: " << temp->bookTitle
             << " -- Alma Zamani: " << ctime(&(temp->borrowTime))
             << endl;
        temp = temp->next;
    }
}

bool LoadStack::isEmpty()
{
    return top == nullptr;
}

//LoadStack içinde belirli bir bookId var mı diye bak
bool LoadStack::contains(int bookId) const
{
    StackNode* temp = top;
    while (temp != nullptr)
    {
        if (temp->bookId == bookId)
            return true;
        temp = temp->next;
    }
    return false;
}

void LoadStack::push(int bookId, const string &bookTitle, time_t customTime)
{
    StackNode *newBook = new StackNode(bookId, bookTitle);
    newBook->borrowTime = customTime; // istediğimiz tarihi veriyoruz
    newBook->next = top;
    top = newBook;
}
