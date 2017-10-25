#include "stdafx.h"
#include "Tree.h"


template<class T>
void Tree<T>::copyTree(const Tree<T>& other)
{
	copy(root, other.root);
}

template<class T>
void Tree<T>::copy(node<T>*& pos, node<T>* const& other) const
{
	pos = nullptr;
	if (other)
	{
		pos = new node<T>;
		assert(pos != nullptr);
		pos->inf = other->inf;
		copy(pos->left, other->left);
		copy(pos->right, other->right);
	}
}

template<class T>
void Tree<T>::deleteTree(node<T>*& pos) const
{
	if (pos)
	{
		deleteTree(pos->left);
		deleteTree(pos->right);
		delete pos;
		pos = nullptr;
	}
}

template<class T>
void Tree<T>::pr(const node<T>* pos) const
{
	if (pos)
	{
		pr(pos->left);
		std::cout << pos->inf << " ";
		pr(pos->right);
	}
}

template<class T>
void Tree<T>::createTree(node<T>*& pos) const
{
	T x;
	char c;
	std::cout << "root: ";
	std::cin >> x;
	pos = new node<T>;
	assert(pos != nullptr);
	pos->inf = x;
	pos->left = nullptr;
	pos->right = nullptr;
}

template<class T>
Tree<T>::Tree()
{
	root = nullptr;
}
template<class T>
Tree<T>::~Tree()
{
	deleteTree(root);
}

template<class T>
Tree<T>::Tree(const Tree &other)
{
	copyTree(other);
}

template<class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other)
{
	if (this != &other)
	{
		deleteTree(root);
		copyTree(other);
	}
	return *this;
}

template<class T>
bool Tree<T>::empty() const
{
	return root == nullptr;
}

template<class T>
node<T>* Tree<T>::getRoot() const
{
	return root;
}

template<class T>
T Tree<T>::rootTree() const
{
	return root->inf;
}

template<class T>
Tree<T> Tree<T>::leftTree() const
{
	Tree<T> leftTree;
	copy(leftTree.root, root->left);
	return leftTree;
}

template<class T>
Tree<T> Tree<T>::rightTree() const
{
	Tree<T> rightTree;
	copy(rightTree.root, root->right);
	return rightTree;
}

template<class T>
void Tree<T>::addDirections(std::string direction)
{
	node<T>* pos = root;
	while (!direction.empty())
	{

		assert(direction[0] == 'L' || direction[0] == 'R');
		if (direction[0] == 'L')
		{
			if (pos->left == nullptr)
			{
				createTree(pos->left);
			}
			pos = pos->left;
		}
		else if (direction[0] == 'R')
		{
			if (pos->right == nullptr)
			{
				createTree(pos->right);
			}
			pos = pos->right;
		}
		

		direction = direction.substr(1);

	}
}




