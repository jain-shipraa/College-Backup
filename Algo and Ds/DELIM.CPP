//DELIMITER MATCHING USING STACK

#include<iostream>
using namespace std;


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
	    int delim(char[]);
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
int stack<T>::delim(char str[])
{
	int i=0;
	char ch;

	while(str[i]!='\0')
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
		{
			push(str[i]);
		}
		else if(str[i]==')' || str[i]=='}' || str[i]==']')
		{
			ch=pop();

			if(ch=='(' && str[i]!=')')
				return 0;
			else if(ch=='[' && str[i]!=']')
				return 0;
			else if(ch=='{' && str[i]!='}')
				return 0;
		}
		else if(str[i]=='/')
		{
			ch=str[i+1];
			if(ch=='*')
			{
				int j;

				for(j=i+2; str[j]!='*' && str[j]!='\0' ;j++)
				{
					if(str[j+1]=='*')
					{
						if(str[j+2]!='/')
							j++;
					}
				}
				
				if(str[j]!='\0')
				{
					if(str[j+1]=='\0')
						return 0;
					else if(str[j+1]!='/')
						return 0;
				}
				else 
					return 0;
				i=j; 
			}
			else
			{
				i++;
				continue;
			}

		}

		i++;
	}

	if(isempty())
		return 1;
	else
		return 0;
}



void main()
{
	char str[50];
	stack<char> S1;
	int i;

	cout<<"\n Enter  expresion:";
	cin>>str;

	i=S1.delim(str);
	if(i==1)
		cout<<"\n Well Formed Formula";
	else
		cout<<"\n Not Well Formed Formula";
	cout<<endl;
}

