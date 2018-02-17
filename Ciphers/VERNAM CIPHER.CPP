//VERNAM CIPHER
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#define MAX 1024

void encrypt(char in[],int len, char out[], int ran[])
{
int i;
int n;
char c;
for(i=0;i<len;i++)
{
c=in[i];
n=ran[i];
if(isalnum(c))
{
	if(isupper(c))
	{
	c=c+n-65;
	out[i]=(c%26)+97;
	}
	else if(islower(c))
	{
	c=c+n-97;
	out[i]=(c%26)+65;
	}
	else if(isdigit(c))
	{
	c=c+n-48;
	out[i]=(c%10)+48;
	}
	else
	{
	in[i]=c;
	}
}//if ending
else
{
out[i]=in[i];
}
}//for loop
out[i]='\0';
}//encrypt function ends

void decrypt(char in[],int len, char out[], int ran[])
{
int i;
int n;
char c;

for(i=0;i<len;i++)
{
c=in[i];
n=ran[i];
if(isalnum(c))
{
	if(isupper(c))
	{
	c=c-n-65;
	if(c>=0)
	out[i]=abs(c%26)+97;
	else
	out[i]=(c%26)+123;
	}
	else if(islower(c))
	{
	c=c-n-97;
	if(c>=0)
	out[i]=abs(c%26)+65;
	else
	out[i]=(c%26)+91;
	}
	else if(isdigit(c))
	{
	c=c-n-48;
	if(c>=0)
	out[i]=abs(c%10)+48;
	else
	out[i]=(c%10)+58;
	}
	else
	{
	in[i]=c;
	}
}//if ending
else
{
out[i]=in[i];
}
}//for loop
out[i]='\0';
}//decrypt function ends

void main()
{
clrscr();
int ran[MAX];
char in[MAX],enc[MAX];
int ilen,elen;
int i;
cout<<"\n Enter text to be encoded:";
cin>>in;

ilen=strlen(in);
elen=ilen;

for(i=0;i<elen;i++)
{
ran[i]=random(100);
cout<<ran[i]<<" ";
}

cout<<"\n Encoded Text is:";
encrypt(in,ilen,enc,ran);
cout<<enc;

cout<<"\n Decrypted Text is :";
decrypt(enc,elen,in,ran);
cout<<in;

getch();
}