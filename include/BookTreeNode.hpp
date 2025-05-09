#ifndef BOOKTREENODE_HPP
#define BOOKTREENODE_HPP

#include <string>
#include <ctime>

using namespace std;

class BookTreeNode
{
private:
    int id;
    string title;
    string author;
    int year;
    int pages;
    time_t borrowTime;
    string publisher;
    string language;
    string category;

public:
    BookTreeNode *left;
    BookTreeNode *right;

    BookTreeNode(int id, string title, string author, int year, int pages, time_t borrowTime,
                 string publisher, string language, string category);

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    int getPages() const;
    time_t getBorrowTime() const;
    string getPublisher() const;
    string getLanguage() const;
    string getCategory() const;
};

#endif