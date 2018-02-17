//ADD TWO LARGE NUMBERS

#include<iostream>
using namespace std;

template <class T, int size=50>
class stack
{
	T a[size];
	int top;

	public:
		stack()
		{
			top=-1;
		}

		void push(T);
		T pop();
		void display();
		
		void clear()
		{
			top=-1;
		}

		int isempty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}

		int isfull()
		{
			if(top==size-1)
				return 1;
			else
				return 0;
		}

};


template <class T, int size>
void stack<T,size>::push(T x)
{
	if(isfull()==0)
	{
		++top;
		a[top]=x;
	}
	else
	{
		cout<<"\n Element can not be pushed into the array";
	}
}

template<class T, int size>
T stack<T,size>::pop()
{
	T x;
	if(isempty()==0)
	{
		x=a[top];
		top--;
	}

	return x;
}

template<class T, int size>
void stack<T, size>::display()
{
	int i=top;
	while(i>=0)
	{
		cout<<a[i];
		i--;
	}
}


void main()
{
	stack<int,50> S1,S2,S3;
	int i,x,y,res=0,n;

	cout<<"\n Enter number of digits:";
	cin>>n;

	cout<<"\n Enter elements of first stack:";
	for(i=0;i<n;i++)
	{
		cin>>x;
		S1.push(x);
	}

	
	cout<<"\n Enter elements of second stack:";
	for(i=0;i<n;i++)
	{
		cin>>x;
		S2.push(x);
	}

	while(S1.isempty()==0 || S2.isempty()==0 )
	{
		if(S1.isempty()==0)
		{
			x=S1.pop();
		}
		else
		{
			x=0;
		}

		
		if(S2.isempty()==0)
		{
			y=S2.pop();
		}
		else
		{
			y=0;
		}

		res=res+x+y;

		S3.push(res%10);

		res=res/10;

	}

	if(res!=0)
	{
		S3.push(res);

	}

	cout<<"\n RESULT: ";
	S3.display();
	cout<<endl;
}


