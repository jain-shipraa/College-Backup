// TO IMPLEMENT BUCKET SORT

#include<iostream>
#include<cmath>
using namespace std;

class node
{
 
public:
	int info;
	node *next;
    node(int p)
	{
		info=p;
		next=NULL;
	}
};

class list
{
	node *head, *tail;

public:

	list()
	{
		head=tail=NULL;
	}

	void insert(int p);


	int deletefromhead()
	{
		int x=head->info;
		node* temp;

		if(head==tail)
		{
			delete head;
			head=NULL;
		}
		else
		{
			temp=head;
			head=head->next;
			delete temp;
		}

		return x;
	}

	int listempty()
	{
		if(head==NULL)
			return 1;
		else
			return 0;
	}

	void disp();
	
};

void list::insert(int p)
{
		node *n=new node(p);

		if(head==NULL)
		{
			head=tail=n;
		}
		else if(head->info>p)
		{
			n->next=head;
			head=n;
		}
		else
		{
			node*prev,*temp;

			prev=head;
			temp=prev->next;

			while(temp->info<p && temp!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}

			if(temp!=NULL)
			{
				prev->next=n;
				n->next=temp;
			}
			else
			{
				prev->next=n;
				tail=n;
			}
		}
}

void list::disp()
{
	node*temp;
	for(temp=head;temp!=NULL;temp=temp->next)
			cout<<temp->info<<" ";
}

class bsort
{
	int arr[50];
	int size;

public:

	bsort()
	{
		size =0;
	}

	void input();
	void bucket_sort();
	void display();
	int nod();

};

void bsort::bucket_sort()
{
	list bucket[10];
	int x,i,k=0;

	for(i=0;i<size;i++)
	{
		x=arr[i]/(pow(10,nod()-1));
		bucket[x].insert(arr[i]);
		
	}

	for(i=0;i<10;)
	{
		while(!bucket[i].listempty())
		{
			x=bucket[i].deletefromhead();
			arr[k]=x;
			k++;
		}
		i++;
	}

}

void bsort::input()
{	
	int i;

	cout<<"\n Enter the number of elements =";
	cin>>size;

	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
}

void bsort::display()
{

	int i;

	for(i=0;i<size;i++)
	{
		cout<<"  "<<arr[i];
	}
}

int bsort::nod()
{
	int i=0,x;
	x=arr[0];
	while(x!=0)
	{
		x/=10;
		i++;
	}

	return i;
}

void main()
{
	bsort O1;

	int op;
	char ch;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INPUT";
		cout<<"\n 2. SORT";
		cout<<"\n 3. DISPLAY:";
		cout<<"\n Enter your choice=";
		cin>>op;

		switch(op)
		{
		case 1: cout<<"\n INPUT";
			    O1.input();
				break;
		case 2: cout<<"\n SORTED ARRAY....";
			    O1.bucket_sort();
	            O1.display();
				break;
		case 3: cout<<"\n DISPLAY....";
			    O1.display();
		}


		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}



