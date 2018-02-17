#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encrypt(char p[],char ci[])
{
 int i,c,k=3;
 for(i=0;p[i]!='\0';i++)
 {
  c=p[i];
  if(isupper(c))
  {
    c=c-65;
    ci[i]=(((c+k)%26)+65);
  }
  else if(islower(c))
  {
   c=c-97;
   ci[i]=((c+k)%26)+97;
  }
  else
   ci[i]=p[i];
  }
  ci[i]='\0';
}
void decrypt(char ci[],char p[])
{
 int i,c,k=3;
 for(i=0;ci[i]!='\0';i++)
 {
  c=ci[i];
  if(isupper(c))
  {
    c=c-65;
    p[i]=(((c-k)+26)%26)+65;
  }
  else if(islower(c))
  {
   c=c-97;
   p[i]=(((c-k)+26)%26)+97;
  }
  else if(!isalnum(c))
   p[i]=ci[i];
  }
  p[i]='\0';
}

void display(char ci[])
{
  int i;
  for(i=0;ci[i]!='\0';i++)
  cout<<ci[i];
}
void main()
{
 char p[100],ci[100],ans;
 int ch;
 cout<<"\nEnter Plaintext to be encrypted:";
 gets(p);

 do{
 cout<<"MENU";
 cout<<"\n1)ENCRYPTION";
 cout<<"\n2)DECRYPTION";
 cout<<"\nEnter choice:";
 cin>>ch;
 switch(ch)
 {
  case 1: encrypt(p,ci);
	  cout<<"\nEncrypted Ciphertext Message:";
	  display(ci);
	  break;

  case 2: decrypt(ci,p);
	  cout<<"\nDecrypted Plaintext Message:";
	  display(p);
	  break;

  default: cout<<"\nInvalid Option";
	   break;
 }
 cout<<"\nWnat to continue? y|n :";
 cin>>ans;
 }while(ans=='y');
 getch();
}