//---------------------------------------------------------------------------

#pragma hdrstop

#include "Figure.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void cirk::get(double X1,double Y1,double X2,double Y2)
	{
	this->X1=X1;
	this->Y1=Y1;
	this->X2=X2;
	this->Y2=Y2;
	}

	void cirk::calculateRadius()
	{
	this->r=sqrt(pow((Y2-Y1),2)+pow((X2-X1),2));
	}

	void cirk::show(TCanvas *Canvas,TImage *Image1)
	{
	Image1->Canvas->Ellipse(X1-r,Y1+r,X1+r,Y1-r);
	}


	double cirk::showSquare()
	{
		   s=3.14*r*r;
		   return s;
	}

	double cirk::showPerimetr()
	{
		   p=2*3.14*r;
		   return p;
	}

	void cirk::showCenterMass()
	{
	  xc=X1;
	  yc=Y1;

	}

	void cirk::moveCenterMass(double X1,double Y1)
	{
	this->X1=X1;
	this->Y1=Y1;
	}

	void rectangle::get(double X1,double Y1,double X2,double Y2)
	{
	a=abs(X1-X2);
	b=abs(Y1-Y2);
	this->X1=X1;
	this->X2=X2;
	this->Y1=Y1;
	this->Y2=Y2;
	}

	void rectangle::show(TCanvas *Canvas,TImage *Image1)
	{
	Image1->Canvas->Rectangle(X1,Y1,X2,Y2);
	}

	double rectangle::showSquare()
	{
		   s=a*b;
		   return s;
	}

	double rectangle::showPerimetr()
	{
		   p=2*(a+b);
		   return p;
	}

	void rectangle::showCenterMass()
	{
	  xc=(X1+X2)/2;
	  yc=(Y1+Y2)/2;
	}

	void rectangle::moveCenterMass(double newX,double newY)
	{
	   X1=newX-a/2;
	   Y1=newY-b/2;
	   X2=2*newX-X1;
	   Y2=2*newY-Y1;
	}
