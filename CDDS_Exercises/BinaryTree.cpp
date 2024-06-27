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
	if (m_pRoot == nullptr)
	{
		m_pRoot->SetData(a_nValue);
	}
	else
	{
		TreeNode* currentNode = new TreeNode(m_pRoot->GetData());
		TreeNode* prevNode = m_pRoot;

		while (currentNode != nullptr)
		{
			prevNode = currentNode;

			if (a_nValue < currentNode->GetData())
			{
				currentNode = &currentNode->GetLeft();

				if (currentNode == nullptr)
				{
					prevNode->SetLeft(*currentNode);
				}

				continue;
			}
			else if (a_nValue > currentNode->GetData())
			{
				currentNode = &currentNode->GetRight();

				if (currentNode == nullptr)
				{
					prevNode->SetRight(*currentNode);
				}

				continue;
			}
			else if (a_nValue == currentNode->GetData())
			{
				break;
			}
		}

		currentNode->SetData(a_nValue);
	}
}

void BinaryTree::Remove(int a_nValue)
{

}

TreeNode& BinaryTree::Find(int a_nValue)
{
	TreeNode* foundNode;

	FindNode(a_nValue, foundNode, foundNode);

	return *foundNode;
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
	TreeNode* currentNode = m_pRoot;
	TreeNode* prevNode = m_pRoot;

	while (currentNode != nullptr)
	{		
		if (a_nSearchValue < currentNode->GetData())
		{
			prevNode = currentNode;
			
			currentNode = &currentNode->GetLeft();

			if (currentNode == nullptr)
			{
				prevNode->SetLeft(*currentNode);
			}
		}
		else if (a_nSearchValue > currentNode->GetData())
		{
			prevNode = currentNode;
			
			currentNode = &currentNode->GetRight();

			if (currentNode == nullptr)
			{
				prevNode->SetRight(*currentNode);
			}
		}
		else if (currentNode->GetData() == a_nSearchValue)
		{
			ppOutNode = currentNode;
			ppOutParent = currentNode;
			return true;
		}
	}

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