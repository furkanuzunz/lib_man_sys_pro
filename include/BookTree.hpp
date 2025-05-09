#ifndef BOOKTREE_HPP
#define BOOKTREE_HPP

#include "BookTreeNode.hpp"
#include <string>
using namespace std;

class BookTree
{
private:
    BookTreeNode *root; // kökümüz

    void insertHelper(BookTreeNode *&node, BookTreeNode *newNode);
    void clearHelper(BookTreeNode *node);

    void inorderByPublisher(BookTreeNode *node, const string &targetPublisher);
    void inorderByLanguage(BookTreeNode *node, const string &targetLanguage);
    void inorderByPageCount(BookTreeNode *node, int threshold, bool greate);
    void inorderByBorrowTime(BookTreeNode *node, int daysThreshold, bool greate);
    void inorder1950And30Days(BookTreeNode *node);

public:
    BookTree();
    ~BookTree();

    void insert(BookTreeNode *newNode);
    void clear();

    void inorderByYear(BookTreeNode *node, int yearThreshold, bool after);

    void filterByPublisher(const string &publisher);
    void filterByLanguage(const string &language);
    void filterByPageCount(int threshold, bool greater);
    void filterByYear(int yearThreshold, bool after);
    void filterByBorrowTime(int daysThreshold, bool greater);
    void filter1950And30Days(); // özel karma filtre

    BookTreeNode* getRoot()
    {
        return root;
    }
};

#endif