#include "PersonelBook.hpp"

PersonelBook::PersonelBook(int id,string title,string author,int year,int pages,time_t addedTime,string publisher, string language,string category)
{
    this->id = id;
    this->title=title;
    this->author = author;
    this->year = year;
    this->pages=pages;
    this->addedTime=addedTime;
    this->damageNote="";
    this->publisher = publisher;
    this->language = language;
    this->category = category;
    this->next=nullptr;
}



int PersonelBook::getId()
{
    return id;
}

string PersonelBook::getTitle()
{
    return title;
}

string PersonelBook::getAuthor()
{
    return author;
}

int PersonelBook::getYear()
{
    return year;
}

int PersonelBook::getPages()
{
    return pages;
}

time_t PersonelBook::getAddedTime()
{
    return addedTime;
}

string PersonelBook::getDamageNote()
{
    return damageNote;
}

PersonelBook* PersonelBook::getNext()
{
    return next;
}

void PersonelBook::setDamageNote(string note)
{
    damageNote = note;
}
void PersonelBook::setNext(PersonelBook *nextBook)
{
    next = nextBook;
}

void PersonelBook::setTitle(string title) {
    this->title = title;
}

void PersonelBook::setAuthor(string author) {
    this->author = author;
}

void PersonelBook::setYear(int year) {
    this->year = year;
}

void PersonelBook::setPages(int pages) {
    this->pages = pages;
}

void PersonelBook::setId(int id)
{
    this->id =  id;
}
void PersonelBook::setAddedTime(time_t addedTime)
{
    this->addedTime = addedTime;
}

string PersonelBook::getPublisher() const {
    return publisher;
}

string PersonelBook::getCategory() const 
{
     return category; 
}

void PersonelBook::setPublisher(const string& pub) {
    publisher = pub;
}

string PersonelBook::getLanguage() const {
    return language;
}

void PersonelBook::setLanguage(const string& lang) {
    language = lang;
}

void PersonelBook::setCategory(const string& categ)
{
    category = categ;
}
