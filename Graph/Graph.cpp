#include<iostream>
#include"Graph.h"
using namespace std;
// Constructor
Graph::Graph(int vertices)
{
	this->vertices = vertices;
	arr = new AdjList[vertices];
	for (int i = 0; i < vertices; i++)
	{
		arr[i].head = NULL;
	}
}
// Creating New Node
AdjListNode* Graph::createNode(int d)
{
	AdjListNode *node = new AdjListNode;
	node->dest = d;
	node->next = NULL;
	return node;
}
// Creating node in the list with a value
AdjListNode* Graph::newAdjListNode(int dest)
{
	AdjListNode* newNode = new AdjListNode;
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}
// Add	Edge
void Graph::addEdge(int source, int dest)
{
	AdjListNode *newNode = newAdjListNode(dest);
	newNode->next = arr[source].head;
	arr[source].head = newNode;

	newNode = newAdjListNode(source);
	newNode->next = arr[dest].head;
	arr[dest].head = newNode;

}
//Printing Graph
void Graph:: printGraph()
{
	int x;
	for (x = 0; x < vertices; x++)
	{
		AdjListNode *temp = arr[x].head;
		cout << "Vertix = " << x << endl;
		while (temp!=NULL)
		{
			cout << temp->dest;
			cout << ",";
			temp = temp->next;
		}
		cout << endl;
	}
}