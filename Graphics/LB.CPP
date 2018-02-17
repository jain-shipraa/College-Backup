#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>

double max(double a, double b)
{
if(a>b)
return a;
else
return b;
}

double min(double a , double b)
{
if(a<b)
return a;
else
return b;
}
void liang_barsky(double x1,double y1, double x2, double y2, double xmin, double ymin, double xmax ,double ymax)
{

float m1=0.0,m2=1.0;
float p1,p2,p3,p4;
float q1,q2,q3,q4;
float r1,r2,r3,r4;
//cout<<"\n STATS:";
//cout<<m1<<" " <<m2<<" " <<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
double x1_n,y1_n,x2_n,y2_n;

p1=(-1)*(x2-x1);
p2=(x2-x1);
p3=(-1)*(y2-y1);
p4=(y2-y1);
//cout<<"\n STATS:";
//cout<<m1<<" " <<m2<<" " <<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
q1=x1-xmin;
q2=xmax-x1;
q3=y1-ymin;
q4=ymax-y1;

if(((p1==0) && (q1<0))||((p2==0) && (q2<0))||((p3==0) && (q3<0))||((p4==0) && (q4<0)))
{

cout<<"\n The Line lies outside the clip window";
return;
}
else
{
if(p1!=0)
{
r1=(float)q1/p1;
if(p1<0)
m1=max(r1,m1);
else
m2=min(r1,m2);
}
//cout<<"\n STATS:";
//cout<<m1<<" " <<m2<<" " <<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;

if(p2!=0)
{
r2=(float)q2/p2;
if(p2<0)
m1=max(r2,m1);
else
m2=min(r2,m2);
}
//cout<<"\n STATS:";
//cout<<m1<<" " <<m2<<" " <<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;

if(p3!=0)
{
r3=(float)q3/p3;
if(p3<0)
m1=max(r3,m1);
else
m2=min(r3,m2);
}
//cout<<"\n STATS:";
//cout<<m1<<" " <<m2<<" " <<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;

if(p4!=0)
{
r4=(float)q4/p4;
if(p4<0)
m1=max(r4,m1);
else
m2=min(r4,m2);
}
//cout<<"\n STATS:";
//cout<<m1<<" " <<m2<<" " <<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
}

cout<<"\n STATS:";
cout<<m1<<" " <<m2<<" " <<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;

if(m1>m2)
{
cout<<"\n The Line is rejected ";
return;
}
else
{
x1_n=x1+m1*(x2-x1);
y1_n=y1+m1*(y2-y1);
x2_n=x1+m2*(x2-x1);
y2_n=y1+m2*(y2-y1);
cout<<x1_n<<" " <<y1_n<<" "<<x2_n<<" "<<y2_n<<endl;

x1_n=(int)(x1_n+0.5);
x2_n=(int)(x2_n+0.5);
y1_n=(int)(y1_n+0.5);
y2_n=(int)(y2_n+0.5);
line(x1_n,y1_n,x2_n,y2_n);
}

}//function

void main()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
double x1,x2,y1,y2;
double xmin,xmax,ymin,ymax;

putpixel(0,0,WHITE);
putpixel(getmaxx(),getmaxy(),WHITE);
cout<<getmaxx()<<" " <<getmaxy()<<endl;
cout<<"\n Enter the endpoints:";
cout<<"\n x start:";
cin>>x1;
cout<<"\n y start:";
cin>>y1;
cout<<"\n x last:";
cin>>x2;
cout<<"\n y last:";
cin>>y2;

//line(x1,y1,x2,y2);
cout<<"\n Enter the co-ordinates of the clip window:";
cout<<"\n x-min:";
cin>>xmin;
cout<<"\n x-max:";
cin>>xmax;
cout<<"\n y-min:";
cin>>ymin;
cout<<"\n y-max:";
cin>>ymax;
//rectangle(xmin,ymin,xmax,ymax);
//line(x1,y1,x2,y2);
//getch();
//clrscr();
rectangle(xmin,ymin,xmax,ymax);
liang_barsky(x1,y1,x2,y2,xmin,ymin,xmax,ymax);
getch();
closegraph();
}