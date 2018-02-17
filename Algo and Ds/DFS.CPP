//IMPLEMENTING DFS
#include<iostream>
using namespace std;


class node
{
   public:
   int key,d;
   node *next, *p;
   char color;
   int fin_time;

   node()
   {
     key=0;
     d=999;
     p=0;
     next=0;
     color='W';
	 fin_time=0;
   }
};


class list
{
	public:
	node *head;

	list()
	{
		head=0;
	}
	void addnode(int);
};

void list ::addnode(int x)
{
	node *temp=new node();
	temp->key=x;
    node *temp1=head;
	while(temp1->next!=0)
    {
		temp1=temp1->next;
    }
    temp1->next=temp;
    temp->p=head;	
}

class graph
{

	int v;
	list *a;
	int time;

public:

	graph(int x)
   {
	   v=x;
       a=new list[v];
		 
	   for (int i = 0; i < v; ++i)
	   {
		   a[i].head = new node();
		   a[i].head->key=i+1;
	   }
	}                  
   
   void insert();
   void display();
   void dfs();
   void dfs_visit(int);
   void display_f();

};

void graph::insert()
{
	int z;
	char ch;

    for(int i=0;i<v;i++)
    {
		ch='y';
		while(ch=='y')
		{
			cout<<"\n Enter the edge of "<<a[i].head->key<<endl;
			cin>>z;
			
			if(z>0&&z<=v)
				a[i].addnode(z);
			else
				cout<<"Vertex not in graph\n";
			
			cout<<"more edges : ";
			cin>>ch;
		}
    }
}

void graph::display()
{
	node *temp;
    for(int i=0;i<v;i++)
    {	
      cout<<"\n\n Vertex "<<a[i].head->key<<" : ";
      temp=a[i].head;
    
	  while(temp->next!=0)
      {
		cout<<temp->key<<"->";
		temp=temp->next;
      }
      cout<<temp->key;
    }
}

void graph::dfs()
{
	int u;
	for(u=0;u<v;u++)
	{
		a[u].head->color='W';
		a[u].head->p=0;
	}
	time=0;
	for(u=0;u<v;u++)
	{
		if(a[u].head->color=='W')
			dfs_visit(u);
	}
}

void graph::dfs_visit(int u)
{
	int v1;
	time=time+1;
	a[u].head->d=time;
	a[u].head->color='G';

	node *temp;
	temp=a[u].head;
	while(temp->next!=0)
	{
		temp=temp->next;
		v1=temp->key;
		v1--;
		if(a[v1].head->color=='W')
		{
			a[v1].head->p=a[u].head;
			dfs_visit(v1);
		}
	}
	a[u].head->color='B';
	time=time+1;
	a[u].head->fin_time=time;
}

void graph::display_f()
{
    for(int i=0;i<v;i++)
    {	
      cout<<"\n\n Vertex "<<a[i].head->key<<" : "<<a[i].head->fin_time;
    }
}


void main()
{
   int op,n;
   char ch;
   cout<<"\n Enter the no. of vertices :: ";
   cin>>n;
   graph G(n);

   do 
   {
	   cout<<"\n MENU";
	   cout<<"\n INPUT EDGES :";
	   cout<<"\n VIEW ADJACENCY ";
	   cout<<"\n VIEW FINISHING TIME FOR DFS OF THE GRAPH:";
	   cout<<"\n Enter your choice";
	   cin>>op;
	   
	   switch(op)
	   {
		case 1:cout<<"\n INSERTING EDGES...............";
			   G.insert();
			   break;
		case 2:cout<<"\n VIEW ADJACENCY ................";
			   G.display();
			   break;
		case 3:cout<<"\n VIEW FINISHING TIME FOR DFS OF THE GRAPH";
			   G.dfs();
			   G.display_f();
			   break;
		default:cout<<"\n Wrong Choice ";
	   }

		cout<<"\n Do you want to continue:";
		cin>>ch;
   }
   while(ch=='y' || ch=='Y');
}
