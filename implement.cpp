#include <calculum.h>


handler::handler(){}

void handler::interface(char* arguments[])
{
   calculator smart;
   
   switch (arguments[1][1])
   {
      case 'c': 
       std::cout << "mpike sto case c\n";
       smart.evexpr(arguments[2]);
       std::cout << "teleiose to calculate\n";
       break;
      default:
       std::cout << "this will be an error message\n";
   }
   

}
