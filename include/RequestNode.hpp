#ifndef RequestNode_hpp
#define RequestNode_hpp

#include <string>
#include <iostream>
using namespace std;

class RequestNode
{
public:
    int requestId;
    string bookTitle;
    string requestName;
    string author;
    int year;
    int pages;
    int priority; // normal == 0;akademik == 1;
    RequestNode *next;

    string publisher;
    string language;

    string category;

    RequestNode(int id, string title, string requester, string author, int year, int pages, int priority = 0,string publisher = "Bilinmiyor",string language = "Bilinmiyor",string category = "Belirtilmedi");
};

#endif