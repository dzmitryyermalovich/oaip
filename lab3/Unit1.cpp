//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include<math.h>
#include<String.h>
#include<String>
#include "List.h"
#include "Unit2.h"
List list;
TForm1 *Form1;
String name;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
ComboBox2->ItemIndex=ComboBox1->ItemIndex;
ComboBox3->ItemIndex=ComboBox1->ItemIndex;
ComboBox4->ItemIndex=ComboBox1->ItemIndex;
ComboBox5->ItemIndex=ComboBox1->ItemIndex;
ComboBox6->ItemIndex=ComboBox1->ItemIndex;
ComboBox7->ItemIndex=ComboBox1->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
try

{
int metka=list.set(Memo1->Lines->Strings[0],Memo1->Lines->Strings[1],Memo1->Lines->Strings[2],Memo1->Lines->Strings[3],Memo1->Lines->Strings[4],Memo1->Lines->Strings[5],Memo1->Lines->Strings[6],Memo1);

if(metka==1)
{
ComboBox1->Items->Add(Memo1->Lines->Strings[0]);
ComboBox6->Items->Add(Memo1->Lines->Strings[1]);
ComboBox7->Items->Add(Memo1->Lines->Strings[2]);
ComboBox2->Items->Add(Memo1->Lines->Strings[3]);
ComboBox3->Items->Add(Memo1->Lines->Strings[4]);
ComboBox4->Items->Add(Memo1->Lines->Strings[5]);
ComboBox5->Items->Add(Memo1->Lines->Strings[6]);
list.pushback(Memo1->Lines->Strings[0],Memo1->Lines->Strings[1],Memo1->Lines->Strings[2],Memo1->Lines->Strings[3],Memo1->Lines->Strings[4],Memo1->Lines->Strings[5],Memo1->Lines->Strings[6]);
Memo1->Clear();
}

}
catch(negAgeEx ex)
{
   int a=ex.get();
   ShowMessage("Error typed age <0 "+a);
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
list.printList(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
switch(RadioGroup1->ItemIndex)
{

case 0:
Memo1->Clear();
name=Edit1->Text;
list.findPlayer(name,Memo1);
Edit1->Clear();
break;

case 1:
Memo1->Clear();
list.delet(Edit1->Text);
Edit1->Clear();
break;

case 2:
//String weight;
Memo1->Clear();
//weight=Edit1->Text;
list.findWeight(Edit1->Text,Memo1);
Edit1->Clear();
break;

case 3:
Memo1->Clear();
list.findYoungerThen(Memo1,StrToInt(Edit1->Text));
Edit1->Clear();
break;

}


}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
  // Edit1->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
list.sort();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{

if(FileOpenDialog1->Execute()){

TStringList *List=new TStringList;
List->LoadFromFile(FileOpenDialog1->FileName);

AnsiString s;
int begin=1;
AnsiString newStr="";
AnsiString processStr="";
int nomer=0;
String str[10];
int index=0;

for(int i=0;i<11;i++)
{
  s=List->Strings[i];
  s=s+" sd";
  for(int j=1;j<s.Length();j++)
  {

	  if (s[j] == ' ')
		{
			for (int k = begin; k < j; k++)
			{
				newStr = newStr + s[k];
			}

		  if(nomer<3)
		 {
			for(int i=1;i<newStr.Length()+1;i++)
			   {
				  if(newStr[i]!='.')
					{
					  processStr=processStr+newStr[i];
					}
					else
					{
					 processStr=processStr+" ";
					}
			   }
			   str[nomer]=processStr;
		 }
		 else
		 {
		 str[nomer]=newStr;
		 }


			switch (nomer)
			{
			case 0:
			ComboBox1->Items->Add(processStr);

			break;

			case 1:

			ComboBox2->Items->Add(processStr);

			break;

			case 2:
			ComboBox3->Items->Add(processStr);
			 break;
			case 3:
			ComboBox4->Items->Add(newStr);
			 break;
			case 4:
			ComboBox5->Items->Add(newStr);
			 break;
			case 5:
			ComboBox6->Items->Add(newStr);
			break;
			case 6:
			ComboBox7->Items->Add(newStr);
			break;
			}

			nomer++;
			newStr = "";
			processStr="";
			begin = j + 1;

		}

  }
	 list.pushback(str[0],str[1],str[2],str[3],str[4],str[5],str[6]);

	 nomer=0;
	 begin=1;
}
delete List;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
list.findYounger(Memo1);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ClearClick(TObject *Sender)
{
Memo1->Lines->Clear();

}
//---------------------------------------------------------------------------

