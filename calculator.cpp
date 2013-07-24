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

	 //to while stamataei sto # kathe fora. logo to for loop to i tha miothei mia akoma fora opote tha to kseperasei kai tha paei ston epomeno arithmo i telesti
      

	 
	 if(mstack.top().code==OP) 
	 {
	    mstack.push(constant);
	 }
         else 
	 {
	    node argument=mstack.top();
	    mstack.pop();
            node binop=mstack.top();
	    mstack.pop();            

	    float arg1 = mkFloat(constant.data);
	    float arg2 = mkFloat(argument.data);
	    

            if(binop.data=="+") constant.data=mkStr(arg1+arg2);
	    else if(binop.data=="-") constant.data=mkStr(arg1-arg2);
	    else if(binop.data=="*") constant.data=mkStr(arg1*arg2);
	    else if(binop.data=="/") constant.data=mkStr(arg1/arg2);            
            
	    mstack.push(constant);
            
	 }
	 
      }
   
   } 
   
   while(mstack.size()>1)
   {
      node constant1, constant2;
      node binop;
   
      constant1=mstack.top();
      mstack.pop();
      constant2=mstack.top();
      mstack.pop();

      binop=mstack.top();
      mstack.pop();

      float arg1 = mkFloat(constant1.data);
      float arg2 = mkFloat(constant2.data);
      
      if(binop.data=="+") constant1.data=mkStr(arg1+arg2);
      else if(binop.data=="-") constant1.data=mkStr(arg1-arg2);
      else if(binop.data=="*") constant1.data=mkStr(arg1*arg2);
      else if(binop.data=="/") constant1.data=mkStr(arg1/arg2);

      mstack.push(constant1);
   }    
return mstack.top().data;

}


