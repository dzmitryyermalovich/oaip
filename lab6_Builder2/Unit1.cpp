//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include<Vcl.h>
#include "Tree.h"
#include<String.h>
TForm1 *Form1;
int deep=0;
binaryNode *root=new binaryNode();
FindDaughter arr;
binaryNode *NewElement;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
StringGrid1->Cells[1][0]=80;
StringGrid1->Cells[1][1]=49;
StringGrid1->Cells[1][2]=57;

StringGrid1->Cells[1][3]=30;
StringGrid1->Cells[1][4]=45;

StringGrid1->Cells[1][5]=39;
StringGrid1->Cells[1][6]=91;
StringGrid1->Cells[1][7]=85;
StringGrid1->Cells[1][8]=100;
StringGrid1->Cells[1][9]=84;
StringGrid1->Cells[1][10]=35;
StringGrid1->Cells[1][11]=40;
//StringGrid1->Cells[1][11]=58;
StringGrid1->Cells[1][12]=55;

StringGrid1->Cells[0][0]="Dima";
StringGrid1->Cells[0][1]="Naruto";
StringGrid1->Cells[0][2]="Saske";

StringGrid1->Cells[0][3]="Itach";
StringGrid1->Cells[0][4]="Sakura";

StringGrid1->Cells[0][5]="Igor";
StringGrid1->Cells[0][6]="Egor";
StringGrid1->Cells[0][7]="Vasua";
StringGrid1->Cells[0][8]="Tima";
StringGrid1->Cells[0][9]="Ales";
StringGrid1->Cells[0][10]="Stas";
StringGrid1->Cells[0][11]="Geka";
StringGrid1->Cells[0][12]="Alex";


root->set(StrToInt(StringGrid1->Cells[1][0]),StringGrid1->Cells[0][0]);

for(int i=1;i<StringGrid1->RowCount;i++)
{
   binaryNode *buf=new binaryNode();
   buf->set(StrToInt(StringGrid1->Cells[1][i]),StringGrid1->Cells[0][i]);
   root->push(buf);
   root=root->makeBalance(root);
}

//TTreeNode *Node1=TreeView1->Items->Item[0];
//TreeView1->Items->AddChild(Node1,IntToStr(root->str));
TreeView1->Items->Item[0]->Text=IntToStr(root->str);
root->createTree(TreeView1,Memo1);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int n;
int n2,n3;
int index=StrToInt(Edit1->Text);
String name=Edit2->Text;
binaryNode *buf=new binaryNode(index,name);

for(int i=0;i<100;i++)
	{
			  if(StrToInt(TreeView1->Items->Item[i]->Text)==root->left_child->str)
				  {
				  n2=i;
				  break;
				  }
				  n2=0;
	}


	if(n2!=0)
	{
	 TreeView1->Items->Delete(TreeView1->Items->Item[n2]);
	}

	for(int i=0;i<100;i++)
	{
			  if(StrToInt(TreeView1->Items->Item[i]->Text)==root->right_child->str)
				  {
				  n3=i;
				  break;
				  }
			  n3=0;
	}
	if(n3!=0)
	{
	 TreeView1->Items->Delete(TreeView1->Items->Item[n3]);
	}

root->push(buf);
root=root->makeBalance(root);
TreeView1->Items->Item[0]->Text=IntToStr(root->str);
root->createTree(TreeView1,Memo1);

Edit1->Clear();
Edit2->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Memo1->Clear();
  switch(RadioGroup1->ItemIndex)
  {
  case 0:
	 root->TraversePreorder(Memo1);
	 break;
  case 1:
	 root->TraverseSim(Memo1);
	 break;
  case 2:
	 root->TraverseObrat(Memo1);
	 break;
  case 3:
	 root->TraverseWidth(Memo1);
	 break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
int n;
int n2,n3;
int index=StrToInt(Edit1->Text);
/*
NewElement=root->findElement(index,Memo1);

//root->remove(index,Memo1);

NewElement->calculateNumberOfElements(Memo1);
//Memo1->Lines->Add(NewElement->sizeOfSubStr);
//if(NewElement->sizeOfSubStr%2!=0)
//{
//  NewElement->sizeOfSubStr-=1;
//}
//NewElement->sizeOfSubStr/=2;
//Memo1->Lines->Add(NewElement->sizeOfSubStr);
for(int i=0;i<100;i++)
{
		  if(StrToInt(TreeView1->Items->Item[i]->Text)==StrToInt(Edit1->Text))
			  {
			  n=i;
			  break;
			  }
}

if(NewElement==nullptr)
{
TreeView1->Items->Delete (TreeView1->Items->Item[n]);
}
else
{
	 for(int i=0;i<100;i++)
	{
			  if(StrToInt(TreeView1->Items->Item[i]->Text)==NewElement->str)
				  {
				  n2=i;
				  break;
				  }
	}
	TreeView1->Items->Item[n]->Text=TreeView1->Items->Item[n2]->Text ;
	TreeView1->Items->Delete(TreeView1->Items->Item[n2]);
	//TreeView1->Items->Item[n2]->Text=TreeView1->Items->Item[n2+1]->Text ;
	//for(int i=n2;i<n2+NewElement->sizeOfSubStr;i++)
	//{
	//TreeView1->Items->Item[i]->Text=TreeView1->Items->Item[i+1]->Text ;
	//}

   //TreeView1->Items->Delete(TreeView1->Items->Item[n2+NewElement->sizeOfSubStr]);
}
*/
	 for(int i=0;i<100;i++)
	{
			  if(StrToInt(TreeView1->Items->Item[i]->Text)==root->left_child->str)
				  {
				  n2=i;
				  break;
				  }
				  n2=0;
	}


	if(n2!=0)
	{
	 TreeView1->Items->Delete(TreeView1->Items->Item[n2]);
	}

	for(int i=0;i<100;i++)
	{
			  if(StrToInt(TreeView1->Items->Item[i]->Text)==root->right_child->str)
				  {
				  n3=i;
				  break;
				  }
			  n3=0;
	}
	if(n3!=0)
	{
	 TreeView1->Items->Delete(TreeView1->Items->Item[n3]);
	}

root->remove(index,Memo1);
root=root->makeBalance(root);
TreeView1->Items->Item[0]->Text=IntToStr(root->str);
root->createTree(TreeView1,Memo1);
Edit1->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TreeView1Change(TObject *Sender, TTreeNode *Node)
{
int n = TreeView1->Selected->AbsoluteIndex;
Label2->Caption=n;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
Memo1->Clear();
binaryNode *buf=root->search(StrToInt(Edit1->Text));
Memo1->Lines->Add(buf->str);
Memo1->Lines->Add(buf->name);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 arr.calculateDaughter(Memo1,root);
}
//---------------------------------------------------------------------------

