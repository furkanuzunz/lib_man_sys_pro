#ifndef RequestQueue_hpp
#define RequestQueue_hpp

#include "RequestNode.hpp"

using namespace std;
#include <string>
#include <iostream>

class RequestQueue
{
private:
    RequestNode *front;
    RequestNode *back;

public:
    RequestQueue();
    void enqueue(int id, string title, string requester, string author, int year, int pages,string publisher,string language,int priority = 0,string category = "Belirtilmedi"); // normal talep
    void academicEnqueue(int id, string title, string requester, string author, int year, int pages,string publisher,string language,string category);           // akademik talep
    void dequeue();                           // personel tedarik ettiğinde kuyruktan çıkar, yani bookmanagera tedarik ettigimizde kuyruktan cıkarcaz.
    void displayQueue() const;                  // talepleri yazdır
    bool isEmpty() const;

    RequestNode* peekFront() const;
};

#endif