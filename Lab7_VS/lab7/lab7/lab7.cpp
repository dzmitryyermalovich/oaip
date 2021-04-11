#include <iostream>
#include <math.h>
#include<time.h>
using namespace std;
//template<typename T>

class Node {
public:
	int data;
	Node* head;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}

	void push(int data) {
		Node* currant = head;
		if (currant == nullptr) {
			Node* newNode = new Node(data);
			//cout << newNode->data << endl;
			head = newNode;
		}
		else {
			while (currant->next!=nullptr) {
				currant = currant->next;
			}
			Node* newNode = new Node(data);
			currant->next = newNode;
		}
	}

	void print() {
		Node* currant = head;
		if (currant != nullptr) {
			while (currant->next != nullptr) {
				cout << currant->data << "\t";
				currant = currant->next;
			}
			cout << currant->data;
		}
		cout << endl;
	}

	Node() {
		head == nullptr;
		data = 0;
	}
};

int h(int key, int sizeOfHashTable) {
	return key % sizeOfHashTable;
}

int main()
{
	srand(time(NULL));
	int num;
	int sizeOfHashTable=10, numbersOfElementsInArray=10;
	//Node<int>** hashTable = new Node<int>* [sizeOfHashTable];
	Node** hashTable = new Node*[sizeOfHashTable]();

	int* arr = new int[numbersOfElementsInArray];

	for (int i = 0; i < sizeOfHashTable; i++) {
		hashTable[i] = new Node();
	}


	for (int i = 0; i < numbersOfElementsInArray; i++) {
		num = rand();
		arr[i] = num;
		cout << num << "\t";
	}
	cout << endl;
	int Hash;
	for (int i = 0; i < numbersOfElementsInArray; i++) {
		Hash = h(arr[i], numbersOfElementsInArray);
		Node* currant = hashTable[Hash];
		currant->push(arr[i]);
		//cout << hashTable[Hash]->data << endl;
	}

	for (int i = 0; i < sizeOfHashTable; i++) {
		Node* currant = hashTable[i];
		//cout << currant->head << endl;
		cout << i << " : ";
		currant->print();
	}
	//Node<int>* p = hashTable[1];
}