#include "Node.h"

Node::Node()
{
	m_data = 0;
	m_previous = nullptr;
	m_next = nullptr;
}

Node::Node(int value)
{
	m_data = value;
	m_previous = nullptr;
	m_next = nullptr;
}

Node::~Node()
{

}
