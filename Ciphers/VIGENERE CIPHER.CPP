#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void encrypt(char p[],char ci[],int r[],int n)
{
 int i,c,j;
 for(i=0,j=0;p[i]!='\0';i++,j++)
 {
   c=p[i];
   if(isalnum(c))
   {
    if(j==n)
     j=0;
    if(islower(c))
    {
     c=c-97;
     ci[i]=((c+r[j])%26)+65;
    }
    else if(isupper(c))
    {
     c=c-65;
     ci[i]=((c+r[j])%26)+97;
    }
   }
   else
    ci[i]=p[i];
 }
  ci[i]='\0';
}
void decrypt(char ci[],char p[],int r[],int n)
{
 int i,c,j;
 for(i=0,j=0;p[i]!='\0';i++,j++)
 {
  c=ci[i];
   if(isalnum(c))
   {
    if(j==n)
     j=0;
    if(islower(c))
    {
     c=(c-r[j]-97)%26;
     p[i]=((c+26)%26)+65;
    }
    else if(isupper(c))
    {
     c=(c-r[j]-65)%26;
     p[i]=((c+26)%26)+97;
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
 char p[100],ci[100],key[5];
 int r[100],n,k[5];
 cout<<"\nEnter Plaintext to be encrypted:";
 gets(p);
 cout<<"\nEnter the key:";
 cin>>key;
 n=strlen(key);
 for(i=0;key[i]!='\0';i++)
  k[i]=key[i];
 encrypt(p,ci,k,n);
 cout<<"\nEncrypted Message:";
 display(ci);
 decrypt(ci,p,k,n);
 cout<<"\nDecrypted Message:";
 display(p);
 getch();
}