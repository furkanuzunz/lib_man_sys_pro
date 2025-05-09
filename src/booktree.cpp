#include "BookTree.hpp"
#include <iostream>
#include <ctime>

#include "BookTreeNode.hpp"

BookTree::BookTree()
{
    root = nullptr;
}

BookTree::~BookTree()
{
    clear();
}

void BookTree::insert(BookTreeNode *newNode)
{
    insertHelper(root, newNode);
}
void BookTree::insertHelper(BookTreeNode *&node, BookTreeNode *newNode)
{
    if (node == nullptr)
    {
        node = newNode;
        return;
    }
    if (newNode->getId() < node->getId())
    {
        insertHelper(node->left, newNode);
    }
    else
    {
        insertHelper(node->right, newNode);
    }
}

void BookTree::clear()
{
    clearHelper(root);
    root = nullptr;
}

void BookTree::clearHelper(BookTreeNode *node)
{
    if (node == nullptr)
        return;
    clearHelper(node->left);
    clearHelper(node->right);
    delete node;
}

// filtrelemeleri yapalim simdi

void BookTree::filterByPublisher(const string &publisher)
{
    inorderByPublisher(root, publisher);
}

void BookTree::inorderByPublisher(BookTreeNode *node, const string &targetPublisher)
{
    if (node == nullptr)
        return;
    inorderByPublisher(node->left, targetPublisher);

    if (node->getPublisher() == targetPublisher)
        cout << "ID: " << node->getId() << ", Title: " << node->getTitle() << endl;

    inorderByPublisher(node->right, targetPublisher);
}

void BookTree::filterByLanguage(const string &language)
{
    inorderByLanguage(root, language);
}

void BookTree::inorderByLanguage(BookTreeNode *node, const string &targetLanguage)
{
    if (node == nullptr)
        return;
    inorderByLanguage(node->left, targetLanguage);
    if (node->getLanguage() == targetLanguage)
    {
        cout << "ID: " << node->getId() << ", Title: " << node->getTitle() << endl;
    }
    inorderByLanguage(node->right, targetLanguage);
}

void BookTree::filterByPageCount(int threshold, bool greater)
{
    inorderByPageCount(root, threshold, greater);
    // threshold burada esik deger unutma
}

void BookTree::inorderByPageCount(BookTreeNode *node, int threshold, bool greater)
{
    if (node == nullptr)
        return;
    inorderByPageCount(node->left, threshold, greater);
    if ((greater && node->getPages() > threshold) || (!greater && node->getPages() <= threshold))
        cout << "ID: " << node->getId() << ", Title: " << node->getTitle() << ", Pages: " << node->getPages() << endl;
    inorderByPageCount(node->right, threshold, greater);
}
void BookTree::filterByYear(int yearThreshold, bool after)
{
    inorderByYear(root, yearThreshold, after);
}
void BookTree::inorderByYear(BookTreeNode *node, int yearThreshold, bool after)
{
    if (node == nullptr)
        return;
    inorderByYear(node->left, yearThreshold, after);
    if ((after && node->getYear() > yearThreshold) || (!after && node->getYear() <= yearThreshold))
        cout << "ID: " << node->getId() << ", Title: " << node->getTitle() << ", Year: " << node->getYear() << endl;
    inorderByYear(node->right, yearThreshold, after);
}
void BookTree::filterByBorrowTime(int daysThreshold, bool greater)
{
    inorderByBorrowTime(root, daysThreshold, greater);
}

void BookTree::inorderByBorrowTime(BookTreeNode *node, int daysThreshold, bool greater)
{
    if (node == nullptr)
        return;

    inorderByBorrowTime(node->left, daysThreshold, greater);

    time_t now = time(0);
    double diffDays = difftime(now, node->getBorrowTime()) / (60 * 60 * 24);

    if ((greater && diffDays > daysThreshold) || (!greater && diffDays <= daysThreshold))
    {
        cout << "ID: " << node->getId() << ", Baslik: " << node->getTitle() << ", Gun: " << (int)diffDays << endl;
    }

    inorderByBorrowTime(node->right, daysThreshold, greater);
}

void BookTree::filter1950And30Days()
{
    inorder1950And30Days(root);
}

void BookTree::inorder1950And30Days(BookTreeNode *node)
{
    if (node == nullptr)
        return;
    inorder1950And30Days(node->left);

    time_t now = time(0);
    double days = difftime(now, node->getBorrowTime()) / (60 * 60 * 24);

    if (node->getYear() < 1950 && days > 30)
        cout << "ID: " << node->getId() << ", Title: " << node->getTitle() << ", Year: " << node->getYear() << ", Days: " << days << endl;

    inorder1950And30Days(node->right);
}