//IMPLRMRNTATION OF RANDOMIZE SELECT

#include<iostream>
using namespace std;

class rselect
{
	int arr[50];
	int size;

public:

	rselect()
	{
		size=0;
	}
	void input();
	int rpartition(int,int);
	int randselect(int, int , int);
	void select();
	void display();
};

void rselect::input()
{
	cout<<"\n Enter the size of the array:";
	cin>>size;
	cout<<"\n Enter elements:";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
}

int rselect::rpartition(int p, int r)
{
	int i,j,x,temp;

	x=rand()%(r-p+1)+p;
	
	temp=arr[x];
	arr[x]=arr[r];
	arr[r]=temp;

	x=arr[r];

	i=p-1 ;

	for(j=p;j<r;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		
		}

	}

	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;

	return (i+1);
}


int rselect::randselect(int p, int r, int i)
{
	int q,k;

	if(p==r)
		return arr[p];
	q=rpartition(p,r);
	k=q-p+1;

	if(i==k)
		return arr[q];
	else if(i<k)
		return randselect(p,q-1,i);
	else
		return randselect(q+1,r,i-k);
}


void rselect::select()
{
	int i,val;
	cout<<"\n Enter the index you want to search:";
	cin>>i;

	val=randselect(0,size-1,i);

	cout<<" Value at "<<i<<" index ="<<val<<endl;
}


void rselect::display()
{
	for( int i=0;i<size;i++)
		cout<<" "<<arr[i];

	cout<<endl;
}

void main()
{
	rselect R;
	int op;
	char ch;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INPUT";
		cout<<"\n 2. SELECTING Ith ELEMENT:";
		cout<<"\n 3. DISPLAY";
		cout<<"\n Enter your choice";
		cin>>op;

		switch(op)
		{
			case 1:cout<<"\n Inputing......";
				   R.input();
				   cout<<endl;
				   break;
			case 2:cout<<"\n Selecting ith element....";
				   R.select();
				   cout<<endl;
				   break;
			case 3:cout<<"\n Displaying.....";
				   R.display();
				   cout<<endl;
				   break;
			default:cout<<"\n You entered a wrong choice";
		}
		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y'||ch=='Y');
}
