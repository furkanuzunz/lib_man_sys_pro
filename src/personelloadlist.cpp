#include "PersonelLoadList.hpp"
using namespace std;
#include <string>
#include <iostream>

Node::Node(int id, const string &title, time_t borrowT, time_t returnT)
{
    this->bookId = id;
    this->bookTitle = title;
    this->borrowTime = borrowT;
    this->returnTime = returnT;
    this->next = nullptr;
}

PersonelLoadList::PersonelLoadList()
{
    this->head = nullptr;
}

PersonelLoadList::~PersonelLoadList()
{
    if (head == nullptr)
        return;

    Node *now = head->next;
    while (now != head)
    {
        Node *temp = now;
        now = now->next;
        delete temp;
    }
    delete head;
}

void PersonelLoadList::addLoan(int bookId, const string &bookTitle, time_t borrowTime)
{
    Node *newNode = new Node(bookId, bookTitle, borrowTime, 0);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void PersonelLoadList::addReturn(int bookId, const string &bookTitle, time_t borrowTime, time_t returnTime)
{
    Node *newNode = new Node(bookId, bookTitle, borrowTime, returnTime);
    // return time burada 0 değil cunku iade var.yukarıda sıfır olmasının anlamı daha iade edilmemis olmasi.

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

void PersonelLoadList::listLoans() const
{
    if (head == nullptr)
    {
        cout << "Odunc alinan kitap bulunamadi " << endl;
        return;
    }

    cout << "--- Ödünç Alınan Kitaplar Raporu ---" << endl;
    Node *temp = head;
    bool found = false;

    do
    {
        if (temp->returnTime == 0)
        {
            found = true;
            cout << "Kitap ID: " << temp->bookId << endl;
            cout << "Başlık: " << temp->bookTitle << endl;
            cout << "Alma Zamanı: " << ctime(&(temp->borrowTime));
            cout << "------------------------------" << endl;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found)
        cout << "Aktif olarak ödünçte kitap bulunmuyor." << endl;
} // bunu direkt while ile yapmak istersen firstcheck = true dersin en basta koşula da onu yazarsin.ardindan alta da false dersin.yoksa girmez zaten en basta temp = head diyoruz.

void PersonelLoadList::listReturns() const
{
    if (!head)
    {
        cout << "Iade edilen kitap bulunamadi!" << endl;
        return;
    }

    cout << "--- Iade Edilen Kitaplar ---" << endl;
    Node *temp = head;
    do
    {
        if (temp->returnTime != 0)
        {
            cout << "ID: " << temp->bookId << ", Baslik: " << temp->bookTitle
                 << ", Alma Zamani: " << ctime(&(temp->borrowTime))
                 << ", Iade Zamani: " << ctime(&(temp->returnTime)) << endl;
        }
        temp = temp->next;
    } while (temp != head);
}

void PersonelLoadList::listAvailableBooks(const BookManager &bookManager, const LoadStack &loadStack) const
{
    PersonelBook *now = bookManager.getHead();

    if (now == nullptr)
    {
        cout << "Kutuphanede kitap bulunmamaktadir! " << endl;
        return;
    }

    cout << "--- Mevcut Kitaplar (odunc Alinmamis) ---" << endl;

    while (now != nullptr)
    {
        if (!loadStack.contains(now->getId()))
        {
            cout << "ID: " << now->getId() << " - Baslik: " << now->getTitle() << endl;
        }
        now = now->getNext();
    }
}