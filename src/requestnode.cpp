#include "RequestNode.hpp"

RequestNode::RequestNode(int id, string title, string requester, string author, int year, int pages, int priority,string publisher,string language,string category)
{
    this->requestId = id;
    this->bookTitle = title;
    this->requestName = requester;
    this->priority = priority;
    this->next = nullptr;
    this->author = author;
    this->year =year;
    this->pages = pages;
    this->publisher = publisher;
    this->language = language;
    this->category = category;
}
