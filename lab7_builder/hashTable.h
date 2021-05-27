//---------------------------------------------------------------------------

#ifndef hashTableH
#define hashTableH
//---------------------------------------------------------------------------
#endif
#include<String.h>
template<typename T1, typename T2>
class Node {
public:
	T1 key;
	T2 info;
	Node* head;
	Node* top;
	Node* pNext;
	Node* pPrev;

	Node(T1 key, T2 info,Node* pPrev) {
		this->key = key;
		this->info = info;
		this->pNext = nullptr;
		this->pPrev = pPrev;
	}

	void push(T1 keyInput, T2 infoInput) {
		if (this->head == NULL) {
			Node<T1,T2>* newNode = new Node<T1, T2>(keyInput, infoInput,top);
			top = newNode;
			head = newNode;
		}
		else {
			Node<T1, T2>* newNode = new Node<T1, T2>(keyInput, infoInput, top);
			top->pNext = newNode;
			top = newNode;
		}
	}
	Node() {
		top = NULL;
		head = NULL;
	}

	String print()
	{
		Node* currant = head;
		String str="";
		if (currant != NULL) {
			while (currant->pNext != NULL) {
				str+= IntToStr(currant->key)+" ";
				currant = currant->pNext;
			}
			str+= IntToStr(currant->key)+" ";
		}
		return str;
	}


};

int h1(int key, int sizeOfHashTable) {
	return (key % sizeOfHashTable);
}

int h2(int key, int sizeOfHashTable) {
	return (1+key % (sizeOfHashTable-2));
}

template<typename T1, typename T2>
Node<T1, T2>* findNode(Node<T1, T2>** hashTable, T1 keyInput, int sizeOfHashTable) {
	int hash = h1(keyInput, sizeOfHashTable);
	Node<T1, T2>* currant = hashTable[hash];
	Node<T1, T2>* head = currant->head;
	while (head->pNext !=NULL)
	{
		if (head->key == keyInput) {
			return head;
		}
		head = head->pNext;
	}
	if (head->key == keyInput) {
		return head;
	}
	return NULL;
}

template<typename T1, typename T2>
Node<T1, T2>* findNodeDouble(Node<T1, T2>** hashTable, T1 keyInt, int sizeOfHashTable) {

	int buf1, buf2,buf3;
	int c = 0;
	if (keyInt<0) {
	}
	else {
		while (true)
		{
			buf1 = h1(keyInt, sizeOfHashTable);
			buf2 = h2(keyInt, sizeOfHashTable);
			buf3 = (buf1 + c * buf2)%sizeOfHashTable;
			if(hashTable[buf3]->head!=NULL)
			{
				int a=hashTable[buf3]->head->key;
				if(a==keyInt){
					return  hashTable[buf3];
				}
			}
			c++;
			if (c > 100000) {
			return NULL;
			}
		}
	}
	return NULL;

}

template<typename T1, typename T2>
int deleteNode(Node<T1, T2>** hashTable, T1 keyInput, int sizeOfHashTable) {
	Node<T1, T2>* deleteNode=findNode(hashTable, keyInput, sizeOfHashTable);
	int hash = h1(keyInput, sizeOfHashTable);
	Node<T1, T2>* currant = hashTable[hash];
	if (deleteNode != NULL) {
		if (deleteNode->pNext == NULL) {
			if (currant->head == deleteNode) {
				currant->head = NULL;
				return 1;
			}
			else {
				Node<T1, T2>* buf = deleteNode->pPrev;
				buf->pNext = NULL;
				return 1;
			}
		}
		else {
			if (currant->head == deleteNode) {
				currant->head = deleteNode->pNext;
				deleteNode->pNext->pPrev = currant->head;
				return 1;
			}
			else {
				Node<T1, T2>* buf = deleteNode->pPrev;
				deleteNode->pNext->pPrev = buf;
				buf->pNext = deleteNode->pNext;
				return 1;
			}
		}
	}
	return 0;
}

template<typename T1, typename T2>
void individExercise(Node<T1, T2>** hashTable, int sizeOfHashTable,int* arr,int numbersOfElementsInArray,TMemo *Memo2) {
	int buf = 0;
	int* keysDecrease = new int[numbersOfElementsInArray];
	for (int i = 0; i < numbersOfElementsInArray; i++) {
		keysDecrease[i] = arr[i];
	}

	for (int i = 0; i < numbersOfElementsInArray; i++) {
		for (int j = 0; j < numbersOfElementsInArray - i-1; j++) {
			if (keysDecrease[j] < keysDecrease[j + 1]) {
				buf = keysDecrease[j];
				keysDecrease[j] = keysDecrease[j + 1];
				keysDecrease[j + 1] = buf;
			}
		}
}
		Node<T1, T2>* currant;
		String str="";
		Memo2->Lines->Add("Key  Info");
		for (int i = 0; i < numbersOfElementsInArray; i++) {
			currant=findNode(hashTable, keysDecrease[i], sizeOfHashTable);
			str+=IntToStr(keysDecrease[i])+"  "+IntToStr(currant->info);
			Memo2->Lines->Add(str);
			str="";
		}
}

int h(int keyInt, int sizeOfHashTable,int* idx) {
	int buf1, buf2,buf3;
	int c = 0;
	if (keyInt<0) {
	}
	else {
		while (true)
		{
			buf1 = h1(keyInt, sizeOfHashTable);
			buf2 = h2(keyInt, sizeOfHashTable);
			buf3 = (buf1 + c * buf2)%sizeOfHashTable;
			if(idx[buf3]!=1){
				break;
			}
			c++;
			if (c > 100000) {
			return -1;
			}
		}
		idx[buf3]++;
		return buf3;
	}
}

template<typename T1, typename T2>
int deleteNodeDouble(Node<T1, T2>** hashTable, T1 keyInput, int sizeOfHashTable,int* idx) {
	Node<T1, T2>* deleteNode=findNodeDouble(hashTable, keyInput, sizeOfHashTable);
	for(int i=0;i<sizeOfHashTable;i++)
	{
	   if(hashTable[i]==deleteNode)
	   {
		 idx[i]=0;
		 hashTable[i]->head=NULL;
		 return 1;
	   }
	}
	return 0;
}

template<typename T1, typename T2>
void individExerciseDouble(Node<T1, T2>** hashTable, int sizeOfHashTable,int* arr,int numbersOfElementsInArray,TMemo *Memo2) {
	int buf = 0;
	int* keysDecrease = new int[numbersOfElementsInArray];
	for (int i = 0; i < numbersOfElementsInArray; i++) {
		keysDecrease[i] = arr[i];
	}

	for (int i = 0; i < numbersOfElementsInArray; i++) {
		for (int j = 0; j < numbersOfElementsInArray - i-1; j++) {
			if (keysDecrease[j] < keysDecrease[j + 1]) {
				buf = keysDecrease[j];
				keysDecrease[j] = keysDecrease[j + 1];
				keysDecrease[j + 1] = buf;
			}
		}
}
		Node<T1, T2>* currant;
		String str="";
		Memo2->Lines->Add("Key  Info");
		for (int i = 0; i < numbersOfElementsInArray; i++) {
			currant=findNodeDouble(hashTable, keysDecrease[i], sizeOfHashTable);
			str+=IntToStr(keysDecrease[i])+"  "+IntToStr(currant->head->info);
			Memo2->Lines->Add(str);
			str="";
		}
}
