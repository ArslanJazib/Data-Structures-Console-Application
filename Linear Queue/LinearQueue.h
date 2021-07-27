#pragma once
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
template<typename datatype>
class lqueue
{
private:
	datatype *queuearray;
	int front;
	int rear;
	int size;
public:
	lqueue(int);
	bool isEmpty();
	bool isFull();
	void enqueue(datatype);
	datatype dequeue();
	datatype my_front();
	void qdisplay();
};