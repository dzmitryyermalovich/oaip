//---------------------------------------------------------------------------

#ifndef Lab5H
#define Lab5H
//---------------------------------------------------------------------------
#endif
#include<vcl.h>
class EmptyList
{
public:
	EmptyList()
	{
		ShowMessage("Your list is empty");
	}
};

template<typename T>
	class Node
	{
	public:
		T number;
		Node* pNext;
		Node* pPrev;
		Node(T number, Node* pPrev, Node* pNext = nullptr)
		{
			this->number = number;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

template<typename T>
class Queue
{
protected:

public:
   	int size;
	Node<T>* head;
	Node<T>* top;

	Queue()
	{
	head = nullptr;
	size = 0;
	top = nullptr;
	}

	void pushBack(T number)
	{
		if (head == nullptr)
		{
			Node<T>* currant = new Node<T>(number, nullptr);
			head = currant;
			top = currant;
			size++;
		}
		else
		{
			top->pNext = new Node<T>(number, top);
			top = top->pNext;
			size++;
		}
	}

	void pop(TListBox *ListBox1)
	{
		size--;
		if (size == -1) throw EmptyList();
		if (size != 0)
		{
		ListBox1->Items->Add(head->number);
			head = head->pNext;
			head->pPrev = nullptr;
		}
		else
		{
			ListBox1->Items->Add(head->number);
			head = nullptr;
			top = nullptr;
		}
	}

	void printFront(TListBox *ListBox1)
	{
	Node<T> *currant=head;
	while(currant->pNext!=0)
	{
		ListBox1->Items->Add(currant->number);
		currant = currant->pNext;
	}
	 ListBox1->Items->Add(currant->number);
	}

	void popReadTop(TListBox *ListBox1)
	{
	ListBox1->Items->Add(top->number);
	}

	void popReadHead(TListBox *ListBox1)
	{
	ListBox1->Items->Add(head->number);
	}
};

template<typename T>
class DoubleList:public Queue<T>
{
	private:
	Node<T>* maxLink;
	Node<T>* minLink;
	int maxIndex,minIndex;

	public:
	void findMaxMin()
	{
		T max = 0;
		T min = this->head->number;
		Node<T>* currant = this->head;
			minLink = currant;
			maxLink = currant;
		for(int i=0;i<(this->size)-1;i++)
		{
			if (max < currant->number)
			{
				max = currant->number;
				maxLink = currant;
				maxIndex = i;
			}
			if(min>currant->number)
			{
				min = currant->number;
				minLink = currant;
				minIndex= i;
			}
			currant = currant->pNext;
		}
	}

	void insertList(DoubleList list2)
		{
			Node<T>* buf;
			this->findMaxMin();

			if(maxIndex<minIndex)
			{
				buf = maxLink;
				maxLink = minLink;
				minLink = buf;
			}

			minLink->pNext = list2.head;
			list2.head->pPrev = minLink;

			maxLink->pPrev = list2.top;
			list2.top->pNext = maxLink;

		}

	void pushBackBetween(int n,T num)
		{
			if(this->size==n)
			{
			 this->pushBack(num);
			}
			else if (n==0)
			{
			Node<T>* ob = new Node<T>(num, nullptr);
			ob->pNext = this->head;
			this->head->pPrev = ob;
			this->head = ob;
			}
			else
			{
			Node<T>* currant =this->head;
			Node<T>* buf;
			for (int i = 0; i < n-1; i++)
			{
				currant = currant->pNext;
			}
			buf = currant->pNext;
			Node<T>* ob = new Node<T>(num, currant);
			ob->pNext = buf;
			currant->pNext = ob;
			buf->pPrev= ob;
			(this->size)++;
			}
		}

		void deleteBetween(int n,TListBox *ListBox1)
			{
				if(this->size==n)
				{
				  Node<T>* currant =this->top->pPrev;
				  currant->pNext=nullptr;
				  (this->size)--;
				}
				else if(n==1){
				   this->pop(ListBox1);
				}
				else{
				n--;
				Node<T>* currant =this->head;
				for (int i = 0; i < n; i++)
				{
					currant = currant->pNext;
				}
				Node<T>*buf = currant->pPrev;
				buf->pNext = currant->pNext;
				currant->pNext->pPrev = buf;
				(this->size)--;
				}
			}
};
