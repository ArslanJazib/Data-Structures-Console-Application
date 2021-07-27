#include"Node.h"
using namespace std;
template<typename datatype>
class dlist
{
public:
	node *head;
	dlist();
	void insert_beg(datatype v);
	void insert_end(datatype v);
	void insert_after(datatype old, datatype value);
	void delete_node(datatype v);
	void revrese_traverse();
	void forward_traverse();
	void reverse();
	bool isEmpty();
};
