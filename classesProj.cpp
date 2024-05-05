using namespace std;
#include <iostream>
#include "Stack.h"
#include <fstream>
#include <string>
#include <cctype>
#include<cmath>
#include <iomanip>

//determines order of functions
int opPrec(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}//close opPrec

//converts infix to postfix
string toPost(const string& infix){
 
 //varaibles
 Stack obj;
 string postfix;

//loops through infix expression
 for(size_t count = 0; count < infix.size(); count++){
    
        //if char is a num it adds it to postfix function 
        //including decimals and nums > 9
     if(isdigit(infix[count]) || infix[count] == '.'){
         string num;
         while(count < infix.size() && (isdigit(infix[count]) || infix[count] == '.')){
             num += infix[count++];
         }
         count--;
         postfix += num+" ";
         
     }else if(infix[count] =='('){//if char is a paranthesis adds it to stack obj
         
        obj << new Node(Data(' ', infix[count]));
         
     }else if(infix[count] ==')'){//takes out until "("
         Node *temp;
         while(obj.getHead()!= nullptr){
             obj >> temp;
             if(temp -> getPayload().getOperator() == '('){
                 delete temp;
                 break;
             }else{
                
                  postfix += temp -> getPayload().getOperator();
                  postfix += " ";
                 delete temp;
             }
         }
            
     }else if(opPrec(infix[count])!= 0){//if operator, orders operator and adds it to postfix
          while (obj.getHead() != nullptr && opPrec(infix[count]) <= opPrec(obj.getHead()->getPayload().getOperator())) {
                Node *temp;
                obj >> temp;
                postfix += temp->getPayload().getOperator();
                postfix += " ";
                delete temp;
            }
        obj << new Node(Data(' ', infix[count]));//adds to stack
        }//close if ekse
     
 }//close for loop
    
    //adds operators to postfix
    Node *temp = nullptr;
  while (obj.getHead()){
        obj >> temp;
        if(temp != nullptr){
            postfix += temp->getPayload().getOperator();
            postfix+= " ";
            delete temp;
        }//close if
    }//close while

    return postfix; 
}//close toPost

//function to solve postfix expression
double solve(const string& postfix){
    
    Stack obj;
    
    //for every char in postfix expression
    for (size_t count = 0; count < postfix.size(); count++) {
        
        //if char is num push it to stack
        if (isdigit(postfix[count]) || postfix[count] == '.') {
            
            string op;
            while (count < postfix.size() && (isdigit(postfix[count]) || postfix[count] == '.')) {
               op += postfix[count];
               count++;
            }
            count--; 
            obj << new Node(Data(stod(op), ' '));
            
        //if char is operator performs operation
        } else if (opPrec(postfix[count])!= 0) {
            
            //make node to keep numbers in
            Node* op1;
            Node* op2;
            obj >> op2;
            obj >> op1;
            
            //puts node value in double
            double oper1 = op1->getPayload().getOperand();
            double oper2 = op2->getPayload().getOperand();
            
            
            //determines what operation to use
            double ans;
            if (postfix[count] == '+') {
                ans = oper1 + oper2;
            } else if (postfix[count] == '-') {
                ans = oper1 - oper2;
            } else if (postfix[count] == '*') {
                ans = oper1 * oper2;
            } else if (postfix[count] == '/') {
                ans = oper1 / oper2;
            } else if (postfix[count] == '^') {
                ans = pow(oper1, oper2);
            }//close if else
            
            //delete pointers to prevent leaks
            delete op1;
            delete op2;

            obj << new Node(Data(ans, ' '));
        }
    }//close for loop

    //get final anwer from stack obj
    Node* finalAns;
    obj >> finalAns;
    double ans = finalAns->getPayload().getOperand();
    delete finalAns;
    
    
    return ans;
}//close solving function

//main
int main(){
    //vars
    string inputFile;
    string iFix;
    string pFix;
    double num;
    ifstream fileName;
    
    //user input and open file
    cout << "Enter file name: " << endl;
    cin >> inputFile;
    fileName.open(inputFile);
    
    //checks to see if file is properly opened
    if(!fileName.is_open()){
        cout << "Error opening file :(";
        return 0;
    }
    
    //while file has info changes to postfix and calculates answer
    while(!fileName.eof()){
        
        getline(fileName, iFix);
        pFix = toPost(iFix);//calls postfix function
        num = solve(pFix);//calls function to solve
        cout << pFix << "\t" << fixed << setprecision(3) << num << endl;//output
    }
    
    //close files
    fileName.close(); 
    return 0;
} //close main