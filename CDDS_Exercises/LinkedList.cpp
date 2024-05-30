#include "LinkedList.h"

//	Node METHODS

template<typename T>
LinkedList<T>::Node::Node()
{
	m_data = nullptr, m_previous = nullptr, m_next = nullptr;
}

template<typename T>
LinkedList<T>::Node::Node(T value)
{
	m_data = value, m_previous = nullptr, m_next = nullptr;
}


//	Iterator METHODS

template<typename T>
LinkedList<T>::Iterator::Iterator()
{
	m_currentNode = nullptr;
}

template<typename T>
LinkedList<T>::Iterator::Iterator(Node& node)
{
	m_currentNode = node;
}

template<typename T>
void LinkedList<T>::Iterator::SetNode(Node& newNode)
{
	m_currentNode = newNode;
}

template<typename T>
void LinkedList<T>::Iterator::SetData(T newData)
{
	m_currentNode->m_data = newData;
}

template<typename T>
LinkedList<T>::Node LinkedList<T>::Iterator::GetNode()
{
	return m_currentNode;
}

template<typename T>
T LinkedList<T>::Iterator::GetData()
{
	return m_currentNode->m_data;
}

template<typename T>
T LinkedList<T>::Iterator::Current()
{
	return m_currentNode->m_data;
}

template<typename T>
T LinkedList<T>::Iterator::operator*()
{
	return m_currentNode->m_data;
}

template<typename T>
void LinkedList<T>::Iterator::MoveNext()
{
	m_currentNode = m_currentNode->m_next;
}

template<typename T>
void LinkedList<T>::Iterator::operator ++ (int i)
{
	m_currentNode = m_currentNode->m_next;
}

template<typename T>
void LinkedList<T>::Iterator::MovePrev()
{
	m_currentNode = m_currentNode->m_previous;
}

template<typename T>
void LinkedList<T>::Iterator::operator -- (int i)
{
	m_currentNode = m_currentNode->m_previous;
}

//	LinkedList METHODS

template<typename T>
LinkedList<T>::LinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{

}

template<typename T>
void LinkedList<T>::PushFront(T value)
{
	Node newNode(value);
	newNode.m_next = m_head;
	m_head->m_previous = &newNode;
	m_head = Iterator(newNode);
}

template<typename T>
void LinkedList<T>::PushBack(T value)
{
	Node newNode(value);
	newNode.m_previous = m_tail;
	m_tail->m_next = &newNode;
	m_tail = Iterator(newNode);
}

template<typename T>
void LinkedList<T>::InsertAfter(Iterator* iterator, T value)
{
	Node newNode(value);

	iterator->m_currentNode->m_next->m_previous = &newNode;
	newNode.m_next = iterator->m_next->m_previous;

	newNode.m_previous = iterator;
	iterator->m_next = &newNode;
}

template<typename T>
LinkedList<T>::Iterator LinkedList<T>::Begin()
{
	return m_head;
}

template<typename T>
LinkedList<T>::Iterator LinkedList<T>::End()
{
	return m_tail;
}

template<typename T>
T LinkedList<T>::First()
{
	return m_head->m_data;
}

template<typename T>
T LinkedList<T>::Last()
{
	return m_tail->m_data;
}

template<typename T>
int LinkedList<T>::Count()
{
	int count = 0;

	return p_Counting(m_head, count);
}

template<typename T>
int LinkedList<T>::p_Counting(Iterator& iterator, int& count)
{	
	count += 1;
	
	if (iterator->m_next != nullptr)
	{
		p_Counting(iterator->m_next, count);
	}

	return count;
}

template<typename T>
void LinkedList<T>::Erase(Iterator* iterator)
{
	iterator->m_previous = iterator->m_next;
	iterator->m_next = iterator->m_previous;
}

template<typename T>
void LinkedList<T>::Remove(T value)
{
	p_RemoveNext(*m_head, value);
}

template<typename T>
void LinkedList<T>::p_RemoveNext(Iterator& iterator, T value)
{
	Node next = *iterator.m_next;
	
	if (value == iterator.m_data)
	{
		Erase(&iterator);
	}

	p_RemoveNext(next, value);
}

template<typename T>
void LinkedList<T>::PopBack()
{
	m_tail->m_previous->m_next = nullptr;
}

template<typename T>
void LinkedList<T>::PopFront()
{
	m_head->m_next->m_previous = nullptr;
}

template<typename T>
bool LinkedList<T>::IsEmpty()
{
	if (p_CheckEmpty(*m_head->m_next))
	{
		return false;
	}

	return true;
}

template<typename T>
bool LinkedList<T>::p_CheckEmpty(Iterator& iterator)
{
	if (&iterator.GetNode().m_data != nullptr)
	{
		return true;
	}
	else if (p_CheckEmpty(*iterator.m_next))
	{
		return false;
	}
}

template<typename T>
void LinkedList<T>::Clear()
{
	m_head = nullptr;
	m_tail = nullptr;
}