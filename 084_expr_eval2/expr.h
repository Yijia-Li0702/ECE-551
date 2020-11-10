#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>

class Expression{  
public:
  virtual std::string toString() const = 0;  //abstract method
  //virtual long evaluate() const = 0; 

  virtual ~Expression(){}
};

class NumExpression : public Expression{
 private:
  long num;
 public:
 NumExpression(long l):num(l){};
  virtual std::string toString() const{
    std::stringstream strm;
    strm << num;
    std::string res = strm.str();
    return res;
    
  }
  virtual ~NumExpression(){}
  //virtual long evaluate() const
}; 

class PlusExpression : public Expression{
 private:
  Expression * lhs;
  Expression * rhs;
 public:
  PlusExpression(Expression * lhs, Expression * rhs):lhs(lhs),rhs(rhs){}
  std::string toString() const {
  std::stringstream strm;
  strm << "(" << lhs->toString() << "+" << rhs->toString() << ")";
  return strm.str();
  }
  virtual ~PlusExpression(){
  delete lhs;
  delete rhs;
  }
  //virtual long evaluate() const{}
};
class MinusExpression : public Expression{
  private:
  Expression * lhs;
   Expression * rhs;
  
  public:
   MinusExpression(Expression * lhs, Expression * rhs):lhs(lhs),rhs(rhs){}
   virtual std::string toString() const {
   std::stringstream strm;
  strm << "(" << lhs->toString() << "-" << rhs->toString() << ")";
  return strm.str();
  }
  virtual ~MinusExpression(){
  delete lhs;
  delete rhs;
  }
   //virtual long evaluate() const{}
 };
 
 class TimesExpression : public Expression{
  private:
  Expression * lhs;
   Expression * rhs;
  
  public:
   TimesExpression(Expression * lhs, Expression * rhs):lhs(lhs),rhs(rhs){}
   virtual std::string toString() const {
   std::stringstream strm;
  strm << "(" << lhs->toString() << "*" << rhs->toString() << ")";
  return strm.str();
  }
  virtual ~TimesExpression(){
  delete lhs;
  delete rhs;
  }
   //virtual long evaluate() const{}
 };
 

 class DivExpression : public Expression{
  private:
   Expression * lhs;
   Expression * rhs;
  
  public:
   DivExpression(Expression * lhs, Expression * rhs):lhs(lhs),rhs(rhs){}
   virtual std::string toString() const {
    std::stringstream strm;
  strm << "(" << lhs->toString() << "/" << rhs->toString() << ")";
  return strm.str();
  }
    virtual ~DivExpression(){
  delete lhs;
  delete rhs;
  }
//   virtual long evaluate() const{}
 };