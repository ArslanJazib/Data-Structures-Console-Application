#pragma once
#include<iostream>
#include<conio.h>
#include"Node.h"
using namespace std;
template<typename datatype>
class lstack
{
public:
	node *top;
	lstack();
	void push(datatype);
	datatype pop();
	datatype my_top();
	bool isEmpty();
	void display();
};