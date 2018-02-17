#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void encrypt(char p[],char ci[],char k)
{
 int i,c,a=k;cout<<"a:"<<a;
 if(isupper(a))
  a=a-65;
 else
  a=a-97;
 for(i=0;p[i]!='\0';i++)
 {
   c=p[i];
   if(isalnum(c))
   {
    if(islower(c))
    {
     c=(c-97)%26;
     ci[i]=(c^a)+97;
    }
    else if(isupper(c))
    {
     c=(c-65)%26;
     ci[i]=(c^a)+65;
    }
   }
   else
    ci[i]=p[i];
 }
  ci[i]='\0';
}
void decrypt(char ci[],char p[],char k)
{
 int i,c,a=k;cout<<"\na:"<<a;
 if(isupper(a))
   a=a-65;
 else
   a=a-97;
 for(i=0;p[i]!='\0';i++)
 {
  c=ci[i];
   if(isalnum(c))
   {
    if(islower(c))
    {
     c=(c-97)%26;
     p[i]=(c^a)+97;
    }
    else if(isupper(c))
    {
     c=(c-65)%26;
     p[i]=(c^a)+65;
    }
   }
   else
    ci[i]=p[i];
 }
 p[i]='\0';
}

void display(char d[])
{
  int i;
  for(i=0;d[i]!='\0';i++)
  cout<<d[i];
}
void main()
{
 clrscr();
 int i;
 char p[100],ci[100],k;
 int r[100],n;
 cout<<"\nEnter Plaintext to be encrypted:";
 gets(p);
 cout<<"\nEnter the alphabet key:";
 cin>>k;
 encrypt(p,ci,k);
 cout<<"\nEncrypted Message:";
 display(ci);
 decrypt(ci,p,k);
 cout<<"\nDecrypted Message:";
 display(p);
 getch();
}