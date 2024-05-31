#include "DLinkList.h"

template<typename T>
void DLinkList<T>::PushFront(T value)
{
	Node* newNode = new Node(value);	//	create a new node
	newNode->m_next = m_head->GetNode();	//	new node points to current head
	m_head->SetNode(newNode);	//	current head points to new node

	if (nullptr == m_tail->GetNode())	//	if there was no tail
	{
		m_tail->SetNode(newNode);	//	current tail becomes new node
	}
}

template<typename T>
void DLinkList<T>::PushBack(T value)
{
	//	Same as PushFront(), but on the tail instead

	Node* newNode = new Node(value);
	newNode->m_prev = m_tail->GetNode();
	m_tail->SetNode(newNode);

	if (nullptr == m_head->GetNode())
	{
		m_head->SetNode(newNode);
	}
}

template<typename T>
void DLinkList<T>::InsertAfter(Iterator* iterator, T value)
{
	Node* newNode = new Node(value);


}

template<typename T>
DLinkList<T>::Iterator* DLinkList<T>::Begin()
{
	return m_head;
}

template<typename T>
DLinkList<T>::Iterator* DLinkList<T>::End()
{
	return m_tail;
}

template<typename T>
T DLinkList<T>::First()
{
	return m_head->GetData();
}

template<typename T>
T DLinkList<T>::Last()
{
	return m_tail->GetData();
}

template<typename T>
int DLinkList<T>::Count()
{
	int count = 0;
	
	Iterator iter(m_head);	//	an iterator to move through the list

	return p_Counting(&iter, count);
}

template<typename T>
int DLinkList<T>::p_Counting(Iterator* iter, int& count)
{
	count += 1;	//	increase list count

	if (nullptr != iter->GetNode()->m_next)
	{
		iter++;	//	move iterator to next point in list
		
		p_Counting(iter, count);	//	repeat
	}

	return count;
}

template<typename T>
void DLinkList<T>::Erase(Iterator* iter)
{
	Iterator temp(iter);

	iter->GetNode()->m_next->m_prev = iter->GetNode()->m_prev->m_next;	//	set the next node's previous pointer to previous node
	iter->GetNode()->m_prev->m_next = iter->GetNode()->m_next->m_prev;	//	set the previous node's next point to next node

	delete temp.GetNode();
}

template<typename T>
void DLinkList<T>::Remove(T value)
{
	Iterator iter(m_head);

	p_RemoveNext(&iter, value);
}

template<typename T>
void DLinkList<T>::p_RemoveNext(Iterator* iter, T value)
{
	Iterator temp(iter);
	
	if (iter->GetData() == value)	//	if data at iterator matches
	{
		delete iter->GetNode();	//	delete the node at the iterator
	}

	if (nullptr != iter->GetNode()->m_next)
	{
		temp++;

		p_RemoveNext(&temp, value);
	}
}

template<typename T>
void DLinkList<T>::PopBack()
{
	m_tail->SetNode(m_tail->GetNode()->m_prev);	//	move current tail back one
	delete m_tail->GetNode()->m_next;	//	delete previous tail
}

template<typename T>
void DLinkList<T>::PopFront()
{
	//	same as PopBack() but for the head

	m_head->SetNode(m_head->GetNode()->m_next);
	delete m_head->GetNode()->m_prev;
}

template<typename T>
bool DLinkList<T>::IsEmpty()
{
	Iterator iter(m_head);
	
	if (p_CheckEmpty(&iter))
	{
		return true;
	}

	return false;
}

template<typename T>
bool DLinkList<T>::p_CheckEmpty(Iterator* iter)
{
	if (0.f != iter->GetNode()->m_data)
	{
		return false;
	}
	
	iter++;

	if (p_CheckEmpty(iter))
	{
		return true;
	}
}

template<typename T>
void DLinkList<T>::Clear()
{
	Iterator iter(m_head);

	while (m_tail != nullptr)
	{
		Iterator temp(iter);

		if (nullptr == iter.GetNode())
		{
			delete iter.GetNode();
		}

		iter++;
	}

	m_head = nullptr;
	m_tail = nullptr;
}