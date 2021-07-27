#include"CircularQueue.h"
// Parameterized
template<typename datatype>
cqueue<datatype>::cqueue<datatype>(int s)
{
	queuearray = new datatype[s];
	size = s;
	front = 0;
	count = 0;
	rear = 0;
}
template class cqueue<int>;
template class cqueue<char>;
// Underflow
template<typename datatype>
bool cqueue<datatype>::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class cqueue<int>;
template class cqueue<char>;
// Overflow
template<typename datatype>
bool cqueue<datatype>::isFull()
{
	if (count == size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class cqueue<int>;
template class cqueue<char>;
// Enqueue
template<typename datatype>
void cqueue<datatype>::enqueue(datatype a)
{
	if (!isFull())
	{
		queuearray[rear] = a;
		rear = (rear + 1) % size;
		count++;
	}
	else
	{
		cout << "Queue Overflow" << endl;
	}
}
template class cqueue<int>;
template class cqueue<char>;
// Dequeue
template<typename datatype>
datatype cqueue<datatype>::dequeue()
{
	datatype temp;
	if (!isEmpty())
	{
		temp = queuearray[front];
		front = (front + 1) % size;
		count--;
		return temp;
	}
	else
	{
		cout << "Queue Underflow" << endl;
		return -1;
	}
}
template class cqueue<int>;
template class cqueue<char>;
// Front Value
template<typename datatype>
datatype cqueue<datatype>::my_front()
{
	if (!isEmpty())
	{
		return queuearray[front];
	}
	else
	{
		cout << "Queue is Empty" << endl;
		return -1;
	}
}
template class cqueue<int>;
template class cqueue<char>;
// Display
