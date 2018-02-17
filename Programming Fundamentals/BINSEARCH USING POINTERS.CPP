//BINARY SEARCH USING POINTERS

#include<iostream>
using namespace std;

int binsearch(int arr[],int size,int target,int** loc)
{
	int *f=arr;
	size--;
	int *l=(f+size);
	int *mid;

	while(f<=l)
	{
		mid=f+(l-f)/2;

		if(target==*mid)
		{ *loc=mid;
			return(1);
		}
		else if(target<*mid)
			l=mid-1;
		else
			f=mid+1;
	}
	*loc=NULL;
	return(0);
}

void main()
{
	int arr[25],s,found,ele,*loc;

	cout<<"\n Enter how many elements:";
	cin>>s;

	for(int i=0;i<s;i++)
	{
		cin>>arr[i];
	}

	cout<<"\n What element do you want to search?";
	cin>>ele;

	found=binsearch(arr,s,ele,&loc);

	if(found)
	{
		cout<<"\n Element found";
		cout<<"\n Position="<<(loc-arr)+1;
	}
	else 
		cout<<"\n Element not found";
}


