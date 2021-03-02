//---------------------------------------------------------------------------

#ifndef FigureH
#define FigureH
//---------------------------------------------------------------------------
#endif
#include<math.h>
#include<vcl.h>
class figure
{
public:

virtual double showSquare();

};

class cirk
{
protected:
double r;
double s,p;
double xc,yc;
double X1,Y1,X2,Y2;
public:

	void get(double X1,double Y1,double X2,double Y2);

	void calculateRadius();

	void show(TCanvas *Canvas,TImage *Image1);

	double showSquare();

	double showPerimetr();

	void showCenterMass();

	void moveCenterMass(double X1,double Y1);

};

class rectangle
{

protected:
double a,b;
double s,p;
double xc,yc;
double X1,Y1,X2,Y2;
public:



	void get(double X1,double Y1,double X2,double Y2);

	void show(TCanvas *Canvas,TImage *Image1);

	double showSquare();

	double showPerimetr();

	void showCenterMass();

	void moveCenterMass(double newX,double newY);


};
