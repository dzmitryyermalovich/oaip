//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include<String.h>
#include<String>
#include<fstream>
#include "list.h"
int index=0;
worker a;
int size=0;
int sizeData=0;
worker* arr=new worker[10];
worker* tim=new worker[10];
worker* data=new worker[10];
String str[10];
TForm1 *Form1;
int nomerDelete;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

if(FileOpenDialog1->Execute()){

TStringList *List=new TStringList;
List->LoadFromFile(FileOpenDialog1->FileName);

AnsiString s;
int begin=1;
AnsiString newStr="";
AnsiString processStr="";
int nomer=0;



for(int i=0;i<3;i++)
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
			}

			nomer++;
			newStr = "";
			processStr="";
			begin = j + 1;

		}

  }
	 arr[index].get(str[0],str[1],str[2],str[3],str[4],str[5]);
	 index++;
	 nomer=0;
	 begin=1;
}
delete List;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
ComboBox2->ItemIndex=ComboBox1->ItemIndex;
ComboBox3->ItemIndex=ComboBox1->ItemIndex;
ComboBox4->ItemIndex=ComboBox1->ItemIndex;
ComboBox5->ItemIndex=ComboBox1->ItemIndex;
ComboBox6->ItemIndex=ComboBox1->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

ComboBox1->Items->Add(Memo1->Lines->Strings[0]);
ComboBox2->Items->Add(Memo1->Lines->Strings[1]);
ComboBox3->Items->Add(Memo1->Lines->Strings[2]);
ComboBox4->Items->Add(Memo1->Lines->Strings[3]);
ComboBox5->Items->Add(Memo1->Lines->Strings[4]);
ComboBox6->Items->Add(Memo1->Lines->Strings[5]);
arr[index].get(Memo1->Lines->Strings[0],Memo1->Lines->Strings[1],Memo1->Lines->Strings[2],Memo1->Lines->Strings[3],Memo1->Lines->Strings[4],Memo1->Lines->Strings[5]);
index++;
Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{

   a.delet(StrToInt(Edit1->Text),arr,index);
   ComboBox1->Items->Delete(StrToInt(Edit1->Text));
   ComboBox2->Items->Delete(StrToInt(Edit1->Text));
   ComboBox3->Items->Delete(StrToInt(Edit1->Text));
   ComboBox4->Items->Delete(StrToInt(Edit1->Text));
   ComboBox5->Items->Delete(StrToInt(Edit1->Text));
   ComboBox6->Items->Delete(StrToInt(Edit1->Text));
   Edit1->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{

for(int i=0;i<index;i++)
{
   arr[i].print(Memo1);
}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	AnsiString str="";

 if(FileSaveDialog1->Execute())
 {

   TFileStream *tfile=new TFileStream(FileSaveDialog1->FileName,fmOpenReadWrite);

   for(int i=0;i<index;i++)
   {
	 str=arr[i].distinguishStr();
	 tfile->Write(str.c_str(),str.Length());
   }
	 delete tfile;
 }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
a.sort(arr,index,Memo1);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button8Click(TObject *Sender)
{
a.find(Memo1,Edit2->Text,arr,index,data,sizeData);
Edit2->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button9Click(TObject *Sender)
{
a.calculate(Memo1,arr,index,tim,size);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
delete[]arr;
delete[]tim;
delete[]data;
Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button11Click(TObject *Sender)
{

if(FileSaveDialog1->Execute())
{
	TFileStream *fs=new TFileStream(FileSaveDialog1->FileName,fmOpenReadWrite);
	AnsiString str;
   for(int i=0;i<size;i++)
   {
	 str=tim[i].returnTime();
	 fs->Write(str.c_str(),str.Length());
   }
	 delete fs;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
if(FileSaveDialog1->Execute())
{

	TFileStream *fs=new TFileStream(FileSaveDialog1->FileName,fmOpenReadWrite);
	AnsiString str;
   for(int i=0;i<sizeData;i++)
   {
	 str=data[i].distinguishStr();
	 fs->Write(str.c_str(),str.Length());
   }
	 delete fs;

}
}
//---------------------------------------------------------------------------

