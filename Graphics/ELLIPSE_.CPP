//ellipse drawing algorithm
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>


void gen(int x,int y, int xc, int yc)
{
putpixel(xc+x,yc+y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
}
void elps(int a, int b, int xc,int yc)
{
double x,y;
double p1,p2;
//Working in Region 1
x=0;
y=b;
p1=b*b-(a*a*b)+(0.25*a*a);
//p2=(b*b*(x+0.5)*(x+0.5))+(a*a*(y-1)*(y-1))-a*a*b*b;

while((a*a*(y-0.5))>(b*b*(x+1)))
{
if(p1<0)
{
p1+=(b*b*((2*x)+3));
}
else
{
p1+=((b*b*((2*x)+3))+(a*a*((-2*y)+3)));
y--;
}
x++;
gen(x,y,xc,yc);
}

p2=(b*b*(x+0.5)*(x+0.5))+(a*a*(y-1)*(y-1))-a*a*b*b;

while(y>0)
{
if(p2<0)
{
p2+=((b*b*((2*x)+2))+(a*a*((-2*y)+3)));
x++;
}
else
{
p2+=(a*a*((-2*y)+3));
}
y--;
gen(x,y,xc,yc);
}
}
/*
void gen(int x,int y, int xc, int yc)
{
putpixel(xc+x,yc+y);
putpixel(xc-x,yc+y);
putpixel(xc+x,yc-y);
putpixel(xc-x,yc-y);
}
*/

void main()
{
clrscr();
int gdrive=DETECT, gmode;
initgraph(&gdrive,&gmode,"C:\\Turboc3\\BGI");
int a,b,xc,yc;

cout<<"\n Enter the radius of major axis:";
cin>>a;
cout<<"\n Enter the radius of minor axis:";
cin>>b;

cout<<"\n Enter the center coordinates:";
cout<<"\n X :";
cin>>xc;
cout<<"\n Y :";
cin>>yc;

clrscr();
elps(a,b,xc,yc);
getch();
closegraph();
}
