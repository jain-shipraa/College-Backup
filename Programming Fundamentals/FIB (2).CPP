#include<iostream.h>


void main()
{

	int n1, n2, n3=0,i,n,num;
	cout<<"\n Enter first term =";
	cin>>n1;

	cout<<"\n Enter second term=";
	cin>>n2;
	cout<<"\n Enter the no of term to be disp";
		   cin>>num;

		   n=num;
		   i=1;
		   while(i<=(n-2))
		   {
			   n3=n1+n2;
			   n1=n2;
			   n2=n3;
			   i++;
		   }

		   cout<<"\n "<<num<<"th term="<<n3;


}