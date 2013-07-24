#include <calculum.h>
#include <string>
#include <stack>

using namespace std;

typedef enum {CONST, OP} flag;

typedef struct{
 flag code;
 std::string data;
} node; 

 
string calculator::evexpr(string expr)
{
   
   string posstr= postfix(expr);   
   cout << posstr <<"\n";
   stack<node> mstack;
   
   for(int i=posstr.length()-1;i>=0;i--)
   {
      if(isOperator(posstr[i])) 
      {
         node binop;
         binop.code=OP;
         binop.data=posstr[i];
         mstack.push(binop);
	 //cout << mstack.top().data << "\n";
      }
      else
      {
         node constant;
         constant.code=CONST;
         constant.data="";
         
	 while((posstr[i]!='#')&&(i>=0))
         {
            constant.data+=posstr[i];
            i--;   
         }
         //cout << posstr[i];
	  //prosperna to #
	 //cout << "const data:" << constant.data << "\n";         
	 //cout << i << "\n";
	 
	 if(mstack.top().code==OP) 
	 {
	    mstack.push(constant);
	    //cout << mstack.top().data << "\n";
	 }
         else 
	 {
	    //edo tha mpei ot kommati pou ipologizei to apotelesma enos operator pou einai resolved
 	    //cout << "kanei praksi \n";
            node argument=mstack.top();
	    mstack.pop();
            node binop=mstack.top();
	    mstack.pop();            

	    float arg1 = mkFloat(constant.data);
	    //cout <<"arg1: " << arg1 << "\n";
	    float arg2 = mkFloat(argument.data);
	    //cout <<"arg2: " <<  arg2 << "\n";

            if(binop.data=="+") constant.data=mkStr(arg1+arg2);
	    else if(binop.data=="-") constant.data=mkStr(arg1-arg2);
	    else if(binop.data=="*") constant.data=mkStr(arg1*arg2);
	    else if(binop.data=="/") constant.data=mkStr(arg1/arg2);            
            
	    mstack.push(constant);
            
	 }
	 
      }
   //std::cout << mstack.top().data << "\n"<< i << "\n" ;
   } 
   //cout << posstr;
   //cout << "\n";

   //if((posstr.find('+')==posstr.length()-1)||(posstr.find('-')==posstr.length()-1)||(posstr.find('*')==posstr.length()-1)||(posstr.find('/')==posstr.length()-1)||(posstr.find('^')==posstr.length()-1))
   //   cout<<"yes\n";

   //cout << mstack.top().data << "\n";
   //cout << mstack.size() << "\n";
   while(mstack.size()>1)
   {
      //cout << mstack.top().data << "\n";
      //mstack.pop();
      

      node constant1, constant2;
      node binop;
   
      constant1=mstack.top();
      mstack.pop();
      constant2=mstack.top();
      mstack.pop();

      binop=mstack.top();
      mstack.pop();

      float arg1 = mkFloat(constant1.data);
      cout << arg1 << "\n";
      float arg2 = mkFloat(constant2.data);
      cout << arg2 << "\n";
      if(binop.data=="+") constant1.data=mkStr(arg1+arg2);
      else if(binop.data=="-") constant1.data=mkStr(arg1-arg2);
      else if(binop.data=="*") constant1.data=mkStr(arg1*arg2);
      else if(binop.data=="/") constant1.data=mkStr(arg1/arg2);

      mstack.push(constant1);
   }    
return mstack.top().data;

}


