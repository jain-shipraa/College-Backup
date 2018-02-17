//ARRAY 1D USING CLASSES 

#include<iostream>
using namespace std;

template<class T>
class Array1D 
{
	T* a;
	int size;
	
	public:

		Array1D(const Array1D<T>& O1);
		Array1D(int sz=0);
		~Array1D(){}
		Array1D<T> operator+( Array1D<T> O1);
		Array1D<T> operator-( Array1D<T> O1);
		Array1D<T> operator*( Array1D<T> O1);
		Array1D<T> operator+=( T x);
		Array1D<T> operator=( Array1D<T> O1);
		T& operator[](int i);
		int size1();
		void resize(int i);
};

template<class T>
Array1D<T>::Array1D(int sz)
{
	size=sz;
	a=new T[size];
}

template<class T>
Array1D<T>::Array1D(const Array1D<T>& O1)
{
	size=O1.size;
	a=new T[size];

	for(int i=0;i<size;i++)
		a[i]=O1.a[i];
}

template<class T>
T& Array1D<T>::operator [](int i)
{
	if(i<0||i>size)
	{
		cout<<"\n Invalid";
		exit(1);
	}

	return a[i];
}

template<class T>
Array1D<T> Array1D<T>::operator=(Array1D<T> O1)
{
	if(this!=&O1)
	{
		size=O1.size;
		delete[] a;
		a=new T[size];

		for(int i=0;i<size;i++)
			a[i]=O1.a[i];
	}
	return (*this);
}

template<class T>
Array1D<T> Array1D<T>::operator+(Array1D<T> O1)
{
	Array1D<T> O2(size);

	if(size!=O1.size)
	{
		cout<<"\n Unequal Sizes";
		exit(1);
	}
	else
	{
		for(int i=0;i<size;i++)
			O2.a[i]=a[i]+O1.a[i];
	}

	return O2;
}

template<class T>
Array1D<T> Array1D<T>::operator-( Array1D<T> O1)
{
	Array1D<T> O2(size);

	if(size!=O1.size)
	{
		cout<<"\n Unequal Sizes";
		exit(1);
	}
	else
	{
		for(int i=0;i<size;i++)
			O2.a[i]=a[i]-O1.a[i];
	}

	return O2;
}

template<class T>
Array1D<T> 	Array1D<T>::operator*( Array1D<T> O1)
{
	Array1D<T> O2(size);

	if(size!=O1.size)
	{
		cout<<"\n Unequal Sizes";
		exit(1);
	}
	else
	{
		for(int i=0;i<size;i++)
			O2.a[i]=a[i]*O1.a[i];
	}

	return O2;
}

template<class T>
Array1D<T> Array1D<T>::operator+=( T x)
{
	for(int i=0;i<size;i++)
			a[i]=a[i]+x;

	return (*this);
}

template<class T>
int Array1D<T>::size1()
{
	return size;
}

template<class T>
void Array1D<T>::resize(int i)
{
	size=i;
	delete[] a;
	a=new T[size];
}

void main()
{

	Array1D<int> A1, A2, A3;
	int ch, sz, x,i;
	char op;

	do
	{
		cout<<"\n MENU";
		cout<<"\n 1. ENTER VALUES";
		cout<<"\n 2. ADDITION ";
		cout<<"\n 3. SUBTRACTION";
		cout<<"\n 4. MULTIPLICATION";
		cout<<"\n 5. SCALAR ADDITION";
		cout<<"\n 6. DISPLAY";
		cout<<"\n ENTER YOUR CHOICE";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\n ENTER VALUES";
			   cout<<"\n Enter the size for your array=";
			   cin>>sz;

			   A1.resize(sz);

			   cout<<"\n Enter values for your array="<<endl;

			   for(i=0;i<A1.size1();i++)
			   {
				   cout<<"["<<i+1<<"]=";
				   cin>>A1[i];
			   }

			   break;
		case 2:cout<<"\n ADDITION";
			   cout<<"\n Enter the size for another array =";
			   cin>>sz;
			   A2.resize(sz);
			   
			   cout<<"\n Enter values for your array="<<endl;

			   for(i=0;i<A2.size1();i++)
			   {
				   cout<<"["<<i+1<<"]=";
				   cin>>A2[i];
			   }

			   
			   A3=A1+A2;
			   cout<<"\n ADDITION RESULT"<<endl;

			   for(i=0;i<A3.size1();i++)
				   cout<<"["<<i+1<<"]="<<A3[i];

			   cout<<endl;
			   break;
		case 3:cout<<"\n SUBTRACTION";
			   cout<<"\n Enter the size for another array =";
			   cin>>sz;
			   A2.resize(sz);
			   
			   cout<<"\n Enter values for your array="<<endl;

			   for(i=0;i<A2.size1();i++)
			   {
				   cout<<"["<<i+1<<"]=";
				   cin>>A2[i];
			   }

			   
			   A3=A1-A2;
			   cout<<"\n SUBTRACTION RESULT"<<endl;

			   for(i=0;i<A3.size1();i++)
				   cout<<"["<<i+1<<"]="<<A3[i];

			   cout<<endl;
			   break;
			   
		case 4:cout<<"\n MULTIPLICATION";
			   cout<<"\n Enter the size for another array =";
			   cin>>sz;
			   A2.resize(sz);
			   
			   cout<<"\n Enter values for your array="<<endl;

			   for(i=0;i<A2.size1();i++)
			   {
				   cout<<"["<<i+1<<"]=";
				   cin>>A2[i];
			   }

			   
			   A3=A1*A2;
			   cout<<"\n MULTIPLICATION RESULT"<<endl;

			   for(i=0;i<A3.size1();i++)
				   cout<<"["<<i+1<<"]="<<A3[i];

			   cout<<endl;
			   break;
		case 5:cout<<"\n SCALAR ADDITION";
			   cout<<"\n Enter values to be added=";
			   cin>>x;

			   
			   A1+=x;
			   cout<<"\n ADDITION RESULT"<<endl;

			   for(i=0;i<A1.size1();i++)
				   cout<<"["<<i+1<<"]="<<A1[i];

			   cout<<endl;
			   break;
		case 6:cout<<"\n DISPLAY";
			   
			   for(i=0;i<A1.size1();i++)
				   cout<<"["<<i+1<<"]="<<A1[i];

			   cout<<endl;
			   break;
		default:cout<<"\n Wrong Choice";
	   } 

	cout<<"\n Want to continue";
	cin>>op;

	}while(op=='y'||op=='Y');
}