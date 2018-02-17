//STACK IMPLEMENTATION USING ARRAY

#include<iostream>
using namespace std;

template <class T, int size=10>
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
		T topel();
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
T stack<T , size>::topel()
{
	return (a[top]);
}

template<class T, int size>
void stack<T, size>::display()
{
	int i=top;
	while(i>=0)
	{
		cout<<" "<<a[i];
		i--;
	}
}

void main()
{
    stack<int,5> S1;
	int x, ch;
	char op;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. PUSH ELEMENT";
		cout<<"\n 2. POP ELEMENT";
		cout<<"\n 3. TOP MOST ELEMENT";
		cout<<"\n 4. DISPLAY";
		cout<<"\n 5. CLEAR";
		cout<<"\n ENTER A CHOICE";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\n PUSH";
			   cout<<"\n Enter an element";
			   cin>>x;
			   if(S1.isfull()==0)
			   {
				   S1.push(x);
			   }
			   else
				   cout<<"\n OVERFLOW";

			   break;
		case 2:cout<<"\n POP";
			   if(S1.isempty()==0)
			   {
				   x=S1.pop();
				   cout<<"\n Element popped:"<<x<<endl;
			   }
			   else
				   cout<<"\n UNDERFLOW";
			   break;
		case 3:if(!S1.isempty())
			   {
				   x=S1.topel();
			       cout<<"\n TOP MOST ELEMNT:"<<x;
			   }
			   else
				   cout<<"\n No element yet to display";

			   break;
		case 4:if(S1.isempty()==0)
			   {
				   S1.display();
			   }
			   else
				   cout<<"\n No element to be  displayed";
			   break;
		case 5:S1.clear();
			   break;
		}
		cout<<"\n Do you want to continue?";
		cin>>op;
	}
	while(op=='Y' || op=='y');
}
