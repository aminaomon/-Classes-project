#ifndef NODE_H
#define NODE_H

#include <string>
#include "Data.h"


class Node{
    private:
    Data Payload;
    Node *next;
    
    public:
    
    Node(){next = nullptr;}
    Node(Data pay){Payload = pay; next = nullptr;}
    
    Data getPayload(){return Payload;}
    Node *getNext(){return next;}
   
    void setPayload(Data Pay){Payload = Pay;}
    void setNext(Node *n){next = n;}
    
};

#endif