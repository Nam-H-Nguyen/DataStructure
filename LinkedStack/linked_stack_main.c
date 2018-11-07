/*
 * file: linked_stack_main.c
 *
 * Test LinkedStack functions
 *
 *  @since Oct 24, 2018
 *  @author philip gust
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_stack.h"

/**
 * Test functions.
 */
int main(void) {
	printf("Creating linked stack\n");
	LinkedStack *stack = newLinkedStack(5);
	bool empty = isLinkedStackEmpty(stack);
	printf("stack empty? %s\n", empty ? "true" : "false");
	size_t size = linkedStackSize(stack);
	printf("stack size: %ld\n", size);

	printf("\nadding 5 values\n");
	pushLinkedStackVal(stack, "A");
	pushLinkedStackVal(stack, "B");
	pushLinkedStackVal(stack, "C");
	pushLinkedStackVal(stack, "D");
	pushLinkedStackVal(stack, "E");
	empty = isLinkedStackEmpty(stack);
	printf("stack empty? %s\n", empty ? "true" : "false");
	size = linkedStackSize(stack);
	printf("stack size: %ld\n", size);
	printLinkedStack(stack);

	const char *val;
	bool status = peekLinkedStackVal(stack, &val);
	if (status) {
		printf("\npeek value: %s\n", val);
	} else {
		printf("\ncannot peek at top\n");
	}

	// swap top two stack values
	status = swapLinkedStackVal(stack);
	if (status) {
		printf("\nswapped top\n");
		printLinkedStack(stack);
	} else {
		printf("\ncannot swap\n");
	}

	status = pokeLinkedStackVal(stack, "Z");
	if (status) {
		printf("\npoked top: Z\n");
		printLinkedStack(stack);
	} else {
		printf("\ncannot poke top\n");
	}

	status = dropLinkedStackVal(stack);
	if (status) {
		printf("\ndropped top\n");
		printLinkedStack(stack);
	} else {
		printf("\ncannot drop top\n");
	}

	status = dupLinkedStackVal(stack);
	if (status) {
		printf("\ndup value\n");
		printLinkedStack(stack);
	} else {
		printf("\ncannot dup value\n");
	}

	empty = isLinkedStackEmpty(stack);
	printf("\nstack empty? %s\n", empty ? "true" : "false");
	size = linkedStackSize(stack);
	printf("stack size: %ld\n", size);

	printf("\ndropping all linked stack values\n");
	dropAllLinkedStackVals(stack);
	empty = isLinkedStackEmpty(stack);
	printf("stack empty? %s\n", empty ? "true" : "false");
	size = linkedStackSize(stack);
	printf("stack size: %ld\n", size);
	printLinkedStack(stack);

	printf("\ndeleting linked stack\n");
	deleteLinkedStack(stack);

	printf("program exiting\n");

	return EXIT_SUCCESS;
}
