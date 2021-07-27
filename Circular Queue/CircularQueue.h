#pragma once
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
template<typename datatype>
class cqueue
{
private:
	datatype *queuearray;
	int size;
	int front;
	int count;
	int rear;
public:
	cqueue(int);
	bool isEmpty();
	bool isFull();
	void enqueue(datatype);
	datatype dequeue();
	datatype my_front();
	void display();
};