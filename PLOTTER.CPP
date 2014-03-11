/**********************************************************************************************************************
						CHANGELOG
						---------
------------------------------------------------->V 1.5<-------------------------------------------------------------
1. Changed plotAxes() to make it more efficient. Now main axes get more highlighted. In v 1.0 since they were plotted
   before the small axes they had many holes. Now corrected

------------------------------------------------->V 1.7<-------------------------------------------------------------
1. Added denominations to the axes.

------------------------------------------------->V 1.8<-------------------------------------------------------------
1. Added y=mx+c

------------------------------------------------->V 2.0<-------------------------------------------------------------
1. Fixed the origin from (325,250) to (275,275) so that y=mx+c is realistic to the human eyes. Try v 1.8 for m=1,c=0
   and compare it to a real graph.

------------------------------------------------->V 2.1<-------------------------------------------------------------
1. Fixed the origin bug. Now origin again is (325,250) so that the graph appears balanced on all quadrants.
   The bug was that m++ c++ statements were inserted in drawLine() to prevent Warning of no possible use during
   compilation. Therefore their effects also got added.

------------------------------------------------->V 2.2<-------------------------------------------------------------
1. Added parabola equation y2=4ax

------------------------------------------------->V 2.2.1<-----------------------------------------------------------
1. Made changes to drawLine() so that line is plotted a little longer to cover all possible quadrants and appear
   realistic. ie Changed for loop termination from 100 to 200.

------------------------------------------------->V 2.3<-------------------------------------------------------------
1. Added parabola equation x2=4by

------------------------------------------------->V 2.4<-------------------------------------------------------------
1. Added Circle

------------------------------------------------->V 2.4.1<-----------------------------------------------------------
1. Added a tweak to the Circle so that the center and radius co-ordinates are shown

------------------------------------------------->V 2.5<-------------------------------------------------------------
1. Added ellipse and plotting of its x and y focii
2. Added a tweak to parabola plotting its focii

------------------------------------------------->V 2.6<-------------------------------------------------------------
1. Added Hyperbola and plotting of its center. A conjugate hyperbola is not supported

------------------------------------------------->V 2.6.5<-----------------------------------------------------------
1. Added conjugate Hyperbola (default).

------------------------------------------------->V 2.6.9<-----------------------------------------------------------
1. Changed menu to help draw Hyperbola and conjugate Hyberbola also.

------------------------------------------------->V 2.7<-------------------------------------------------------------
1. Added Rectangular Hyberbola

------------------------------------------------->V 3.0<-------------------------------------------------------------
1. Changed precisions of for loops for better pixel generation so that the diagrams appear more realistic

------------------------------------------------->V 4.0<-------------------------------------------------------------
1. Added LPP for maximizing z. Only takes input and plots two lines. Only two equations supported

------------------------------------------------->V 4.1<-------------------------------------------------------------
1. Modified LPP. Generalized to work for n equations of 2 unknowns. 

------------------------------------------------->V 4.2<-------------------------------------------------------------
1. Fixed a glitch with drawLine() which cannot draw equations of the form x=c;
2. Only x>=0,y>=0 allowed

------------------------------------------------->V 4.3<-------------------------------------------------------------
1. Z(max) is calculated and displayed
2. Only x>=0,y>=0 allowed

------------------------------------------------->V 4.4<-------------------------------------------------------------
1. Trying to fix a glitch which causes z to get maximized over points which are not in the feasible region

------------------------------------------------->E V 4.4<-----------------------------------------------------------
1. Fixed the glitch and modified the sorting method.. To compare check out V 4.4 and E V 4.4 methods.

------------------------------------------------->V 4.4<-------------------------------------------------------------
1. Fused E V 4.4 and V 4.4 to fix the glitch

**********************************************************************************************************************/
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>

	void main()
	{
/*---------------------------------------------------PROTOTYPES----------------------------------------------------*/

		void startgraph();
		void endgraph();
		void plotAxes();
		void drawLine(double,double);
		void drawParabola1(double);
		void drawParabola2(double);
		void drawCircle(double,double,double);
		void drawEllipse(double,double,double,double);
		void drawHyperbola(double,double,double,double);
		void draw_conjugateHyperbola(double,double,double,double);
		void draw_rectangularHyperbola(double,double,double);
		void LPP(int);
		void drawLine_X(double);
/*----------------------------------------------------VARIABLES----------------------------------------------------*/

		int gd,gm,option,no_of_equations;
		double m,c,a,b,radius,x_center,y_center;

/*-----------------------------------------------------------------------------------------------------------------*/


	//*****************************MENU********************************


	restart:
	{
		clrscr();
		cout<<"========================MENU============================="<<endl;
		cout<<"1. y=mx+c"<<endl;
		cout<<"2. y2=4ax"<<endl;
		cout<<"3. x2=4by"<<endl;
		cout<<"4. Circle"<<endl;
		cout<<"5. Ellipse"<<endl;
		cout<<"6. Hyperbola"<<endl;
		cout<<"7. Conjugate Hyperbola"<<endl;
		cout<<"8. Rectangular Hyberbola"<<endl;
		cout<<"9. LPP"<<endl;
		cout<<"Enter your option"<<endl;
		cin>>option;
	}//end of restart

			switch(option)
			{
			case 1:
				cout<<"Enter m"<<endl;
				cin>>m;
				cout<<"Enter c"<<endl;
				cin>>c;
				break;

			case 2:
				cout<<"Enter a"<<endl;
				cin>>a;
				break;

			case 3:
				cout<<"Enter b"<<endl;
				cin>>b;
				break;

			case 4:
				cout<<"Enter radius"<<endl;
				cin>>radius;
				cout<<"Enter 'x' co-ordinate of center"<<endl;
				cin>>x_center;
				cout<<"Enter 'y' co-ordinate of center"<<endl;
				cin>>y_center;
				break;

			case 5:
			case 6:
			case 7:
				cout<<"Enter x co-ordinate of center"<<endl;
				cin>>x_center;
				cout<<"Enter y co-ordinate of center"<<endl;
				cin>>y_center;
				cout<<"Enter a"<<endl;
				cin>>a;
				cout<<"Enter b"<<endl;
				cin>>b;
				break;

			case 8:
				cout<<"Enter x co-ordinate of center"<<endl;
				cin>>x_center;
				cout<<"Enter y co-ordinate of center"<<endl;
				cin>>y_center;
				cout<<"Enter c"<<endl;
				cin>>c;
				break;

			case 9:
				cout<<"Enter no of equations"<<endl;
				cin>>no_of_equations;
				break;


			default:
				cout<<"Please enter a valid option"<<endl;
				goto restart;
			}

	if(option==9)
	goto caller; 	//since we dont want graph to be initialized since we want more i/p  from user.
		     	//if you want to remove this loop and the label be sure to have closegraph() as 
			//the first line of the method LPP()

	gd=DETECT;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	      plotAxes();

		caller:
		{

			switch(option)
			{
			case 1:	drawLine(m,c);
				break;

			case 2:	drawParabola1(a);
				break;

			case 3: drawParabola2(b);
				break;

			case 4:
				drawCircle(radius,x_center,y_center);
				break;

			case 5:
				drawEllipse(x_center,y_center,a,b);
				break;

			case 6:
				drawHyperbola(x_center,y_center,a,b);
				break;

			case 7:
				draw_conjugateHyperbola(x_center,y_center,a,b);
				break;

			case 8:
				draw_rectangularHyperbola(x_center,y_center,c);
				break;

			case 9:
				LPP(no_of_equations);
				break;
			}
		}
/*------------------------------------------------------PROGRAM----------------------------------------------------*/
	}//end of main

	void plotAxes()
	{
		//putpixel(325,250,RED);   Point of intersection
		//line(325,250,350,250);   1cm=25 pixels on both axes

	      setcolor(8);
	      for(int i=0;i<26;i++)
	      {
	       line((i*25),0,(i*25),500);
	       line(0,(i*25),650,(i*25));
	      }

	// =-=-=-=-=-=-=-=-=-=-=-=MAJOR AXES=-=-=-=-=-=-=-=-=-=-=-=
		setcolor(7);
		line(325,0,325,500);
		line(0,250,650,250);

	//[*][*][*][*][*][*][*][*][*][*][*][*][*][*][*][*][*][*][*]


	//############# GENERATION OF DENOMINATIONS #############

		settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
		setusercharsize(1,2,1,3);

			char *origin="0";
			outtextxy(328,253,origin);

		int value=1;
		char c[1];


		for(i=1;i<12;i++)
		{
		sprintf(c,"%d",value);
		outtextxy(328+(i*25),253,c);
		outtextxy(328,253-(i*25),c);

		sprintf(c,"%d",(value*(-1)));
		outtextxy(328-(i*25),253,c);
		outtextxy(328,253+(i*25),c);
		value++;
		}
	//#########################################################


	getch();
	}

	void drawLine(double m,double c)
	{
	double x,y;

		for(x=0;x<200;x+=0.1)
		{
		y=(m*x)+(c*25);
		putpixel(x+325,250-y,10);
		}
		for(x=-0.1;x>-200;x-=0.1)
		{
		y=(m*x)+(c*25);
		putpixel(x+325,250-y,10);
		}
	 getch();
	}

	void drawLine_X(double c)
	{
	double y;

		for(y=0;y<200;y+=0.1)
		putpixel(325+(c*25),250-y,10);

		for(y=-0.1;y>-200;y-=0.1)
		putpixel(325+(c*25),250-y,10);
	 getch();
	}

	void drawParabola1(double a)
	{
	double x,y;
	double A=4*a;
		for(y=0;y<100;y+=0.001)
		{
		x=(y*y)/A;
		putpixel(x+325,250-y,10);
		putpixel(x+325,250+y,10);
		}
		
		int col=2;
		setcolor(col);
		setfillstyle(SOLID_FILL,col);
		pieslice((a*25)+325,250,0,360,2);

	getch();
	}

	void drawParabola2(double b)
	{
	double x,y;
	double B=4*b;
		for(x=0;x<100;x+=0.001)
		{
		y=(x*x)/B;
		putpixel(x+325,250-y,10);
		putpixel(325-x,250-y,10);
		}

		int col=2;
		setcolor(col);
		setfillstyle(SOLID_FILL,col);
		pieslice(325,250-(b*25),0,360,2);
	getch();
	}

	void drawCircle(double radius,double x,double y)
	{
	setcolor(10);
	//ellipse((x*25)+325,250-(y*25),0,360,(radius*25),(radius*25));
	circle((x*25)+325,250-(y*25),(radius*25));

		int col=2;
		setcolor(col);
		setfillstyle(SOLID_FILL,col);
		pieslice((x*25)+325,250-(y*25),0,360,2);


	getch();
	}

	void drawEllipse(double x,double y,double a,double b)
	{
	/*
	double A=a*a;
	double B=b*b;
	double AB=A*B;
	double X;
	double term;

	       for(x=0;x<a;x+=0.01)
		{
		X=x*x;                         
		term=(AB-(B*X))/A;              
			if(term>=0)                		use this to plot via putpixel one extra     
			{                              		for loop with 325-(x*25) will be required
			y=sqrt(term);
			putpixel((x*25)+325,250-(y*25),10);
			putpixel((x*25)+325,250+(y*25),10);
			}
		}
	*/
		setcolor(10);
		ellipse((x*25)+325,250-(y*25),0,360,(a*25),(b*25));

			double A=a*a;
			double B=b*b;

			double e=sqrt((A-B)/A);
			double X_focii=a*e;
			double Y_focii=b*e;

/*___________________________Plotting of the focii_________________________*/

		int col=19;
		setcolor(col);
		setfillstyle(SOLID_FILL,col);
		pieslice(325+(x*25)+(X_focii*25),250-(y*25),0,360,2);
		pieslice(325+(x*25)-(X_focii*25),250-(y*25),0,360,2);

		pieslice(325+(x*25),250-(y*25)-(Y_focii*25),0,360,2);
		pieslice(325+(x*25),250-(y*25)+(Y_focii*25),0,360,2);

/*__________________________Plotting of the major axes_____________________*/

	line(325+(x*25)+(a*25),250-(y*25),325+(x*25)-(a*25),250-(y*25));
	line(325+(x*25),250-(y*25)+(b*25),325+(x*25),250-(y*25)-(b*25));
	getch();
	}

	void drawHyperbola(double x_center,double y_center,double a,double b)
	{

	double A=a*a;
	double B=b*b;
	double AB=A*B;
	double Y,y,x;
	double term;

	       for(y=0;y<5;y+=0.001)
		{
		Y=y*y;
		term=(AB+(A*Y))/B;
			if(term>=0)
			{
			x=sqrt(term);
			putpixel(325+(x_center*25)+(x*25),250-(y_center*25)-(y*25),10);
			putpixel(325+(x_center*25)+(x*25),250-(y_center*25)+(y*25),10);
			putpixel(325+(x_center*25)-(x*25),250-(y_center*25)-(y*25),10);
			putpixel(325+(x_center*25)-(x*25),250-(y_center*25)+(y*25),10);
			}
		}

		int col=2;
		setcolor(col);
		setfillstyle(SOLID_FILL,col);
		pieslice(325+(x_center*25),250-(y_center*25),0,360,2);
	getch();
	}

	void draw_conjugateHyperbola(double x_center,double y_center,double a,double b)
	{

	double A=a*a;
	double B=b*b;
	double AB=A*B;
	double X,y,x;
	double term;

	       for(x=0;x<5;x+=0.001)
		{
		X=x*x;
		term=(AB+(B*X))/A;
			if(term>=0)
			{
			y=sqrt(term);
			putpixel(325+(x_center*25)+(x*25),250+(y_center*25)-(y*25),10);
			putpixel(325+(x_center*25)+(x*25),250+(y_center*25)+(y*25),10);
			putpixel(325+(x_center*25)-(x*25),250+(y_center*25)-(y*25),10);
			putpixel(325+(x_center*25)-(x*25),250+(y_center*25)+(y*25),10);
			}
		}

		int col=2;
		setcolor(col);
		setfillstyle(SOLID_FILL,col);
		pieslice(325+(x_center*25),250-(y_center*25),0,360,2);
	getch();
	}

	void draw_rectangularHyperbola(double x_center,double y_center,double c)
	{
	double x,y;
	//double C=c*c;  if only positive c wanted as in xy=c2.

		int col=2;
		setcolor(col);
		setfillstyle(SOLID_FILL,col);
		pieslice(325+(x_center*25),250-(y_center*25),0,360,2);

		setcolor(10);
		for(x=0;x<100;x+=0.0001)
		{
		y=c/x;  //replace c by C if above comment is valid
		putpixel(325+(x_center*25)+(x*25),250+(y_center*25)-(y*25),10);
		putpixel(325+(x_center*25)-(x*25),250+(y_center*25)+(y*25),10);
		}

	getch();
	}

	void LPP(int n)
	{
	void plotAxes();  //not required since it is defined before the method
	void colorAxes();
	void getPoints(double [100][2],double[2],double[100],int);
	/*
	double a[n][n];	 not allowed since C++ asks for size to be static not dynamic. therefore initialize a high
			 size and use n as the limit in the for loops.
	*/

	double variable_matrix[100][2];
	double parameter_matrix[2];
	double constant_matrix[100];

	int i,j;

		for(i=0;i<2;i++)
		{
			if(i%2==0)
			cout<<"Enter co-efficient for x for z"<<endl;
			else
			cout<<"Enter co-officient of y for z"<<endl;
		cin>>parameter_matrix[i];
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			if(j%2==0)
			{
			cout<<"Enter the x-variable for equation "<<(i+1)<<endl;
			cin>>variable_matrix[i][j];
			}
			else
			{
			cout<<"Enter the y-variable for equation "<<(i+1)<<endl;
			cin>>variable_matrix[i][j];
			}
		cout<<"Enter the constant variable for equation"<<(i+1)<<endl;
		cin>>constant_matrix[i];

		}

/*==============================================DEBUGGING PURPOSES======================================================
		cout<<"The equations are"<<endl;
		int count=0;
		char c[]={'x','+','y','='};

			cout<<"Maximize  z=";
			for(i=0;i<n;i++)
			{
			cout<<parameter_matrix[i];
			cout<<c[count++];
				if(i<n-1)
				cout<<c[count++];
			}
			cout<<endl;

			for(i=0;i<n;i++)
			{
			count=0;
				for(j=0;j<2;j++)
				{
				cout<<variable_matrix[i][j];
				cout<<c[count++];
				cout<<c[count++];
				}

			cout<<constant_matrix[i];
			cout<<endl;
			}
			getch();
======================================================================================================================*/

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	double m,c;
	      plotAxes();

		for(i=0;i<n;i++)
		{
			if(variable_matrix[i][1]==0)
			{
			c=constant_matrix[i]/variable_matrix[i][0];
			drawLine_X(c);
			}
			else
			{
			m=((-1)*variable_matrix[i][0])/variable_matrix[i][1];
			c=constant_matrix[i]/variable_matrix[i][1];
			drawLine(m,c);
			}
		}
	setfillstyle(SLASH_FILL,10);
	colorAxes();
       floodfill(330,245,10);


	getch();
	closegraph();// ...DEBUGGING..TO SEE THE COMPUTATION IN getPoints();

			getPoints(variable_matrix,parameter_matrix,constant_matrix,n);
	}

/*_________________________________________________________*/
		struct Variable
		{
		int x,y;
		};
/*__________________________________________________________*/

	void getPoints(double variable_matrix[100][2],double parameter_matrix[2],double constant_matrix[100],int n)
	{


	Variable solve(int,int,double[100][2],double[100],double);

      //	int total_size=3*n;
       	int optimum_size=n+1;

	int total_index=0;
       	int optimum_index=0;

	Variable total[100];
	Variable optimum[100];

	//int can_be_solved=0;
			/*==============================INTERSECTION WITH X AXIS=================================*/
				for(int i=0;i<n;i++)
				{

					if(variable_matrix[i][0]!=0)
					total[total_index].x=constant_matrix[i]/variable_matrix[i][0];
					else
					total[total_index].x=0;

					total[total_index++].y=0;
				}

			/*==============================INTERSECTION WITH Y AXIS=================================*/			
				for(i=0;i<n;i++)
				{

					if(variable_matrix[i][1]!=0)
					total[total_index].y=constant_matrix[i]/variable_matrix[i][1];
					else
					total[total_index].y=0;

					total[total_index++].x=0;

				}
			/*======================================================================================*/
		
		
		/*------------------------DEBUGGING------------------------------
		for(i=0;i<total_index;i++)
		cout<<"("<<total[i].x<<","<<total[i].y<<")"<<endl;
		cout<<"==================================================";
		----------------------------------------------------------------*/

		double AD,BC,D;
				for(i=0;i<n;i++)
					for(int j=i+1;j<n;j++)
					{
					AD=variable_matrix[i][0]*variable_matrix[j][1];
					BC=variable_matrix[i][1]*variable_matrix[j][0];
					D=AD-BC;
					  	if(D!=0)
						total[total_index++]=solve(i,j,variable_matrix,constant_matrix,D);
						else
						continue;	//it is of type x=c or y=c...thus points are
								//already computed during intersection with axes

					}
		/*------------------------DEBUGGING------------------------------
		for(i=0;i<total_index;i++)
		cout<<"("<<total[i].x<<","<<total[i].y<<")"<<endl;
		----------------------------------------------------------------*/


	   Variable temp;

			for(i=0;i<total_index;i++)
				for(j=0;j<total_index;j++)
				if(total[j].y>=total[i].y)
				{
				temp=total[i];
				total[i]=total[j];
				total[j]=temp;
				}

		/*-----------------------------DEBUGGING-----------------------------------
		for(i=0;i<total_index;i++)
		cout<<"("<<total[i].x<<","<<total[i].y<<")"<<endl;
		cout<<"-----------------------------------------"<<endl;
		+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	    double min=total[0].x;
	    int index;
			for(i=0;i<total_index;i++)			// to get the first intersection with x-axis
				if(total[i].y==0&&min<total[i].x<=min)	// nearest to the origin
				index=i;

	     optimum[optimum_index++]=total[index];		//min x-intercept recorded
	     index=0;

		while(optimum_index<optimum_size)
		{
			if(total[index].y==0)			//since x-intercept minimum point is already 
			{					//computed and in array do not consider any
			index++;				// other point on x-axis to put in array
			continue;				//no need to write extra code for y-intercept
			}					//since it is of form(0,c) therefore sorted in order
			optimum[optimum_index++]=total[index++];

		}

		/*-----------------------------DEBUGGING-----------------------------------
		for(i=0;i<optimum_size;i++)
		cout<<"("<<optimum[i].x<<","<<optimum[i].y<<")"<<endl;
		-------------------------------------------------------------------------*/
			

	double sum=0;
	double max=0;
	index=0;


			for(i=0;i<optimum_index;i++)
			{
			sum=(parameter_matrix[0]*optimum[i].x)+(parameter_matrix[1]*optimum[i].y);
			
				if(max<sum)
				{
				max=sum;
				index=i;
				}
			}

	//closegraph();
	cout<<"MAX z="<<max<<"  At ("<<optimum[index].x<<","<<optimum[index].y<<")"<<endl;
	getch();	
				

	}

	Variable  solve(int i,int j,double variable_matrix[100][2],double constant_matrix[100],double D)
	{
	Variable v;
		
		//Using Cramer's rule..   http://en.wikipedia.org/wiki/Cramer's_rule
 
		v.x=((constant_matrix[i]*variable_matrix[j][1])-(constant_matrix[j]*variable_matrix[i][1]))/D;
		v.y=((constant_matrix[j]*variable_matrix[i][0])-(constant_matrix[i]*variable_matrix[i][0]))/D;	

	return v;
	}

	void colorAxes()
	{
		for(int x=325;;x++)
		{
		if(getpixel(x,250)!=10)
		putpixel(x,250,10);
		else
		break;
		}

		for(int y=249;;y--)  //since 250 is already colored by
		{                    //previous loop..ie origin already done
		if(getpixel(325,y)!=10)
		putpixel(325,y,10);
		else
		break;
		}
	       //getch();   DEBUGGING
	}