//TO CHECK WHETHER A STRING IS PALINDROME OR NOT 

#include<iostream>
using namespace std;

class pal
{
public:
	
	int palin(char arr[], int i, int j, int s)
	{
	if(arr[i]==arr[j] && i<s/2-1)
	{
		return palin(arr,i+1,j-1,s);
	}
	else if(i==s/2-1)
	{
		if(arr[i]==arr[j])
			return 0;
		else
			return 1;
	}
	else
		return 1;
	}

};


void main()
{
	char arr[50],size;
    pal P; 
	int status;


	cout<<"\n Enter a string =";
	cin>>arr;

	for(int i=0;arr[i]!='\0';i++);
	size=i;

	status=P.palin(arr,0,size-1,size);

	if(status==0)
		cout<<"\n Palindrome";
	else
		cout<<"\n Not palindrome";
}
