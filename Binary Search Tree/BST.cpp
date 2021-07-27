#include"BST.h"
// Default Constructor
BST::BST()
{
	Root = NULL;
}
// Creating a new node
TNode* BST::NewNode(int value)
{
	TNode* n = new TNode;
	n->Data = value;
	n->Left = NULL;
	n->Right = NULL;
	return n;
}
// Checking for an empty tree
bool BST::Empty()
{
	if (Root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Inserting new node
void BST::Insert(TNode*root, int value)
{
	if (Empty())
	{
		TNode *New = NewNode(value);
		Root = New;
	}
	else
	{
		if (value < root->Data)
		{
			if (root->Left == NULL)
			{
				TNode *New = NewNode(value);
				root->Left = New;
			}
			else
			{
				Insert(root->Left, value);
			}
		}
		else if (value >= root->Data)
		{
			if (root->Right == NULL)
			{
				TNode *New = NewNode(value);
				root->Right = New;
			}
			else
			{
				Insert(root->Right, value);
			}
		}
	}
}
// Function overloading
void BST::Insert(int value)
{
	Insert(Root, value);
}
// Function to search a node
void BST::Search(TNode* root, int value)
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
	}
	else
	{
		if (root == NULL)
		{
			cout << "Value not found" << endl;
		}
		else if (value == root->Data)
		{
			cout <<" "<< root->Data<< endl;
		}
		else if (value <= root->Data)
		{
			Search(root->Left, value);
		}
		else if (value > root->Data)
		{
			Search(root->Right, value);
		}
	}
}
// Function overloading
void BST::Search(int value)
{
	Search(Root, value);
}
// Pre-order Traversal
void BST::PreOrder(TNode*root)
{
	if (root != NULL)
	{
		cout << " " << root->Data;
		PreOrder(root->Left);
		PreOrder(root->Right);
	}
}
// Function Overloading 
void BST::PreOrder()
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
	}
	else
		PreOrder(Root);
}
// Post Order Traversal
void BST::PostOrder(TNode*root)
{
	if (root != NULL)
	{
		PostOrder(root->Left);
		PostOrder(root->Right);
		cout << root->Data;
	}
}
// Function Overloading
void BST::PostOrder()
{
	if (Empty())
	{
		cout << "Empty Tee" << endl;
	}
	else
		PostOrder(Root);
}
// Inorder Traversal
void BST::InOrder(TNode*root)
{
	if (root != NULL)
	{
		InOrder(root->Left);
		cout <<" "<< root->Data;
		InOrder(root->Right);
	}
}
// Function Overloading
void BST::InOrder()
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
	}
	else
		InOrder(Root);
}
// Minimum Value
TNode* BST::Minimum(TNode*root)
{
	if (root->Left == NULL)
	{
		cout << " " << root->Data << endl;
		return root;
	}
	else
		Minimum(root->Left);
}
// Function Overloading 
TNode* BST::Minimum()
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
		return 0;
	}
	else
		return Minimum(Root);
}
// Maximum Value
void BST::Maximum(TNode*root)
{
	if (root->Right == NULL)
		cout << " " << root->Data << endl;
	else
		Maximum(root->Right);
}
// Function Overloading
void BST::Maximum()
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
	}
	else
		Maximum(Root);
}
// Get Parent
TNode* BST::Get_Parent(TNode*curr, TNode* prev, int value)
{
	if (curr == NULL)
	{
		cout << "Parent not found" << endl;
	}
	else if (curr->Data == value)
	{
		return prev;
	}
	else if (value <= curr->Data)
	{
		Get_Parent(curr->Left, curr, value);
	}
	else
	{
		Get_Parent(curr->Right, curr, value);
	}
}
// Function Overloading
TNode* BST::Get_Parent(int value)
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
		return 0;
	}
	else
		return Get_Parent(Root, NULL, value);
}
// Leaf Nodes
void BST::Leaf_Nodes(TNode*root, int& value)
{
	if (root != NULL)
	{
		if (root->Left == NULL && root->Right == NULL)
		{
			value++;
		}
		Leaf_Nodes(root->Left, value);
		Leaf_Nodes(root->Right, value);
	}
}
// Function Overloading
void BST::Leaf_Nodes()
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
	}
	else
	{
		int V = 0;
		Leaf_Nodes(Root, V);
		cout << " " << V << endl;

	}
}
// Delete Node
void BST::Delete_Node(TNode*root, int value)
{
	if (value <= root->Data)
	{
		if (value == root->Data)
		{
			TNode* Parents = Get_Parent(value);
			if (root->Left == NULL && root->Right == NULL)
			{
				Parents->Left = NULL;
				delete root;
			}
			else if (root->Left != NULL && root->Right != NULL)
			{
				TNode* Mini_Number = Minimum(root);
				TNode* Mini_Parents = Get_Parent(Mini_Number->Data);
				if (Mini_Number->Right != NULL)
				{
					Mini_Parents->Left = Mini_Number->Right;
					if (Parents->Right == root)
					{
						Mini_Number->Left = root->Left;
						Mini_Number->Right = root->Right;
						Parents->Right = Mini_Number;
					}
					else
					{
						Mini_Number->Left = root->Left;
						Mini_Number->Right = root->Right;
						Parents->Left = Mini_Number;
					}
				}
				else
				{
					Mini_Parents->Left = NULL;
					if (Parents->Right == root)
					{
						Mini_Number->Left = root->Left;
						Mini_Number->Right = root->Right;
						Parents->Right = Mini_Number;
					}
					else
					{
						Mini_Number->Left = root->Left;
						Mini_Number->Right = root->Right;
						Parents->Left = Mini_Number;
					}
				}
			}
			else
			{
				if (Parents->Left == root)
				{
					if (root->Left != NULL)
					{
						Parents->Left = root->Left;
						delete root;
					}
					else
					{
						Parents->Left = root->Right;
						delete root;
					}
				}
				else if (Parents->Right == root)
				{
					if (root->Left != NULL)
					{
						Parents->Right = root->Left;
						delete root;
					}
					else
					{
						Parents->Right = root->Right;
						delete root;
					}
				}
			}
		}
		else
		{
			Delete_Node(root->Left, value);
		}
	}
	else if (value >= root->Data)
	{
		if (value == root->Data)
		{
			TNode* Parents = Get_Parent(value);
			if (root->Left == NULL && root->Right == NULL)
			{
				Parents->Right = NULL;
				delete root;
			}
			else if (root->Left != NULL && root->Right != NULL)
			{
				TNode* Mini_Number = Minimum(root);
				TNode* Mini_Parents = Get_Parent(Mini_Number->Data);
				if (Mini_Number->Right != NULL)
				{
					Mini_Parents->Left = Mini_Number->Right;
					if (Parents->Right == root)
					{
						Mini_Number->Left = root->Left;
						Mini_Number->Right = root->Right;
						Parents->Right = Mini_Number;
					}
					else
					{
						Mini_Number->Left = root->Left;
						Mini_Number->Right = root->Right;
						Parents->Left = Mini_Number;
					}
				}
				else
				{
					Mini_Parents->Left = NULL;
					if (Parents->Right == root)
					{
						Mini_Number->Left = root->Left;
						Mini_Number->Right = root->Right;
						Parents->Right = Mini_Number;
					}
					else
					{
						Mini_Number->Left = root->Left;
						Mini_Number->Right = root->Right;
						Parents->Left = Mini_Number;
					}
				}
			}
			else
			{
				if (Parents->Left == root)
				{
					if (root->Left != NULL)
					{
						Parents->Left = root->Left;
						delete root;
					}
					else
					{
						Parents->Left = root->Right;
						delete root;
					}
				}
				else if (Parents->Right == root)
				{
					if (root->Left != NULL)
					{
						Parents->Right = root->Left;
						delete root;
					}
					else
					{
						Parents->Right = root->Right;
						delete root;
					}
				}

			}
		}
		else
		{
			Delete_Node(root->Right, value);
		}
	}
}
// Function Overloading
void BST::Delete_Node(int value)
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
	}
	else
		Delete_Node(Root, value);
}
// Count Nodes
void BST::Count_Nodes(TNode* root, int &value)
{
	if (root != NULL)
	{
		value++;
		Count_Nodes(root->Left, value);
		Count_Nodes(root->Right, value);
	}
}
// Function Overloading
void BST::Count_Nodes()
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
	}
	else
	{
		int V = 0;
		Count_Nodes(Root, V);
		cout << "Total Nodes = " << V << endl;
	}
}
// Function to search a node
void BST::traverse(TNode* root, int value)
{
	if (Empty())
	{
		cout << "Empty Tree" << endl;
	}
	else
	{
		cout << " " << root->Data;
		if (root == NULL)
		{
			cout << "Value not found" << endl;
		}
		else if (value == root->Data)
		{

		}
		else if (value <= root->Data)
		{
			traverse(root->Left, value);
		}
		else if (value > root->Data)
		{
			traverse(root->Right, value);
		}
	}
}
// Function overloading
void BST::traverse(int value)
{
	traverse(Root, value);
}
int BST:: get_sibiling(TNode* root, int value)
{
	TNode *temp=new TNode;
	if (root == NULL)
	{
		cout << "Value not found" << endl;
	}
	else if (value == root->Data)
	{
		temp= Get_Parent(root->Data);
		if (temp->Left->Data == root->Data)
		{
			return temp->Right->Data;
		}
		else
		{
			return temp->Left->Data;
		}
	}
	else if (value <= root->Data)
	{
		get_sibiling(root->Left, value);
	}
	else if (value > root->Data)
	{
		get_sibiling(root->Right, value);
	}
}