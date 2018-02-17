//STRING FUNCTION

#include<iostream>
#include<string>
using namespace std;

void main()
{
	char str[10],*p;

	cout<<"\n Enter a string=";
	cin>>str;

	p=str;

	for(int i=0;i<10;i++)
	{	
		cout<<"\n"<<(int)(p+i);//ADDRESS
	}

	char str2[25];

	cout<<"\n Enter another string:";
	cin>>str2;
	strcat(str2,str);
	cout<<"\n"<<str2;

	//calculating string length using pointers

	
	for( i=0;str[i]!='\0';i++)
	{ 
      p++;		
	}

	int q;
	q=(int)p-(int)str;
	cout<<"\n LENGTH:"<<q;
}


