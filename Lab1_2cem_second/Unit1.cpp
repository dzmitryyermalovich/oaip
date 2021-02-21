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
int X1;
int Y1;
int X2;
int Y2;
int activationNumber;
int operation;
double radius;
double square;
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

 switch (operation) {

 case 0:
 x=abs(X1-X2);
 y=abs(Y1-Y2);
 rec.get(x,y);
 //fig=&rec;
 square=rec.showSquare();
 //Panel1->Caption="hello";
 Panel1->Caption="regtangle square = "+FloatToStr(square);
 break;

 }


 break;

case 1:
radius=sqrt(pow((Y2-Y1),2)+pow((X2-X1),2));
Image1->Canvas->Ellipse(X1-radius,Y1+radius,X1+radius,Y1-radius);

 switch (operation)
 {
 case 0:

 kr.get(radius);
 //fig=&rec;
 square=kr.showSquare();
 Panel1->Caption=FloatToStr(square);
 Panel1->Caption="Circus square = "+FloatToStr(square);
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

