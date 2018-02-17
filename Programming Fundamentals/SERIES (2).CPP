//1-2+3-4+ ...N

#include<iostream.h>
#include<stdlib.h>

void main()
{
	 
	 system("cls");

	 int n,s=0,i=1;

	 cout<<"\n Enter the last no. of the series=";
	 cin>>n;

	 cout<<endl;
	 while(i<=n)
	 {

		 s+=i;
		 i++;
		 if(i<=n)
		 {
			  s-=i;
		      i++;
		 }

	 }

	 cout<<"Sum="<<s<<endl;

}

