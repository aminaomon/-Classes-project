#include "Stack.h"
#include <iostream>

Stack::Stack(){
    head = nullptr;
}

Stack::Stack(Node *node){
    setHead(node);
}

Stack::Stack(Stack& x){
    
    if(x.head){
        
        head = new Node(*(x.head));
        Node* temp = head;
        Node* xTemp = x.head->getNext();
        
        while(xTemp){
            temp->setNext(new Node(*(xTemp)));
            temp = temp->getNext();
            xTemp = xTemp->getNext();
        }
    } else {
        head = nullptr;
    }
}

Stack::~Stack() {
    Node* temp = head;
    while (temp){
        Node* next = temp->getNext();
        delete temp;
        temp = next;
    }
}


void Stack::setHead(Node *h){
    head = h;
    
}


std::ostream& operator<<(std::ostream& out, const Stack& obj) {
    
    Node* temp = obj.head;
        
        if (temp->getPayload().getOperator()!= ' ') {
            while(temp){
                
                out << temp->getPayload().getOperator();
                
                if(temp->getNext()){
                    out << ", ";
                }
                
                temp = temp->getNext();
                
            }
        }else if (temp->getPayload().getOperand()!= 0){
            while (temp) {
                
                out << temp->getPayload().getOperand();
                
               if(temp->getNext()) {
                    out << ", ";
               }
                temp = temp->getNext();
                
             }
             
            }
            
    
    return out;
}

void operator>>(Stack& obj, Node*& nodePtr) {
    if (obj.head) {
        nodePtr = obj.head;
        obj.head = obj.head->getNext();
        nodePtr->setNext(nullptr);
    } else {
        nodePtr = nullptr;
    }
}

void operator<<(Stack& obj, Node* nodePtr) {
    if (nodePtr) {
        nodePtr->setNext(obj.head);
        obj.head = nodePtr;
    }
}
