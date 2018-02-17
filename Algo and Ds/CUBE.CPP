//TO IMPLEMENT A LOOP USING RECURSION

#include<iostream>
using namespace std;

class cube
{
public:

	void prcube(int n)
	{
		if(n>=1)
		{
			prcube(n-1);
			cout<<n*n*n<<" ";
		}
	}
};


void main()
{
	cube C;
	int max;

	cout<<"\n Enter maximum number=";
	cin>>max;

	C.prcube(max);
}

