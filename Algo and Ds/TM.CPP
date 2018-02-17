//Find second largest in a list using tournament method................

#include<iostream.h>
#include<conio.h>


struct st
{
       int a,i;
       int* beaten;
};


st tournament(int first,int end,st* s)
{
      int mid;
      st left,right;

      if(first==end)
      return s[first];
   else
      if(first<end)
      {
	   mid=(first+end)/2;

	   left=tournament(first,mid,s);
	   right=tournament(mid+1,end,s);

	   if(left.a>right.a)
	   {

		left.beaten[++(left.i)]=right.a;
		return left;
	   }
	else
	   {
		right.beaten[++(right.i)]=left.a;
		return right;
	   }
      }
}


int tour(st* ele,int first,int end)
{
     st winner=tournament(first,end,ele);

     int max=winner.beaten[0];

     int j;
     for(j=1;j<=winner.i;j++)
     {
	   if(max<winner.beaten[j])
	   max=winner.beaten[j];
     }

     return max;

}

void main()
{
     clrscr();
     int k,size;
     int temp;
     st* ele;
     char ch='y';

     cout<<"\n\t  >>>>>>>>>> SEARH FOR SECOND LARGEST USING TOURNAMENT METHOD <<<<<<<<<<";

     do
     {
     cout<<"\n\nEnter the size of your array :: ";
     cin>>size;


     if(size!=0)
     {
	  ele=new st[size];

	  cout<<"\n\nNow,enter the elements :: ";
	  for(k=0;k<size;k++)
	  {
	      cin>>temp;

	      ele[k].a=temp;
	      ele[k].beaten=new int[size];
	      ele[k].i=-1;
	  }

	  cout<<"\n\nIn your entered array,the second largest element is "<<tour(ele,0,size-1)<<".";
     }
     else
     {
	  cout<<"\n\n\t               !!!!!!!!ERROR!!!!!!!!!!";
	  cout<<"\n\n\t...........You have entered an empty array..........";
     }

	      cout<<"\n\nTo continue,press y otherwise no :: ";
	      cin>>ch;

	      cout<<"\n..................................................";

     }while(ch=='y'||ch=='Y');
     getch();
}