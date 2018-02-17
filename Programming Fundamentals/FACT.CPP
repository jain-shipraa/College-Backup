//FACTORIAL

#include<iostream.h>
#include<stdlib.h>

void main()
{
	system("cls");

	int fact=1,n,i=1;

	cout<<"\n ENTER NUMBER=";
	cin>>n;

	while(i<=n)
	{
		fact=fact*i;
		i++;

	}

	cout<<"\n Factorial="<<fact<<endl;

}
