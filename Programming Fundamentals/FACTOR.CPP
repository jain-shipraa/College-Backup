//FACTORS

#include<iostream.h>

void main()
{
	int i=2,n,num,flag=0;
     
	cout<<"\n Enter any number=";
	cin>> num;

	if(num==1)
	{
		cout<<"\n FACTOR=1";
		
	}
    else
	{
		cout<<"\n Factors :\n1";

		n=num;
		while(i<=(n/2))
		{
			if((n%i)==0)
				cout<<" \n"<<i;
			i++;

		}
		cout<<"\n"<<num;
		
	}

	cout<<endl;

}