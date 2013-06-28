#include <calculum.h>


float calculate(std::string input)
{
 std::cout << input << "\n";
}


handler::handler(){}

void handler::interface(char* arguments[])
{

   
   switch (arguments[1][1])
   {
      case 'c': 
       calculate(arguments[2]);
       break;
      default:
       std::cout << "this will be an error message\n";
   }
   

}
