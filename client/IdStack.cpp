#include "IdStack.h"

IdStack::IdStack(){
    stack.push(0);
}

void IdStack::push(int id){
    stack.push(id);
}

int IdStack::pop(){
    int topId = stack.top();
    stack.pop();
    if (stack.empty())
        stack.push(topId + 1);
    return topId;
}
