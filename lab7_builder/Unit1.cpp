//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "hashTable.h"
#include<String.h>
#include<time.h>
int counterDouble=0;
int counter=0;
int sizeOfHashTable;
int numbersOfElemeontsInArray;
Node<int, int>** hashTable = new Node<int, int>*[100];
int* keys = new int[100];
int* info = new int[100];


int sizeOfHashTableDouble;
int numbersOfElemeontsInArrayDouble;
Node<int, int>** hashTableDouble = new Node<int, int>*[100];
int* keysDouble = new int[100];
int* infoDouble = new int[100];
int* idx = new int[100];

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	if(RadioGroup1->ItemIndex==0)
	{
	numbersOfElemeontsInArray=StrToInt(Edit1->Text);
	sizeOfHashTable=StrToInt(Edit2->Text);
		for (int i = 0; i < sizeOfHashTable; i++)
		{
			hashTable[i] = new Node<int, int>();
		}
			int num;
			randomize();
			for (int i = 0; i < numbersOfElemeontsInArray; i++)
			{
				num = (random(30000))+10;
				keys[i] = num;
				num = random(60);
				info[i] = num;
			}
		int Hash;
		for (int i = 0; i < numbersOfElemeontsInArray; i++) {
			Hash = h1(keys[i], sizeOfHashTable);
			hashTable[Hash]->push(keys[i],info[i]);
		}
	}
	else if(RadioGroup1->ItemIndex==1)
	{
	numbersOfElemeontsInArrayDouble=StrToInt(Edit1->Text);
	sizeOfHashTableDouble=StrToInt(Edit2->Text);
	randomize();
	if(numbersOfElemeontsInArrayDouble>sizeOfHashTableDouble)
	{
	numbersOfElemeontsInArrayDouble=sizeOfHashTableDouble;
	}
		for (int i = 0; i < sizeOfHashTableDouble; i++) {
			idx[i] = 0;
		}

		for (int i = 0; i < sizeOfHashTableDouble; i++) {
			hashTableDouble[i] = new Node<int, int>();
		}

		int num;
		for (int i = 0; i < numbersOfElemeontsInArrayDouble; i++) {
				num = (random(30000)+10);
				keysDouble[i] = num;
				num = random(60);
				infoDouble[i] = num;
		}

		int hash;

		for (int i = 0; i < numbersOfElemeontsInArrayDouble; i++) {

		while (true)
		{
			hash = h(keysDouble[i], sizeOfHashTableDouble, idx);
			if (hash == -1) {
				keysDouble[i] = random(30000);
			}
			else {
				break;
			}
		}

		if (hash != -1) {
			Node<int, int>* currant = hashTableDouble[hash];
			currant->push(keysDouble[i], infoDouble[i]);
			counter++;
			if(counter==sizeOfHashTableDouble)
			{
			break;
			}
		}
		else {
			//break;
		}

	}


	}
	Edit1->Clear();
	Edit2->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
String str1="";
String str2="";
if(RadioGroup1->ItemIndex==0){
	 switch(RadioGroup2->ItemIndex)
	{

	case 0:
	  Memo2->Lines->Clear();
	  if(Edit3->Text!="")
	  {
	  Node<int,int>* res=findNode(hashTable,StrToInt(Edit3->Text),sizeOfHashTable);
	  String str="";
		if (res != NULL) {
			Memo2->Lines->Clear();
			str+=IntToStr(res->key)+" "+IntToStr(res->info);
			Memo2->Lines->Add(str);
		}
		else {
			Memo2->Lines->Clear();
			Memo2->Lines->Add("NotFind");
		}
		Edit3->Clear();
	  }

	  break;
	case 1:
		 int cheak;
		 if(Edit3->Text!="")
		 {
			cheak=deleteNode(hashTable,StrToInt(Edit3->Text),sizeOfHashTable);
			if(cheak==0)
			{
			Memo2->Lines->Add("Can't find node");
			}else
			{
				int buf4;
				for(int i=0;i<numbersOfElemeontsInArray-1;i++)
				{
				   if(keys[i]==StrToInt(Edit3->Text))
				   {
				   buf4=keys[i];
				   keys[i]=keys[i+1];
				   keys[i+1]=buf4;
				   }
				}
				numbersOfElemeontsInArray--;
			}
		 }
		 Edit3->Clear();
	  break;
	case 2:
				Memo1->Lines->Clear();
				for (int i = 0; i < sizeOfHashTable; i++) {
				   Node<int, int>* currant = hashTable[i];
				   str1=IntToStr(i)+" : ";
				   str2=currant->print();
				   str1+=str2;
				   Memo1->Lines->Add(str1);
				}
	  break;
	case 3:
	  Memo2->Lines->Clear();
	  Memo2->Lines->Add(h1(StrToInt(Edit3->Text),sizeOfHashTable));
	  Edit3->Clear();
	  break;
	case 4:
	  Memo2->Lines->Clear();
	  for(int i=0;i<numbersOfElemeontsInArray;i++)
	  {
		Memo2->Lines->Add(keys[i]);
	  }
	  break;

	case 5:
	individExercise(hashTable,sizeOfHashTable,keys,numbersOfElemeontsInArray,Memo2);
	break;
	}
}else if(RadioGroup1->ItemIndex==1)
{
 switch(RadioGroup2->ItemIndex)
	{
	case 0:
	  Memo2->Lines->Clear();
	  if(Edit3->Text!="")
	  {
	  Node<int,int>* res=findNodeDouble(hashTableDouble,StrToInt(Edit3->Text),sizeOfHashTableDouble);
	  String str="";
		if (res != NULL) {
			Memo2->Lines->Clear();
			str+=IntToStr(res->head->key)+" "+IntToStr(res->head->info);
			Memo2->Lines->Add(str);
		}
		else {
			Memo2->Lines->Clear();
			Memo2->Lines->Add("NotFind");
		}
		Edit3->Clear();
	  }

	  break;
	case 1:
		 int cheak;
		 if(Edit3->Text!="")
		 {
			cheak=deleteNodeDouble(hashTableDouble,StrToInt(Edit3->Text),sizeOfHashTableDouble,idx);
			if(cheak==0)
			{
			Memo2->Lines->Add("Can't find node");
			}else
			{
				int buf4;
				for(int i=0;i<numbersOfElemeontsInArrayDouble;i++)
				{
				   if(keysDouble[i]==StrToInt(Edit3->Text))
				   {
				   buf4=keysDouble[i];
				   keysDouble[i]=keysDouble[i+1];
				   keysDouble[i+1]=buf4;
				   }
				}
				numbersOfElemeontsInArrayDouble--;
				counter--;
			}
		 }
		 Edit3->Clear();
	  break;
	case 2:
				Memo1->Lines->Clear();
				for (int i = 0; i < sizeOfHashTableDouble; i++) {
				   Node<int, int>* currant = hashTableDouble[i];
				   str1=IntToStr(i)+" : ";
				   str2=currant->print();
				   str1+=str2;
				   Memo1->Lines->Add(str1);
				}
	  break;
	case 3:
	 break;
	case 4:
	  Memo2->Lines->Clear();
	  for(int i=0;i<numbersOfElemeontsInArrayDouble;i++)
	  {
		Memo2->Lines->Add(keysDouble[i]);
	  }
	  break;

	case 5:
	individExerciseDouble(hashTableDouble,sizeOfHashTableDouble,keysDouble,numbersOfElemeontsInArrayDouble,Memo2);
	break;
	}
}

}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button3Click(TObject *Sender)
{
int Hash;
int control=0;
if(Edit3->Text!=""&Edit4->Text!="")
{
	int keyInput=StrToInt(Edit3->Text);
	int infoInput=StrToInt(Edit4->Text);
	if(keyInput>0)
	{
		 switch(RadioGroup1->ItemIndex)
		{
		case 0:

		   for(int i=0;i<numbersOfElemeontsInArray;i++)
		   {
			 if(keys[i]==keyInput)
			 {
			  Memo2->Lines->Add("Similar key");
			  control=1;
			 }
		   }

		   if(control==0)
		   {
			   Hash = h1(keyInput, sizeOfHashTable);
			   hashTable[Hash]->push(keyInput,infoInput);
			   keys[numbersOfElemeontsInArray]=keyInput;
			   info[numbersOfElemeontsInArray]=infoInput;
			   numbersOfElemeontsInArray++;
		   }
		   break;
		case 1:
				if(counter!=sizeOfHashTableDouble)
				{
							   for(int i=0;i<numbersOfElemeontsInArrayDouble;i++)
							   {
								 if(keysDouble[i]==keyInput)
								 {
								  Memo2->Lines->Add("Similar key");
								  control=1;
								 }
							   }
					if(control==0)
					{
						Hash = h(keyInput, sizeOfHashTableDouble, idx);
						if (Hash == -1) {
						Memo2->Lines->Add("Can't add this key");
						}else
						{
						Node<int, int>* currant = hashTableDouble[Hash];
						currant->push(keyInput, infoInput);
						counter++;
						keysDouble[numbersOfElemeontsInArrayDouble]=keyInput;
						infoDouble[numbersOfElemeontsInArrayDouble]=infoInput;
						numbersOfElemeontsInArrayDouble++;
						}
					}
				}
				else
				{
				 Memo2->Lines->Add("Hash table is full");
				}
		}
	}
	else
	{
	 Memo2->Lines->Add("Key<=0");
	}

	 Edit3->Clear();
	 Edit4->Clear();
}else
{
	 Memo2->Lines->Add("Incorrect input");
	 Edit3->Clear();
	 Edit4->Clear();
}

}
//---------------------------------------------------------------------------

