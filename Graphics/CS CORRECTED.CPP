#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

enum{TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8};

void midp_line(int x,int y,int x1,int y1)
{
int m=0;
if((x1-x)!=0)
{
 m=(y1-y)/(x1-x);
 while(x<=x1)
 {
   putpixel(x,y,WHITE);
   y+=m;
   x=x+1;
 }
}
else if((x1-x)==0)
{
 m=(x1-x)/(y1-y);
 while(y<=y1)
 {
   putpixel(x,y,WHITE);
   x+=m;
   y=y+1;
 }
}
}

unsigned int compoutcode(double x, double y,double xmin, double xmax, double ymin, double ymax)
{
  unsigned int code=0;
  if(y > ymax)
   code |= TOP ;
  else if(y < ymin)
   code |= BOTTOM;
  if(x > xmax)
   code |= RIGHT;
  else if(x < xmin)
   code |= LEFT;
   return code;
}

void CohenS_clip(double x0, double y0, double x1, double y1, double xmin, double xmax, double ymin, double ymax)
{
 unsigned int outcode0,outcode1,outcodeOut;
 int accept= 0, done=0;
 outcode0 = compoutcode(x0,y0,xmin,xmax,ymin,ymax);
 outcode1 = compoutcode(x1,y1,xmin,xmax,ymin,ymax);
 do
 {
   if(!(outcode0|outcode1)){
     accept=1;
     done=1;
    }//if
   else {
    double x,y;
    outcodeOut = outcode0 ? outcode0 : outcode1;
    if(outcodeOut & TOP){
      x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
      y=ymax;
     }
    else if(outcodeOut & BOTTOM){
      x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
      y=ymin;
     }
    else if(outcodeOut * RIGHT){
      y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
      x=xmax;
     }
    else{
      y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
     }
     if(outcodeOut==outcode0){
      x0=x;
      y0=y;
      outcode0=compoutcode(x0,y0,xmin,xmax,ymin,ymax);
     }
     else{
      x1=x;
      y1=y;
      outcode1=compoutcode(x1,y1,xmin,xmax,ymin,ymax);
     }
    }//else "subdivide"
  }while(done==0);
  if(accept==1)
  midp_line(x0,y0,x1,y1);
}


int main()
{
double x,y,x1,y1,xmax,xmin,ymax,ymin;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
cout<<"\nEnter line initial x : ";
cin>>x;
cout<<"\nEnter line final x : ";
cin>>x1;
cout<<"\nEnter line initial y : ";
cin>>y;
cout<<"\nEnter line final y : " ;
cin>>y1;
cout<<"\nEnter Clip Window initial x : ";
cin>>xmin;
cout<<"\nEnter Clip Window final x : ";
cin>>xmax;
cout<<"\nEnter Clip Window initial y : ";
cin>>ymin;
cout<<"\nEnter Clip Window final y : ";
cin>>ymax;
clrscr();
rectangle(xmin,ymin,xmax,ymax);
getch();
rectangle(xmin,ymin,xmax,ymax);
CohenS_clip(x,y,x1,y1,xmin,xmax,ymin,ymax);
getch();
closegraph();
return 0;
}
