//LINEAR SEARCH USING RECURSION

#include<iostream>
using namespace std;

class ln_srch
{
public:

	int ln(int arr[],int s, int i,int ele)
	{
		if(i<s)
		{
			if(arr[i]==ele)
			{
				return i;
			}
			else
			{
				return ln(arr,s,i+1,ele);
			}
		}
		else
			return -1;
	}
};

void main()
{   ln_srch L;
	int ele , arr[50], size,pos;
	cout<<"\n How many elements?";
	cin>>size;

	cout<<"\n Enter elements=";
	for(int i=0;i<size;i++)
	cin>>arr[i];

	cout<<"\n Which element";
	cin>>ele;

	pos=L.ln(arr,size,0,ele);

	if(pos==-1)
		cout<<"\n Element not found";
	else
		cout<<"\n Position="<<pos+1;
}
