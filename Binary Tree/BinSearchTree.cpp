#include "stdafx.h"
#include "BinSearchTree.h"


void BinSearchTree::destroy_tree(TreeNode * _root)
{
	if (_root != nullptr)
	{
		destroy_tree(_root->left);
		destroy_tree(_root->right);
		delete _root;
	}
}

void BinSearchTree::insert(int key, TreeNode *& _root)
{
	if (_root == nullptr)
	{
		_root = new TreeNode(key);
	}
	else
	{
		if (key > _root->data)
		{
			insert(key, _root->right);
		}
		else if (key <= _root->data)
		{
			insert(key, _root->left);
		}
	}
}

TreeNode* BinSearchTree::copy_from(const TreeNode * crr)
{
	if (crr == nullptr)
	{
		return nullptr;
	}
	else
	{
		return new TreeNode(crr->data, copy_from(crr->left), copy_from(crr->right));
	}
}

TreeNode * BinSearchTree::search(int key, TreeNode *& _root)
{
	if (_root != nullptr)
	{
		if (_root->data == key)
		{
			return _root;
		}
		else if (key >= _root->data)
		{
			search(key, _root->right);
		}
		else if (key < _root->data)
		{
			search(key, _root->left);
		}
	}
	else return nullptr;
}

void BinSearchTree::insert(int key)
{
	insert(key, root);
}

TreeNode * BinSearchTree::search(int key)
{
	return search(key, root);
}



void BinSearchTree::destroy_tree()
{
	destroy_tree(root);
}

BinSearchTree::BinSearchTree()
{
	root = nullptr;
}

BinSearchTree::BinSearchTree(const BinSearchTree & other)
{
	root = copy_from(other.root);
}

BinSearchTree & BinSearchTree::operator=(const BinSearchTree & other)
{
	if (this == &other)
	{
		return *this;
	}
	else
	{
		destroy_tree();
		root = copy_from(other.root);
	}
}

bool BinSearchTree::compare(const TreeNode * crr1, const TreeNode * crr2)
{
	if (crr1 == nullptr)
		return crr2 == nullptr;
	if (crr2 == nullptr)
		return crr1 == nullptr;
	return (crr1->data == crr2->data) && compare(crr1->left, crr2->left) && compare(crr1->right, crr2->right);
}

bool BinSearchTree::operator==(const BinSearchTree & other) 
{
	return compare(root, other.root);
}

int& BinSearchTree::getmin(TreeNode* crr)
{
	while (crr->left != nullptr)
	{
		crr = crr->left;
	}
	return crr->data;
}


TreeNode* BinSearchTree::removeFromSubtree(const int &x, TreeNode *crr)
{
	//1
	if (crr == nullptr)
		return nullptr;

	//2
	if (crr->data == x && crr->left == nullptr)
	{
		TreeNode *save = crr->right;
		delete crr;
		return save;
	}
	//3
	if (crr->data == x && crr->right == nullptr)
	{
		TreeNode *save = crr->left;
		delete crr;
		return save;
	}
	//4
	if (crr->data == x)
	{
		int rightmin = BinSearchTree::getmin(crr->right);
		crr->data = rightmin;
		crr->right = removeFromSubtree(rightmin, crr->right);
		crr = removeFromSubtree(x, crr);
		return crr;

	}
	//5, 6
	if (crr->data < x)
	{
		crr->right = removeFromSubtree(x, crr->right);
	}
	else {
		crr->left = removeFromSubtree(x, crr->left);
	}

	return crr;

}

int  BinSearchTree::count(TreeNode * crr)
{
	int value = 1;
	if (crr == nullptr) return 0;
	else
	{
		value = value + count(crr->left) + count(crr->right);
		return value;
	}
}

int BinSearchTree::countEvens(TreeNode * crr)
{
	int value;
	if (crr == nullptr) return 0;
	if (crr->data % 2 == 0) {
		value = 1;
	}
	else {
		value = 0;
	}
	
	value = value + countEvens(crr->left);
	value = value + countEvens(crr->right);
	return value;
}

int BinSearchTree::height(TreeNode * crr)
{
	if (crr == nullptr) {
		return -1;
	}

	int lefth = height(crr->left);
	int righth = height(crr->right);

	if (lefth > righth) {
		return lefth + 1;
	}
	else {
		return righth + 1;
	}
}

int BinSearchTree::countLeaves(TreeNode * crr)
{
	int leavesCounter = 0;
	if (crr == nullptr) return 0;
	if (crr->left == nullptr && crr->right == nullptr) return 1;
	else
	{
		return leavesCounter = leavesCounter + countLeaves(crr->left) + countLeaves(crr->right);
	}
}

TreeNode * BinSearchTree::maxLeaf(TreeNode * crr)
{
	if (crr == nullptr) return nullptr;
	while (crr->right != nullptr)
	{
		crr = crr->right;
	}
	return crr;
}

std::vector<int>& BinSearchTree::leavesValues(TreeNode * crr, std::vector<int>& values)
{	
	if (crr == nullptr) return values;
	if (crr->left == nullptr && crr->right == nullptr)
	{
		values.push_back(crr->data);
	}
	else
	{
		leavesValues(crr->left, values);
		leavesValues(crr->right, values);
	}
	return values;
}

std::vector<int>& BinSearchTree::level(TreeNode * crr, std::vector<int>& values, int k)
{
	if (crr == nullptr) return values;
	if (k == 0)
	{
		values.push_back(crr->data);
	}
	else
	{
		level(crr->left, values , k-1);
		level(crr->right, values , k-1);
	}
	return values;
}

void BinSearchTree::deleteFromSubtree(const int & x)
{
	root = removeFromSubtree(x, root);
	
}

int BinSearchTree::count()
{
	return count(root);
}

int BinSearchTree::countEvens()
{
	return countEvens(root);
}

int BinSearchTree::height()
{
	return height(root);
}

int BinSearchTree::countLeaves()
{
	return countLeaves(root);
}

TreeNode * BinSearchTree::maxLeaf()
{
	return maxLeaf(root);
}

std::vector<int> BinSearchTree::leavesValues()
{
	std::vector<int> values;
	return leavesValues(root, values);

}

std::vector<int> BinSearchTree::level(int k)
{
	std::vector<int> values;
	return level(root, values, k);
}





BinSearchTree::~BinSearchTree()
{
	destroy_tree();
}
