
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<stdio.h>

struct point
{
       double x,y;
};

void hermite(point p1,point p4,double r1,double r4)
{
     char text[50];
     cleardevice();

     double t=0.0;
     double xt,yt;

     for(t=0;t<=1.0;t+=0.001)
     {
	 xt=((2*t*t*t-3*t*t+1)*p1.x)+((-2*t*t*t+3*t*t)*p4.x)+((t*t*t-2*t*t+t)*r1)+((t*t*t-t*t)*r4);
	 yt=((2*t*t*t-3*t*t+1)*p1.y)+((-2*t*t*t+3*t*t)*p4.y)+((t*t*t-2*t*t+t)*r1)+((t*t*t-t*t)*r4);

	 putpixel(xt,yt,GREEN);
	 delay(2);
     }
     int x1=p1.x,y1=p1.y;
     int x2=p4.x,y2=p4.y;

     sprintf(text,"(%d,%d)",x1,y1);
     outtextxy(p1.x-5,p1.y-10,text);
     putpixel(p1.x,p1.y,WHITE);

     sprintf(text,"(%d,%d)",x2,y2);
     outtextxy(p4.x-5,p4.y-10,text);
     putpixel(p4.x,p4.y,WHITE);

     getch();
}

void bezier(point p1,point p2,point p3,point p4)
{
     cleardevice();

     double t=0.0;
     double xt,yt;

     setcolor(RED);
     line(p1.x,p1.y,p2.x,p2.y);
     line(p2.x,p2.y,p3.x,p3.y);
     line(p3.x,p3.y,p4.x,p4.y);

     for(t=0;t<=1.0;t+=0.001)
     {
	 xt=(pow((1-t),3)*p1.x)+(3*t*pow((1-t),2)*p2.x)+(3*t*t*(1-t)*p3.x)+(t*t*t*p4.x);
	 yt=(pow((1-t),3)*p1.y)+(3*t*pow((1-t),2)*p2.y)+(3*t*t*(1-t)*p3.y)+(t*t*t*p4.y);

	 putpixel(xt,yt,GREEN);
	 delay(2);
     }
     getch();
}


void main()
{
    clrscr();
    int gd=DETECT,gm,choice;
    point p1,p2,p3,p4;
    double r1,r4;
    char ch;

    do
    {
       cout<<"\n\n\t   ........HERMITE/BEZIER CURVE........\n";

       initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
       cout<<"\n.......MENU.......";
       cout<<"\n1.Hermite curve.";
       cout<<"\n2.Bezier curve.";
       cout<<"\n..................";

       cout<<"\n\nEnter your choice :: ";
       cin>>choice;

       switch(choice)
       {
	   case 1:cout<<"\n\n\t   ........FOR HERMITE CURVE........\n";
		  cout<<"\nEnter the end points of the curve to be drawn... ";
		  cout<<"\nx1 : ";
		  cin>>p1.x;
		  cout<<"y1 : ";
		  cin>>p1.y;

		  cout<<"\nx4 : ";
		  cin>>p4.x;
		  cout<<"y4 : ";
		  cin>>p4.y;

		  cout<<"\nNow,enter the tangent vectors for the above end points....";
		  cout<<"\nTangent vector for P1 (i.e. R1) : ";
		  cin>>r1;
		  cout<<"\nTangent vector for P4 (i.e. R4) : ";
		  cin>>r4;

		  hermite(p1,p4,r1,r4);
		  break;

	   case 2:cout<<"\n\n\t   ........FOR BEZIER CURVE........\n";
		  cout<<"\nEnter the four control points for the curve to be drawn... ";
		  cout<<"\nx1 : ";
		  cin>>p1.x;
		  cout<<"y1 : ";
		  cin>>p1.y;

		  cout<<"\nx2 : ";
		  cin>>p2.x;
		  cout<<"y2 : ";
		  cin>>p2.y;

		  cout<<"\nx3 : ";
		  cin>>p3.x;
		  cout<<"y3 : ";
		  cin>>p3.y;

		  cout<<"\nx4 : ";
		  cin>>p4.x;
		  cout<<"y4 : ";
		  cin>>p4.y;

		  bezier(p1,p2,p3,p4);
		  break;

	  default:cout<<"\n\n\t!!!INVALID CHOICE!!!";
		  getch();
       }

       closegraph();

       cout<<"\nWanna try another type of curve(y/n)...";
       cin>>ch;

    }while(ch=='y');

}