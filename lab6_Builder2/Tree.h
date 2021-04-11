//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
//---------------------------------------------------------------------------
#endif
#include<String.h>
class binaryNode {
public:
	binaryNode* left_child = nullptr;
	binaryNode* right_child = nullptr;
	binaryNode* pNext = nullptr;
	binaryNode* pPrev = nullptr;
	int sizeOfSubStr=0;

	void createTree(TTreeView *TreeView1,TMemo *Memo1);

	void calculateNumberOfElements(TMemo *Memo1);

	binaryNode* leftTern(binaryNode* root);

	int hightOfTree();

	int defineBalance();

	binaryNode* makeBalance(binaryNode *root);
	void print(TMemo *Memo1)
	{
	   String st= IntToStr(this->str)+" "+this->name;
	   Memo1->Lines->Add(st);
	}
	binaryNode* binaryNode::rightTern(binaryNode* root);
	void TraversePreorder(TMemo *Memo1)
	{

	this->print(Memo1);
	if (this->left_child) {
		this->left_child->TraversePreorder(Memo1);
	}

	if (this->right_child) {
		this->right_child->TraversePreorder(Memo1);
	}

	}

	void TraverseSim(TMemo *Memo1){
		if (this->left_child) {
			this->left_child->TraverseSim(Memo1);
		}

		this->print(Memo1);

		if (this->right_child) {
			this->right_child->TraverseSim(Memo1);
		}
	}

	void TraverseObrat(TMemo *Memo1)
	{
	if (this->left_child)
		{
			this->left_child->TraverseObrat(Memo1);
		}

	if (this->right_child)
		{
			this->right_child->TraverseObrat(Memo1);
		}
		this->print(Memo1);
	}

	void TraverseWidth(TMemo *Memo1);

	binaryNode() {
		this->str = 0;
		this->name="";
	}

	binaryNode(int str,String name) {
		this->str = str;
		this->name=name;
	}

	void set(int str,String name)
	{
		this->str = str;
		this->name=name;
	}

	void push(binaryNode *ob){
		binaryNode *buf=search(ob->str);
		if(buf==nullptr)
		{
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
	}

	binaryNode* findMax(TMemo *Memo1)
	{
		if (this->right_child)
		{
			return this->right_child->findMax(Memo1);
		}
		else {
		//Memo1->Lines->Add(this->str);
		return this;
		}
	}

	binaryNode* findElement(int index,TMemo *Memo1)
	{
		int def;
		binaryNode* currant;
		binaryNode* pred = this;
		currant=this->search(index);
		pred = this->searchPrev(index, pred);
		def=this->defineNode(currant);
		binaryNode* currantMaxElementInSubTree=nullptr;

		if (def == 0) {
			return currantMaxElementInSubTree;
		}

		else if (def == 1) {
			if (currant->left_child != nullptr) {
				currantMaxElementInSubTree = currant->left_child->findMax(Memo1);
			}
			else {
				currantMaxElementInSubTree = currant->right_child->findMin();
			}
			return currantMaxElementInSubTree;
		}


	}

	binaryNode* remove(int index,TMemo *Memo1)
	{

		int def;
		binaryNode* currant;
		binaryNode* pred = this;
		currant=this->search(index);
		if(currant!=nullptr&currant!=this)
		{
			pred = this->searchPrev(index, pred);
			def=this->defineNode(currant);
			binaryNode* currantMaxElementInSubTree=nullptr;
			binaryNode* predtMaxElementInSubTree=nullptr;
			if (def == 0) {
				this->removeList(currant, pred);
				return currantMaxElementInSubTree;
			}

			else if (def == 1) {
				if (currant->left_child != nullptr) {
					currantMaxElementInSubTree = currant->left_child->findMax(Memo1);
				}
				else {
					currantMaxElementInSubTree = currant->right_child->findMin();
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

					if (currant->left_child) {
						predtMaxElementInSubTree->right_child = currantMaxElementInSubTree->left_child;
						currantMaxElementInSubTree->left_child = currant->left_child;
						currantMaxElementInSubTree->right_child = currant->right_child;
					}
					else {
						currantMaxElementInSubTree->right_child = currant->right_child;
						predtMaxElementInSubTree->left_child = nullptr;
					}
				}
				else {
					if (pred->left_child == currant) {
						pred->left_child = currantMaxElementInSubTree;
					}
					else if (pred->right_child == currant) {
						pred->right_child = currantMaxElementInSubTree;
					}
					if(currant->left_child)
					{
					 currantMaxElementInSubTree->right_child = currant->right_child;
					}
				}
				return currantMaxElementInSubTree;
			}
	  }
	}


	binaryNode* search(int index){
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


	binaryNode* searchPrev(int index,binaryNode* Prev)
		{
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


	int defineNode(binaryNode* p){
		if (p->left_child || p->right_child)
		{
			return 1;
		}
		else {
			return 0;
		}
	}

	void removeList(binaryNode* currant, binaryNode* pred)
	{
			if (pred->left_child == currant)
			{
			pred->left_child = nullptr;
			}
			else if (pred->right_child == currant) {
				pred->right_child = nullptr;
			}
	}

		binaryNode* findMin()
	{
		if (this->left_child)
		{
			   return this->left_child->findMin();
		}
			else
			{
				return this;
			}
	}

	int str;
	String name;
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
			//cout << currant->str << endl;
			currant = currant->pNext;
		}
		//cout << currant->str << endl;
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

void binaryNode::TraverseWidth(TMemo *Memo1)
{
	queue qu;
	qu.pushBack(this);
	binaryNode* buf;
	String stroka;
	while (qu.size!=0)
	{
		buf=qu.pop();
		stroka=IntToStr(buf->str)+" "+buf->name;
		Memo1->Lines->Add(stroka);
		if (buf->left_child) {
			qu.pushBack(buf->left_child);
		}

		if (buf->right_child) {
			qu.pushBack(buf->right_child);
		}
	}
}

void binaryNode::createTree(TTreeView *TreeView1,TMemo *Memo1)
{

queue qu;
qu.pushBack(this);
binaryNode* buf;
int index;
	while (qu.size!=0)
	{
	   buf=qu.pop();

		if (buf->left_child) {
			qu.pushBack(buf->left_child);
			for(int i=0;i<100;i++)
			{
			  if(StrToInt(TreeView1->Items->Item[i]->Text)==buf->str)
			  {
			  index=i;
			  break;
			  }
			}
			TTreeNode *Node1=TreeView1->Items->Item[index];
			TreeView1->Items->AddChild(Node1,IntToStr(buf->left_child->str));
		}

		if (buf->right_child) {
			qu.pushBack(buf->right_child);
			for(int i=0;i<100;i++)
			{
			  if(StrToInt(TreeView1->Items->Item[i]->Text)==buf->str)
			  {
			  index=i;
			  break;
			  }
			}
			TTreeNode *Node1=TreeView1->Items->Item[index];
			TreeView1->Items->AddChild(Node1,IntToStr(buf->right_child->str));
		}
	}

}

void binaryNode::calculateNumberOfElements(TMemo *Memo1)
{
	binaryNode* buf;
	queue qu;
	qu.pushBack(this);
	//Memo1->Lines->Add(this->str);
	//Memo1->Lines->Add(buf1->str);
	//Memo1->Lines->Add(buf1->left_child->str);
	while (qu.size != 0)
	{
		buf = qu.pop();
		if (buf->left_child) {
			qu.pushBack(buf->left_child);
			sizeOfSubStr++;
		   //	Memo1->Lines->Add(buf->left_child->str);
		}

		if (buf->right_child) {
			qu.pushBack(buf->right_child);
			sizeOfSubStr++;
		   //	Memo1->Lines->Add(buf->right_child->str);
		}

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


int binaryNode::defineBalance() {
	int n1, n2;
	n1 = this->left_child->hightOfTree();
	n2 = this->right_child->hightOfTree();
	return n2-n1;

}

binaryNode* binaryNode::makeBalance(binaryNode *root)
{

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

class FindDaughter:public binaryNode
{
public:
void calculateDaughter(TMemo *Memo1,binaryNode* root) {
	queue qu;
	qu.pushBack(root);
	binaryNode* buf;
	int kol=0, met=0;
	while (qu.size != 0)
	{
		buf = qu.pop();
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
	String stroka="kol = "+IntToStr(kol);
	Memo1->Clear();
	Memo1->Lines->Add(stroka);
}
};
