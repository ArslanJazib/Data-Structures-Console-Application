#pragma once
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<stack>
using namespace std;
class etnode
{
public:
	char data;
	etnode *right;
	etnode *left;
	etnode(char val)
	{
		this->data = val;
		right = left = NULL;
	}
};
etnode* constructTree(string postfix)
{
	stack<etnode *> s;
	etnode *curr = NULL;
	int length = postfix.length();
	for (int x = 0; x < length; x++)
	{
		if (postfix[x] >= 'a' && postfix[x] <= 'z')
		{
			curr = new etnode(postfix[x]);
			s.push(curr);
		}
		else if (postfix[x] == '+' || postfix[x] == '-' || postfix[x] == '*' || postfix[x] == '/')
		{
			curr = new etnode(postfix[x]);
			curr->right = s.top();
			s.pop();
			curr->left = s.top();
			s.pop();
			s.push(curr);
		}
	}
	return curr;
}
void postorder(etnode *curr)
{
	if (curr == NULL)
	{

	}
	else
	{
		postorder(curr->left);
		postorder(curr->right);
		cout << curr->data << " ";
	}
}