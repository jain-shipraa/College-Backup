#include<iostream>
#include<string>
using namespace std;

class LCS
{
	char X[50],Y[50];
	int m,n,**b,**c;


public:

	LCS()
	{
		m=n=0;
	}

	void input();
	void LCS_LENGTH();
	void PRINT_LCS(int i, int j);
	void PRINT_LCS();
};

void LCS::PRINT_LCS()
{
	PRINT_LCS(m,n);
}

void LCS::input()
{
	cout<<"\n Enter Sequence 1:";
	cin>>X;

	cout<<"\n Enter another Sequence 2 :";
	cin>>Y;

	m=strlen(X);
	n=strlen(Y);
}


void LCS::LCS_LENGTH()
{
	int i,j;

	b=new int*[m+1];
	for(i = 0; i <=m; ++i)
		b[i] = new int[n+1];

	c=new int*[m+1];
	for(i=0;i<=m;i++)
		c[i]=new int[n+1];


	for(i=0;i<m;i++)
		c[i][0]=0;

	for(j=0;j<n;j++)
		c[0][j]=0;

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
	}


	cout<<"\n Longest Common Sequence Length :"<<c[m][n];
}

void LCS::PRINT_LCS(int i, int j)
{
	if (i==0 || j==0)
	{
		return;
	}
	if(b[i][j]==1)
	{
		PRINT_LCS(i-1,j-1);
		cout<<X[i-1];
	}
	else if(b[i][j]==2)
	{
		PRINT_LCS(i-1,j);
	}
	else
	{
		PRINT_LCS(i,j-1);
	}
}

void main()
{
	LCS L;
	int op;
	char ch;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INPUT";
		cout<<"\n 2. FIND SUBSEQUENCE AND DISPLAY";
		cout<<"\n Enter your choice=";
		cin>>op;

		switch(op)
		{
		case 1: cout<<"\n INPUT";
                L.input();
				break;
		case 2: cout<<"\n FIND SUBSEQUENCE AND DISPLAY";
			    L.LCS_LENGTH();
				L.PRINT_LCS();
				break;
		}

		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}

