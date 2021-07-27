#include"LinearQueue.h"
// Parameterized
template<typename datatype>
lqueue<datatype>::lqueue<datatype>(int s)
{
	queuearray = new datatype[s];
	rear = -1;
	front = -1;
	size = s;
}
template class lqueue<int>;
template class lqueue<char>;
// Underflow
template<typename datatype>
bool lqueue<datatype>::isEmpty()
{
	if (front == rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class lqueue<int>;
template class lqueue<char>;
//Overflow
template<typename datatype>
bool lqueue<datatype>::isFull()
{
	if (rear == size-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class lqueue<int>;
template class lqueue<char>;
//Enqueue
template<typename datatype>
void lqueue<datatype>::enqueue(datatype a)
{
	if (!isFull())
	{
		queuearray[++rear] = a;
		
		
	}
	else
	{
		cout << "Queue Overflow" << endl;
	}
}
template class lqueue<int>;
template class lqueue<char>;
// Dequeue
template<typename datatype>
datatype lqueue<datatype>::dequeue()
{
	if (!isEmpty())
	{
		return queuearray[++front];
	}
	else
	{
		cout << "Queue Underflow" << endl;
	}
}
template class lqueue<int>;
template class lqueue<char>;
// Front Value
template<typename datatype>
datatype lqueue<datatype>::my_front()
{
	if (!isEmpty())
	{
		return queuearray[front + 1];
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}
template class lqueue<int>;
template class lqueue<char>;
// Display
template<typename datatype>
void lqueue<datatype>::qdisplay()
{
	if(!isEmpty())
	for (int i = front + 1; i <= rear; i++)
	{
		cout << queuearray[i] << endl;
	}
	else
	{
		cout << "Queue is Empty" << endl;
	}
 }