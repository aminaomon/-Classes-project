#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>
#include "Node.h"

class Stack{
    private:
    Node *head;
    
    public:
    Stack();
    Stack(Node*);
    Stack(Stack&);
    
    ~Stack();
    
    Node* getHead(){return head;}
    void setHead(Node* H);
    
    friend std::ostream& operator<<(std::ostream& out, const Stack& obj);
    friend void operator>>(Stack& obj, Node*& nodePtr);
    friend void operator<<(Stack& obj, Node* nodePtr);
};

#endif