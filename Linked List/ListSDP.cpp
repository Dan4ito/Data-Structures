// ListSDP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	List *obj = new List;
	obj->addNode(3);
	obj->addNode(5);
	obj->addNode(7);
	obj->print();	// adding three nodes and print

	
	obj->deleteNode(3);
	obj->print();	// delete one node and print

	cout << count(obj, 5) << endl;	// count and print

	obj->addNode(3);
	obj->addNode(5);
	obj->addNode(7);
	obj->print();	// add three nodes again and print
	List *rangedList = obj->range(1, 5);
	rangedList->print();	// create and print ranged list

	removeAll(obj, 7);
	obj->print();	// deleting all nodes with data = 7 and then print
	
	append(obj, rangedList);
	obj->print();	// append and then print

	List *concatList = new List;
	concatList = concat(obj, rangedList);
	concatList->print();	// concatinate and then print

	cout << concatList->map(5) << endl;	// print the fifth element
	
	concatList->reverse();
	concatList->print();	// reverse and print

	cout << duplicates(concatList) <<endl;	// check for duplicates

	concatList->addNode(123);
	removeduplicates(concatList);	// check for duplicates
	concatList->print();

	List *obj1 = new List;
	obj1->addNode(6);
	obj1->addNode(4);
	obj1->addNode(5);
	obj1->addNode(4);
	obj1->addNode(6);


	obj1->print();	// adding three nodes and print
	cout << issorted(obj1) << endl;

	cout << palindrom(obj1) << endl;	// printing if it's a palindrome

	



    return 0;
}

