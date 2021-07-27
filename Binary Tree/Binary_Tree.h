#pragma once
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<stack>
using namespace std;
int counter = 0;
int counter2 = 0;
int flag = 0;
class btnode
{
public:
	int data;
	btnode *right;
	btnode *left;
	btnode(int val)
	{
		this->data = val;
		right = left = NULL;
	}
};
void constructTree(btnode** root, btnode* n)
{
	if (!*root)
	{
		*root = n;
		return;
	}
	if ((*root)->data <=n->data)
	{
		constructTree(&(*root)->right, n);
	}
	else
	{
		constructTree(&(*root)->left, n);
	}
}

void Preorder(btnode *root)
{
	if (root == NULL)
	{

	}
	else
	{
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}
bool search(btnode *root, int key)
{
	if (root == NULL)
	{
		return false;
	}
	else if (key == root->data)
	{
		return true;
	}
	else if (key < root->data)
	{
		search(root->left, key);
	}
	else if (key > root->data)
	{
		search(root->right, key);
	}
}
int count_leaf(btnode *root)
{
	if (root != NULL)
	{

		    count_leaf(root->left);
			if ((root->left == NULL) && (root->right == NULL))
			{
				counter++;
			}
			count_leaf(root->right);
		
	}
	return counter;
}
int count_nonleaf(btnode *root)
{
	if (root != NULL)
	{

		count_nonleaf(root->left);
		if ((root->left != NULL) || (root->right != NULL))
		{
			counter2++;
		}
		count_nonleaf(root->right);

	}
	return counter2;
}
bool isleaf(btnode *root, int value)
{
	if (root != NULL)
	{

		isleaf(root->left,value);
		if ((root->left == NULL) && (root->right == NULL))
		{
			if (root->data == value)
			{
				flag++;
			}
		}
		isleaf(root->right, value);

	}
	if (flag != 0)
	{
		return true;
	}
}
void preorder(btnode *curr)
{
	if (curr == NULL)
	{

	}
	else
	{
		cout << curr->data << " ";
		preorder(curr->left);
		preorder(curr->right);
	}
}
void Traversal(btnode* temp, int count)
{
	if (temp != NULL) {
		if (count % 2 == 0)
		{
			cout <<" "<<temp->data;
		}
		count++;
		Traversal(temp->left, count);
		Traversal(temp->right, count);
	}
}
int A_Recursive_Counter(btnode *root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + A_Recursive_Counter(root->left) + A_Recursive_Counter(root->right);
}


