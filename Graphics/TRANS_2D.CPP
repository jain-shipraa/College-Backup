#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

class D2
{
int p[10][10];
int res[10][10],X[10][10];
public:
int insert(int [][10]);
void draw(int [][10],int);
void drawfloat(int [][10],int);
void matmult(int [][10],int [][10],int,int,int,int [][10]);
void matmultfloat(int [][10],float [][10],int,int,int,float [][10]);
//TRANSFORMATIONS
void shear(int [][10],int);
void scale(int [][10],int);
void rotate(int [][10],int);
void translate(int [][10],int);
void reflect(int [][10],int);
void arbrot(int [][10],int);
void arbref(int [][10],int);
};

int D2::insert(int p[][10])
{
int i,n;
cout <<"\n Enter no. of vertices:";
cin >> n;

for(i=0;i<n;i++)
{
cout << "\n Enter (x,y) Co-ordinate of point P[" << i <<"]:";
cin >> p[i][0] >> p[i][1];
p[i][2] = 1;
}

p[n][0] = p[0][0];
p[n][1] = p[1][0];
p[n][2] = 1;

for(i=0;i<n;i++)
{
cout<<"\n FIGURE CORDINATES ARE AS FOLLOWS: \n";
for(int j=0;j<3;j++)
{
cout<<p[i][j]<<"\t";
}
}

getch();
return n;
}

void D2::draw(int p[][10], int n)
{
int i,gd = DETECT,gm;
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

line(320,0,320,480);
line(0,240,640,240);

for(i=0;i<n;i++)
{
if(i!=n-1)
line(p[i][0]+320, p[i][1]+240, p[i+1][0]+320, p[i+1][1]+240);
else
line(p[i][0]+320, p[i][1]+240, p[0][0]+320, p[0][1]+240);
}

getch();
closegraph();
}

void D2:: matmult(int mat1[][10],int mat2[][10],int r1,int c1,int c2,int mat3[][10])
{
int i,j,k;
for(i=0;i<10;i++)
for(j=0;j<10;j++)
mat3[i][j] = 0;

for(i=0;i<r1;i++)
for(j=0;j<c2;j++)
for(k=0;k<c1;k++)
mat3[i][j] = mat3[i][j]+(mat1[i][k] * mat2[k][j]);

mat3[c2][0] = mat3[0][0];
mat3[c2][1] = mat3[0][1];
mat3[c2][2] = mat3[0][2];
}

void D2:: translate(int p[10][10],int n)
{
int tx,ty,i,j;
cout <<"\n Enter X-Translation tx:";
cin >> tx;
cout <<"\n Enter Y-Translation ty:";
cin >> ty;

for(i=0;i<3;i++)
for(j=0;j<3;j++)
X[i][j] = 0;

X[0][0] = X[1][1] = X[2][2] = 1;
X[2][0] = tx;
X[2][1] = ty;

matmult(p,X,3,3,n,res);
cout <<"\n Polygon after Translation: ";
draw(res,n);
}

void D2:: reflect(int p[][10],int n)
{
int ch,i,j;
cout <<"\n **** Reflection Types ****";
cout <<" \n1.About X-Axis";
cout <<" \n2.About Y-Axis";
cout <<" \n3.About Origin";
cout <<" \n4.About Line y = x";
cout <<" \n5.About Line y = -x";
//cout <<" \n6.About Arbitrary Line";
cout <<" \nEnter your choice(1-6):";
cin >> ch;

for(i=0;i<3;i++)
for(j=0;j<3;j++)
{
if(i == j)
X[i][j] = 1;
else
X[i][j] = 0;
}

switch(ch)
{
case 1:
X[1][1] = -1;
break;
case 2:
X[0][0] = -1;
break;
case 3:
X[1][1] = -1;
X[0][0] = -1;
break;
case 4:
X[1][1] = 0;
X[0][0] = 0;
X[1][0] = 1;
X[0][1] = 1;
break;
case 5:
X[1][1] = 0;
X[0][0] = 0;
X[1][0] = -1;
X[0][1] = -1;
break;
}
matmult(p,X,3,3,n,res);
cout <<"\nPolygon after Reflection";
draw(res,n);
}

void D2:: rotate(int p[][10],int n)
{
int type,rot[10][10],res_1[10][10],i,j;
float ang,s_ang,c_ang;
cout <<"\n Enter the angle of rotation in degrees";
cin >> ang;
cout <<"\n **** Rotation Types ****";
cout << "\n1.Clockwise Rotation";
cout << "\n2.Anti-Clockwise Rotation";
cout << "\nEnter your choice(1-2): ";
cin >> type;

ang = (ang * 6.2832)/360;
s_ang = sin(ang);
//cout<<s_ang;
c_ang = cos(ang);
//cout<<endl<<c_ang;
//getch();

for(i=0;i<3;i++)
for(j=0;j<3;j++)
rot[i][j] = 0;

rot[0][0] = rot[1][1] =floor(0.5+c_ang);
rot[0][1] = rot[1][0] =floor(0.5+s_ang);
rot[2][2] = 1;

if(type == 1)
rot[1][0] = -1*floor(0.5+s_ang);
else
rot[0][1] =floor(0.5+s_ang);
matmult(p,rot,3,3,n,res_1);
cout << "\n Polygon after Rotation";
draw(res_1,n);
}

void D2:: scale(int p[][10],int n)
{
int Sx,Sy,res_2[10][10],sc[10][10],i,j;
cout <<"\n Enter X-Scaling Sx: ";
cin >> Sx;
cout <<"\n Enter Y-Scaling Sy: ";
cin >> Sy;

for(i=0;i<3;i++)
for(j=0;j<3;j++)
sc[i][j] = 0;

sc[0][0] = Sx;
sc[1][1] = Sy;
sc[2][2] = 1;

matmult(p,sc,3,3,n,res_2);
cout << "\n Polygon after Scaling";
draw(res_2,n);
}

void D2:: shear(int p[][10],int n)
{
int Sx,Sy,type,i,j;

for(i=0;i<3;i++)
for(j=0;j<3;j++)
{
if(i == j)
X[i][j] = 1;
else
X[i][j] = 0;
}

cout << "\n **** Shearing Types ****";
cout << "\n1.X-Direction Shear";
cout << "\n2.Y-Direction Shear";
cout << "\nEnter your choice(1-2):";
cin >> type;
if(type == 1)
{
cout << "\nEnter X-Shear Sx: ";
cin >> Sx;
X[0][1] = Sx;
}
else
{
cout << "\nEnter Y-Shear Sy: ";
cin >> Sy;
X[1][0] = Sy;
}
matmult(p,X,3,3,n,res);
cout << "\nPolygon after Shearing";
draw(res,n);
}

void D2::arbrot(int p[][10],int sz)
{
int type,rot[10][10],res_1[10][10],i,j,m,n;
float ang,s_ang,c_ang;
cout <<"\n Enter the angle of rotation in degrees";
cin >> ang;
cout << "\n Enter the point about which u want to rotate?";
cout << "\n X coordinate:";
cin >> m;
cout << "\n Y coordinate:";
cin >> n;

cout <<"\n **** Rotation Types ****";
cout << "\n1.Clockwise Rotation";
cout << "\n2.Anti-Clockwise Rotation";
cout << "\nEnter your choice(1-2): ";
cin >> type;

ang = (ang * 6.2832)/360;
s_ang = floor(0.5+sin(ang));
//cout<<s_ang;
c_ang = floor(0.5+cos(ang));
//cout<<endl<<c_ang;
//getch();

for(i=0;i<3;i++)
for(j=0;j<3;j++)
rot[i][j] = 0;

rot[0][0] = rot[1][1] =c_ang;
rot[0][1] = rot[1][0] =s_ang;
rot[2][2] = 1;
if(type==1)
{
rot[2][0] =-1*m*(c_ang-1)+n*s_ang;
rot[2][1] =-1*n*(c_ang-1)-m*s_ang;
rot[1][0] = -1*floor(0.5+s_ang);
}
else
{
rot[2][0] =-1*m*(c_ang+1)-n*s_ang;
rot[2][1] =-1*n*(c_ang+1)+m*s_ang;
rot[0][1] = -1*floor(0.5+s_ang);
}

matmult(p,rot,3,3,sz,res_1);
cout << "\n Polygon after Rotation";
draw(res_1,sz);
}

void D2::arbref(int p[][10],int n)
{
float m ,c;
float Xi[10][10];
int res_1[10][10];
float ang,s_ang,c_ang;
cout<<"\n Enter Arbitrary line :";
cout<<"\n Enter the slope :";
cin>>m;
cout<<"\n Enter the intercept:";
cin>>c;

cout<<"\n You want to reflect about the line : y=("<<m<<")x+("<<c<<")";

ang=(-1)*atan((-1)*m);
s_ang=sin(ang);
c_ang = cos(ang);


for(i=0;i<3;i++)
for(j=0;j<3;j++)
Xi[i][j] = 0;


Xi[0][0] = floor((((c_ang)^2)-((s_ang)^2))+0.5);
Xi[0][1] = floor((X[1][0] = (-2)*(c_ang)*(s_ang))+0.5);
Xi[1][1] = floor((((s_ang)^2)-((c_ang)^2))+0.5);
Xi[2][2] = 1;
Xi[2][0] = floor(((2)*(c)*(c_ang)*(s_ang))+0.5);
Xi[2][1] = floor((((-1)*c*s_ang*s_ang)+(c*c_ang*c_ang)+c)+0.5);

matmult(p,Xi,3,3,n,res_1);
cout << "\n Polygon after Reflection";
draw(res_1,n);

}

int menu()
{
int ch;
clrscr();
cout << "\n **** 2-D TRANSFORMATION ***";
cout << "\n 1.Translation";
cout << "\n 2.Scaling";
cout << "\n 3.Rotation";
cout << "\n 4.Reflection";
cout << "\n 5.Shearing";
cout << "\n 6.Rotation about an arbitary point";
cout << "\n 7.Reflection through an arbitary line";
cout << "\n 8.Exit";
cout << "\n Enter your choice(1-6): ";
cin >> ch;
return ch;
}

void main()
{
int ch,n,p[10][10];
D2 f1;
clrscr();
cout << "\n\n **** 2-D TRANSFORMATION ****";
n = f1.insert(p);
clrscr();
cout << "\n Original Polygon ";
f1.draw(p,n);

do
{
ch = menu();
switch(ch)
{
case 1:
f1.translate(p,n);
break;

case 2:
f1.scale(p,n);
break;

case 3:
f1.rotate(p,n);
break;

case 4:
f1.reflect(p,n);
break;

case 5:
f1.shear(p,n);
break;

case 6:
f1.arbrot(p,n);
break;

case 7:
f1.arbref(p,n);
break;

case 8:
exit(0);
}
}while(ch!=8);
getch();
}