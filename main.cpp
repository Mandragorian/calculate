#include <iostream>
#include <string>
#include <calculum.h>

using namespace std;





int main(int argc, char* argv[])
{
   
   handler asd;
   //cout << argc << argv[0]  <<"\n";
   if(argc>2)
   {
      cout <<"is in the main section\n";
      asd.interface(argv);
      cout << "prin to telos\n";
      return 0;
   }
   else 
   {
      cout << "this will be the help section \n";
   }

   cout <<"telos \n";
}
