/*
 * array_stack.c
 *
 * Code example of ArrayStack for lecture 8.
 *
 * Operations add and delete from the front because
 * that is more efficient for linked lists.
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
 * Create an array stack with an initial capacity and max capacity.
 *
 * @param maxCapacity maximum capacity of ArrayStack.
 *     Use SIZE_MAX for unlimited capacity
 * @return the allocated array stack
 */
ArrayStack *newArrayStack(size_t maxCapacity) {
	ArrayStack *stack = malloc(sizeof(ArrayStack));
	stack->list = newArrayList(maxCapacity);

	return stack;
}

/**
 * Delete the array stack. Frees copies of all strings,
 * then the array stack, and finally the stack itself.
 *
 * @param stack the ArrayStack
 */
void deleteArrayStack(ArrayStack *stack) {
	// free the strings in the array
	deleteArrayList(stack->list);
	stack->list = NULL;

	// free the stack itself
	free(stack);
}

/**
 * Push value onto the stack. Cannot add NULL string to the stack.
 * @param stack the ArrayStack
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool pushArrayStackVal(ArrayStack *stack, const char *val) {
	return addLastArrayListVal(stack->list, val);
}

/**
 * Get the top stack value without removing it.
 * @param stack the ArrayStack
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekArrayStackVal(ArrayStack *stack, const char **val) {
	return getLastArrayListVal(stack->list, val);
}

/**
 * Set the stack top to a new value.
 * @param stack the ArrayStack
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeArrayStackVal(ArrayStack *stack, const char *val) {
	return setLastArrayListVal(stack->list, val);
}

/**
 * Deletes and returns copy of stack top.
 * @param stack the array stack
 * @param val result parameter is pointer to result value location;
 *   cannot be null; returned value must be freed
 * @return if stack is empty
 */
bool popArrayStackVal(ArrayStack *stack, char **val) {
	const char* localVal;
	// copy first because drop causes returned value to be freed
	if (peekArrayStackVal(stack, &localVal)) {
		*val = strdup(localVal);
		dropArrayStackVal(stack);
		return true;
	}
	return false;
}

/**
 * Exchange the top two stack values.
 * @param stack the ArrayStack
 * @return false if the stack does not have two values or
 *   operation is not supported
 */
bool swapArrayStackVal(ArrayStack *stack) {
	size_t size = arrayListSize(stack->list);
	if (size >= 2) {
		// NOTE: having swapArrayListValsAt(stack->list, i, j)
		// would make this operation much more efficient
		char *val1, *val2;
		popArrayStackVal(stack, &val1);
		popArrayStackVal(stack, &val2);
		pushArrayStackVal(stack, val1);
		pushArrayStackVal(stack, val2);

		// must free because pop returns allocated storage
		free(val1);
		free(val2);
		return true;
	}
	return false;
}

/**
 * Pushes another copy of the top stack value onto the stack.
 * @param stack the ArrayStack
 * @return false if the stack is empty or operation is not supported
 */
bool dupArrayStackVal(ArrayStack *stack) {
	const char *val;
	if (peekArrayStackVal(stack, &val)) {
		return pushArrayStackVal(stack, val);
	}
	return false;
}

/**
 * Deletes top value from the stack.
 * @param stack the ArrayStack
 * @return false if the stack is empty or operation is not supported
 */
bool dropArrayStackVal(ArrayStack *stack) {
	return deleteLastArrayListVal(stack->list);
}

/**
 * Drops all array stack values.
 * @param stack the ArrayStack
 */
void dropAllArrayStackVals(ArrayStack *stack) {
	deleteAllArrayListVals(stack->list);
}

/**
 * Returns number of items in the array stack.
 * @param stack the ArrayStack
 * @return the number of items in the array stack.
 */
size_t arrayStackSize(ArrayStack *stack) {
    return arrayListSize(stack->list);
}

/**
 * Determines whether array stack is empty.
 * @param stack the ArrayStack
 * @return true if array stack is empty, flase otherwise
 */
bool isArrayStackEmpty(ArrayStack *stack) {
	return isArrayListEmpty(stack->list);
}

/**
 * Print array stack for diagnostic purposes.
 *
 * @param stack the ArrayStack
 */
void printArrayStack(ArrayStack *stack) {
	size_t size = arrayListSize(stack->list);
	printf("stack (%lu):\n", size);
	const char *val;
	for (int i = size-1; i >= 0; i--) {
		getArrayListValAt(stack->list, i, &val);
		printf("%s\n", val);
	}
}
