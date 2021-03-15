//---------------------------------------------------------------------------

#pragma hdrstop

#include "list.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include<String.h>
#include<String>
#include <vcl.h>
#include "Unit1.h"
#include<math.h>

void worker::processArr(int *time,worker *arr,int size,TMemo *Memo1)
 {
	 AnsiString s,subStr="";
	 int alpha[3]={10,1000,1000000};
	 int iter=0;
	 int begin=1;
	 int index=0;

	 for(int i=0;i<size;i++)
	 {
		time[i]=0;
	 }


	for(int i=0;i<size;i++)
	  {
		 s=arr[i].dataEnd+".re";
		for(int j=1;j<s.Length();j++)
		 {
		   if(s[j]=='.')
		   {

			for(int k=begin;k<j;k++)
			{
			  subStr=subStr+s[k];
			}
			time[index]=time[index]+StrToInt(subStr)*alpha[iter];
			iter++;
			begin=j+1;
		   }
		   subStr="";
		 }

		 iter=0;
		 begin=1;
		 index++;

	  }
 }

   void worker::processData(int *time,worker *arr,int size,TMemo *Memo1)
  {

	 AnsiString start,end,subStrStart="",subStrEnd="";
	 int alpha[3]={1,30,365};
	 int iter=0;
	 int begin=1;
	 int index=0;
	 int workTime;
	 for(int i=0;i<size;i++)
	 {
		time[i]=0;
	 }

		for(int i=0;i<size;i++)
	  {
		 end=arr[i].dataEnd+".re";
		 start=arr[i].dataBegin+".re";

		for(int j=1;j<start.Length();j++)
		 {
		   if(start[j]=='.')
		   {

			for(int k=begin;k<j;k++)
			{
			  subStrStart=subStrStart+start[k];
			  subStrEnd=subStrEnd+end[k];
			}
			time[index]=time[index]+abs(StrToInt(subStrStart)-StrToInt(subStrEnd))*alpha[iter];
			iter++;
			begin=j+1;
		   }

		 subStrStart="";
		 subStrEnd="";
		 }
		 index++;
		 iter=0;
		 begin=1;


	  }
  }

	void worker::get(String name,String project,String exercise,String dataPr,String dataBegin,String dataEnd)
	{

	  this->name=name;
	  this->project=project;
	  this->exercise=exercise;
	  this->dataPr=dataPr;
	  this->dataBegin=dataBegin;
	  this->dataEnd=dataEnd;

	}

	void worker::print(TMemo *Memo1)
	{
	Memo1->Lines->Add(name+"  "+project+"  "+exercise+"  "+dataPr+"  "+dataBegin+"  "+dataEnd+"\n");
	Memo1->Lines->Add("\n");
	}

	String worker::distinguishStr()
	{
		String str;
		str=name+"  "+project+"  "+exercise+"  "+dataPr+"  "+dataBegin+"  "+dataEnd+"\n";
		return str;
	}

		 void worker::delet(int n,worker *&arr,int &size)
	{
		 worker* newArr=new worker[size-1];
		 int index=0;
		 for(int i=0;i<size;i++)
		 {
		   if(i!=n)
			{

			 newArr[index].operator=(arr[i]);
			 index++;
			}

		 }
		 size--;
		 delete []arr;
		 arr=newArr;
	}

	void worker::find(TMemo *Memo1,String data,worker *arr,int index,worker *dat,int &size)
	{
	size=0;
	int j=0;
	 for(int i=0;i<index;i++)
	 {
		if(data==arr[i].dataPr)
		{
		dat[j].operator=(arr[i]);
		arr[i].print(Memo1);
		j++;
		size++;
		}
	 }

	}

	void worker::calculate(TMemo *Memo1,worker *arr,int size,worker *tim,int &sizeTime)
	{
	  int *time=new int[size];
	  processData(time,arr,size,Memo1);
	  sizeTime=0;
	  for(int i=0;i<size;i++)
	  {
		Memo1->Lines->Add(arr[i].name+"  "+time[i]+" Days \n");
		tim[i].name=arr[i].name+"  "+time[i]+" Days \n";
		sizeTime++;
		Memo1->Lines->Add("\n");
	  }
		delete []time;
	}

	void worker::sort(worker *arr,int &size,TMemo *Memo1)
	{

	worker* newArr=new worker[size];
	int *time=new int[size];

	int index=0;

		   for(int i=0;i<size;i++)
		 {
				newArr[i].operator=(arr[i]);
		 }

		 processArr(time,arr,size,Memo1);
		 worker temp;
		 int buf;
		for(int i=0;i<size-1;i++)
		{
		  for(int j=0;j<size-i-1;j++)
		  {
			 if(time[j]>time[j+1])
			 {

				  temp.operator=(arr[j]);
				  arr[j].operator=(arr[j+1]);
				  arr[j+1].operator=(temp);

				  buf=time[j];
				  time[j]=time[j+1];
				  time[j+1]=buf;
			 }
		  }
		}

	  for(int i=0;i<size;i++)
	  {

	  arr[i].print(Memo1);

	  }
	  delete[] newArr;
	  delete[] time;
	}


	String worker::returnTime()
	{

	AnsiString str;

	str=this->name;

	return str;

	}
