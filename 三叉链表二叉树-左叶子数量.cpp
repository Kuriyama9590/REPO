#include <iostream>
#include <string>

using namespace std;

class BiTreeNode {
public:
	char data;
	BiTreeNode* leftChild;
	BiTreeNode* rightChild;
	BiTreeNode* parent;
	BiTreeNode(char c) {
		data = c;
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
	}
	~BiTreeNode() {}
};

class BiTree {
private:
	int pos;//用于记录当前访问到了strTree的哪个位置
	int leaves;
	int left_leaves;
	BiTreeNode* root;
	string strTree;
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void	InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);

public:
	BiTree() {}
	~BiTree() {}
	void CreateBiTree(string TreeArray);
	void PreOrder();
	void InOrder();
	void PostOrder();
	int get_leaves() {return leaves;}
	int get_left_leaves() {return left_leaves;}
};

void BiTree::CreateBiTree(string TreeArray) {
	pos = 0;
	strTree = TreeArray;
	root = CreateBiTree();
}

BiTreeNode* BiTree::CreateBiTree() {
	BiTreeNode* T;
	char ch = strTree[pos++];
	if (ch == '0') {
		T = NULL; // 递归结束，建空树
	}
	else {
		T = new BiTreeNode(ch);
		T->leftChild = CreateBiTree();
		T->rightChild = CreateBiTree();
		if (T->leftChild != NULL) {//左孩子非空,设置左孩子的父节点
			T->leftChild->parent = T;
		}
		if (T->rightChild != NULL) {//右孩子非空,设置右孩子的父节点
			T->rightChild->parent = T;
		}
	}
	return T;
}

void BiTree::PreOrder() {
	PreOrder(root);
}

void BiTree::PreOrder(BiTreeNode* t) {
	if (t != NULL) {
		if (t->leftChild == NULL && t->rightChild == NULL && t ==  t->parent->leftChild) {
			left_leaves++;
		}
		//cout << t->data ;
		PreOrder(t->leftChild);
		PreOrder(t->rightChild);
	}
}

void BiTree::InOrder() {
	InOrder(root);
}

void BiTree::InOrder(BiTreeNode* t) {
	if (t != NULL) {
		InOrder(t->leftChild);
		cout << t->data ;
		InOrder(t->rightChild);
	}
}

void BiTree::PostOrder() {
	PostOrder(root);
}

void BiTree::PostOrder(BiTreeNode* t) {
	if (t != NULL) {
		PostOrder(t->leftChild);
		PostOrder(t->rightChild);
		cout << t->data ;	
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		BiTree tree;
		tree.CreateBiTree(s);
		tree.PreOrder();
		cout <<tree.get_left_leaves()<< endl;
	}
	return 0;
}