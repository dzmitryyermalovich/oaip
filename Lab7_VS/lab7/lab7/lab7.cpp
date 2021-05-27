#include <iostream>
#include <math.h>
#include<time.h>
#include<string>
using namespace std;
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
		if (this->head == nullptr) {
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

	void print() {
		Node* currant = head;
		if (currant != nullptr) {
			while (currant->pNext != nullptr) {
				cout << currant->key << "\t";
				currant = currant->pNext;
			}
			cout << currant->key;
		}
		cout << endl;
	}

	Node() {
		head = nullptr;
		top = nullptr;
	}
};

int h2(int key, int sizeOfHashTable) {
	return (1+key % (sizeOfHashTable-2));
}

int h1(int key, int sizeOfHashTable) {
	return (key % sizeOfHashTable);
}

int h(string key, int sizeOfHashTable) {
	char buf1, buf2;
	if (key.length()==1) {
		buf1 = key[0];
		return (int)buf1 / sizeOfHashTable;
	}
	else {
		buf1 = key[0];
		buf2 = key[key.length()-1];
		return (((int)buf1 + (int)buf2) % sizeOfHashTable);
	}
}

int h2(string key, int sizeOfHashTable) {
	char buf1, buf2;
	if (key.length() == 1) {
		buf1 = key[0];
		return (((int)buf1+1) / (sizeOfHashTable-2));
	}
	else {
		buf1 = key[0];
		buf2 = key[key.length() - 1];
		return (((int)buf1 + (int)buf2+1) % (sizeOfHashTable-2));
	}
}

int h(string key, int sizeOfHashTable,int* idx) {
	char buf1, buf2,buf3;
	int c = 0;
	int keyInt = atoi(key.c_str());
	if (key.length() == 1) {
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
Node<T1, T2>* findNode(Node<T1, T2>** hashTable, T1 keyInput, int sizeOfHashTable) {
	int hash = h(keyInput, sizeOfHashTable);
	Node<T1, T2>* currant = hashTable[hash];
	Node<T1, T2>* head = currant->head;
	while (head->pNext !=nullptr)
	{
		if (head->key == keyInput) {
			return head;
		}
		head = head->pNext;
	}
	if (head->key == keyInput) {
		return head;
	}
	return nullptr;
}

template<typename T1, typename T2>
int deleteNode(Node<T1, T2>** hashTable, T1 keyInput, int sizeOfHashTable) {
	Node<T1, T2>* deleteNode=findNode(hashTable, keyInput, sizeOfHashTable);
	int hash = h(keyInput, sizeOfHashTable);
	Node<T1, T2>* currant = hashTable[hash];
	if (deleteNode != nullptr) {
		if (deleteNode->pNext == nullptr) {
			if (currant->head == deleteNode) {
				currant->head = nullptr;
				return 1;
			}
			else {
				Node<T1, T2>* buf = deleteNode->pPrev;
				buf->pNext = nullptr;
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
void individExercise(Node<T1, T2>** hashTable, int sizeOfHashTable,int* arr,int numbersOfElementsInArray) {
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
		cout << "\nKey\tInfo\n";
		for (int i = 0; i < numbersOfElementsInArray; i++) {
			currant=findNode(hashTable, to_string(keysDecrease[i]), sizeOfHashTable);
			cout << keysDecrease[i] <<"\t" <<currant->info << endl;
		}
}

int main()
{
	srand(time(0));
	int num;
	int sizeOfHashTable=10, numbersOfElementsInArray=10;

	Node<string, int>** hashTable = new Node<string, int>*[sizeOfHashTable];

	
	int* keys = new int[numbersOfElementsInArray];
	int* info = new int[numbersOfElementsInArray];
	int* idx = new int[sizeOfHashTable];

	for (int i = 0; i < sizeOfHashTable; i++) {
		idx[i] = 0;
	}

	for (int i = 0; i < sizeOfHashTable; i++) {
		hashTable[i] = new Node<string, int>();
	}

	for (int i = 0; i < numbersOfElementsInArray; i++) {
		num = rand();
		keys[i] = num;
		num = rand() % 60;
		info[i] = num;
	}
	int hash;

	for (int i = 0; i < numbersOfElementsInArray; i++) {

		while (true)
		{
			hash = h(to_string(keys[i]), sizeOfHashTable, idx);
			if (hash == -1) {
				keys[i] = rand();
			}
			else {
				break;
			}
		}

		if (hash != -1) {
			Node<string, int>* currant = hashTable[hash];
			currant->push(to_string(keys[i]), info[i]);
		}
		else {
			//break;
		}

		cout << hash << endl;
	}
	cout << endl;

	for (int i = 0; i < numbersOfElementsInArray; i++) {
		cout << keys[i] << "\t";
	}
	cout << "\n\n";
	for (int i = 0; i < sizeOfHashTable; i++) {
		Node<string, int>* currant = hashTable[i];
		cout << i << " : ";
		currant->print();
	}

	/*
	Node<string,int>** hashTable = new Node<string, int>*[sizeOfHashTable]();

	int* keys = new int[numbersOfElementsInArray];
	int* info = new int[numbersOfElementsInArray];

	for (int i = 0; i < sizeOfHashTable; i++) {
		hashTable[i] = new Node<string, int>();
	}


	for (int i = 0; i < numbersOfElementsInArray; i++) {
		num = rand();
		keys[i] = num;
		num = rand()%60;
		info[i] = num;
		cout << keys[i] << "\t";
	}
	cout << "\n";
	for (int i = 0; i < numbersOfElementsInArray; i++) {
		cout << info[i] << "\t";
	}
	cout << "\n\n";


	int Hash;
	for (int i = 0; i < numbersOfElementsInArray; i++) {
		Hash = h(to_string(keys[i]), sizeOfHashTable);
		Node<string, int>* currant = hashTable[Hash];
		currant->push(to_string(keys[i]),info[i]);
	}

	for (int i = 0; i < sizeOfHashTable; i++) {
		Node<string, int>* currant = hashTable[i];
		cout << i << " : ";
		currant->print();
	}


	//individExercise(hashTable, sizeOfHashTable, keys,numbersOfElementsInArray);
	//Ищем инфу по ключу
	/*
	cout << "\n";
	cout << "Enter key" << endl;
	int keyInput;
	cin >> keyInput;
	Node* res=findNode(hashTable, keyInput, sizeOfHashTable);
	if (res != nullptr) {
		cout << res->key << endl;
	}
	else {
		cout << "NotFind" << endl;
	}
	*/

	/*
	cout << "\n";
	cout << "Enter delete key" << endl;
	string keyInput;
	cin >> keyInput;
	deleteNode(hashTable, keyInput, sizeOfHashTable);

	cout << "\n\n";
	for (int i = 0; i < sizeOfHashTable; i++) {
		Node<string, int>* currant = hashTable[i];
		cout << i << " : ";
		currant->print();
	}
	*/
}