#include <iostream>
#include <string>
#include <calculum.h>

using namespace std;





int main(int argc, char* argv[])
{
   
   handler asd;

   if(argc>1)
   {
      cout <<"is in the main section\n";
      asd.interface(argv);
      return 0;
   }
   else 
   {
      cout << "this will be the help section \n";
   }
}
