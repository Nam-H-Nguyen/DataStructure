/*
 * @file linked_list_main.c
 *
 * This file exercises the singly linked list functions.
 *
 * @since 2018-02-14
 * @author philip gust
 */
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/**
 * Test LinkedList functions.
 */
void testLinkedList(void) {
	printf("\nstart testLinkedList\n");

	printf("creating array list\n");
	LinkedList *list = newLinkedList(6);
	bool empty = isLinkedListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size_t size = linkedListSize(list);
	printf("list size: %zu\n", size);

	printf("\nadding 5 values\n");
	addLastLinkedListVal(list, "A");
	addLastLinkedListVal(list, "B");
	addLastLinkedListVal(list, "C");
	addLastLinkedListVal(list, "D");
	addLastLinkedListVal(list, "E");
	printLinkedList(list);
	empty = isLinkedListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size = linkedListSize(list);
	printf("list size: %zu\n", size);

	const char *val;
	bool status = getLinkedListValAt(list, 0, &val);
	if (status) {
		printf("list[0]: %s\n", val);
	} else {
		printf("cannot access list[0]\n");
	}

	status = getLinkedListValAt(list, 4, &val);
	if (status) {
		printf("list[4]: %s\n", val);
	} else {
		printf("cannot access list[4]\n");
	}

	status = setLinkedListValAt(list, 4, "Z");
	if (status) {
		printf("setting list[4]: Z\n");
	} else {
		printf("cannot set list[4]\n");
	}
	printLinkedList(list);

	status = getLinkedListValAt(list, 4, &val);
	if (status) {
		printf("list[4]: %s\n", val);
	} else {
		printf("cannot access list[4]\n");
	}

	status = getLinkedListValAt(list, 5, &val);
	if (status) {
		printf("list[5]: %s\n", val);
	} else {
		printf("cannot access list[5]\n");
	}

	status = addLinkedListValAt(list, 1, "AA");
	if (status) {
		printf("add list[2]: %s\n", "AA");
	} else {
		printf("cannot add list[2]\n");
	}
	printLinkedList(list);

	empty = isLinkedListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size = linkedListSize(list);
	printf("list size: %zu\n", size);

	status = deleteLinkedListValAt(list, 2);
	if (status) {
		printf("delete list[2]\n");
	} else {
		printf("cannot delete list[2]\n");
	}
	empty = isLinkedListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size = linkedListSize(list);
	printf("list size: %zu\n", size);

	printf("\ndeleting all array list values\n");
	deleteAllLinkedListVals(list);
	printLinkedList(list);

	empty = isLinkedListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size = linkedListSize(list);
	printf("list size: %zu\n", size);

	printf("\ndeleting linked list\n");
	deleteLinkedList(list);

	printf("end testLinkedList\n");
}

/**
 * Test functions.
 */
int main(void) {
	testLinkedList();

	printf("program exiting\n");
}
