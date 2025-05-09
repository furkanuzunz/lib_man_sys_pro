#ifndef LoadStack_hpp
#define LoadStack_hpp

#include "StackNode.hpp"

#include <ctime>
#include <string>
using namespace std;



class LoadStack
{
private:
    StackNode *top; // stackin tepe elemani diyebilirsi.

public:
    LoadStack(); // cosntructor.
    ~LoadStack();

    void push(int bookId, const string &bookTitle); // kitaplarimizi yigina ekliyoruz.
    StackNode* pop();                                     // eleman cikarma icin.
    void display()const;
    bool isEmpty();

    bool contains(int bookId) const;

    StackNode* getTop()
    {
        return top;
    }

    void push(int bookId, const string &bookTitle, time_t customTime); // overload



};

#endif