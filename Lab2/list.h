//---------------------------------------------------------------------------

#ifndef listH
#define listH
//---------------------------------------------------------------------------
#endif

#include<String.h>
#include<String>
#include <vcl.h>


#include "Unit1.h"

#include<String.h>
#include<String>


 class worker
 {
 private:
 String name,project,exercise,dataPr,dataBegin,dataEnd;

 void processArr(int *time,worker *arr,int size,TMemo *Memo1)
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
			//Memo1->Lines->Add(StrToInt(subStr));
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

 public:

	void get(String name,String project,String exercise,String dataPr,String dataBegin,String dataEnd)
	{

	  this->name=name;
	  this->project=project;
	  this->exercise=exercise;
	  this->dataPr=dataPr;
	  this->dataBegin=dataBegin;
	  this->dataEnd=dataEnd;

	}

	void print(TMemo *Memo1)
	{
	Memo1->Lines->Add(name+"  "+project+"  "+exercise+"  "+dataPr+"  "+dataBegin+"  "+dataEnd+"\n");
	Memo1->Lines->Add("\n");
	}

	void operator=(const worker& p)
	{
	   this->name=p.name;
	   this->project=p.project;
	   this->exercise=p.exercise;
	   this->dataPr=p.dataPr;
	   this->dataBegin=p.dataBegin;
	   this->dataEnd=p.dataEnd;
	}

	 //friend void delet(int n,worker *&arr,int &size);

	 void delet(int n,worker *&arr,int &size)
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
		 delete []arr;
		 arr=newArr;
	}

	void sort(worker *arr,int &size,TMemo *Memo1)
	{

	worker* newArr=new worker[size];
	int *time=new int[size];

	int index=0;

		   for(int i=0;i<size;i++)
		 {
				newArr[i].operator=(arr[i]);
		 }

		 processArr(time,arr,size,Memo1);
		 //Memo1->Lines->Add(time[0]);
		 //Memo1->Lines->Add(time[1]);
		 //Memo1->Lines->Add(time[2]);
		 worker temp;
		 int buf;
		for(int i=0;i<size-1;i++)
		{
		  for(int j=0;j<size-i-1;j++)
		  {
			 if(time[j]>time[j+1])
			 {

				  temp.operator=(newArr[j]);
				  newArr[j].operator=(newArr[j+1]);
				  newArr[j+1].operator=(temp);

				  buf=time[j];
				  time[j]=time[j+1];
				  time[j+1]=buf;
			 }
		  }
		}

	  for(int i=0;i<size;i++)
	  {

	  newArr[i].print(Memo1);

	  }

	}



 };
  /*
 void delet(int n,worker *&arr,int &size)
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
		 delete []arr;
		 arr=newArr;
	}
	*/
