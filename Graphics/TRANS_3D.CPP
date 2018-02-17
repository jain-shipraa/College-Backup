
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

#define pi 3.14285714

class projections
{
      double vertices[8][4];               //matrix contains vertices of the triangle
      double t_matrix[4][4];             //transformation matrix
      double result[8][4];

      public:
      projections(){};

      void get_vertices();
      void display_cube();

      void multiplication();
      void copyback();

      void orthographic();
      void axonometric(double angle_x,double angle_y);
      void cavalier(double angle);
      void cabinet(double angle);
      void single_point(double r);
      void two_point(double r);
      void three_point(double r);
};


void projections::get_vertices()
{
     for(i=0;i<8;i++)
     {
	 cout<<"\nEnter vertex "<<i+1<<"...";
	 cout<<"\nx : ";
	 cin>>vertices[i][0];
	 result[i][0]=vertices[i][0];

	 cout<<"y : ";
	 cin>>vertices[i][1];
	 result[i][1]=vertices[i][1];

	 cout<<"z : ";
	 cin>>vertices[i][2];
	 result[i][2]=vertices[i][2];

	 vertices[i][3]=result[i][3]=1;
     }
}


void projections::display_cube()
{
     int i=0;

     for(i=0;i<3;i++)
     line(result[i][0],result[i][1],result[i+1][0],result[i+1][1]);
     line(result[i][0],result[i][1],result[0][0],result[0][1]);

     for(i=4;i<7;i++)
     line(result[i][0],result[i][1],result[i+1][0],result[i+1][1]);
     line(result[i][0],result[i][1],result[4][0],result[4][1]);

     for(i=0;i<4;i++)
     line(result[i][0],result[i][1],result[i+4][0],result[i+4][1]);
}


void projections::copyback()
{
     int i=0,j=0;

     for(i=0;i<8;i++)
     for(j=0;j<4;j++)
     result[i][j]=vertices[i][j];
}


void projections::multiplication()
{
     double r[8][4];
     int i=0,j=0,k=0;

	 for(i=0;i<8;i++)
	 {
	     for(j=0;j<4;j++)
	     {
		 r[i][j]=0;
		 for(k=0;k<4;k++)
		 r[i][j]+=result[i][k]*t_matrix[k][j];
	     }
	 }

     for(i=0;i<8;i++)              //Copying back the result
     for(j=0;j<4;j++)
     result[i][j]=r[i][j];
}

//ORTHOGRAPHIC PROJECTION....................................................................
void projections::orthographic()
{
     cleardevice();
     clearviewport();
     cout<<"\tORTHOGRAPHIC PROJECTION...........";

     copyback();

     t_matrix[0][0]=1;              //[T] for parallel projection on plane z=0
     t_matrix[0][1]=0;
     t_matrix[0][2]=0;
     t_matrix[0][3]=0;

     t_matrix[1][0]=0;
     t_matrix[1][1]=1;
     t_matrix[1][2]=0;
     t_matrix[1][3]=0;

     t_matrix[2][0]=0;
     t_matrix[2][1]=0;
     t_matrix[2][2]=0;
     t_matrix[2][3]=0;

     t_matrix[3][0]=0;
     t_matrix[3][1]=0;
     t_matrix[3][2]=0;
     t_matrix[3][3]=1;

	      multiplication();

    setcolor(GREEN);
    display_cube();
    delay(20);
    getch();
}

//AXONOMETRIC PROJECTION..................................................................
void projections::axonometric(double angle_x,double angle_y)
{
     angle_x=((pi/180)*angle_x);                //tan inverse(slope)=angle
     angle_y=((pi/180)*angle_y);

     cleardevice();
     clearviewport();
     cout<<"\tAXONOMETRIC PROJECTION...........";

     copyback();

     t_matrix[0][0]=cos(angle_y);              //[T] for parallel projection on plane z=0
     t_matrix[0][1]=(sin(angle_y))*(sin(angle_x));
     t_matrix[0][2]=0;
     t_matrix[0][3]=0;

     t_matrix[1][0]=0;
     t_matrix[1][1]=cos(angle_x);
     t_matrix[1][2]=0;
     t_matrix[1][3]=0;

     t_matrix[2][0]=sin(angle_y);
     t_matrix[2][1]=(-1)*(cos(angle_y)*sin(angle_x));
     t_matrix[2][2]=0;
     t_matrix[2][3]=0;

     t_matrix[3][0]=0;
     t_matrix[3][1]=0;
     t_matrix[3][2]=0;
     t_matrix[3][3]=1;

	      multiplication();

    setcolor(GREEN);
    display_cube();
    delay(20);
    getch();
}


//CAVALIER OBLIQUE PROJECTION..................................................................
void projections::cavalier(double angle)
{
     angle=((pi/180)*angle);                //converting degrees into radian

     cleardevice();
     clearviewport();
     cout<<"\tCAVALIER PROJECTION...........";

     copyback();

     t_matrix[0][0]=1;              //[T] for cavalier projection on plane z=0
     t_matrix[0][1]=0;
     t_matrix[0][2]=0;
     t_matrix[0][3]=0;

     t_matrix[1][0]=0;
     t_matrix[1][1]=1;
     t_matrix[1][2]=0;
     t_matrix[1][3]=0;

     t_matrix[2][0]=(-1)*1*cos(angle);
     t_matrix[2][1]=(-1)*1*sin(angle);
     t_matrix[2][2]=0;
     t_matrix[2][3]=0;

     t_matrix[3][0]=0;
     t_matrix[3][1]=0;
     t_matrix[3][2]=0;
     t_matrix[3][3]=1;

	      multiplication();

    setcolor(GREEN);
    display_cube();
    delay(20);
    getch();
}


//CABINET OBLIQUE PROJECTION..................................................................
void projections::cabinet(double angle)
{
     angle=((pi/180)*angle);        //converting degrees into radian

     cleardevice();
     clearviewport();
     cout<<"\tCABINET PROJECTION...........";

     copyback();

     t_matrix[0][0]=1;              //[T] for cabinet projection on plane z=0
     t_matrix[0][1]=0;
     t_matrix[0][2]=0;
     t_matrix[0][3]=0;

     t_matrix[1][0]=0;
     t_matrix[1][1]=1;
     t_matrix[1][2]=0;
     t_matrix[1][3]=0;

     t_matrix[2][0]=(-1)*0.5*cos(angle);
     t_matrix[2][1]=(-1)*0.5*sin(angle);
     t_matrix[2][2]=0;
     t_matrix[2][3]=0;

     t_matrix[3][0]=0;
     t_matrix[3][1]=0;
     t_matrix[3][2]=0;
     t_matrix[3][3]=1;

	      multiplication();

    setcolor(GREEN);
    display_cube();
    delay(20);
    getch();
}


//SINGLE POINT PRESPECTIVE PROJECTION..................................................................
void projections::single_point(double r)
{
     double l=10,m=10,n=10;            //Translation factors along x, y and z axis

     cleardevice();
     clearviewport();
     cout<<"\tSINGLE POINT PRESPECTIVE PROJECTION...........";

     r=(-1/r);
     copyback();

     t_matrix[0][0]=1;              //[T] for single point prespective projection on plane z=0
     t_matrix[0][1]=0;
     t_matrix[0][2]=0;
     t_matrix[0][3]=0;

     t_matrix[1][0]=0;
     t_matrix[1][1]=1;
     t_matrix[1][2]=0;
     t_matrix[1][3]=0;

     t_matrix[2][0]=0;
     t_matrix[2][1]=0;
     t_matrix[2][2]=0;
     t_matrix[2][3]=r;

     t_matrix[3][0]=l;
     t_matrix[3][1]=m;
     t_matrix[3][2]=0;
     t_matrix[3][3]=r*n+1;

     multiplication();

     setcolor(GREEN);
     display_cube();
     delay(20);
     getch();
}


//TWO-POINT PRESPECTIVE PROJECTION..................................................................
void projections::two_point(double r)
{
     double angle=45;
     angle=(pi/180)*angle;

     cleardevice();
     clearviewport();
     cout<<"\tTWO POINT PRESPECTIVE PROJECTION...........";

     copyback();

     r=(-1/r);

     t_matrix[0][0]=cos(angle);              //[T] for two point prespective projection on plane z=0
     t_matrix[0][1]=0;
     t_matrix[0][2]=(-1*sin(angle));
     t_matrix[0][3]=sin(angle)/r;

     t_matrix[1][0]=0;
     t_matrix[1][1]=1;
     t_matrix[1][2]=0;
     t_matrix[1][3]=0;

     t_matrix[2][0]=sin(angle);
     t_matrix[2][1]=0;
     t_matrix[2][2]=cos(angle);
     t_matrix[2][3]=(-1*cos(angle))/r;

     t_matrix[3][0]=0;
     t_matrix[3][1]=0;
     t_matrix[3][2]=0;
     t_matrix[3][3]=1;

                    multiplication();

     setcolor(GREEN);
     display_cube();
     delay(20);
     getch();
}


//THREE POINT PRESPECTIVE PROJECTION..........................................
void projections::three_point(double r)
{
     double angle_y=45,angle_x=45;
     angle_y=(pi/180)*angle_y;
     angle_x=(pi/180)*angle_x;

     cleardevice();
     clearviewport();
     cout<<"\tTHREE POINT PRESPECTIVE PROJECTION...........";

     copyback();

     r=(-1/r);

     t_matrix[0][0]=cos(angle_y);              //[T] for three point prespective projection on plane z=0
     t_matrix[0][1]=sin(angle_y)*sin(angle_x);
     t_matrix[0][2]=0;
     t_matrix[0][3]=(sin(angle_y)*cos(angle_x))/r;

     t_matrix[1][0]=0;
     t_matrix[1][1]=cos(angle_x);
     t_matrix[1][2]=0;
     t_matrix[1][3]=(-1*sin(angle_x))/r;

     t_matrix[2][0]=(sin(angle_y));
     t_matrix[2][1]=(-1*cos(angle_y)*sin(angle_x));
     t_matrix[2][2]=0;
     t_matrix[2][3]=(-1*cos(angle_y)*cos(angle_x))/r;

     t_matrix[3][0]=0;
     t_matrix[3][1]=0;
     t_matrix[3][2]=0;
     t_matrix[3][3]=1;

     multiplication();

     setcolor(GREEN);
     display_cube();
     delay(20);
     getch();
}


void main()
{
    clrscr();
    int gd=DETECT,gm,choice;
    projections t1;
    char ch1,ch2,axis,axis1,axis2;
    double angle_x,angle_y,angle,ratio,ratio1,ratio2,ratio3;

    do
    {
       cout<<"\n\n\t   ........PROJECTIONS OF 3D OBJECTS........\n";
       cout<<"\nEnter the details of a cube(i.e. 3D object).....";
       t1.get_vertices();

	  do
	  {
	      initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	      cout<<"\n\n...........MENU...........";
	      cout<<"\n1.Orthographic.";
	      cout<<"\n2.Axonometric.";
	      cout<<"\n3.Cavalier (Oblique type 1).";
	      cout<<"\n4.Cabinet (Oblique type 2)";
	      cout<<"\n5.Single-Point presepective.";
	      cout<<"\n6.Two-Point presepective.";
	      cout<<"\n7.Three-Point presepective.";
	      cout<<"\n............................";

	      cout<<"\n\nEnter your choice :: ";
	      cin>>choice;

	      switch(choice)
	      {
		     case 1:t1.orthographic();
			    break;

		     case 2:cout<<"\n\nFOR AXONOMETRIC PROJECTION..........";
			    cout<<"\nEnter the angle of rotation about :-";
			    cout<<"\nx-axis : ";
			    cin>>angle_x;
			    cout<<"And, y-axis : ";
			    cin>>angle_y;

			    t1.axonometric(angle_x,angle_y);
			    break;

		     case 3:cout<<"\n\nFOR CAVALIER PROJECTION..........";
			    cout<<"\nEnter the angle of inclination : ";
			    cin>>angle;

			    t1.cavalier(angle);
			    break;

		     case 4:cout<<"\n\nFOR CABINET PROJECTION..........";
			    cout<<"\nEnter the angle of inclination : ";
			    cin>>angle;

			    t1.cabinet(angle);
			    break;

		     case 5:cout<<"\n\nFOR SINGLE POINT PRESPECTIVE PROJECTION..........";
			    cout<<"\nAssuming that the VP lies on the z-axis....";
			    cout<<"Enter the prespective ratio for z-axis :: ";
			    cin>>ratio;

			    t1.single_point(ratio);

			    break;

		     case 6:cout<<"\n\nFOR TWO POINT PRESPECTIVE PROJECTION..........";
			    cout<<"\nAssuming that the VP lies on the z-axis....";
			    cout<<"Enter the prespective ratio for z-axis :: ";
			    cin>>ratio;

			    t1.two_point(ratio);

			    break;

		     case 7:cout<<"\n\nFOR THREE POINT PRESPECTIVE PROJECTION..........";
			    cout<<"\nAssuming that the VP lies on the z-axis....";
			    cout<<"Enter the prespective ratio for z-axis :: ";
			    cin>>ratio;

			    t1.three_point(ratio);

                          		    break;

		    default:cout<<"\n\n\t!!!INVALID CHOICE!!!";
                           		    getch();
	      }
	      closegraph();

	      cout<<"\nWanna try another projection(y/n)...";
	      cin>>ch2;

	  }while(ch2=='y');

       cout<<"\nWanna try with a cube of different dimensions(y/n)... ";
       cin>>ch1;

    }while(ch1=='y');
}