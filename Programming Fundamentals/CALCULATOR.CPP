//CALCULATOR USING SWITCH

#include<iostream>
using namespace std;

void main()
{

   int n1,n2;
   char ch;

   cout<<"\n Enter any two no.=";
   cin>>n1>>n2;

   cout<<"\n Enter the symbol operation to be executed=";
   cin>>ch;

   switch(ch)
   {
	   case '+':cout<<"Sum="<<(n1+n2);
		        break;
       case '-':cout<<"\n Subtration="<<(n1-n2);
		        break;
       case '*':cout<<"\n Product="<<(n1*n2);
		        break;
       case '/':cout<<"\n Quotient="<<(n1/n2);
		        break;
	   default: cout<<"\n Invalid Oprator!!!!";
		       
   }

}


