//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include<math.h>
#include "Figure.h"
figure* fig;
rectangle rec;
cirk kr;
TForm1 *Form1;
int X1=0;
int Y1=0;
int X2=0;
int Y2=0;
int activationNumber;
int operation=-1;
double radius;
double square;
double perimetr;
int x;
int y;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	Image1->Canvas->Brush->Color=clWhite;
	 X1=X;
	 Y1=Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Image1->Canvas->Pen->Color=clRed;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
X2=X;
Y2=Y;


switch(activationNumber)
{

case 0:

  Image1->Canvas->Rectangle(X1,Y1,X2,Y2);

  rec.get(X1,Y1,X2,Y2);

 switch (operation) {

 case 0:

  //fig=&rec;
  square=rec.showSquare();
  //Panel1->Caption="hello";
  Panel1->Caption="regtangle square = "+FloatToStr(square);

 break;

 case -1:

	Panel1->Caption="";

 break;

 case 1:
	 perimetr=rec.showPerimetr();
	 Panel1->Caption="regtangle perimetr = "+FloatToStr(perimetr);
 break;

 case 2:
	 //rec.showCenterMass();
	 Panel1->Caption="centers rectangle X = "+FloatToStr((X1+X2)/2)+" Y = "+FloatToStr((Y1+Y2)/2);
 break;
 }


 break;

case 1:
radius=sqrt(pow((Y2-Y1),2)+pow((X2-X1),2));
Image1->Canvas->Ellipse(X1-radius,Y1+radius,X1+radius,Y1-radius);
kr.get(X1,Y1,X2,Y2);

 switch (operation)
 {
   case 0:
   //fig=&rec;
   square=kr.showSquare();
   Panel1->Caption=FloatToStr(square);
   Panel1->Caption="Circus square = "+FloatToStr(square);
   break;

  case -1:
  Panel1->Caption="";
  break;

	 case(1):
	 perimetr=kr.showPerimetr();
	 Panel1->Caption="circus perimetr = "+FloatToStr(perimetr);
	 break;

	 case 2:
	 //rec.showCenterMass();
	 Panel1->Caption="centers circus X = "+FloatToStr(X1)+" Y = "+FloatToStr(Y1);
	 break;
 }

break;

}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
activationNumber=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
activationNumber=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
operation=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
operation=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
operation=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
operation=2;
}
//---------------------------------------------------------------------------


