 //CRC CODE DEVELOPMENT 

#include<iostream>
#include<string>
using namespace std;

class crc 
{
 char dw[50];
 char div[50];
 char dvs[50];
 char *rem;
 char* dvs2;
 int dl,dvsl;
 
 
 public:
  
 void input();
 void calc_crc();
 void XOR(char arr[],char d[],int k);
 void receiver();
 void sender();
 void error();
 
};

void crc::input()
{
	cout<<"\n Enter divident :";
	cin>>div;
	
	cout<<"\n Enter divisor:";
	cin>>dvs;
	
	
	dvsl=strlen(dvs);
	
	dvs2=new char[dvsl];
	
	for(int i=0;i<dvsl;i++)
	dvs2[i]='0';
	
	strncat(div,dvs2,dvsl-1);
	dl=strlen(div);
	
	strcpy(dw,div);
	//cout<<div;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}

void  crc::calc_crc()
{
 char *arr=new char[dvsl];
 dl=strlen(div);
 for(int i=0;i<dl-dvsl+1;i++)
 {
   for(int j=0;j<dvsl;j++)
     arr[j]=div[i+j];
	 
	 //cout<<"\n"<<arr;	    
	 if(arr[0]=='1')
	 	{
		  XOR(arr,dvs,i);
		//  cout<<"case 1";
		 }
	 else
	 	{
			XOR(arr,dvs2,i);
		//	  cout<<"case 2";
		}
		
 }

}

void crc::XOR(char arr[], char d[], int k)
{

	for(int i=0;i<dvsl;i++)
	{
	if(arr[i]==d[i])
		div[i+k]='0';
	else
		div[i+k]='1';
	}
}
void crc::sender()
{
	int i;
	calc_crc();
	rem=new char[dvsl-1];
	for(i=0;i<dvsl-1;i++)
 	{
	 dw[dl-dvsl+1+i]=div[dl-dvsl+1+i];
 	 rem[i]=div[dl-dvsl+1+i];
 	}
	rem[i]='\0';
	 cout<<"\n Code word:"<<dw;
	 cout<<"\n Remainder :"<<rem;
}	 
	
void crc::receiver()
{
	int i;
	strcpy(div,dw);
	//cout<<strlen(div);
	cout<<"\n New divident ;"<<div;
	calc_crc();
	
	for(i=0;i<dvsl-1;i++)
 	{
 	 rem[i]=div[dl-dvsl+1+i];
 	}
	rem[i]='\0';
	 cout<<"\n Remainder :"<<rem;
	
	for(i=0;i<dl;i++)
	{
		if(div[i]!='0')
		 {
			 cout<<"\n Error Message";
			 return;
		 }
	}
	
	cout<<"\n Correct Message";	   
}	 
	   
void crc::error()
{
	char ch;
	int pos;
	cout<<"\n Do you want to generate an error?";
	cin>>ch;
	
	if(ch=='y'||ch=='Y')
	{
	cout<<"\n Which position do you want to flip ?";
	cin>>pos;
	pos--;
	if(dw[pos]!='\0')
	{
		if(dw[pos]=='1')
		{
		dw[pos]='0';
		}
		else
		{	
		dw[pos]='1';
		}
	}
	else
	{
		cout<<"\n Position out of range !!!";
	}
	
	receiver();
	
	}
	else
	{
	receiver();
	}	 
}

int main()
{
 crc C;
 char ch;
 int op;
 
 do
 {
 cout<<"***** ***** ***** ***** CRC ***** ***** ***** *****";
 cout<<"\n SENDER ----- >>>> RECEIVER ";
 cout<<"\n 1. INPUT DATA FOR SENDING ";
 cout<<"\n 2. GENERATE ERROR ";
 cout<<"\n 3. RECEIVED DATA ";
 cout<<"\n 4. EXIT OUT ";
 cout<<"\n ENTER CHOICE ............";
 cin>>op;
  
 switch(op)
 {
 case 1:  C.input();
 		  C.sender();
 		  break;
 case 2:  C.error(); 
 	      break;
 case 3:  C.receiver();
 	      break;
 case 4:  break;
 default: cout<<"\n Wrong Choice";
 }
 
 cout<<"\n Do you want to continue :";
 cin>>ch;
 
 }
 while(ch=='y' || ch=='Y');

return 0;
}
 

