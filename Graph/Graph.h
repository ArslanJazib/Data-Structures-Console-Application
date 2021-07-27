#pragma once
#include"AdjList.h"
#include"AdjListNode.h"
class Graph
{
public:
	int vertices;
	AdjList* arr;
	Graph(int V);
	AdjListNode* newAdjListNode(int d);
	void addEdge(int src, int dest);
	AdjListNode* createNode(int);
	void printGraph();
};
