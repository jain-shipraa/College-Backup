//STOP AND WAIT PROTOCOL
#include<iostream>
#include<string>
using namespace std;
int ack,ack_1,fl;

class sender
{
	public:
	int fsz;
	char fs[100];
	

	
	void fromnetworklayer();
	void sendtophy();
	void waitforevent();
	char* frame();
	void acklost();
	void framelost();
};

class receiver
{

	public: 
	int f;
	char fs[100];
	void fromphy(sender* S);
	void tonetwork();
	void waitforevent();
	
};

void sender::fromnetworklayer()
{

	cout<<"\n Enter frame size:";
	cin>>fsz;
		cout<<"\n Enter frame:";
	cin>>fs;
	sendtophy();
}
	
void sender::sendtophy()
{
	cout<<"\n Frame received on physical layer.....";
	ack=0;
	waitforevent();
}

void sender::waitforevent()
{
	receiver R;

	R.fromphy(this);	
	
	if(ack_1==-1)
	{
	cout<<"\n Acknowledgement lost .... Send Again!!!!";
	ack_1=0;
	R.fromphy(this);
	}
	
	if(ack==1)
	{
	cout<<"\n Received on the receiver side";
	cout<<"\n Successful transmission";
	cout<<R.fs;
	}
	else
	{
	cout<<"\n Unsuccessful transmission";
	fl=0;
	}
}

char* sender::frame()
{
	return fs;
}

void sender::acklost()
{
	char ch;
	cout<<"\n Want to manipulate:";
	cin>>ch;
	
	if(ch=='y'||ch=='Y')
		ack_1=-1;
	fromnetworklayer();	  
}

void sender::framelost()
{ 
	char ch;
	cout<<"\n Want to manipulate:";
	cin>>ch;
	
	if(ch=='y'||ch=='Y')
		fl=1;
	fromnetworklayer();
}
	
void receiver::fromphy(sender* S)
{
	if(ack_1!=-1 && fl==0)	  	  
	{
	strcpy(fs,S->fs);
	cout<<"\n Data received on Receiver's physical layer";
	tonetwork();
	}
	
}

void receiver::tonetwork()
{
	cout<<"\n Frame transfered on network layer ";
	waitforevent();
}

void receiver::waitforevent()
{
	if(fl!=1)
	{
	cout<<"\n Received frame ";
	ack=1;
	}
	else
		ack=0;
}
 
int main()
{
	char ch;
	int op;
	sender S;
	do
	{
	cout<<"\n MENU ";
	cout<<"\n 1. SUCCESSFULL TRANSMISSION";
	cout<<"\n 2. ACKNOWNLEDGEMENT LOST ";
	cout<<"\n 3. FRAME LOST ";
	cin>>op;
	
	switch(op)
	{
	case 1:S.fromnetworklayer();
		   break;
	case 2:S.acklost();
		   break;
	case 3:S.framelost();
  	     break;
	}
	
	cout<<"\n Do you want to enter more ?";
	cin>>ch;
	}
	while(ch=='Y'|| ch=='y');
		
	return 0;	 
}


	

