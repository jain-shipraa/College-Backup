#include<stdlib.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
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
printf("x start:");
cin>>x;
//scanf("%d",&x);
//printf("x start %d:",x);
printf("y start:");
//scanf("%d",&y);
cin>>y;
printf("x end:");
//scanf("%d",&x1);
cin>>x1;
printf("y end:");
//scanf("%d",&y1);
cin>>y1;
//m=(y1-y)/(x1-x);
if((x1-x)!=0)
{
m=(y1-y)/(x1-x);
while(x<=x1)
{
putpixel(x,y,WHITE);
y=y+m;
x=x+1;
}}
else if((x1-x)==0)
{
m=(x1-x)/(y1-y);
while(y<=y1)
{
putpixel(x,y,WHITE);
y++;
x=x+m;
}
}


//putpixel(639,479,WHITE);
getch();
closegraph();
return 0;

}
