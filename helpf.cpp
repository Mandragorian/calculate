#include <calculum.h>
#include <string>
#include <stack>


std::string calculate(std::string input)
{
   std::cout << postfix(input) << " " << "klisi calculate" << "\n";
   return "test";
}


bool isOperator(char in)
{
   if ((in=='+')||(in=='*')||(in=='-')||(in=='/')||(in=='^')) return true;
   else return false;
}

bool precedes(char x, char y)
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

std::string postfix(std::string foo )
{
   std::string posstr="";
   std::stack<char> stack;

   for (int i=0;i<foo.length();i++)
   {
      if(!isOperator(foo[i])) posstr=posstr + foo[i];
      else if (stack.empty()) 
      {
         stack.push(foo[i]);
         posstr=posstr +'#';
      }
      else if(!precedes(stack.top(),foo[i]))
      {
         stack.push(foo[i]);
         posstr=posstr+'#';
      }

      else 
      {
         while ((!stack.empty())&&(precedes(stack.top(),foo[i])))
         {
            posstr=posstr +stack.top();
            stack.pop();
         }
         stack.push(foo[i]);
      }
   }
   while(!stack.empty())
   {
      posstr=posstr + stack.top();
      stack.pop();
   }
   return posstr;
}

