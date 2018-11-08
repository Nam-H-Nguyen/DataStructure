/*
 * array_stack_main.c
 *
 * Code example of ArrayStack for lecture 8.
 *
 *  @date Nov 8, 2018
 *  @author: Nam H. Nguyen
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_stack.h"

/**
 * Test functions.
 */
int main(void) {
	printf("Creating array stack\n");
	ArrayStack *stack = newArrayStack(5);
	bool empty = isArrayStackEmpty(stack);
	printf("stack empty? %s\n", empty ? "true" : "false");
	size_t size = arrayStackSize(stack);
	printf("stack size: %ld\n", size);

	printf("\nadding 5 values\n");
	pushArrayStackVal(stack, "A");
	pushArrayStackVal(stack, "B");
	pushArrayStackVal(stack, "C");
	pushArrayStackVal(stack, "D");
	pushArrayStackVal(stack, "E");
	empty = isArrayStackEmpty(stack);
	printf("stack empty? %s\n", empty ? "true" : "false");
	size = arrayStackSize(stack);
	printf("stack size: %ld\n", size);
	printArrayStack(stack);

	const char *val;
	bool status = peekArrayStackVal(stack, &val);
	if (status) {
		printf("\npeek value: %s\n", val);
	} else {
		printf("\ncannot peek at top\n");
	}

	// swap top two stack values
	status = swapArrayStackVal(stack);
	if (status) {
		printf("\nswapped top\n");
		printArrayStack(stack);
	} else {
		printf("\ncannot swap\n");
	}

	status = pokeArrayStackVal(stack, "Z");
	if (status) {
		printf("\npoked top: Z\n");
		printArrayStack(stack);
	} else {
		printf("\ncannot poke top\n");
	}

	status = dropArrayStackVal(stack);
	if (status) {
		printf("\ndropped top\n");
		printArrayStack(stack);
	} else {
		printf("\ncannot drop top\n");
	}

	status = dupArrayStackVal(stack);
	if (status) {
		printf("\ndup value\n");
		printArrayStack(stack);
	} else {
		printf("\ncannot dup value\n");
	}

	empty = isArrayStackEmpty(stack);
	printf("\nstack empty? %s\n", empty ? "true" : "false");
	size = arrayStackSize(stack);
	printf("stack size: %ld\n", size);

	printf("\ndropping all array stack values\n");
	dropAllArrayStackVals(stack);
	empty = isArrayStackEmpty(stack);
	printf("stack empty? %s\n", empty ? "true" : "false");
	size = arrayStackSize(stack);
	printf("stack size: %ld\n", size);
	printArrayStack(stack);

	printf("\ndeleting array stack\n");
	deleteArrayStack(stack);

	printf("program exiting\n");

	return EXIT_SUCCESS;
}
