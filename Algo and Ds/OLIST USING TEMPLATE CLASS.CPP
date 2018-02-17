//ORDERED LIST USING TEMPLATE CLASS

#include<iostream>
using namespace std;

template <class T>
class node
{
	public:
		T info;
		node *next;
		
		node(T x, node *n=0)
		{
			info=x;
			next=n;
		}
};

template<class T>
class OList
{
	node<T> *head;

	public:

		OList()
		{
			head=NULL;
		}

		int isempty();
		void deletion(T);
		void insertion(T);
		OList<T> merge(OList<T>);
		void display();

};


template<class T>
int OList<T>::isempty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

template<class T>
void OList<T>::deletion(T x)
{
	node<T> *temp,*prev;
	if(head->next==NULL && head->info==x)
	{
		delete head;
		head=NULL;
	}
	else if(head->info==x)
	{
		temp=head;
		head=head->next;
		delete temp;
	}
	else 
	{
		prev=head;
		temp=head->next;

		while(temp!=NULL && temp->info!=x)
		{
			prev=temp;
			temp=temp->next;
		}

		if(temp!=NULL)
		{
			prev->next=temp->next;
			delete temp;
		}
		else
		{
			cout<<"\n Element not Found";
		}
	}
}

template<class T>
void OList<T>::insertion(T x)
{
	node<T> *temp=new node<T>(x);

	if(isempty())
	{
		head=temp;
	}
	else
	{
		node<T> *cur,*prev;

		cur=head;
		if(cur->info>=temp->info)
		{
			temp->next=cur;
			head=temp;
		}
		else
		{
			cur=head->next;
			prev=head;

			while(cur!=NULL &&  cur->info<temp->info)
			{
				prev=cur;
				cur=cur->next;
			}

			if(cur!=NULL)
			{
				temp->next=cur;
				prev->next=temp;
			}
			else
			{
				prev->next=temp;
			}
		}
	}
}


template<class T>
OList<T> OList<T>::merge(OList<T> O1)
{
	OList<T> O3;
	node<T> *temp,*temp1;
	temp=head;
	temp1=O1.head;

	while(temp!=NULL && temp1!=NULL)
	{
		if(temp->info>temp1->info)
		{
			O3.insertion(temp1->info);
			temp1=temp1->next;
		}
		else if(temp->info<temp1->info)
		{
			O3.insertion(temp->info);
			temp=temp->next;
		}
		else
		{
			O3.insertion(temp->info);
			temp=temp->next;
			temp1=temp1->next;
		}
	}

	if(temp!=NULL)
	{
		while(temp!=NULL)
		{
			O3.insertion(temp->info);
			temp=temp->next;
		}
	}
	else
	{
		while(temp1!=NULL)
		{
			O3.insertion(temp1->info);
			temp1=temp1->next;
		}
	}

	return O3;
}

template<class T>
void OList<T>::display()
{
	node<T> *temp;
	temp=head;

	while(temp!=NULL)
	{
		cout<<" "<<temp->info;
		temp=temp->next;
	}
}

void main()
{

	OList<int> O1,O2,O3;
	int ch,x;
	char op;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INSERTION:";
		cout<<"\n 2. DELETION";
		cout<<"\n 3. MERGE ";
		cout<<"\n 4. DISPLAY";
		cout<<"\n ENTER A CHOICE:";
		cin>>ch;

		switch(ch)
		{
		case 1: cout<<"\n INSERTION";
			    cout<<"\n Enter an elsment to insert into the list:";
				cin>>x;
				O1.insertion(x);
				break;
		case 2: cout<<"\n DELETION";
			    if(O1.isempty()==0)
				{
					cout<<"\n Enter the element to be deleted:";
					cin>>x;
					O1.deletion(x);
				}
				else
					cout<<"\n No element to be deleted";

				break;
		case 3: cout<<"\n MERGE:";
			    cout<<"\n You have to create another list to be merged";
				op='y';
				while(op=='y'|| op=='Y')
				{
					cout<<"\n Enter element";
					cin>>x;
					O2.insertion(x);
					cout<<"\n Want to enter more?";
					cin>>op;
				}

				cout<<"\n MERGED LIST....";
				O3=O1.merge(O2);
				O3.display();
				break;
		case 4: cout<<"\n DISPLAY";
			    O1.display();
				cout<<endl;
				break;
		default: cout<<"\n WRONG CHOICE!!!";
		}

		cout<<"\n Do you want to continue?";
		cin>>op;
	}
	while(op=='y' || op=='Y');
}


