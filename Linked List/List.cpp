#include "stdafx.h"
#include "List.h"


List::List()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::addNode(int addData)
{
	node *newptr = new node;
	newptr->next = NULL;	// setting this to be the last node of the list
	newptr->data = addData;
	
	if (head != NULL){	// if we already have a list
		curr = head;
		while (curr->next != NULL)	// we go at the last node of the list
		{
			curr = curr->next;
		}
		curr->next = newptr;	// we set the last node to point at the newly created node
	}
	else{	// basically we tell the new node to be the first one
		head = newptr;
	}
	size++;
}

void List::deleteNode(int delData)
{
	node *delptr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data!=delData) {	// if we are at the end, we stop or if we find the node we want to delete
		temp = curr;
		curr = curr->next;	// we keep temp one step behind curr
	}
	if (curr == NULL) {		// we gotta check which case was it
		delete delptr;	// avoid garbage
	}
	else{
		delptr = curr;
		curr = curr->next;	// we connect the adjacent nodes
		temp->next = curr;
		
		if (delptr == head) {	// we do this check because if we get rid of the first node, the whole list breaks
			head = delptr->next;
			temp = NULL;	// if we want to delete the first element, we just make the head to point at the second node
		}
		delete delptr;
		size--;
	}
}

void List::print()
{
	if (size == 0)	// we do this check because of the invalid input of range function
	{
		cout << "Empty list";
	}
	else
	{
		curr = head;	// make the curr pointer to point at the start of the list
		while (curr != NULL)
		{
			cout << curr->data << "  ";
			curr = curr->next;

		}
	}
	curr = head;	// if we have a f
	cout << endl;

}

List * List::range(int x, int y)
{
	List *rangedList = new List;
	if (y >= x && (x > 0 && y <= size))
	{
		curr = head;
		for (int i = 0; i < x - 1; i++)		// we skip the first x nodes
		{
			curr = curr->next;
		}
		for (int i = 0; i < y - x + 1; i++)		// and then we add from the xth position to y-x+1
		{
			rangedList->addNode(curr->data);	// the new list is linked because addNote function links them !
			curr = curr->next;
			rangedList->size++;
		}		
	}
	return rangedList;
}


int List::map(int position)
{
	if (position < 1)	// a check for invalid position
	{
		return 404;	// not found :D
	}
	curr = head;
	position--;	// we do this because start from the first element so we need to do one less step from now
	while (curr != NULL && position > 0)	// we go to the end or to the exact position
	{
		curr = curr->next;
		position--;

	}
	if (curr == NULL)	// the list has less nodes than position value
	{
		return 404;	// not found :D
	}
	else   // we are at the correct spot, so we return
	{
		return curr->data;
	}
	
}

void List::reverse()
{
	node *prev, *next;	// prev for previous node, next for next node
	curr = head;
	prev = NULL;	// because the first elements is going to be last, so points to NULL
	next = curr;
	while (curr != NULL)
	{
		next = curr->next;	// next pointer goes 1 step ahead
		curr->next = prev;	// then we switch the pointer of the first element to prev
		prev = curr;	// we change the previous element to go one ahead 
		curr = next;	// then we change the current element to the next node
	}
	head = prev;	// because we need a new starting point
}


int count(List * l, int x)
{
	l->curr = l->head;	// make the curr pointer to point at the start of the list
	int counter = 0;
	while (l->curr != NULL)
	{
		if (l->curr->data == x)
		{
			counter++;	// we go through the whole linked list and increase counter if we have matching values
		}
		l->curr = l->curr->next;
	}
	return counter;
}

void removeAll(List *& l, int x)	// seach for matching node and carefully delete it
{
	l->curr = l->head;
	while (l->curr != NULL) {
		if (l->curr->data == x)
		{
			l->deleteNode(x);
		}
		else
		{
			l->curr=l->curr->next;
		}
	}
}

void append(List *& l1, List *& l2)		// basically we search the last node of l1 and point it to the start of l2
{
	l1->curr = l1->head;
	l2->curr = l2->head;
	while (l1->curr->next != NULL)
	{
		l1->curr = l1->curr->next;
	}
	l1->curr->next = l2->curr;
	l1->size = l1->size + l2->size;
}

List * concat(List * l1, List * l2)		// go through the first list and the second list, building the new list
{
	List *concatList = new List;

	l1->curr = l1->head;
	l2->curr = l2->head;
	while (l1->curr->next != NULL)
	{
		concatList->addNode(l1->curr->data);
		l1->curr = l1->curr->next;
	}
	while (l2->curr->next != NULL)
	{
		concatList->addNode(l2->curr->data);
		l2->curr = l2->curr->next;
	}
	l1->size = l1->size + l2->size;

	return concatList;
}

bool duplicates(List * l)	// for every node, run through the whole list O(n^2) algorithm
{
	l->curr = l->head;
	l->temp = l->head;
	for (int i = 0; i < l->size; i++)
	{
		for (int k = 0; k < l->size; k++)
		{
			if (l->curr->data == l->temp->data && l->curr!=l->temp) return true;
			l->temp = l->temp->next;
		}
		l->curr = l->curr->next;
		l->temp = l->head;	// resetting temp = head for the new iteration
	}
	return false;
}

void removeduplicates(List *& l)
{
	l->curr = l->head;
	l->temp = l->head;
	while(l->curr != NULL)
	{
		while(l->temp!=NULL)
		{
			if (l->curr->data == l->temp->data && l->curr != l->temp)	// we first get a node, and search for a node with same data
			{
				removeAll(l,l->temp->data);	// if there is a match we delete all the nodes in the list with this data
				l->curr = l->head;	// we reset everything like we start the operation again
				l->temp = l->head;				
			}
			if (l->size == 0) return;	// we do this check becouse if the list is empty, we can't get NULL->next
			l->temp = l->temp->next;
		}

		l->curr = l->curr->next;
		l->temp = l->head;	// resetting temp = head for the new iteration
	}

}

bool issorted(List * l)
{
	l->curr = l->head;	
	while (l->curr->next->next != NULL)
	{
		if (l->curr->data == l->curr->next->data)
		{
			l->curr = l->curr->next;
			
		}
		if (l->curr->data > l->curr->next->data)
		{
			while (l->curr->next->next != NULL)
			{
				l->curr = l->curr->next;
				if (l->curr->data < l->curr->next->data) return false;
			}
		}
		if (l->curr->data < l->curr->next->data)
		{
			while (l->curr->next->next != NULL)
			{
				l->curr = l->curr->next;
				if (l->curr->data > l->curr->next->data) return false;
			}
		}
	}
	return true;
}

bool palindrom(List * l)
{
	l->curr = l->head;
	List *lRev = new List;
	while (l->curr != NULL)		// make a copy of the first list
	{
		lRev->addNode(l->curr->data);
		l->curr = l->curr->next;
	}
	lRev->reverse();		// reversing the new list
	l->print();
	lRev->print();

	l->curr = l->head;		// setting the heads at the start
	lRev->curr = lRev->head;	// they are actually always at start, just to be easily understanded

	while (l->curr != NULL)		
	{
		if (l->curr->data != lRev->curr->data) return false;
		l->curr = l->curr->next;
		lRev->curr = lRev->curr->next;
	}
	return true;
}




