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
	void push(binaryNode *ob);
	void remove(int index);
	binaryNode* search(int index);
	binaryNode* searchPrev(int index,binaryNode *p);
	int defineNode(binaryNode* p);
	void removeList(binaryNode* currant, binaryNode* pred);
	binaryNode* findMax();
	int str;
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
        
		if (currant !=predtMaxElementInSubTree) {
			if (pred->left_child == currant) {
				pred->left_child = currantMaxElementInSubTree;
			}
			else if (pred->right_child == currant) {
				pred->right_child = currantMaxElementInSubTree;
			}

			predtMaxElementInSubTree->right_child = currantMaxElementInSubTree->left_child;
			currantMaxElementInSubTree->left_child = currant->left_child;
			currantMaxElementInSubTree->right_child = currant->right_child;
		}
		else {
			if (pred->left_child == currant) {
				pred->left_child = currantMaxElementInSubTree;
			}
			else if (pred->right_child == currant) {
				pred->right_child = currantMaxElementInSubTree;
			}
			if (currantMaxElementInSubTree->right_child) {
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

void binaryNode::push(binaryNode* ob) {

	//binaryNode* currant = this;
	if (this->str > ob->str& this->left_child==nullptr) {
		this->left_child = ob;
	}
	else if(this->str > ob->str) {
		this->left_child->push(ob);
	}

	if (this->str < ob->str & this->right_child == nullptr) {
		this->right_child = ob;
	}
	else if (this->str < ob->str) {
		this->right_child->push(ob);
	}

}

int main()
{
	
	binaryNode* root = new binaryNode(60);
	binaryNode* node1_1 = new binaryNode(35);
	binaryNode* node1_2 = new binaryNode(42);
	binaryNode* node2_1 = new binaryNode(21);
	binaryNode* node2_2 = new binaryNode(17);
	binaryNode* node3_1 = new binaryNode(11);
	binaryNode* node3_2 = new binaryNode(25);
	binaryNode* node4_1 = new binaryNode(23);
	binaryNode* node4_2 = new binaryNode(22);
	binaryNode* a = new binaryNode(24);
	binaryNode* b = new binaryNode(80);
	binaryNode* c = new binaryNode(18);
	binaryNode* d = new binaryNode(66);
	binaryNode* f = new binaryNode(95);
	binaryNode* g = new binaryNode(70);
	root->push(node1_1);
	root->push(node1_2);
	root->push(node2_1);
	root->push(node2_2);
	root->push(node3_1);
	root->push(node3_2);
	root->push(node4_1);
	root->push(node4_2);
	root->push(a);
	root->push(b);
	root->push(c);
	root->push(d);
	root->push(f);
	root->push(g);
	//root->remove(35);
	//root->TraversePreorder();
}