#include <calculum.h>
#include <string>
#include <stack>
#include <sstream>

//std::string calculate(std::string input)
//{
//   std::cout << postfix(input) << " " << "klisi calculate" << "\n";
//   return "test";
//}


bool calculator::isOperator(char in)
{
   if ((in=='+')||(in=='*')||(in=='-')||(in=='/')||(in=='^')) return true;
   else return false;
}

bool calculator::precedes(char x, char y)
{
   if(x=='^') return true;
   else if ((x=='*')||(x=='/'))
   {
      if(y=='^') return false;
      else return true;
   }
   else if ((x=='+')||(x=='-'))
   {
      if((y=='+')||(y=='-')) return true;
      else return false;
     
   }
}

std::string calculator::postfix(std::string foo )
{
   std::string posstr="";
   std::stack<char> stack;

   for (int i=0;i<foo.length();i++)
   {
      if(!isOperator(foo[i])) posstr=posstr + foo[i]; // oso den exei diabasei operator prosthetei psifia sto string
      else if (stack.empty()) 			      // otan diabasei operator an i stoiba einai adia ton bazei stin stoiba kai markarei to telos tou arithmou me #
      {
         stack.push(foo[i]);
         posstr=posstr +'#';
      }
      else if(!precedes(stack.top(),foo[i]))	     // an i stoiba den einai adeia kai diabasei operator pou exei megaliteri proteraiotita apo to top ton bazei sti stoiba kai markarei telos arithmou me #
      {
         stack.push(foo[i]);
         posstr=posstr+'#';
      }

      else 					    // an den isxiei tipota apo ta parapano mpainei edo
      {
         
	//posstr= posstr +'#';
	
	while ((!stack.empty())&&(precedes(stack.top(),foo[i]))) // oso i stiba den einai adeia kai to topi stoixeio exei proteraiotita prosthetei sto string ta operators kai kanei pop tin stoiba 

         {
            posstr=posstr +stack.top();
            stack.pop();
         }
         stack.push(foo[i]);					 // molis i stoiba adeiasei i den exei proteraiotita to top bazei ton operator pou diabase sti stoiba kai sinexizeii
	 posstr=posstr+'#';
      }
   }
   while(!stack.empty())					// oti operators minane mpenoun sto string	
   {
      posstr=posstr + stack.top();
      stack.pop();
   }
   return posstr;
}


float calculator::mkFloat(std::string constant)
{
   std::stringstream ss;
   float rtrn;
   ss << constant;
   ss >> rtrn;
   return rtrn;

}

std::string calculator::mkStr(float constant)
{
   std::stringstream ss;
   std::string rtrn;
   ss << constant;
   ss >> rtrn;
   return rtrn;
}
