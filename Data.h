#ifndef DATA_H
#define DATA_H

#include <string>


class Data{
   private:
   
   double dubOp;
   char charOp;
   
   public:
   
   Data(){dubOp = 0.0; charOp = ' ';}
   Data(double dubO, char charO){dubOp = dubO; charOp = charO;}
   
   double getOperand(){return dubOp;}
   char getOperator(){return charOp;}
   
   void setOperand(double dubOper){dubOp = dubOper;}
   void setOperator(char charOper){charOp = charOper;}
   
   };
   
#endif