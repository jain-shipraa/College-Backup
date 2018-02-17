//MATRIX OPERATIONS
#include<iostream>
using namespace std;

void input(int arr[][5],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<"\n Enter mat["<<i+1<<"]["<<j+1<<"]=";
		    cin>>arr[i][j];
		}

	}

}

void disp(int arr[][5],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		cout<<endl;
		for(j=0;j<c;j++)
		{
		 cout<<" "<<arr[i][j];
		}

	}

}

void add(int arr[][5],int ar2[][5],int res[][5],int r,int c)
{

	int i,j;
	res[5][5];

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			res[i][j]=arr[i][j]+ar2[i][j];
		}
	}

}


void sub(int arr[][5],int ar2[][5],int res_s[][5],int r,int c)
{

	int i,j;

	res_s[5][5];

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			res_s[i][j]=arr[i][j]-ar2[i][j];
		}
	}
}

void mult(int arr[][5],int const r1,int c1,int ar2[][5],int r2,int const c2,int pro[][5])
{
	int i,j,k;
	pro[r1][c2];


	if(c1==r2)
	{

	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{     
			pro[i][j]=0;
			for(k=0;k<c1;k++)
				pro[i][j]+=arr[i][k]*ar2[k][j];
		}
	}
	}

 	else
		cout<<"\n Entered matrices cannot be multiplied in the order requested";
}


void tran(int arr[][5],int r,int c)
{

	int i,j,temp;

	if(r==c || r>c)
	{

	for(i=0;i<r;i++)
		for(j=0;j<=i;j++)
		{
			temp=arr[i][j];
		    arr[i][j]=arr[j][i];
			arr[j][i]=temp;
		}
	}
	else
	{

	for(i=0;i<c;i++)
		for(j=0;j<=i;j++)
		{
			temp=arr[i][j];
		    arr[i][j]=arr[j][i];
			arr[j][i]=temp;
		}
	}

}




void main()

{

  int ch,a[5][5],ra,ca,b[5][5],rb,cb,ad[5][5],sb[5][5],pro[5][5];
  char op;



	do
	{
		cout<<"\n Menu";
		cout<<"\n 1. INPUT";
		cout<<"\n 2. ADD TWO MATRIX";
		cout<<"\n 3. SUBTRACT MATRICES";
        cout<<"\n 4. MULTIPLY THE TWO MATRICES";
		cout<<"\n 5. TRANSPOSE OF THE MATRIX";
		cout<<"\n 6. DISPLAY";
		cout<<"\n Enter your choice";
		cin>>ch;


		switch(ch)
		{
		case 1: cout<<"\n Inputting matrices";
			    cout<<"\n Which matrix do you want to input";
				cout<<"\n 1. MAT A";
                cout<<"\n 2. MAT B";
				cout<<"\n Enter choice=";
				cin>>ch;

				if(ch==1)
				{
					cout<<"\n Enter rows=";
					cin>>ra;
					cout<<"\n Enter columns";
					cin>>ca;

					input(a,ra,ca);
					
				}
				else if(ch==2)
				{
					
					cout<<"\n Enter rows=";
					cin>>rb;
					cout<<"\n Enter columns";
					cin>>cb;

					input(b,rb,cb);
				}
				else
					cout<<"\n Wrong choice";

				break;
        case 2:cout<<"\n Adding the two matrices";
			   if(ra==rb && ca==cb)
			   {
				   add(a,b,ad,ra,ca);
				   disp(ad,ra,ca);
			   }
			   else
				   cout<<"\n Entered matrices can not be added";

			   break;
		case 3:cout<<"\n Subtracting one matrix from the other";
			   if(ra==rb && ca==cb)
			   {
				   cout<<"\n Which matrix result do you want";
				   cout<<"\n 1. A-B";
				   cout<<"\n 2. B-A";
				   cin>>ch;

				   if (ch==1)
				   {
					   sub(a,b,sb,ra,ca);
					   disp(sb,ra,ca);
				   }
				   else if(ch==2)
				   {
					   sub(b,a,sb,ra,ca);
					   disp(sb,ra,ca);
				   }
				   else
					   cout<<"\n Wrong choice";
			   }
			   else
				   cout<<"\n Subtraction not possible";

				   break;
		case 4: cout<<"\n Multiply the two matrices";
			    cout<<"\n Which product do you want to see";
				cout<<"\n 1. A*B";
				cout<<"\n 2. B*A";
				cout<<"\n Enter choice=";
				cin>>ch;

				if(ch==1)
				{
					mult(a,ra,ca,b,rb,cb,pro);
					disp(pro,ra,cb);
				}
				else if(ch==2)
				{
					mult(b,rb,cb,a,ra,ca,pro);
					disp(pro,rb,ca);
				}
				else
					cout<<"\n Wrong choice";
				break;
		case 5:cout<<"\n Transpose of the matrix";
			   cout<<"\n Choices";
		       cout<<"\n 1. A";
			   cout<<"\n 2. B";
			   cout<<"\n Enter choice=";
			   cin>>ch;

			   if(ch==1)
			   { 
				   tran(a,ra,ca);
				 
				   ra+=ca;
				   ca=ra-ca;
				   ra=ra-ca;

				   disp(a,ra,ca);
			   }
			   else if(ch==2)
			   {
				   tran(b,rb,cb);
				   
				   rb+=cb;
				   cb=rb-cb;
				   rb=rb-cb;

				   disp(b,rb,cb);
			   }
			   else
				   cout<<"\n Wrong choice";
			   break;

        case 6:cout<<"\n Display";
			   cout<<"\n 1. A";
			   cout<<"\n 2. B";
			   cout<<"\n choice";
			   cin>>ch;

			   if(ch==1)
			   {
				   disp(a,ra,ca);
			   }
			   else if(ch==2)
			   {
				   disp(b,rb,cb);
			   }
			   else
				   cout<<"\n Wrong choice";
			   break;
		default:cout<<"\n Wrong choice";
			   }

		cout<<"\n Do you want to continue";
		cin>>op;
			}
			while(op=='y' || op=='Y');
	}
