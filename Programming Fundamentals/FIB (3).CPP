//GENERATE N TERMS OF FIBONACCI SERIES

#include<iostream.h>
#include<stdlib.h>

void main()
{

	int n1, n2, n3=0,i,n,ch;

	cout<<"\n Enter first term =";
	cin>>n1;

	cout<<"\n Enter second term=";
	cin>>n2;
	
    cout<<"\n Enter no of terms to be displayed=";
	       cin>>n;

        	cout<<"\n Series:";

	       cout<<"\n "<<n1<<"\n "<<n2;
            i=1;
         	while(i<=(n-2))
			{
				n3=n1+n2;
				n1=n2;
				n2=n3;
				cout<<"\n "<<n3;
				i++;

			}


	cout<<endl;
}
