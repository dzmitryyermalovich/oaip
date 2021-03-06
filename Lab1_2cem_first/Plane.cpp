//---------------------------------------------------------------------------

#pragma hdrstop

#include "Plane.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

  void plane::show(TCanvas *Canvas)
  {
  Canvas->Pen->Color=clRed;
  Canvas->Rectangle(x1,y1,x2,y2);
  }

  void plane::hide(TCanvas *Canvas)
  {
  Canvas->Pen->Color=clWhite;
  Canvas->Rectangle(x1,y1,x2,y2);
  }

  void plane::move(TCanvas *Canvas,int lr)
  {
  learningRate=lr;
  Canvas->Pen->Color=clRed;
  hide(Canvas);
  x1=x1+learningRate;
  x2=x2+learningRate;
  show(Canvas);
  }


  void plane::moveDown(TCanvas *Canvas)
  {
  Canvas->Pen->Color=clRed;
  hide(Canvas);
  x1=x1+8;
  x2=x2+8;
  y1=y1+4;
  y2=y2+4;
  show(Canvas);
  }

  void planeAndChassis::move(TCanvas *Canvas)
  {
   hideChassisFly(Canvas);
   plane::move(Canvas,5);
   moveChassisFly(Canvas);
  }

  void planeAndChassis::hideChassisFly(TCanvas *Canvas)
  {
   Canvas->Pen->Color=clWhite;

   Canvas->MoveTo(x2,y2-1);
   Canvas->LineTo(x2+20,y2-1);
   Canvas->Ellipse((x2+20)-10,(y2-1)+10,(x2+20)+10,(y2-1)-10);

   Canvas->MoveTo(x1,y2-1);
   Canvas->LineTo(x1-20,y2-1);
   Canvas->Ellipse((x1-20)-10,(y2-1)+10,(x1-20)+10,(y2-1)-10);
  }

	void planeAndChassis::moveChassisFly(TCanvas *Canvas)
  {
   Canvas->MoveTo(x2,y2-1);
   Canvas->LineTo(x2+20,y2-1);
   Canvas->Ellipse((x2+20)-10,(y2-1)+10,(x2+20)+10,(y2-1)-10);

   Canvas->MoveTo(x1,y2-1);
   Canvas->LineTo(x1-20,y2-1);
   Canvas->Ellipse((x1-20)-10,(y2-1)+10,(x1-20)+10,(y2-1)-10);
  }

	void planeAndChassis::hideChassisDown(TCanvas *Canvas)
  {
   Canvas->Pen->Color=clWhite;

   Canvas->MoveTo(x2,y2-1);



   if(((x2+20)-i)==x2)
   {
	   Canvas->MoveTo(x2,y2-1);
	   Canvas->LineTo(x2,y2-1+i);
	   Canvas->Ellipse(x2-10,((y2-1)+i)+10,x2+10,((y2-1)+i)-10);

	   Canvas->MoveTo(x1,y2-1);
	   Canvas->LineTo(x1,y2-1+i);
	   Canvas->Ellipse(x1-10,((y2-1)+i)+10,x1+10,((y2-1)+i)-10);

   }
   else
   {
	   Canvas->MoveTo(x2,y2-1);
	   Canvas->LineTo((x2+20)-(i-5),y2-1+(i-5));
	   Canvas->Ellipse((x2+20)-10-(i-5),((y2-1)+i-5)+10,(x2+20)+10-(i-5),((y2-1)+i-5)-10);

	   Canvas->MoveTo(x1,y2-1);
	   Canvas->LineTo((x1-20)+(i-5),y2-1+(i-5));
	   Canvas->Ellipse((x1-20)-10+(i-5),((y2-1)+i-5)+10,(x1-20)+10+(i-5),((y2-1)+i-5)-10);
   }



  }

  void planeAndChassis::moveFinal(TCanvas *Canvas)
  {
   Canvas->Pen->Color=clRed;

   Canvas->MoveTo(x2,y2-1);
   Canvas->LineTo((x2+20)-i,y2-1+i);
   Canvas->Ellipse(x2-10,((y2-1)+i)+10,x2+10,((y2-1)+i)-10);

   Canvas->MoveTo(x1,y2-1);
   Canvas->LineTo((x1-20)+i,y2-1+i);
   Canvas->Ellipse(x1-10,((y2-1)+i)+10,x1+10,((y2-1)+i)-10);
  }

	void planeAndChassis::moveChassisDown(TCanvas *Canvas)
  {

   Canvas->MoveTo(x2,y2-1);
   Canvas->LineTo((x2+20)-i,y2-1+i);
   Canvas->Ellipse((x2+20)-10-i,((y2-1)+i)+10,(x2+20)+10-i,((y2-1)+i)-10);

   Canvas->MoveTo(x1,y2-1);
   Canvas->LineTo((x1-20)+i,y2-1+i);
   Canvas->Ellipse((x1-20)-10+i,(y2-1+i)+10,(x1-20)+10+i,(y2-1+i)-10);

   if(((x2+20)-i)!=x2)
   {
   i+=5;
   }


  }

	void planeAndChassis::moveDown(TCanvas *Canvas)
  {
  if(((x2+20)-i)==x2)
  {

	hideChassisDown(Canvas);
	plane::move(Canvas,2);
	moveFinal(Canvas);
  }
  else
  {
   hideChassisDown(Canvas);
   plane::moveDown(Canvas);
   moveChassisDown(Canvas);
  }
  }
