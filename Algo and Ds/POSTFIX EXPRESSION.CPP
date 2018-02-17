//WAP TO EVALUATE POSTFIX EXPRESSION USING STACK

#include<iostream>
using namespace std;
#include<ctype.h>

template<class T>
class node
{
	public:
		T info;
		node *next;
		node(T x, node *n=NULL)
		{
			info=x;
			next=n;
		}
};

//STACK CLASS
 
template<class T>
class stack
{
	node<T> *top;

	public:

		stack()
		{
			top=NULL;
		}

		void push(T);
		T pop();
		void display();
		T topel();
		void clear();
		int isempty();
		void evaluate(char[]);
};

template<class T>
void stack<T>::push(T x)
{
	node<T> *temp=new node<T>(x);

	if(isempty())
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}

template<class T>
int stack<T>::isempty()
{
	if(top==NULL)
		return 1;
	else 
		return 0;
}

template<class T>
T stack<T>::pop()
{
	node<T> *temp;
	T x;
	x=top->info;

	if(top->next==NULL)
	{
		delete top;
		top=NULL;
	}
	else
	{
		temp=top;
		top=top->next;
		delete temp;
	}

	return x;

}

template<class T>
void stack<T>::display()
{
	node<T> *temp;
	temp=top;
	while(temp!=NULL)
	{
		cout<<temp->info;
		temp=temp->next;
	}
}

template<class T>
T stack<T>::topel()
{
	T x;
	x=top->info;
	return(x);
}

template<class T>
void stack<T>::clear()
{
	T x;
	while(top!=NULL)
	{
		x=pop();
	}

	top=NULL;
}


template<class T>
void stack<T>::evaluate(char str[])
{
	int i=0,x1,x2;
	
	while(str[i]!='\0')
	{
		if(isdigit(str[i]))
		{
			push(str[i]-48);
		}
		else if(str[i]>=42  && str[i]<=47)
		{
			x1=pop();
			x2=pop();

			switch(str[i])
			{
			case '+':push(x1+x2);
				     break;
			case '-':push(x2-x1);
				     break;
			case '*':push(x1*x2);
				     break;
			case '/':push(x2/x1);
				     break;
			default :cout<<"\n Wrong Choice";
				     break;
			}
		}
		i++;

	}
	
		cout<<"\n RESULT:"<<pop();

}

				 
void main()
{
	char str[50];
	stack<int> S1;

	cout<<"\n Enter postfix expresion:";
	cin>>str;

	S1.evaluate(str);
	cout<<endl;
}












