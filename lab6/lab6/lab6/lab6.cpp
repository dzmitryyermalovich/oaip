#include <iostream>
#include<math.h>
#include<string>
using namespace std;

class binaryNode {
public:
	binaryNode* left_child = nullptr;
	binaryNode* right_child = nullptr;
	binaryNode* pNext = nullptr;
	binaryNode* pPrev = nullptr;
	binaryNode(int str) {
		this->str = str;
	}
	void print() {
		cout << str << endl;
	}
	void TraversePreorder();
	void TraverseSim();
	void TraverseObrat();
	void TraverseWidth();
	void push(binaryNode* root, binaryNode *ob);
	void remove(int index);
	void calculateDaught();
	binaryNode* search(int index);
	binaryNode* searchPrev(int index,binaryNode *p);
	int defineNode(binaryNode* p);
	void removeList(binaryNode* currant, binaryNode* pred);
	int hightOfTree();
	int defineBalance();
	binaryNode* makeBalance(binaryNode* root);
	binaryNode* rightTern(binaryNode* root);
	binaryNode* leftTern(binaryNode* root);
	binaryNode* findMax();
	int str;
	int sizeOfSubStr = 0;
	void calculateNumberOfElements();

protected:
	
};

class queue {
public:

	void pushBack(binaryNode* object)
	{
		binaryNode* currant = head;
		if (currant == nullptr) {
			this->head= object;
			this->top= object;
		}
		else {
			this->top->pNext = object;
			object->pPrev = this->top;
			this->top = object;
		}
		size++;
	}

	void printFront() {
		binaryNode* currant = head;
		while (currant->pNext) {
			cout << currant->str << endl;
			currant = currant->pNext;
		}
		cout << currant->str << endl;
	}

	binaryNode* pop() {
		if (size == 1) {
			binaryNode* object = this->head;
			this->head = nullptr;
			this->top = nullptr;
			(this->size)--;
			return object;
		}
		else
		{
			binaryNode* object = this->head;
			this->head->pNext->pPrev = nullptr;
			this->head = this->head->pNext;
			(this->size)--;
			return object;
		}
	}

	queue() 
	{
		head = nullptr;
		top = nullptr;
		size = 0;
	}
	int size;
protected:
	binaryNode* head;
	binaryNode* top;

};

binaryNode* binaryNode::search(int index) {

	if (this->str == index) {
		return this;
	}

	if (this->str > index) {
		if (this->left_child) {
			return this->left_child->search(index);
		}
		else {
			return nullptr;
		}
	}

	if (this->str < index) {
		if (this->right_child) {
			return this->right_child->search(index);
		}
		else {
			return nullptr;
		}
	}
}

binaryNode* binaryNode::searchPrev(int index,binaryNode* Prev) {
	if (this->str == index) {
		return Prev;
	}

	if (this->str > index) {
		if (this->left_child) {
			return this->left_child->searchPrev(index, this);
		}
		else {
			return nullptr;
		}
	}

	if (this->str < index) {
		if (this->right_child) {
			return this->right_child->searchPrev(index, this);
		}
		else {
			return nullptr;
		}
	}
}

int binaryNode::defineNode(binaryNode* p) {
	if (p->left_child || p->right_child) {
		return 1;
	}
	else {
		return 0;
	}
}

void binaryNode::removeList(binaryNode* currant, binaryNode* pred) {
	if (pred->left_child == currant) {
		pred->left_child = nullptr;
}
	else if (pred->right_child == currant) {
		pred->right_child = nullptr;
	}
}

binaryNode* binaryNode::findMax() {
	if (this->right_child) {
		this->right_child->findMax();
	}
	else { return this; }
}

void binaryNode::remove(int index) {
	int def;
	binaryNode* currant;
	binaryNode* pred = this;
	currant=this->search(index);
	pred = this->searchPrev(index, pred);
	def=this->defineNode(currant);
	binaryNode* currantMaxElementInSubTree;
	binaryNode* predtMaxElementInSubTree;

	if (def == 0) {
		this->removeList(currant, pred);
	}
	else if (def == 1) {
		if (currant->left_child != nullptr) {
			currantMaxElementInSubTree = currant->left_child->findMax();
		}
		else {
			currantMaxElementInSubTree = currant->right_child->findMax();
		}
		predtMaxElementInSubTree = currantMaxElementInSubTree;
		predtMaxElementInSubTree = this->searchPrev(currantMaxElementInSubTree->str, predtMaxElementInSubTree);
        
		if (currant != predtMaxElementInSubTree) {
			if (pred->left_child == currant) {
				pred->left_child = currantMaxElementInSubTree;
			}
			else if (pred->right_child == currant) {
				pred->right_child = currantMaxElementInSubTree;
			}

			if (currant->left_child) {
				predtMaxElementInSubTree->right_child = currantMaxElementInSubTree->left_child;
				currantMaxElementInSubTree->left_child = currant->left_child;
				currantMaxElementInSubTree->right_child = currant->right_child;
			}
			else {
				currantMaxElementInSubTree->right_child = currant->right_child;
				predtMaxElementInSubTree->left_child = NULL;
			}

		}
		else {
			if (pred->left_child == currant) {
				pred->left_child = currantMaxElementInSubTree;
			}
			else if (pred->right_child == currant) {
				pred->right_child = currantMaxElementInSubTree;
			}
			//currantMaxElementInSubTree->right_child = currant->right_child;
			//currantMaxElementInSubTree->left_child = currant->left_child;
			if (currant->left_child)
			{
				currantMaxElementInSubTree->right_child = currant->right_child;
			}
		}
	}
}

void binaryNode::TraversePreorder() {
 	this->print();
	if (this->left_child) {
		this->left_child->TraversePreorder();
	}

	if (this->right_child) {
		this->right_child->TraversePreorder();
	}
}

void binaryNode::TraverseSim() {

	if (this->left_child) {
		this->left_child->TraverseSim();
	}

	this->print();

	if (this->right_child) {
 		this->right_child->TraverseSim();
	}

}

void binaryNode::TraverseObrat() {
	if (this->left_child) {
		this->left_child->TraverseObrat();
	}

	if (this->right_child) {
		this->right_child->TraverseObrat();
	}
	this->print();
}

void binaryNode::TraverseWidth() 
{
	queue qu;
	qu.pushBack(this);
	binaryNode* buf;

	while (qu.size!=0) 
	{
		buf=qu.pop();
		cout << buf->str << endl;
		if (buf->left_child) {
			qu.pushBack(buf->left_child);
		}

		if (buf->right_child) {
			qu.pushBack(buf->right_child);
		}

	}

}

void binaryNode::calculateNumberOfElements()
{
	queue qu;
	qu.pushBack(this);

	binaryNode* buf;

	while (qu.size != 0)
	{
		buf = qu.pop();
		cout << buf->str << endl;
		if (buf->left_child) {
			qu.pushBack(buf->left_child);
			sizeOfSubStr++;
		}

		if (buf->right_child) {
			qu.pushBack(buf->right_child);
			sizeOfSubStr++;
		}

	}

}

void binaryNode::push(binaryNode* root,binaryNode* ob) {

	//binaryNode* currant = this;
	if (this->str > ob->str& this->left_child==nullptr) {
		this->left_child = ob;
	}
	else if(this->str > ob->str) {
		this->left_child->push(root,ob);
	}

	if (this->str < ob->str & this->right_child == nullptr) {
		this->right_child = ob;
	}
	else if (this->str < ob->str) {
		this->right_child->push(root,ob);
	}
}

int binaryNode::hightOfTree() {
	
	if (this == nullptr) {
		return 0;
	}
	int hLeft, hRight;
	hLeft = this->left_child->hightOfTree();
	hRight = this->right_child->hightOfTree();

	if (hLeft > hRight) {
		return hLeft + 1;
	}
	else 
	{
		return hRight + 1;
	}
}

binaryNode* binaryNode::leftTern(binaryNode* root) {
	binaryNode* pPrev = root->searchPrev(this->str, nullptr);

	binaryNode* newNode = this->right_child;
	this->right_child = newNode->left_child;
	newNode->left_child = this;

	if (pPrev == nullptr) {
		return newNode;
	}
	else {
		if (pPrev->left_child == this) {
			pPrev->left_child = newNode;
		}
		else if (pPrev->right_child == this) {
			pPrev->right_child = newNode;
		}
		return newNode;
	}

}

binaryNode* binaryNode::rightTern(binaryNode* root) {
	binaryNode* pPrev = root->searchPrev(this->str, nullptr);

	binaryNode* newNode = this->left_child;
	this->left_child = newNode->right_child;
	newNode->right_child = this;


	if (pPrev == nullptr) {
		return newNode;
	}
	else {
		if (pPrev->left_child == this) {
			pPrev->left_child = newNode;
		}
		else if (pPrev->right_child == this) {
			pPrev->right_child = newNode;
		}
		return newNode;
	}
}

int binaryNode::defineBalance() {
	int n1, n2;
	n1 = this->left_child->hightOfTree();
	n2 = this->right_child->hightOfTree();
	return n2-n1;

}

binaryNode* binaryNode::makeBalance(binaryNode *root) {
	int n1 = root->defineBalance();
	int n2;
	if (abs(n1) == 2)
	{ 
		if(n1<0)
		{
			n2 = root->left_child->defineBalance();
			if (n2 < 0) {
				root = root->rightTern(root);
				return root;
			}
			else {
				root->left_child->leftTern(root);
				root = root->rightTern(root);
				return root;
			}
		}
		else {
			int n2 = root->right_child->defineBalance();
			if (n2 > 0) {
				root = root->leftTern(root);
				return root;
			}
			else {
				root->right_child->rightTern(root);
				root = root->leftTern(root);
				return root;
			}

		}
	}
	return root;
}

void binaryNode::calculateDaught() {

	queue qu;
	qu.pushBack(this);
	binaryNode* buf;
	int kol=0, met=0;
	while (qu.size != 0)
	{
		buf = qu.pop();
		//cout << buf->str << endl;
		if (buf->left_child) {
			qu.pushBack(buf->left_child);
			met++;
		}

		if (buf->right_child) {
			qu.pushBack(buf->right_child);
			met++;
		}
		if (met == 2) {
			kol++;
		}
		met = 0;
	}
	cout <<"\nkol = "<< kol << endl;
}

int main()
{
	

	binaryNode* root = new binaryNode(60);
	binaryNode* a = new binaryNode(35);
	binaryNode* b = new binaryNode(42);
	binaryNode* c = new binaryNode(21);
	binaryNode* d = new binaryNode(17);
	binaryNode* g = new binaryNode(95);
	binaryNode* h = new binaryNode(23);
	binaryNode* i = new binaryNode(16);
	binaryNode* k = new binaryNode(90);
	binaryNode* l = new binaryNode(100);
	binaryNode* m = new binaryNode(18);
	root->push(root, a);
	//root = root->makeBalance(root);

	root->push(root, b);
	//root = root->makeBalance(root);

	root->push(root, c);
	//root = root->makeBalance(root);

	root->push(root, d);
	//root = root->makeBalance(root);

	root->push(root, g);
	//root = root->makeBalance(root);

	root->push(root, h);
	//root = root->makeBalance(root);

	root->push(root, i);
	//root = root->makeBalance(root);
	
	root->push(root, k);
	root->push(root, l);
	root->push(root, m);

	root->TraversePreorder();
	root->calculateDaught();
}