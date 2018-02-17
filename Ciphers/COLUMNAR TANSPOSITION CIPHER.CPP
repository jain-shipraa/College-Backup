#include<iostream.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void columntpose(char p[],char c[],int n)
{
 int i=0,j=0,k,t,q;
 char te[100];

 for(k=0;p[k]!='\0';k++)
 {
  if(isalnum(p[k]))
  {
   te[i]=p[k];
   c[i]=0;
   cout<<te[i];
   i++;
  }
 }
 t=i;cout<<"t:"<<t;
 q=t/n;cout<<"q:"<<q;                        //Number of characters to be transferred at one go
 cout<<"\nCHECKING:";
			       //n is the width
 for(i=0;i<n;i++)
 {
   j=i*q;
   k=0;
   while(k<t)
   {
    if(j<t)
    {
    c[j]=te[i+k];
    k+=n;j++;
   }
   }
 }
 c[j]='\0';
 }
void decrypt(char c[],char p[],int n)
{
 int i,j,k,t,q;
 t=strlen(c);cout<<"t:"<<t;
 q=t/n;cout<<"q:"<<q;                        //Number of characters to be transferred at one go
 j=0;
					       //n is the width
 for(i=0;i<t&&j<n;)
 {
   cout<<" j:"<<j;
   k=0;
   while(k<t)
   {
    p[j+k]=c[i];
    cout<<"j+k:"<<j+k;
    k+=n;i++;
   }j++;
 }
  p[i]='\0';
}
void main()
{
 clrscr();
 char p[100],c[100];
 int i,n;
 cout<<"\nEnter a Plaintext message:";
 gets(p);
 cout<<"\nEnter the Width:";
 cin>>n;
 columntpose(p,c,n);
 cout<<"\nEncrypted Message:";
 for(i=0;c[i]!='\0';i++)
 cout<<c[i];
 decrypt(c,p,n);
 for(i=0;p[i]!='\0';i++)
 cout<<p[i];
 getch();
}
