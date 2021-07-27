#pragma once
#include"TNode.h"
using namespace std;
class BST
{
private:
	TNode* NewNode(int);
	void Insert(TNode*, int);
	void Search(TNode*, int);
	void traverse(TNode*, int);
	void PreOrder(TNode*);
	void PostOrder(TNode*);
	void InOrder(TNode*);
	TNode* Minimum(TNode*);
	void Maximum(TNode*);
	TNode* Get_Parent(TNode*, TNode*, int);
	void Leaf_Nodes(TNode*, int& value);
	void Count_Nodes(TNode*, int& value);
	void Delete_Node(TNode*, int);
public:
	TNode* Root;
	BST();
	bool Empty();
	void Insert(int);
	void Search(int);
	void traverse(int);
	void PreOrder();
	void PostOrder();
	void InOrder();
	TNode* Minimum();
	void Maximum();
	TNode* Get_Parent(int);
	void Leaf_Nodes();
	void Count_Nodes();
	void Delete_Node(int);
	int get_sibiling(TNode* root, int value);
};
