#include "ReturnedStack.hpp"
using namespace std;
#include <string>
#include <iostream>

// loadstack gibi caliscak aslinda bu, sadece loadstackte pop ile iade aldıgımız kitabı
// buraya push edeceğiz.odunc mantıgındaki gibi dusun

// returned stackin icinde de top olucak , iade edilenlerin tepesi gibi düşün.

StackNode::StackNode(int id, const string &title, time_t borrowT, time_t returnT)
    : bookId(id), bookTitle(title), borrowTime(borrowT), returnTime(returnT), next(nullptr) {}

ReturnedStack::ReturnedStack()
    : top(nullptr) {}

void ReturnedStack::push(int id, const string &title,time_t borrowT,time_t returnT)
{
    StackNode *newNode = new StackNode(id, title,borrowT,returnT);

    if (top != nullptr)
    {
        newNode->next = top;
    }
    top = newNode;
}

void ReturnedStack::display() const
{
    if (top == nullptr)
    {
        cout << "Iade edilen kitap bulunamadi!" << endl;
        return;
    }

    StackNode *temp = top;
    cout << "--- Iade Edilen Kitaplar ---" << endl;
    while (temp != nullptr)
    {
        cout << "Kitap ID: " << temp->bookId << ", Baslik: " << temp->bookTitle << endl;
        cout << "Odunc Alma Zamani: " << ctime(&(temp->borrowTime));
        cout << "Iade Zamani: " << ctime(&(temp->returnTime));
        cout << "------------------------------" << endl;
        temp = temp->next;
    }
}
