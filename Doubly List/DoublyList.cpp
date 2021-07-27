#include"DoublyList.h"
//  Constructor
template<typename datatype>
dlist<datatype>::dlist()
{
	head = NULL;
}
template class dlist<int>;
template class dlist<char>;
//Empty List
template<typename datatype>
bool dlist<datatype>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}
template class dlist<int>;
template class dlist<char>;
// Insert Beggining 
template<typename datatype>
void dlist<datatype>::insert_beg(datatype v)
{

	node*p = new node;
	p->data = v;
	p->prev = NULL;
	p->next = NULL;
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		p->next = head;
		head->prev = p;
		head = p;
	}

}
template class dlist<int>;
template class dlist<char>;
// Insert End
template<typename datatype>
void dlist<datatype>::insert_end(datatype v)
{
	node *p = new node;
	p->data = v;
	p->prev = NULL;
	p->next = NULL;
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		node *t = head;
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = p;
		p->prev = t;
	}
}
template class dlist<int>;
template class dlist<char>;
// Insert after
template<typename datatype>
void dlist<datatype>::insert_after(datatype old, datatype value)
{
	if (isEmpty() == true)
	{
		cout << "List is Empty";

	}
	else
	{
		node *t = head;
		while (t->data != old && t != NULL)
		{
			t = t->next;
		}
		if (t == NULL)
		{
			cout << "No Node Found";
		}
		else
		{
			node *p = new node;
			p->data = value;
			p->prev = NULL;
			p->next = NULL;
			if (t->next == NULL)
			{
				t->next = p;
				p->prev = t;
			}
			else if (t->next != NULL)
			{
				p->next = t->next;
				t->next->prev = p;
				t->next = p;
				p->prev = t;
			}
		}
	}
}
template class dlist<int>;
template class dlist<char>;
// Delete Node
template<typename datatype>
void dlist<datatype>::delete_node(datatype v)
{

	if (isEmpty() == true)
	{
		cout << "List is Empty";
	}
	else
	{
		node *t = head;
		while (t->data != v && t != NULL)
		{
			t = t->next;
		}
		if (t == NULL)
		{
			cout << "Node not found";
		}
		else
		{

			if (t->prev == NULL)
			{
				if (t->next != NULL)
				{
					t->next->prev = NULL;
				}
				head = t->next;
				delete t;
			}
			else
			{
				if (t->next == NULL)
				{

					t->prev->next = NULL;
					delete t;
				}
				else
				{
					t->next->prev = t->prev;
					t->prev->next = t->next;
					delete t;
				}
			}
		}
	}
}
template class dlist<int>;
template class dlist<char>;
// Forward Traverse
template<typename datatype>
void dlist<datatype>::forward_traverse()
{
	node*f = new node;
	f = head;
	if (isEmpty() == true)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		while (f != NULL)
		{
			cout << f->data;
			f = f->next;
		}
	}
}
template class dlist<int>;
template class dlist<char>;
// Reverse Traverse
template<typename datatype>
void dlist<datatype>::revrese_traverse()
{
	node *p = new node;
	p = head;
	node *t = new node;
	t = head;

	if (isEmpty() == true)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		while (p != NULL)
		{
			t = p;
			p = p->next;

		}
		while (t != NULL)
		{
			cout << t->data;
			t = t->prev;
		}

	}
}
template class dlist<int>;
template class dlist<char>;
template<typename datatype>
//Reversing List
void dlist<datatype>::reverse()
{
	node *p1, *p2;
	p1 = head;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;

	while (p2 != NULL)
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	head = p1;
	cout << "List Reversed" << endl;
}
template class dlist<int>;
template class dlist<char>;
