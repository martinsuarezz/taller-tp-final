#ifndef ID_STACK_H
#define ID_STACK_H
#include <stack>

class IdStack{
    private:
        std::stack<int> stack;

    public:
        IdStack();
        int pop();
        void push(int id);

};

#endif
