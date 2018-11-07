/*
 * @file array_list_main.c
 *
 * Test program for ArrayList and functions for lecture 2
 *
 * @date Oct 22, 2018
 * @author  philip gust
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

/**
 * Test functions.
 */
int main(void) {
	printf("Creating array list\n");
	ArrayList *list = newArrayList(5);
	bool empty = isArrayListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size_t size = arrayListSize(list);
	printf("list size: %ld\n", size);

	printf("\nadding 5 values\n");
	addLastArrayListVal(list, "A");
	addLastArrayListVal(list, "B");
	addLastArrayListVal(list, "C");
	addLastArrayListVal(list, "D");
	addLastArrayListVal(list, "E");
	empty = isArrayListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size = arrayListSize(list);
	printf("list size: %ld\n", size);

	const char *val;
	bool status = getArrayListValAt(list, 0, &val);
	if (status) {
		printf("list[0]: %s\n", val);
	} else {
		printf("cannot access list[0]\n");
	}

	status = getArrayListValAt(list, 4, &val);
	if (status) {
		printf("list[4]: %s\n", val);
	} else {
		printf("cannot access list[4]\n");
	}

	status = setArrayListValAt(list, 4, "Z");
	if (status) {
		printf("setting list[4]: Z\n");
	} else {
		printf("cannot set list[4]\n");
	}

	status = getArrayListValAt(list, 4, &val);
	if (status) {
		printf("list[4]: %s\n", val);
	} else {
		printf("cannot access list[4]\n");
	}

	status = getArrayListValAt(list, 5, &val);
	if (status) {
		printf("list[5]: %s\n", val);
	} else {
		printf("cannot access list[5]\n");
	}

	status = deleteArrayListValAt(list, 2);
	if (status) {
		printf("delete list[2]\n");
	} else {
		printf("cannot delete list[2]\n");
	}
	empty = isArrayListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size = arrayListSize(list);
	printf("list size: %ld\n", size);

	printf("\ndeleting all array list values\n");
	deleteAllArrayListVals(list);
	empty = isArrayListEmpty(list);
	printf("list empty? %s\n", empty ? "true" : "false");
	size = arrayListSize(list);
	printf("list size: %ld\n", size);

	printf("\ndeleting array list\n");
	deleteArrayList(list);

	printf("program exiting\n");

	return EXIT_SUCCESS;
}
