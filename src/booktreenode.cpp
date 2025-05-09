#include "BookTreeNode.hpp"

BookTreeNode::BookTreeNode(int id, string title, string author, int year, int pages, time_t borrowTime,
                           string publisher, string language, string category)
{
    this->id = id;
    this->title = title;
    this->author = author;
    this->year = year;
    this->pages = pages;
    this->borrowTime = borrowTime;
    this->publisher = publisher;
    this->language = language;
    this->category = category;
    this->left = nullptr;
    this->right = nullptr;
}

int BookTreeNode::getId() const
{
    return id;
}
string BookTreeNode::getTitle() const
{
    return title;
}
string BookTreeNode::getAuthor() const
{
    return author;
}
int BookTreeNode::getYear() const
{
    return year;
}
int BookTreeNode::getPages() const
{
    return pages;
}
time_t BookTreeNode::getBorrowTime() const
{
    return borrowTime;
}
string BookTreeNode::getPublisher() const
{
    return publisher;
}
string BookTreeNode::getLanguage() const
{
    return language;
}
string BookTreeNode::getCategory() const
{
    return category;
}
