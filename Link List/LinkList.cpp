#include"LinkList.h"
template<typename datatype>
// Constructor
list<datatype>::list()
{
	head = NULL;
}
template class list<int>;
template class list<char>;
// Empty List
template<typename datatype>
bool list<datatype>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class list<int>;
template class list<char>;
// Traverse
template<typename datatype>
void list<datatype>::traverse()
{
	node *p;
	p = head;
	if (isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		while (p != NULL)
		{
			cout << p->data;
			p = p->next;
			cout << endl;
		}
	}
}
template class list<int>;
template class list<char>;
// Insert at beginning
template<typename datatype>
void list<datatype>::insert_beg(datatype v)
{
	node*p = new node;
	p->data = v;
	p->next = NULL;
	if (isEmpty())
	{
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
	cout << head->data;
}
template class list<int>;
template class list<char>;
// Insert at end
template<typename datatype>
void list<datatype>::insert_end(datatype v)
{
	node *p = new node;
	p->data = v;
	p->next = NULL;
	if (isEmpty())
	{
		head = p;
	}
	else
	{
		node *q;
		q = head;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}
template class list<int>;
template class list<char>;
// Insert after
template<typename datatype>
void list<datatype>::insert_after(datatype old, datatype v)
{
	if (isEmpty())
	{
		cout << "List is empty";
	}
	else
	{
		node *q = head;
		while (q->data != old && q->data != NULL)
		{
			q = q->next;
		}
		if (q == NULL)
		{
			cout << "Predecessor Not found" << endl;
		}
		else
		{
			node *p = new node;
			p->data = v;
			p->next = NULL;
			p->next = q->next;
			q->next = p;
		}
	}
}
template class list<int>;
template class list<char>;
// Delete
template<typename datatype>
void list<datatype>::del(datatype v)
{
	if (isEmpty())
	{
		cout << "List is empty";
	}
	else
	{
		node *p;
		node *q;
		q = NULL;
		p = head;
		while (p->data != v && p != NULL)
		{
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "Node not found" << endl;
		}
		else
		{
			if (q == 0)
			{
				head = p->next;
				delete p;
			}
			else
			{
				q->next=p->next;
				delete p;
			}
		}
	}
}
template class list<int>;
template class list<char>;
// Max
template<typename datatype>
datatype list<datatype>::max()
{
	node *temp = new node;
	temp = head;
	int max;
	max = temp->data;
	while (temp != NULL)
	{
		
		if (temp->data > max)
		{
			max = temp->data;
		}
		temp = temp->next;
	}
	return max;

}
template class list<int>;
template class list<char>;
// Counting Nodes
template<typename datatype>
datatype list<datatype>::counter()
{
	node *temp = new node;
	temp = head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
template class list<int>;
template class list<char>;
// Searching
template<typename datatype>
datatype list<datatype> :: search(datatype value)
{
	int count = 1;
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		if (value == temp->data)
		{
			break;
		}	
		count++;
		temp = temp->next;

	}
	return count;
}
template class list<int>;
template class list<char>;
// Swaping
template<typename datatype>
void list<datatype>::swapdata(node *n1, node *n2)
{
	node *tval = new node; // For swapping
	node *temp = new node; // For securing list
	temp = head;
	n1 = temp;
	n2 = temp->next;
	tval->data = n1->data;
	n1->data = n2->data;
	n2->data = tval->data;
}
template class list<int>;
template class list<char>;
// Recursion
template<typename datatype>
void list<datatype>::recursive_display(node *h1)
{
	node *temp = new node;
	temp = head;

	if (isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		if (h1 != NULL)
		{
			cout << (h1->data);
			cout << endl;
			recursive_display(h1->next);
		}
	}
}
template class list<int>;
template class list<char>;
// Ascending Insert
template<typename datatype>
void list<datatype>::ascending_insert(datatype value)
{
	node *temp2 = new node;
	temp2->data = value;
	temp2->next = NULL;
	node *temp3 = new node;
	node *pre = new node;
	pre->next = NULL;
	node *old = new node;
	old->next = NULL;
	node*temp4 = new node;
	temp4->next = NULL;
	node *temp5 = new node;
	temp5->next = NULL;
	if (isEmpty())
	{
		head = temp2;
	}
	else
	{
		node *temp = new node;
		temp = head;
		temp4->data = old->data;
		while (temp!= NULL)
		{
			old = temp;
			temp = temp->next;
		}
		while (old != NULL)
		{
			temp5 = old;
			old = old->next;
		}
			if (temp4->data > value)
			{
				pre->data = old->data;
				temp3->data = temp2->data;
				old->data = temp2->data;
				old->data = temp3->data;
				old->next = pre;
			}
			else
			{
				old->next = temp2;
			}
		}

}
template class list<int>;
template class list<char>;