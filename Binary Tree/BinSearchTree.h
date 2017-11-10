#pragma once
#include <vector>

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(const int& _data, TreeNode *_left = nullptr, TreeNode *_right = nullptr) : data(_data), left(_left), right(_right) {}
};

class BinSearchTree
{
private:


	TreeNode* root;

	void destroy_tree(TreeNode *_root);
	void insert(int key, TreeNode *&_root);
	TreeNode* copy_from(const TreeNode *crr);
	TreeNode* search(int key, TreeNode *&_root);
	TreeNode* removeFromSubtree(const int &x, TreeNode* crr);

	int count(TreeNode* crr);
	int countEvens(TreeNode* crr);
	int height(TreeNode* crr);
	int countLeaves(TreeNode* crr);
	TreeNode* maxLeaf(TreeNode* crr);
	std::vector<int>& leavesValues(TreeNode* crr, std::vector<int>& values);
	std::vector<int>& level(TreeNode* crr, std::vector<int>& values, int k);

public:

	void insert(int key);
	TreeNode* search(int key);
	void destroy_tree();
	bool compare(const TreeNode *crr1, const TreeNode *crr2);
	bool operator == (const BinSearchTree &other);
	static int& getmin(TreeNode* crr);
	void deleteFromSubtree(const int &x);

	//
	int count();
	int countEvens();
	int height();
	int countLeaves();
	TreeNode* maxLeaf();
	std::vector<int> leavesValues();
	std::vector<int> level(int k);
	//

	BinSearchTree();
	BinSearchTree(const BinSearchTree &other);
	BinSearchTree& operator= (const BinSearchTree &other);
	~BinSearchTree();
};

