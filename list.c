/* list.c -- */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Local func prototype */
static void CopyToNode(Car car, Node * pnode);

/* Inteface function */
/* Set list to empty condition */

void InitializeList(const List * plist)
{
	*plist = NULL;
}

/* Return "True" if list in empty */
bool ListIsEmpty(const List * plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

/* Return "True" if list is full */
bool ListIsFull(const List * plist)
{
	Node * pt;
	bool full;

	pt = (Node *) malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

unsigned int ListCarAmount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;						/* Set to start of list */

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;					/* Set to next node */
	}

	return count;
}

/* create node to store for element and add it to end */
/* of list (plist) */
bool AddCar(Car car, List * plist)
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *) malloc(sizeof(Node));
	if (pnew == NULL)
		return false;							/* get out from func if err */

	CopyToNode(car, pnew);
	pnew->next = NULL;
	if (scan == NULL)							/* List is empty */
		*plist = pnew;							/* so put pnew to start of list */
	else
	{
		while (scan->next != NULL)
			scan = scan->next;					/* search end of list */
		scan->next = pnew;						/* add pnew to end */
	}

	return true;
}

void Traverse (const List * plist, void(*pfun)(Car car))
{
	Node * pnode = *plist;						/* set to start of list */

	while (pnode != NULL)
	{
		(*pfun)(pnode->car);					/* apply func for element */
		pnode = pnode->next;					/* jump to next element */
	}
}

/* free memory after malloc */
/* set list pointer to NULL */
void EmptyTheList(List * plist)
{
	Node * psave;

	while (*plist != NULL)
	{
		psave = (*plist)->next;					/* save pointer of next node */
		free(*plist);							/* free current node */
		*plist = psave;							/* jump to next node */
	}
}

/* definition of local func */
/* copy element to node */
static void CopyToNode(Car car, Node * pnode)
{
	pnode->car = car;							/* copy struct */
}

