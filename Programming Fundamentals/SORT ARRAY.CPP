//TO SORT ARRAY OF STRINGS

#include<iostream>
#include<string>
using namespace std;

void main()
{
	char str[10][25],temp[25];
	int i,j,n;

	cout<<"\n Enter how many strings do you want ?";
	cin>>n;

	for(i=0;i<n;i++)
	{

	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}


	cout<<"\n Sorted array....";

	for(i=0;i<n;i++)
		cout<<str[i]<<endl;
}

