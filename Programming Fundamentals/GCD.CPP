//GCD BY ANOTHER METHOD

#include<iostream>
using namespace std;

void main()

{

	int n1, n2,temp,gcd,d,div;

	cout<<"\n Enter any two numbers=";
	cin>>n1>>n2;


           if(n1==0 || n2==0)
		   { d=1;
		   }
 		   else if(n1<n2)
		   {
			   d=n1;
			   div=n2;

		   }
		   else
		   {
			   d=n2;
			   div=n1;
		   }


		while(d!=0)
		{
			if(div%d==0)
			{
			gcd=d;
				break;
			}

			temp=div;
			div=d;
			d=temp%d;
			

		}

		cout<<"\n GCD="<<gcd<<endl;
}
