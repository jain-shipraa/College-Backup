#include<iostream.h>
#include<string.h>

class hash
{
	         
char data[100];
char hdata[100];
int len;
int hlen;
int h1;
int h2;

public:

hashcipher()
{
h1=0;
h2=0;
}
			  
void input()
{
int i;
cout<<"ENTER DATA"<<endl;
cin>>data;
len=strlen(data);
	
hlen=len;
for(i=0;i<len;i++)
{ 
  if(data[i]>='A' &&data[i]<='Z')
	  { 
		hdata[i]=data[i]-65;
	  }
  else 
	  {
		hdata[i]=data[i]-97;
	  }
}
}


int senderhash()
{

int a,b,i;
int num =31; 
for(i = 0; i<len; i++)
{

h1 = (h1 * num) + hdata[i];

}

h1=h1%100;
cout<<"H1:"<<h1<<endl;	    
}
			  

int recieverhash()
{
int a,b,i;
int num =31; 
for(i = 0; i<len; i++)
{

h2 = (h2 * num) + hdata[i];

}
h2=h2%100;
cout<<"H2:"<<h2<<endl;
				  
}
			  
void change()
{ 
int i;
cout<<"ENTER CHANGED MESSAGE"<<endl;
cin>>hdata;

hlen=strlen(hdata);
for(i=0;i<len;i++)
{ 
if(hdata[i]>='A' &&hdata[i]<='Z')
{ 
hdata[i]=hdata[i]-65;
}
else 
{
hdata[i]=hdata[i]-97;
}
}
}
			  
			  
void check()
{
  
if(h1==h2)
cout<<"MESSAGE INTACT"<<endl;
else
cout<<"MESSAGE TAMPERED"<<endl;
}
			  
			  
Void display()
{
cout<<"DATA IS:"<<data<<endl;
}
};

int main()
{ 
hashcipher c;
char ch='y';
char n;
while(ch=='y')
{
	c.input();
	c.senderhash();

	cout<<"want to change message?"<<endl;
	cin>>n;
	if(n=='y'||n=='Y')
	c.change();
	c.recieverhash();
	c.check();
	c.display();
	cout<<"want to cont?"<<endl;
    	cin>>ch;

}	
return 0;

}

