#pragma once
#include<iostream>
#include<conio.h>
#include"Node.h"
class lqueue
{
private:
	node *front;
	node *rear;
public:
	lqueue();
	void lenqueue(int v);
	int ldequeue();
	int my_front();
	void display();

};