#include "UserBook.hpp"
#include <iostream>
#include <string>
using namespace std;

UserBook::UserBook(int id)
{
    this->id = id;
    read = false;
    comment = "";
    next = nullptr;
    prev = nullptr;
}

int UserBook::getId()
{
    return id;
}

bool UserBook::isRead()
{
    return read;
}

void UserBook::setRead(bool r)
{
    this->read = r;
}

string UserBook::getComment()
{
    return comment;
}

void UserBook::setComment(string c)
{
    this->comment = c;
}


UserBook* UserBook::getNext()
{
    return next;
}

void UserBook::setNext(UserBook *n)
{
    this->next = n;
}

UserBook* UserBook::getPrev()
{
    return prev;
}

void UserBook::setPrev(UserBook* p)
{
    this->prev = p;
}

