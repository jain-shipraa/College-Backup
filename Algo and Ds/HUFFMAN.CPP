#include<iostream>
using namespace std;

class node
{
public:
	char c;
	int f;
	node *l,*r;
	node* p;

	node(char c1=0,int fre=0,node* l1=0, node* r1=0, node* p1=0)
	{
		c=c1;
		f=fre;
		l=l1;
		r=r1;
		p=p1;
	}
};

class pque
{

	node* a[20];
	node* b[20];
	node* root;
	int len,heapsize;

public:

	pque()
	{
		root=0;
	}

	void input();
	int parent(int);
	int left(int);
	int right(int);
	void minheapify(int);
	void buildminheap();
	void insert(node*);
	void heap_dec(int,node *);
	node* heap_extract();
	void huff();
	void inorder(node*);
	void display();
	void display1(node *);
};

void pque::input()
{
	char c;
	int f;
	
	cout<<"\n Enter the size of the heap=";
	cin>>heapsize;
	len=heapsize;

	for(int i=0;i<heapsize;i++)
	{
		cout<<"\n Enter char :";
		cin>>c;
		cout<<"\n enter fre:";
		cin>>f;
		a[i]=new node(c,f);
		b[i]=a[i];
	}	
	buildminheap();
}

int pque::parent(int i)
{
	return ((i-1)/2);
}

int pque::left(int i)
{
	return ((2*i )+1);
}

int pque::right(int i)
{
	return ((2*i)+2);
}

void pque::minheapify(int i)
{

	int l, r, smallest;
	node *temp;

	smallest=i;
	l=left(i);
	r=right(i);

	if(l<heapsize && a[l]->f<a[i]->f)
		smallest=l;
	else
		smallest=i;

	if(r<heapsize && a[r]->f<a[smallest]->f)
		smallest=r;

	if(smallest!=i)
	{
		temp=a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
		minheapify(smallest);
	}

}
void pque::buildminheap()
{
	for(int i=(heapsize-1)/2; i>=0;i--)
	{
		minheapify(i);
	}
}

void pque::insert(node * n)
{
	
	a[heapsize]=n;
	heapsize++;
	heap_dec(heapsize,n);
	
}

void pque::heap_dec(int i, node * n)
{
	node* temp;
	a[i]=n;

	while(i>0 && a[parent(i)]->f>a[i]->f)
	{
		temp=a[parent(i)];
		a[parent(i)]=a[i];
        a[i]=temp;
		i=parent(i);
	}
}


node * pque::heap_extract()
{
	node *min;

	min=a[0];
	a[0]=a[heapsize-1];
	heapsize--;
	
	minheapify(0);
	return min;
}




void pque::huff()
{
	int n;
	n=heapsize;
	node *x;
	node *y;

	for(int i=0;i<n-1;i++)
	{
		node *z=new node();
		x=heap_extract();
		y=heap_extract();
		x->p=z;
		y->p=z;

		z->l=x;
		z->r=y;
		z->f=x->f+y->f;
	    insert(z);
	}

	root=heap_extract();
	cout<<"\n DISPLAYING INORDER OF TREE .....";
	inorder(root);
}


void pque::inorder(node *n)
{       
	if(n!=0)
	{ 
		inorder(n->l);
		cout<<n->c<<":"<<n->f<<" ";
		inorder(n->r);
	}
}

void pque::display()
{
	for(int i=0;i<len;i++)
	{
		cout<<endl<<"Huffman Code for :"<<b[i]->c<<" ";
		display1(b[i]);
	}
}

void pque::display1(node *t)
{
	if(t!=root)
	{
		if(t==t->p->l)
		{
			display1(t->p);
			cout<<"0";
		}
		else
		{
			display1(t->p);
			cout<<"1";
		}
	}
}



void main()
{
	pque P;
	int op;
	char ch;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INPUT";
		cout<<"\n 2. DISPLAY HUFFMAN CODE";
		cout<<"\n Enter your choice=";
		cin>>op;

		switch(op)
		{
		case 1: cout<<"\n INPUT";
			    P.input();
				break;
		case 2: cout<<"\n SORTED ARRAY....";
			    P.huff();
				P.display();
				break;
		}

		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}


