#pragma once
#include<iostream>
using namespace std;
class List
{
private:
	
	struct node {
	int data;
	node *next;
	};
	int size = 0;
	node *head;	// pointer to the first node
	node *curr;	// pointer to the current node
	node *temp;	// pointer to the previous of the current node
	
public:
	List();
	void addNode(int addData);	// adds a node at the end
	void deleteNode(int delData);	// search for a node with data = delData and delete it
	void print();

	friend int count(List * l, int x);
	List *range(int x, int y);	// creates a ranged list (first element is with index 1)
	friend void removeAll(List *& l, int x);	 // deletes all nodes with data = x
	friend void append(List *& l1, List *& l2);	 // appends two lists
	friend List *concat(List * l1, List * l2);	 // concatinates two lists and creates a new one
	int map(int position);	// returns the integer data of a position (first element is with index 1)
	void reverse();	// reverses the elements of a list
	friend  bool duplicates(List *l);
	friend void removeduplicates(List *&l);
	friend bool issorted(List *l);
	friend bool palindrom(List *l);
};

