#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;
}

LinkedList::~LinkedList()
{

}

void LinkedList::PushFront(int value)
{
	Node newNode(value);
	newNode.m_next = m_head;
	m_head->m_previous = &newNode;
	m_head = &newNode;
}

void LinkedList::PushBack(int value)
{
	Node newNode(value);
	newNode.m_previous = m_tail;
	m_tail->m_next = &newNode;
	m_tail = &newNode;
}

void LinkedList::InsertAfter(Node* iterator, int value)
{
	Node newNode(value);

	iterator->m_next->m_previous = &newNode;
	newNode.m_next = iterator->m_next->m_previous;

	newNode.m_previous = iterator;
	iterator->m_next = &newNode;
}

Node* LinkedList::Begin()
{
	return m_head;
}

Node* LinkedList::End()
{
	return m_tail;
}

int LinkedList::First()
{
	return m_head->m_data;
}

int LinkedList::Last()
{
	return m_tail->m_data;
}

int LinkedList::Count()
{
	return 0;
}

int* LinkedList::Counting(Node* iterator, int* count)
{
	count += 1;
	
	if (iterator->m_next != nullptr)
	{

	}
}

void LinkedList::Erase(Node* iterator)
{
	iterator->m_previous = iterator->m_next;
	iterator->m_next = iterator->m_previous;
}

void LinkedList::Remove(int value)
{
	RemoveNext(*m_head, value);
}

void LinkedList::RemoveNext(Node& iterator, int value)
{
	Node next = *iterator.m_next;
	
	if (value == iterator.m_data)
	{
		Erase(&iterator);
	}

	RemoveNext(next, value);
}

void LinkedList::PopBack()
{
	m_tail->m_previous->m_next = nullptr;
}

void LinkedList::PopFront()
{
	m_head->m_next->m_previous = nullptr;
}

bool LinkedList::IsEmpty()
{
	if (CheckEmpty(*m_head->m_next))
	{
		return false;
	}

	return true;
}

bool LinkedList::CheckEmpty(Node& iterator)
{
	if (&iterator.m_data != nullptr)
	{
		return true;
	}
	else if (CheckEmpty(*iterator.m_next))
	{
		return false;
	}
}

void LinkedList::Clear()
{
	m_head = nullptr;
	m_tail = nullptr;
}