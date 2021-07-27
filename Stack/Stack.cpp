#include"stack.h"
// Parameterized 
template<typename datatype>
stack<datatype>::stack(int s)
{
	stackarray = new datatype[s];
	top = -1; 
	size = s;
}
template class stack<int>;
template class stack<char>;
// Stack Underflow
template<class datatype>
bool stack<datatype>::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class stack<int>;
template class stack<char>;
// Stack Overflow
template<class datatype>
bool stack<datatype>::isFull()
{
	if (top == size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class stack<int>;
template class stack<char>;
// Push Function
template<class datatype>
void stack<datatype>::push(datatype a)
{
	if (!isFull())
	{
		stackarray[++top] = a;
	}
	else
	{
		cout << "Overflow" << endl;
	}
}
template class stack<int>;
template class stack<char>;
// Pop Function
template<class datatype>
datatype stack<datatype>::pop()
{
	if (!isEmpty())
	{
		return stackarray[top--];
	}
	else
	{
		cout << "Underflow" << endl;
	}
	return -1;
}
template class stack<int>;
template class stack<char>;
// Displays Current Top
template<class datatype>
datatype stack<datatype>::my_top()
{
	if (!isEmpty())
	{
		return stackarray[top];
	}
	else
	{
		cout << "Stack is Empty" << endl << " -1 Is A Symbol for an empty stack" << endl;
	}
	return -1; // Symbol for an empty stack
}
template class stack<int>;
template class stack<char>;
// Displaying the whole Stack
template<class datatype>
void stack<datatype>::display()
{
	for (int loop1 = top; loop1 >= 0; loop1--)
	{
		cout << stackarray[loop1] << " ";
	}
	cout << endl;
}
template class stack<int>;
template class stack<char>;
