#pragma once
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
template<typename datatype>
class stack
{
private:
	datatype *stackarray;
	int top;
	int size;
public:
	stack(int);
	bool isEmpty();
	bool isFull();
	void push(datatype);
	datatype pop();
	datatype my_top();
	void display();
};
