//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Lab5.h"
#include<time.h>
#include <stdlib.h>
Queue<float> queue;
DoubleList<float> list1;
DoubleList<float> lists[2];
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	switch(RadioGroup1->ItemIndex)
	{
		case 0:
			lists[RadioGroup2->ItemIndex].pushBack(StrToFloat(Edit1->Text));
			Edit1->Clear();
			break;
		case 1:
		ListBox1->Clear();
			try
			{
			 lists[RadioGroup2->ItemIndex].pop(ListBox1);
			}
			catch(EmptyList){}

			break;
		case 2:
			ListBox1->Clear();
			lists[RadioGroup2->ItemIndex].popReadHead(ListBox1);
			break;
		case 3:
			ListBox1->Clear();
			lists[RadioGroup2->ItemIndex].popReadTop(ListBox1);
			break;
		case 4:
			ListBox1->Clear();
			lists[RadioGroup2->ItemIndex].printFront(ListBox1);
			break;
		case 5:
		ListBox1->Clear();
		lists[0].insertList(lists[1]);
		lists[0].printFront(ListBox1);
		break;
		case 6:
		ListBox1->Clear();
		lists[RadioGroup2->ItemIndex].deleteBetween(StrToFloat(Edit2->Text),ListBox1);
		Edit1->Clear();
		Edit2->Clear();
		break;
		case 7:
		ListBox1->Clear();
		lists[RadioGroup2->ItemIndex].pushBackBetween(StrToInt(Edit2->Text),StrToFloat(Edit1->Text));
		Edit1->Clear();
		Edit2->Clear();
		break;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

	randomize();
	int buf;
	for(int i=0;i<5;i++)
	{
		 buf=random(20);
		 lists[0].pushBack(buf);
		 buf=random(20);
		 lists[1].pushBack(buf);
	}
	/*
	lists[0].pushBack(9);
	lists[0].pushBack(0);
	lists[0].pushBack(4);
	lists[0].pushBack(2.4);
	lists[0].pushBack(5);
	lists[0].pushBack(2);
	lists[0].pushBack(7.9);

	lists[1].pushBack(10);
	lists[1].pushBack(10);
	lists[1].pushBack(10);
	lists[1].pushBack(10);
	lists[1].pushBack(10);
	  */
	//list1.pushBack(6);

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{

switch(RadioGroup3->ItemIndex){

		case 0:
			queue.pushBack(StrToFloat(Edit3->Text));
			Edit3->Clear();
			break;
		case 1:
		ListBox1->Clear();
			try
			{
			 queue.pop(ListBox1);
			}
			catch(EmptyList){}
			break;
		case 2:
			ListBox1->Clear();
			queue.popReadHead(ListBox1);
			break;
		case 3:
			ListBox1->Clear();
			queue.popReadTop(ListBox1);
			break;
		case 4:
			ListBox1->Clear();
			queue.printFront(ListBox1);
			break;
}

}
//---------------------------------------------------------------------------

