// MAKING CLASS MATRICES

#include<iostream>
using namespace std;

class matrix
{
private:
 int arr[5][5],rows,cols;
public:
	void getinput();
	void disp();
	matrix add(matrix m);
	matrix sub(matrix m);
	matrix trans();
	matrix multiply(matrix m);
};

void matrix::getinput()
{
	cout<<"\n Enter number of rows=";
	cin>>rows;
	cout<<"\n Enter number of columns=";
	cin>>cols;

	int i,j;

	cout<<"\n Enter "<<rows*cols<<" elements=";
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			cin>>arr[i][j];
}


void matrix::disp()
{
	cout<<"\n Displaying matrix.....";

	int i,j;

	for(i=0;i<rows;i++)
	{		cout<<endl;
		for(j=0;j<cols;j++)
			cout<<" "<<arr[i][j];
	}
}

matrix matrix::add(matrix m)
{
	int i,j;
	matrix m3;

	m3.rows=rows;
	m3.cols=cols;

	if(rows==m.rows && cols==m.cols)
	{
		for(i=0;i<rows;i++)
		{
		    for(j=0;j<cols;j++)
				m3.arr[i][j]=arr[i][j]+m.arr[i][j];
		}
	}
	else
		cout<<"\n Given matrices can not be added";
  return m3;

}

matrix matrix::sub(matrix m)
{
	int i,j;
	matrix m3;

	m3.rows=rows;
	m3.cols=cols;

	if(rows==m.rows && cols==m.cols)
	{
		for(i=0;i<rows;i++)
		{
			for(j=0;j<cols;j++)
				m3.arr[i][j]=arr[i][j]-m.arr[i][j];
		}
	}
	else
		cout<<"\n Given matrices can not be subtracted ";
   
	return m3;
}

matrix matrix::multiply(matrix m)
{
	int i,j,k;
	matrix m3;

	
	m3.rows=rows;
	m3.cols=m.cols;

	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			m3.arr[i][j]=0;

	if(cols==m.rows)
	{
		for(i=0;i<rows;i++)
			for(j=0;j<m.cols;j++)
				for(k=0;k<cols;k++)
					m3.arr[i][j]+=arr[i][k]*m.arr[k][j];
	}
	else
		cout<<"\n Multiplication not possible";

		return m3;
}


matrix matrix::trans()
{
	int i,j;
    matrix m3;

	m3.rows=cols;
	m3.cols=rows;

	if(rows)
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
		{
			m3.arr[i][j]=arr[j][i];
		}

	return m3;
			
}

void main()
{

  matrix m1,m2,m3,m4,m5,m6;
  char op;
  int ch;

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
				  m1.getinput();	
				}
				else if(ch==2)
				{
				  m2.getinput();
				}
				else
					cout<<"\n Wrong choice";

				break;
        case 2:cout<<"\n Adding the two matrices";
			   m3=m1.add(m2);
			   m3.disp();
			   break;
		case 3:cout<<"\n Subtracting one matrix from the other";
			   cout<<"\n Which matrix result do you want";
			   cout<<"\n 1. A-B";
			   cout<<"\n 2. B-A";
	    	   cin>>ch;

       		   if (ch==1)
				   {
					  m4=m1.sub(m2);
				   }
				   else if(ch==2)
				   {
					   m4=m2.sub(m1);
				   }
				   else
					   cout<<"\n Wrong choice";

		           m4.disp();
				   break;
		case 4: cout<<"\n Multiply the two matrices";
			    cout<<"\n Which product do you want to see";
				cout<<"\n 1. A*B";
				cout<<"\n 2. B*A";
				cout<<"\n Enter choice=";
				cin>>ch;

				if(ch==1)
				{
				m5=m1.multiply(m2);
				}
				else if(ch==2)
				{
					m5=m2.multiply(m1);
				}
				else
					cout<<"\n Wrong choice";

				m5.disp();
				break;
		case 5:cout<<"\n Transpose of the matrix";
			   cout<<"\n Choices";
		       cout<<"\n 1. A";
			   cout<<"\n 2. B";
			   cout<<"\n Enter choice=";
			   cin>>ch;

			   if(ch==1)
			   { 
				m6=m1.trans();
			   }
			   else if(ch==2)
			   {
				   m6=m2.trans();
			   }
			   else
				   cout<<"\n Wrong choice";

			   m6.disp();
			   break;

        case 6:cout<<"\n Display";
			   cout<<"\n 1. A";
			   cout<<"\n 2. B";
			   cout<<"\n choice";
			   cin>>ch;

			   if(ch==1)
			   {
				   m1.disp();
			
			   }
			   else if(ch==2)
			   {
				   m2.disp();
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
