//SUM OF N NUMBER USING RECURSION 

#include<iostream>
using namespace std;

class sum
{
public:

int add(int arr[], int s)
{
	if(s>0)
	{
        return arr[s]+add(arr,s-1);
	}
	else
		return arr[0];
}

};

void main()
{
	int arr[50],size,res;
	sum S;

	cout<<"\n Enter how many elements?";
	cin>>size;

	for(int i=0;i<size;i++)
		cin>>arr[i];

	res=S.add(arr,size-1);
	cout<<"\n Result="<<res;
}

