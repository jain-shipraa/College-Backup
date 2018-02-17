//QUESTION 44 PG 222

#include<iostream>
using namespace std;

void main()
{
	int num1;

	cout<<"\n Enter any number=";
	cin>>num1;

	if(num1==9||num1==2||num1==3||num1==10)
	{
		if(num1==10)
		{
			num1=num1*num1;
		}
		else
		{
			if(num1==9)
			{
				cout<<"\n Enter another value=";
				cin>>num1;
			}
			else
			{
				num1=num1*99;
			}	}
	}
    else
	{
		cout<<"\n Invalid value recieved";

	}

	cout<<"\n RESULT:"<<num1;
	}


	