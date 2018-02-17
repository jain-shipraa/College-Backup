//PRIME NO.

#include<iostream.h>

void main()
{
	int i=2,n,num,flag=0;
     
	cout<<"\n Enter any number=";
	cin>> num;

	if(num==1)
	{
		cout<<"\n Neither prime nor cons";
		
	}
    else
	{
		n=num;
		while(i<=(n/2))
		{
			if((n%i)==0)
				flag=1;
			i++;

		}
			
		if(flag==0)
		cout<<num<<"is prime";
       	else
		cout<<num<<"is not prime";


	}

	cout<<endl;


}