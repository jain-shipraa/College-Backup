//IMPLEMENTING BFS
#include<iostream>
using namespace std;

//THE NODE FOR QUEUE CLASS......................................................
template<class T>
class qnode
{
	public:
		T info;
		qnode *next;
		qnode(T x, qnode *n=NULL)
		{
			info=x;
			next=n;
		}
};
 
//THE QUEUE CLASS.........................................................
template<class T>
class queue
{
	qnode<T> *front,*rear;

	public:

		queue()
		{
			front=rear=NULL;
		}

		void enqueue(T);
		T dequeue();
		int isempty();
};


template<class T>
void queue<T>::enqueue(T x)
{
	qnode<T> *temp=new qnode<T>(x);

	if(isempty())
	{
		front=rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}


template<class T>
int queue<T>::isempty()
{
	if(front==NULL)
		return 1;
	else 
		return 0;
}


template<class T>
T queue<T>::dequeue()
{
	qnode<T> *temp;
	T x;
	x=front->info;

	if(front==rear)
	{
		delete front;
		front=rear=NULL;
	}
	else
	{
		temp=front;
		front=front->next;
		delete temp;
	}

	return x;

} 

//THE VERTEX NODE...........................................................................
class node
{
   public:
   int key,d;
   node *next, *p;
   char color;
   node()
   {
     key=0;
     d=999;
     p=0;
     next=0;
     color='W';
     
   }
   
};

//THE LIST OF SUCH NODES.....................................................................
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

//THE GRAPH CLASS............................................................................
class graph
{
	int v;
	list *a;

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
   void bfs(int s);
   void print_path(int s, int v);
   void view_shortpath();
};

void graph::insert()
{
	int z;
	char ch='y';

    for(int i=0;i<v;i++)
    {
		ch='y';
		while(ch=='y')
		{
			cout<<"\n Enter the edge of "<<a[i].head->key<<"=";
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

void graph::bfs(int s)
{
	int u,v1;

	for(u=0;u<v;u++)
	{
		a[u].head->color='W';
		a[u].head->d=999;
		a[u].head->p=0;


		if(u==s-1)
		{

			a[u].head->color='G';
			a[u].head->d=0;
			a[u].head->p=0;
		}
	}

	queue<int> Q;
	Q.enqueue(s);
	node *temp;

	while(!Q.isempty())
	{
		u=Q.dequeue();
		u=u-1;
		temp=a[u].head;
		
		while(temp->next!=0)
		{
			temp=temp->next;
			v1=temp->key;
			cout<<v1-1<<" ";
			v1--;
			if(a[v1].head->color=='W')
			{
				a[v1].head->color='G';
				a[v1].head->d=a[u].head->d+1;
				a[v1].head->p=a[u].head;
				Q.enqueue(v1+1);
			}
		}

		a[u].head->color='B';
	}
}

void graph::print_path(int s, int v)
{
	if(v==s)
	{
		s=s-1;
		cout<<a[s].head->key<<" ";
	}
	else if(a[v-1].head->p==0)
	{
		cout<<"\n No path from "<<v<<" to "<<s <<" exists";
	}
	else
	{
		print_path(s,a[v-1].head->p->key);
		cout<<v<<" ";
	}
}

void graph::view_shortpath()
{
	int s;

	cout<<"\n Enter the source vertex:";
	cin>>s;

	bfs(s);

	cout<<"\n Shortest path of each vertex from "<<s<<"  is.....";
	for(int i=1; i<=v; i++)
	{
		cout<<"\n For vertex["<<i<<"]:";
		print_path(s,i);
		cout<<endl;
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
		cout<<"\n VIEW SHORTEST PATH OF VERTICES FROM A SOURCE VERTEX:";
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
		case 3:cout<<"\n VIEW SHORTEST PATH OF VERTICES FROM A SOURCE VERTEX:";
			   G.view_shortpath();
			   break;
		default:cout<<"\n Wrong Choice ";
		}

		cout<<"\n Do you want to continue:";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');

}