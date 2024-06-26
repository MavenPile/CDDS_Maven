#pragma once

class TreeNode;

class BinaryTree
{
private:
	TreeNode* m_pRoot;

public:
	BinaryTree();
	~BinaryTree();

	bool IsEmpty() const;
	
	void Insert(int a_nValue);
	void Remove(int a_nValue);

	TreeNode& Find(int a_nValue);

	void PrintOrdered();
	void PrintUnordered();

	void Draw(TreeNode* selected = nullptr);

private:
	bool FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent);

	void PrintOrderedRecurse(TreeNode*);
	void PrintUnorderedRecurse(TreeNode*);

	void Draw(TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);
};