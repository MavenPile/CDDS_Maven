#pragma once

class TreeNode
{
private:
	int m_value;

	TreeNode* m_left;
	TreeNode* m_right;

public:
	TreeNode(int value);
	~TreeNode();

	bool HasLeft();
	bool HasRight();

	int GetData();
	TreeNode& GetLeft();
	TreeNode& GetRight();

	void SetData(int value);
	void SetLeft(TreeNode& node);
	void SetRight(TreeNode& node);

	void Draw(int x, int y, bool selected = false);
};