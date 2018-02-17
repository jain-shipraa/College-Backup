//mid point circle algorithm
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void gen(int x,int  y,int  xc,int yc)
{
putpixel(xc+x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc-x,yc-y,WHITE);
putpixel(xc+y,yc+x,WHITE);
putpixel(xc-y,yc+x,WHITE);
putpixel(xc+y,yc-x,WHITE);
putpixel(xc-y,yc-x,WHITE);
}

void cir(int rad,int xc, int yc)
{
int p,x,y;
x=0;
y=rad;
p=1-rad;

while(x<=y)
{
x++;
if(p<0)
{
p+=2*x+1;
}
else
{
p+=2*(x-y)+1;
y--;
}
gen(x,y,xc,yc);
}

}


void main()
{
clrscr();
int gdrive =DETECT, gmode;
initgraph(&gdrive, &gmode, "C:\\Turboc3\\BGI");
int r,xc,yc;

cout<<"\n Enter the center of the circle:";
cout<<"X center:";
cin>>xc;
cout<<"y center:";
cin>>yc;

cout<<"\n Enter the radius:";
cin>>r;

clrscr();

cir(r, xc, yc);
getch();
closegraph();
}

