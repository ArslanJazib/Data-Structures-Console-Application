#pragma once
#include<iostream>
using namespace std;
class TNode
{
public:
	int Data;
	TNode* Left;
	TNode *Right;
	TNode()
	{
		Data = 0;
		Left = NULL;
		Right = NULL;
	}
};
