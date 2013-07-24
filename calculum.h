#include <iostream>
#include <string>



class handler{

   public:
handler();
void interface(char* []);

};

class calculator{

   public:
std::string  evexpr(std::string);
   private:
std::string  postfix(std::string);
bool         isOperator(char);
bool         precedes(char,char);
std::string  evaluator(std::string);
float        mkFloat(std::string);
std::string  mkStr(float);


};



