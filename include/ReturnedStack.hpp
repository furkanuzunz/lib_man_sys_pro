#ifndef RETURNEDSTACK_HPP
#define RETURNEDSTACK_HPP

#include "StackNode.hpp"

#include <string>
using namespace std;
#include <ctime>



class ReturnedStack {
private:
    StackNode* top;

public:
    ReturnedStack();
    void push(int id, const string& title,time_t borrowTime,time_t returnTime);
    void display() const;
};

#endif
