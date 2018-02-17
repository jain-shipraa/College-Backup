//DESIGN 1  12321  ....

#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	int i,j,r,n=1,num;

	cout<<"\n Enter rows=";
	cin>>r;

	for(i=r;i>=1;i--)
	{
		
		    if(i>1)
			cout<<setw(2*(i-1))<<" ";

			num=n/2;

        	for(j=0;j<n;j++)
			{
				
				if(j<=n/2)
					cout<<j+1;
				else
					cout<<num--;
			}


		n+=4;
		cout<<endl;


	}

}
