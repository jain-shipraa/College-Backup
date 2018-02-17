//QUESTION 1 TO USE COMMAND LINE

#include<cstring>
#include<iostream>
using namespace std;

void main(int argc,char* argv[])
{
	int i,count=0,j;
	char str[20];

	for(i=0;i<argc;i++)
	{
		cout<<argv[i];
		cout<<endl;
	}

	strcpy(str,argv[1]);

	for(i=0;i<=122;i++)
	{
		for(j=0;str[j]!='\0';j++)
		{

			if(str[j]==(char)i)
				count++;
		}

		if(count)
		{
			cout<<char(i)<<" "<<count<<endl;
			count=0;
		}
	}
}
