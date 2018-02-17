//QUESTION 51 PG 222

#include<iostream>
using namespace std;

void main()
{
	 float num,num2,num3,avg;
	 char gr;

	 cout<<"\n Enter Marks in sub 1=";
	 cin>>num;

	 cout<<"\n Enter Marks in sub 2=";
	 cin>>num2;
	 
	 cout<<"\n Enter Marks in sub 3=";
	 cin>>num3;
	 
	 avg=(num+num2+num3)/3;

	 if(avg>=90.00)
	 {
		 gr='A';
	 }
	 else 
	 {
		 if(avg>=70.00)
		 {
			 if(num3>=90)
			 gr='A';
				else
			    gr='B';
		 }
	     else 
		 {
			 if(avg>=50.00)
			 {
				 if(((num+num2)/2)>=70.00)
				  gr='C';
					else
					gr='D';
			 }
         	 else
	    	 gr='F';
		 }

	 }

	 cout<<"\n Result="<<gr<<endl;
}
