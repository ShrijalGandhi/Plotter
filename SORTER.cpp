/*
Code snippet to sort a structure for v 4.5
*/


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

		void LPP(int);

/*----------------------------------------------------VARIABLES----------------------------------------------------*/
		 clrscr();
		int gd,gm,option,no_of_equations;

				cout<<"Enter no of equations"<<endl;
				cin>>no_of_equations;


		LPP(no_of_equations);


	}//end of main


	void LPP(int n)
	{

	void getPoints(double [100][2],double[2],double[100],int);

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



	   Variable temp;

			for(i=0;i<total_index;i++)
				for(j=0;j<total_index;j++)
				if(total[j].y>=total[i].y)
				{
				temp=total[i];
				total[i]=total[j];
				total[j]=temp;
				}
		/*
		for(i=0;i<total_index;i++)
		cout<<"("<<total[i].x<<","<<total[i].y<<")"<<endl;
		cout<<"-----------------------------------------"<<endl;
		*/

	    double min=total[0].x;
	    int index;
			for(i=0;i<total_index;i++)
				if(total[i].y==0&&min<total[i].x<=min)
				index=i;

	     optimum[optimum_index++]=total[index];
	     index=0;
		while(optimum_index<optimum_size)
		{
			if(total[index].y==0)
			{
			index++;
			continue;
			}
			optimum[optimum_index++]=total[index++];

		}

		/*
		for(i=0;i<optimum_size;i++)
		cout<<"("<<optimum[i].x<<","<<optimum[i].y<<")"<<endl;
		*/

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

