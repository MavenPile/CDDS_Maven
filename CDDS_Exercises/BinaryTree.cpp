#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib-cpp.hpp"

BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::IsEmpty() const
{
	return m_pRoot == nullptr;
}

void BinaryTree::Insert(int a_nValue)
{
	if (m_pRoot != nullptr)
	{
		TreeNode* currentNode = m_pRoot;

		while (currentNode != nullptr)
		{
			if (a_nValue < currentNode->GetData())
			{
				currentNode = &currentNode->GetLeft();
			}
			else if (a_nValue > currentNode->GetData())
			{
				currentNode = &currentNode->GetRight();
			}
			else if (a_nValue == currentNode->GetData())
			{
				break;
			}
		}
	}
	else
	{
		m_pRoot->SetData(a_nValue);
	}


	
	if (m_pRoot != nullptr)
	{
		if (a_nValue < m_pRoot->GetData())
		{

		}
	}
	else
	{

	}
}

void BinaryTree::Remove(int a_nValue)
{
}

TreeNode& BinaryTree::Find(int a_nValue)
{
	// TODO: insert return statement here
}

void BinaryTree::PrintOrdered()
{
}

void BinaryTree::PrintUnordered()
{
}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	return false;
}

void BinaryTree::PrintOrderedRecurse(TreeNode*)
{
}

void BinaryTree::PrintUnorderedRecurse(TreeNode*)
{
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			Draw(&pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			Draw(&pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		pNode->Draw(x, y, (selected == pNode));
	}
}