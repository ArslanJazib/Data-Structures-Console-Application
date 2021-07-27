#include"Node.h"
#include<iostream>
#include<conio.h>
using namespace std;
template<typename datatype>
class list
{
public:
	node *head;
	list();
	void traverse();
	bool isEmpty();
	void insert_beg(datatype);
	void insert_end(datatype);
	void insert_after(datatype, datatype);
	void ascending_insert(datatype);
	void del(datatype);
	datatype max();
	datatype counter();
	datatype search(datatype value);
	void swapdata(node *n1, node *n2);
	void recursive_display(node *head);
};

