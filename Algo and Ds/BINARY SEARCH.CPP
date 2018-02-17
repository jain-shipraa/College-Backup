//BINARY SEARCH USING RECURSION 

#include<iostream>
using namespace std;

class bin
{

	int mid;

public:
	int bn_srch(int arr[],int frst, int last, int ele)
	{
	
		if(frst<=last)
		{
			mid=(frst+last)/2;
			if(arr[mid]>ele)
				return bn_srch(arr,frst,mid-1,ele);
			else if(arr[mid]==ele)
				return mid;
			else
				return bn_srch(arr,mid+1,last,ele);
		}
		else
			return -1;
	}

};

void main()
{
	bin B;
	int ele , arr[50], size,pos;
	cout<<"\n How many elements?";
	cin>>size;

	cout<<"\n Enter elements=";
	for(int i=0;i<size;i++)
	cin>>arr[i];

	cout<<"\n Which element";
	cin>>ele;

	pos=B.bn_srch(arr,0,size-1,ele);

	if(pos==-1)
		cout<<"\n Element not found";
	else
		cout<<"\n Position="<<pos+1;
}
