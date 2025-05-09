#ifndef StackNode_hpp
#define StackNode_hpp
#include <string>
#include <ctime>
using namespace std;

struct StackNode {
    int bookId;
    string bookTitle;
    StackNode* next;
    time_t borrowTime;
    time_t returnTime;

    StackNode(int id, const string& title,time_t borrowTime,time_t returnTime);
    StackNode(int id, const string &title); // constructorımız.

   
    StackNode* getNext()
    {
        return next;
    }



};


#endif