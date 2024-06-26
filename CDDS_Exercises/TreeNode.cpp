#include "TreeNode.h"
#include "raylib-cpp.hpp"

TreeNode::TreeNode(int value)
{
	m_value = value;
	m_left = nullptr;
	m_right = nullptr;
}

TreeNode::~TreeNode()
{
}

bool TreeNode::HasLeft()
{
	return m_left != nullptr;
}

bool TreeNode::HasRight()
{
	return m_right != nullptr;
}

int TreeNode::GetData()
{
	return m_value;
}

TreeNode& TreeNode::GetLeft()
{
	return *m_left;
}

TreeNode& TreeNode::GetRight()
{
	return *m_right;
}

void TreeNode::SetData(int value)
{
	m_value = value;
}

void TreeNode::SetLeft(TreeNode& node)
{
	m_left = &node;
}

void TreeNode::SetRight(TreeNode& node)
{
	m_right = &node;
}

void TreeNode::Draw(int x, int y, bool selected)
{
	static char buffer[10];

	sprintf(buffer, "%d", m_value);

	DrawCircle(x, y, 30, YELLOW);

	if (selected == true)
	{
		DrawCircle(x, y, 28, GREEN);
	}
	else
	{
		DrawCircle(x, y, 28, BLACK);
	}

	DrawText(buffer, x - 12, y - 10, 12, WHITE);
}
