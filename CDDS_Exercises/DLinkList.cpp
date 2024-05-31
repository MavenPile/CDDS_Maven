#include "DLinkList.h"

void DLinkList::PushFront(float value)
{
	Node* newNode = new Node(value);	//	create a new node
	newNode->m_next = m_head->GetNode();	//	new node points to current head
	m_head->SetNode(newNode);	//	current head points to new node

	if (nullptr == m_tail->GetNode())	//	if there was no tail
	{
		m_tail->SetNode(newNode);	//	current tail becomes new node
	}
}

void DLinkList::PushBack(float value)
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

void DLinkList::InsertAfter(Iterator* iterator, float value)
{
	Node* newNode = new Node(value);


}

DLinkList::Iterator DLinkList::Begin()
{
	return Iterator();
}

DLinkList::Iterator DLinkList::End()
{
	return Iterator();
}

float DLinkList::First()
{
	return m_head->GetData();
}

float DLinkList::Last()
{
	return m_tail->GetData();
}

int DLinkList::Count()
{
	int count = 0;
	
	Iterator iter(m_head);	//	an iterator to move through the list

	return p_Counting(&iter, count);
}

int DLinkList::p_Counting(Iterator* iter, int& count)
{
	count += 1;	//	increase list count

	if (nullptr != iter->GetNode()->m_next)
	{
		iter++;	//	move iterator to next point in list
		
		p_Counting(iter, count);	//	repeat
	}

	return count;
}

void DLinkList::Erase(Iterator* iterator)
{

}

void DLinkList::Remove(float value)
{
	Iterator iter(m_head);

	p_RemoveNext(&iter, value);
}

void DLinkList::p_RemoveNext(Iterator* iter, float value)
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

void DLinkList::PopBack()
{
	m_tail->SetNode(m_tail->GetNode()->m_prev);	//	move current tail back one
	delete m_tail->GetNode()->m_next;	//	delete previous tail
}

void DLinkList::PopFront()
{
	//	same as PopBack() but for the head

	m_head->SetNode(m_head->GetNode()->m_next);
	delete m_head->GetNode()->m_prev;
}

bool DLinkList::IsEmpty()
{
	Iterator iter(m_head);
	
	if (p_CheckEmpty(&iter))
	{
		return true;
	}

	return false;
}

bool DLinkList::p_CheckEmpty(Iterator* iter)
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

void DLinkList::Clear()
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