// TO  PRINT  DESIGN 
#include<iostream>
#include<iomanip>
using namespace std;

void main()
{


	int i,j,n=1,r;

	cout<<"\n Enter rows=";
	cin>>r;



	for(i=0;i<r;i++)
	{


		if(i<r-1)
		cout<<setw(r-i-1)<<" ";


		for(j=0;j<n;j++)
			cout<<"*";

		n+=2;
		cout<<endl;

	}

}
