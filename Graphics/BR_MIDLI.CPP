//brasenham line drawing algorithm
#include<stdlib.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void mid_line(int x0,int y0,int x1,int y1)
{
int dx=x1-x0;
int dy=y1-y0;
int d=2*dy-dx;
int incrE=2*dy;
int incrNE=2*(dy-dx);
int x=x0;
int y=y0;

putpixel(x,y,WHITE);

while(x<x1)
{
if(d<=0)
{
d+=incrE;
x++;
}
else
{
d+=incrNE;
x++;
y++;
}
putpixel(x,y,WHITE);
}//while
}//midpt line

int main()
{
int i;
double x,y,x1,y1;
double m;

int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
//printf("%d %d",gd,gm);
//y=150;
//x1=y1=230;
//x1=getmaxx();
//y1=getmaxy();
//printf("Maximum x: %d",x1);
//printf("Maximum y: %d",y1);
printf("\n Enter starting point ");
printf("\n x start:");
cin>>x;
//scanf("%d",&x);
//printf("x start %d:",x);
printf("\n y start:");
//scanf("%d",&y);
cin>>y;
printf("\n x end:");
//scanf("%d",&x1);
cin>>x1;
printf("\n y end:");
//scanf("%d",&y1);
cin>>y1;
//m=(y1-y)/(x1-x);
mid_line(x,y,x1,y1);
getch();
closegraph();
return 1;
}
