//IMPLEMENTING CLASSES FRACTION
#include<iostream>
using namespace std;

class fraction 
{
   private:
     float num,denom;
   public:
     void store(float n, float d)
	 {
		 num=n;
		 denom=d;
	 }

	 void print() const
	 {
		 cout<<num<<"/"<<denom;
		 cout<<endl;
	 }
}fr;

/*
outside the class definition:
void fraction::store(float n,float d)
{
  num=n;
  denom=d;
}


void fraction::print() const
{
  cout<<num<<"/"<<denom;
  cout<<endl;
}
*/

void getdata(float & numt,float & denum)
{
	cout<<"\n Enter numerator=";
	cin>>numt;
	cout<<"\n Enter denominator=";
	cin>>denum;
}



void main()
{
	float numt,denum;

	getdata(numt,denum);
    fr.store(numt,denum);
	fr.print();

}