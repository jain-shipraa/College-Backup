//LINEAR SEARCH

#include<iostream>
using namespace std;

int const size=100;

int lin_search(int arr[],int s);

void main()
{
	int arr[size],s,i,flag;

	cout<<"\n Enter size of the array=";
	cin>>s;


	cout<<"\n Enter array elements";
	for(i=0;i<s;i++)
		cin>>arr[i];

	flag=lin_search(arr,s);


	if(!flag)
		cout<<"\n Element not found"<<endl;
	else
		cout<<"\n Position on which found="<<flag<<endl;

}

int lin_search(int arr[],int s)
{
	int ele,i;
	
	cout<<"\n Enter the element you want to search=";
	cin>>ele;


	for(i=0;i<s;i++)
	{
		if(arr[i]==ele)
		{
			return (i+1);
			
		}
	}

	return(0);
}