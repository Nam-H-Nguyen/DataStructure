/*
 * @file linked_stack.c
 *
 * Code example of LinkedStack for lecture 8.
 *
 * Operations add and delete from the front because
 * that is more efficient for linked lists.
 *
 *  @date Nov 8, 2018
 *  @author: Nam H. Nguyen
 */
#include "linked_stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Create an linked stack with a max capacity.
 *
 * @param maxCapacity the maximum capacity of the stack
 * @return the allocated linked stack
 */
LinkedStack *newLinkedStack(size_t maxCapacity) {
	LinkedStack *stack = malloc(sizeof(LinkedStack));
	stack->list = newLinkedList(maxCapacity);

	return stack;
}

/**
 * Delete the linked stack. Frees copies of all strings,
 * then the linked stack, and finally the stack itself.
 *
 * @param stack the LinkedStack
 */
void deleteLinkedStack(LinkedStack *stack) {
	// free the strings in the array
	deleteLinkedList(stack->list);
	stack->list = NULL;

	// free the stack itself
	free(stack);
}

/**
 * Push value onto the stack. Cannot add NULL string to the stack.
 * @param stack the LinkedStack
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool pushLinkedStackVal(LinkedStack *stack, const char *val) {
	return addFirstLinkedListVal(stack->list, val);
}

/**
 * Get the top stack value without removing it.
 * @param stack the LinkedStack
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekLinkedStackVal(LinkedStack *stack, const char **val) {
	return getFirstLinkedListVal(stack->list, val);
}

/**
 * Set the stack top to a new value.
 * @param stack the LinkedStack
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeLinkedStackVal(LinkedStack *stack, const char *val) {
	return setFirstLinkedListVal(stack->list, val);
}

/**
 * Delete the linked stack value at the specified index.
 * @param stack the LinkedStack
 * @param val result parameter is pointer to result value location;
 *   cannot be null; returned value must be freed
 * @return if stack is empty
 */
bool popLinkedStackVal(LinkedStack *stack, const char **val) {
	const char* localVal;
	if (peekLinkedStackVal(stack, &localVal)) {
		// copy first because drop causes returned value to be freed
		*val = strdup(localVal);
		dropLinkedStackVal(stack);
		return true;
	}
	return false;
}

/**
 * Exchange the top two stack values.
 * @param stack the LinkedStack
 * @return false if the stack does not have two values or
 *   operation is not supported
 */
bool swapLinkedStackVal(LinkedStack *stack) {
	size_t size = linkedListSize(stack->list);
	if (size >= 2) {
		// portable but not as efficient
		const char *val1, *val2;
		popLinkedStackVal(stack, &val1);
		popLinkedStackVal(stack,&val2);
		pushLinkedStackVal(stack, val1);
		pushLinkedStackVal(stack, val2);

		// must free because pop returns allocated storage
		free((char*)val1);
		free((char*)val2);
		return true;
	}
	return false;
}

/**
 * Pushes another copy of the top stack value onto the stack.
 * @param stack the LinkedStack
 * @return false if the stack is empty or operation is not supported
 */
bool dupLinkedStackVal(LinkedStack *stack) {
	const char *val;
	if (peekLinkedStackVal(stack, &val)) {
		return pushLinkedStackVal(stack, val);
	}
	return false;
}

/**
 * Deletes top value from the stack.
 * @param stack the LinkedStack
 * @return false if the stack is empty or operation is not supported
 */
bool dropLinkedStackVal(LinkedStack *stack) {
	return deleteFirstLinkedListVal(stack->list);
}

/**
 * Drops all linked stack values.
 * @param list the LinkedStack
 */
void dropAllLinkedStackVals(LinkedStack *stack) {
	deleteAllLinkedListVals(stack->list);
}

/**
 * Returns number of items in the linked stack.
 * @param stack the LinkedStack
 * @return the number of items in the linked stack.
 */
size_t linkedStackSize(LinkedStack *stack) {
    return linkedListSize(stack->list);
}

/**
 * Determines whether linked stack is empty.
 * @param stack the LinkedStack
 * @return true if linked stack is empty, flase otherwise
 */
bool isLinkedStackEmpty(LinkedStack *stack) {
	return isLinkedListEmpty(stack->list);
}

/**
 * Print linked stack for diagnostic purposes.
 *
 * @param stack the LinkedStack
 */
void printLinkedStack(LinkedStack *stack) {
	size_t size = linkedListSize(stack->list);
	printf("stack (%lu):\n", size);
	const char *val;
	for (int i = 0; i < size; i++) {
		getLinkedListValAt(stack->list, i, &val);
		printf("%s\n", val);
	}
}
