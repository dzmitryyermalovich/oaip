//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
//---------------------------------------------------------------------------
#endif
#include<math.h>
#include<String.h>
#include<String>

class negAgeEx
{
int a;
public:

	negAgeEx(int num,TMemo *Memo1)
	{
	this->a=num;
	Memo1->Lines->Add("asdsdas");
	}

	int get()
	{
	return a;
	}

};

class List
{
private:

String name;
String country,team,number,age,growth,weigth;
int size;
int numOfTeam;

class Node
{
public:
   Node *pNext;
   String name;
   String country,team,number,age,growth,weigth;

   Node(String name,String country,String team,String number,String age,String growth,String weigth,Node* pNext=nullptr)
	{
		  this->name=name;
		  this->country=country;
		  this->team=team;
		  this->number=number;
		  this->age=age;
		  this->growth=growth;
		  this->weigth=weigth;
		  this->pNext=pNext;
	}
	void operator=(const Node &p)
	{
		  this->name=p.name;
		  this->country=p.country;
		  this->team=p.team;
		  this->number=p.number;
		  this->age=p.age;
		  this->growth=p.growth;
		  this->weigth=p.weigth;
		  this->pNext=p.pNext;
	}
};
Node *head;
public:

List()
{
  head=nullptr;
  size=0;
}

int set(String name,String country,String team,String number,String age,String growth,String weigth,TMemo *Memo1)
{

	char buf;
	int kol=0;
	int metka=1;

	String str[4];
	String arr[3];

	arr[0]=name;
	arr[1]=country;
	arr[2]=team;

	str[0]= number;
	str[1]= age;
	str[2]= growth;
	str[3]= weigth;
	String unit;

   for(int j=0;j<3;j++)
   {
   unit=arr[j];
   for(int i=1;i<unit.Length()+1;i++)
   {
	buf=unit[i];
	if(((int)buf<65||(int)buf>90)&&((int)buf<97||(int)buf>122)&&(int)buf!=32)
	{
	   metka=0;
	   return metka;
	}
   }
   }

   for(int j=0;j<4;j++)
   {
   unit=str[j];
   for(int i=1;i<str[j].Length()+1;i++)
   {
	buf=unit[i];
	if((int)buf<48||(int)buf>57)
	{
	   metka=0;
	   return metka;
	}
   }
   }

   for(int j=0;j<4;j++)
   {
   if(StrToInt(str[j])<0) throw negAgeEx(StrToInt(str[j]),Memo1);
   }

   return 1;

}

void pushback(String name,String country,String team,String number,String age,String growth,String weigth)
{

 size++;

 if(head==nullptr)
 {
   head=new Node(name,country,team,number,age,growth,weigth);
 }
 else
 {

 Node*currant=head;

  while(currant->pNext!=nullptr)
  {
  currant=currant->pNext;
  }
  currant->pNext=new Node(name,country,team,number,age,growth,weigth);

 }

}

void printList(TMemo *Memo1)

{

Node *currant=head;

for(int i=0;i<size;i++)
 {
  Memo1->Lines->Add(currant->name+" "+currant->country+" "+currant->team+" "+currant->number+" "+currant->age+" "+currant->growth+" "+currant->weigth+"\n");
  currant=currant->pNext;
 }

}

void findPlayer(String str,TMemo *Memo1)
{

Node* currant=head;
for(int i=0;i<size;i++)
{

if(currant->name==str)
{
   Memo1->Lines->Add(currant->name+" "+currant->country+" "+currant->team+" "+currant->number+" "+currant->age+" "+currant->growth+" "+currant->weigth+"\n");
}
 currant=currant->pNext;
}

}

void delet(String str)
{

Node* currant=head;
Node* pNew=head;
Node* pPrevios=head;
int independent=0;
int i=0;

while(i<size)
{

if(currant->team==str)
{

	//currant=currant->pNext;
	if(i==0)
	{
	 head=currant->pNext;
	}
	else
	{
	//pNew->pNext=currant->pNext;
	pPrevios->pNext=currant->pNext;
	}

	i=-1;
	size--;
}
  if(i==-1)
  {
   currant=head;
   i++;
  }
  else
  {
   //pNew=currant;
   pPrevios=currant;
   currant=currant->pNext;
   i++;
  }

}

}

void findWeight(String str,TMemo *Memo1)
{

Node* currant=head;
for(int i=0;i<size;i++)
{

if(currant->weigth==str)
{
   Memo1->Lines->Add(currant->name+" "+currant->country+" "+currant->team+" "+currant->number+" "+currant->age+" "+currant->growth+" "+currant->weigth+"\n");
}
 currant=currant->pNext;
}

}

void sort()
{

	Node* currant = head;
	Node* pPrevious = head;
	Node* pNewNext = head;
	Node* buf1 = head;
	Node* buf2 = head;
	Node* buf3 = head;

	int independent=0;
	for (int i = 0; i < size; i++)
	{

		while (currant->pNext != nullptr)
		{

			//if (currant->age<currant->pNext->age)
			if (int((currant->country)[1]) > int((currant->pNext->country)[1]))
			{

				if (independent == 0)
				{
					buf1 = head;
					buf2 = head->pNext->pNext;
					head = currant->pNext;
					head->pNext = buf1;
					buf1->pNext = buf2;
				}
				else
				{
					buf3 = currant;
					buf1 = pPrevious->pNext;
					buf2 = currant->pNext->pNext;
					pPrevious->pNext = currant->pNext;
					pPrevious->pNext->pNext = buf1;
					buf3->pNext = buf2;
				}
				independent++;

			}
			else
			{
				pPrevious = currant;
				currant = currant->pNext;
				independent++;
			}

		}
		independent = 0;
		currant = head;
	}

}

void findYounger(TMemo *Memo1)
{

float *arr=new float [size];
for(int i=0;i<size;i++)
{
 arr[i]=0;
}

Node *currant=head;
int index=0;
int kol=1;

for(int i=0;i<size-1;i++)
{

if(currant->country==currant->pNext->country&&currant->pNext!=nullptr)
{
   arr[index]+=StrToFloat(currant->age);
   currant=currant->pNext;
   kol++;
}
else
{
if(currant->pNext!=nullptr)
{

arr[index]+=StrToFloat(currant->age);
arr[index]/=kol;
//Memo1->Lines->Add(arr[index]);
kol=1;
index++;
currant=currant->pNext;

}

//if(currant->pNext!=nullptr)
//{currant=currant->pNext;}
}


}


float min=arr[0];
int j=0;

for(int i=1;i<index;i++)
{

if(min>arr[i])
{
 min=arr[i];
 j=i;
}

}

Memo1->Lines->Add("Age is "+FloatToStr(min)+"\n");


currant=head;
index=0;
String str;
for(int i=0;i<size-1;i++)
{

if(currant->country==currant->pNext->country)
{
   currant=currant->pNext;
}
else
{

if(index==j)
{
  str=currant->team;
}

index++;
currant=currant->pNext;
}


}
  //Memo1->Clear();
  //Memo1->Lines->Add(min+"\n");
  //min=0;
  Memo1->Lines->Add("Team is "+str+"\n");
  currant=head;


for(int i=0;i<size;i++)
{
if(currant->team==str)
{
 Memo1->Lines->Add(currant->name+" "+currant->country+" "+currant->team+" "+currant->number+" "+currant->age+" "+currant->growth+" "+currant->weigth+"\n");
}
 currant=currant->pNext;
}


}


void findYoungerThen(TMemo *Memo1,int let)
{

int *arr=new int [size];
int *sizeOfSubStr=new int [size];
for(int i=0;i<size;i++)
{
 arr[i]=0;
}

Node *currant=head;
int index=0;
int kol=1;
int independent=0;
for(int i=0;i<size-1;i++)
{

if(currant->country==currant->pNext->country&&currant->pNext!=nullptr)
{
   if(StrToInt(currant->age)<let)
   {
	independent++;
   }
   //arr[index]+=StrToFloat(currant->age);
   currant=currant->pNext;
   kol++;
}
else
{
if(currant->pNext!=nullptr)
{
   if(StrToInt(currant->age)<let)
   {
	independent++;
   }

   if(independent==kol)
   {
	  arr[index]=1;
   }
   else
   {
   arr[index]=0;
   }
//arr[index]+=StrToFloat(currant->age);
//arr[index]/=kol;
//Memo1->Lines->Add(arr[index]);
kol=1;
independent=0;
index++;
currant=currant->pNext;

}

//if(currant->pNext!=nullptr)
//{currant=currant->pNext;}
}


}
 currant=head;
 index=0;
 int index2=0;
 String str[10];
for(int i=0;i<size-1;i++)
{

if(currant->country==currant->pNext->country&&currant->pNext!=nullptr)
{
   currant=currant->pNext;

}
else
{
if(currant->pNext!=nullptr)
{

 if(arr[index]==1)
 {
	 str[index2]=currant->team;
	 index2++;
 }

index++;
currant=currant->pNext;

}


}


}

currant=head;

for(int j=0;j<index2;j++)
{
  for(int i=0;i<size-1;i++)
  {
	if(currant->team==str[j])
	{
		 Memo1->Lines->Add(currant->name+" "+currant->country+" "+currant->team+" "+currant->number+" "+currant->age+" "+currant->growth+" "+currant->weigth+"\n");
	}
	currant=currant->pNext;
  }
}

}


};
