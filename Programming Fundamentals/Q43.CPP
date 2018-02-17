//QUESTION 43 PG 293

#include<iostream>

using namespace std;

void main()
{

	int i,j,r,n=1;

	cout<<"\n Enter number of rows=";
	cin>>r;


	for(i=1;i<=r;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"*";
		}

		if(i<r/2)
		    n+=2;
		else if(i>=(r/2)+1)
			n-=2;
		cout<<endl;

	}

}


