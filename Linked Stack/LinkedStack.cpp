#include"LinkedStack.h"
// Constructor
template<typename datatype>
lstack<datatype>::lstack()
{
	top = NULL;
}
template class lstack<int>;
template class lstack<char>;
// Empty
template<typename datatype>
bool lstack<datatype>::isEmpty()
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class lstack<int>;
template class lstack<char>;
// Push
template<typename datatype>
void lstack<datatype>::push(datatype v)
{
	node *p = new node;
	p->data = v;
	p->next = NULL;
	if (top == NULL)
	{
		top = p;
	}
	else
	{
		p->next = top;
		top = p;
	}
}
template class lstack<int>;
template class lstack<char>;
// Pop
template<typename datatype>
datatype lstack<datatype>::pop()
{
	if (top == NULL)
	{
		cout << "Stack Underflow" << endl;
		return -1;
	}
	else
	{
		int v = top->data;
		node *temp = top;
		top = top->next;
		delete temp;
		return v;
	}
}
template class lstack<int>;
template class lstack<char>;
// Display
template<typename datatype>
void lstack<datatype>::display()
{
	if (isEmpty())
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		node *temp = top;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}
template class lstack<int>;
template class lstack<char>;
// Top value
template<typename datatype>
datatype lstack<datatype>::my_top()
{
	if (!isEmpty())
	{
		return top->data;
	}
	else
	{
		cout << "Stack is Empty" << endl;
	}
	return -1; // Symbol for an empty stack
}
template class lstack<int>;
template class lstack<char>;