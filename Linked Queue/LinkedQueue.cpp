#include"LinkedQueue.h"
// Default Constructor
lqueue::lqueue()
{
	front = rear = NULL;
}
// Enqueue
void lqueue::lenqueue(int v)
{
	node *p = new node;
	p->data = v;
	p->next = NULL;
	if (front != NULL && rear != NULL)
	{
		rear->next = p;
		rear = p;
	}
	else if (front == NULL && rear == NULL)
	{
		
		//front = rear - 1;
		front = rear = p;
	}
}
// Dequeue
int lqueue::ldequeue()
{
	if (front == NULL && rear == NULL)
	{
		cout << "Queue Underflow";
		return - 1;
	}
	else
	{
		int v = front->data;
		node *temp = front;
		if (front == NULL) 
		{
			cout << "Queue is Empty\n"; 
			return 0;
		}

		if (front == rear)
		{
			front = rear = NULL;
			delete temp;
		}
		else
		{
			front = front->next;
			delete temp;
		}
		return v;
	}
}
// Front
int lqueue::my_front()
{
	if (front == NULL)
	{
		cout << "Queue is empty" << endl;
			return -1;
	}
	else
	{
		return front->data;
	}
}
// Display
void lqueue::display()
{
	if (front == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	node* temp = front;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}