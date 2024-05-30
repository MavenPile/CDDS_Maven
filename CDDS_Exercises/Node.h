#pragma once

class Node
{
public:
	//	VARIABLES

	int m_data;
	Node* m_previous;
	Node* m_next;

	//	CONSTRUCTORS

	Node();
	Node(int value);
	~Node();
};