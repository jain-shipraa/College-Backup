// STRING BASED PROGRAM

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int len(char str[])
{
        int i,len;
		char *p;
		p=str;
	    for( i=0;str[i]!='\0';i++)
		{ 
           p++;		
		}
	    len=(int)p-(int)str;
			return (len);

}

void concat(char str[],int s, char str1[], int s1)
{

	int i,j;
	for(i=s,j=0;i<s+s1;i++,j++)
	{
		str[i]=str1[j];
	}
	str[s+s1]='\0';

    cout<<str;

}

void upper(char str[],int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		if(str[i]>=97 && str[i]<=122)
		{
			str[i]-=32;
		}
	}

	cout<<str;

}

void lower(char str[] ,int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		if(str[i]>=65 && str[i]<=91)
		{
			str[i]+=32;
		}
	}

cout<<str;

}

int compare(char str[],int s, char str1[], int s1)
{

	int i;

	if(s==s1)
	{
		for(i=0;i<s;i++)
		{
			if(str[i]!=str[i])
				return 0;
		}
		return 1;
	}
	else
        return 0;

}

void substr(char str[],int s)
{

	int i,j,flag=0;
	char sbstr[256],l;
	cout<<"\n Enter a string to be searches in "<<str<<"=";
	cin>>sbstr;
	l=len(sbstr);

	for(i=0;i<s;i++)
	{    
		j=0;
		if(str[i]==str[j])
		{
			while(j<l)
			{
				if(str[i]==str[j])
					j++;
				else
					break;
			}
			flag=1;
		}
	}

	if(flag)
		cout<<"\n the given sub string is a part of string";
	else
		cout<<"\n the given sub string is not a part of string";

}

int nov(char str[],int s)
{
	int n=0;

	for(int i=0;i<s;i++)
	{
		switch(str[i])
		{
		case 'a':
		case 'A':
		case 'o':
		case 'O':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
	    case 'u': 
		case 'U': n++;
		}
	}

	return n;
}


int const size=256;

void main()
{


	int ch, l1,l2,flag,op,n,i;
	char str[size], str1[size],choic,*p;

		cout<<"\n Enter string 1=";
		cin>>str;
		cout<<"\n Enter string 2=";
		cin>>str1;

	    l1=len(str);
	    l2=len(str1);
			   
	do
	{
	    system("cls");
		cout<<"\n Menu=";
		cout<<"\n 1. Show address of each alphabet ";
		cout<<"\n 2. Concatenate using strcat function";
		cout<<"\n 3. Concatenate two strings=";
		cout<<"\n 4. Compare two strings";
		cout<<"\n 5. Calculate string lenght using pointers ";
		cout<<"\n 6. Convert all lower case alphabets to upper case="; 
		cout<<"\n 7. Convert all upper case alphabets to lower case=";
		cout<<"\n 8. Know the number of vowels";
		cout<<"\n 9. Find a sub string in a given string=";
		cout<<"\n 0. Reverse a string";

		cout<<"\n Enter your choice";
        cin>>ch;

		switch(ch)
		{
		case 1: p=str;
            	for(i=0;str[i]!='\0';i++)
				{	
		           cout<<"\n"<<str[i]<<"="<<(int)(p+i);//ADDRESS
				}
				break;
		case 2:	strcat(str1,str);
            	cout<<"\n"<<str1;
				break;
	    case 3:concat(str,l1,str1,l2);
		        l1=l1+l2;
			    break;

		case 4: flag=compare(str,l1,str1,l2);
			    if(flag)
					cout<<"\n Equal strings";
				else
					cout<<"\n Unequal strings";

				break;
        case 5: l1=len(str);
			    l2=len(str1);
			    cout<<"\n length of string "<<str<<" ="<<l1;
				cout<<"\n length of string "<<str1<<" ="<<l2;
                break;
		case 6 :cout<<"\n Which string do you want to change?";
			    cout<<"1."<<str;
				cout<<"2."<<str1;
				cout<<"\n Your choice=";
				cin>>op;

				if(op==1)
				  upper(str,l1);
				else if(op==2)
				  upper(str1,l2);
				else
					cout<<"\n Wrong choice";
				break;
		case 7:cout<<"\n Which string do you want to change?";
			    cout<<"1."<<str;
				cout<<"2."<<str1;
				cout<<"\n Your choice=";
				cin>>op;

				if(op==1)
				 lower(str,l1);
				else if(op==2)
				 lower(str1,l2);
				else
					cout<<"\n Wrong choice";
				break;

		case 8: cout<<"\n Which string do you want to use ?";
			    cout<<"1."<<str;
				cout<<"2."<<str1;
				cout<<"\n Your choice=";
				cin>>op;

				if(op==1)
					n=nov(str,l1);
				else if(op==2)
					n=nov(str1,l2);
				else
					cout<<"\n Wrong choice";

				cout<<"\n Number of vowels="<<n;
				break;
		case 9:cout<<"\n Which string do you want to find your substr in ?";
			    cout<<"1."<<str;
				cout<<"2."<<str1;
				cout<<"\n Your choice=";
				cin>>op;

				if(op==1)
					substr(str,l1);
				else if(op==2)
					substr(str1,l2);
				else
					cout<<"\n Wrong choice";
				break;
		case 0:char temp;
			    int j;
			     p=str;
	             for(i=0,j=l1-1;i<l1/2;i++,j--)
				 {
	        	  temp=*(p+i);
		          *(p+i)=*(p+j);
		          *(p+j)=temp;
				 }

				 cout<<"\n "<<str;
				 break;
		default:cout<<"\n Wrong choice";
		}

		cout<<"\n Do you want to continue=";
		cin>>choic;

	}while(choic=='y'||choic=='Y');

}

