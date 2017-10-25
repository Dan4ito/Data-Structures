#pragma once
#include <cassert>
#include <string>

template<class T>
struct node {
	T inf;
	node* left;
	node* right;
};

template<class T = int>
class Tree
{
private:
	node<T>* root;
	void copyTree(const Tree<T>&);								// creates a copy of a tree, pointed by pointer 'this'
	void copy(node<T>*&, node<T>* const &) const;
	void deleteTree(node<T>*&) const;
	void pr(const node<T>*) const;
	void createTree(node<T>*&) const;

public:
	Tree();														// cannonical four
	~Tree();
	Tree(const Tree&);
	Tree& operator=(const Tree&);
	bool empty() const;											// checks whether tree is empty
	node<T>* getRoot() const;									// returns the root
	T rootTree() const;											// finds the root's data
	Tree leftTree() const;										// finds the left subTree
	Tree rightTree() const;										// finds the right subTree
	void print() const
	{
		pr(root);
	}
	void create() {
		createTree(root);
	}
	void addDirections(std::string direction);					// builds nodes

};




