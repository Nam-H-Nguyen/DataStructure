/*
 * @file linked_list_iterator_main.c
 *
 * This file exercises the singly linked list and singly linked list
 * iterators functions.
 *
 *  @since Oct 24, 2018
 *  @author: Nam H. Nguyen
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linked_list_iterator.h"


/**
 * Test LinkedListIterator functions
 */
void testLinkedListIterator(void) {
	printf("\nstart testLinkedListIterator\n");

	printf("initial list\n");
	LinkedList *list = newLinkedList(5);
	printLinkedList(list);
	printf("list size: %ld\n", linkedListSize(list));

	// add 5 nodes to the list
	printf("\nAdding 5 values to list\n");
	addLastLinkedListVal(list, "A");
	addLastLinkedListVal(list, "B");
	addLastLinkedListVal(list, "C");
	addLastLinkedListVal(list, "D");
	addLastLinkedListVal(list, "E");
	printLinkedList(list);

	printf("list size: %ld\n", linkedListSize(list));

	printf("\nTraversing list forward with iterator\n");
	LinkedListIterator *itr = newLinkedListIterator(list);
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));
	while (hasNextLinkedListIteratorVal(itr)) {
		const char *val;
		if (getNextLinkedListIteratorVal(itr, &val)) {
			printf("iterator next: \"%s\"\n", val);
		} else {
			printf("iterator next: unavailable\n");
		}
	}
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));

	printf("\nMoving back one from end with iterator\n");
	printf("iterator has prev: %s\n", hasPrevLinkedListIteratorVal(itr) ? "true" : "false");
	const char *val;
	if (getPrevLinkedListIteratorVal(itr, &val)) {
		printf("iterator prev: \"%s\"\n", val);
	} else {
		printf("iterator prev: unavailable\n");
	}
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));

	printf("\nMoving forward one to end with iterator\n");
	if (getNextLinkedListIteratorVal(itr, &val)) {
		printf("iterator next: \"%s\"\n", val);
	} else {
		printf("iterator next: unavailable\n");
	}
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));

	printf("\nResetting iterator\n");
	resetLinkedListIterator(itr);
	printf("iterator has next: %s\n", hasNextLinkedListIteratorVal(itr) ? "true" : "false");
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));

	printf("\nTrying to move back one from beginning with iterator\n");
	printf("iterator has prev: %s\n", hasPrevLinkedListIteratorVal(itr) ? "true" : "false");
	if (getPrevLinkedListIteratorVal(itr, &val)) {
		printf("iterator prev: \"%s\"\n", val);
	} else {
		printf("iterator prev: unavailable\n");
	}

	printf("\nDeleting iterator and linked list\n");
	deleteLinkedListIterator(itr);
	deleteLinkedList(list);

	printf("end testLinkedListIterator\n");
}

/**
 * Test functions.
 */
int main(void) {
	testLinkedListIterator();

	printf("program exiting\n");
}
