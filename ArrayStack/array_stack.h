/*
 * array_stack.h
 *
 *  @date Nov 8, 2018
 *  @author: Nam H. Nguyen
 */

#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_

#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"

/** Array stack data structure */
typedef struct {
	/** Uses ArrayList as backing store */
	ArrayList *list;
} ArrayStack;

/**
 * Create an array stack with an initial capacity and max capacity.
 *
 * @param maxCapacity maximum capacity of ArrayStack.
 *     Use MAX_SIZE for unlimited capacity
 * @return the allocated array stack
 */
ArrayStack *newArrayStack(size_t maxCapacity);

/**
 * Push value onto the stack. Cannot add NULL string to the stack.
 * @param stack the ArrayStack
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool pushArrayStackVal(ArrayStack *stack, const char *val);

/**
 * Get the top stack value without removing it.
 * @param stack the ArrayStack
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekArrayStackVal(ArrayStack *stack, const char **val);

/**
 * Set the stack top to a new value.
 * @param stack the ArrayStack
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeArrayStackVal(ArrayStack *stack, const char *val);

/**
 * Deletes and returns copy of top top.
 * @param stack the array stack
 * @param val result parameter is pointer to result value location;
 *   cannot be null; returned value must be freed
 * @return if stack is empty
 */
bool popArrayStackVal(ArrayStack *stack, char **val);

/**
 * Exchange the top two stack values.
 * @param stack the ArrayStack
 * @return false if the stack does not have two values or
 *   operation is not supported
 */
bool swapArrayStackVal(ArrayStack *stack);

/**
 * Pushes another copy of the top stack value onto the stack.
 * @param stack the ArrayStack
 * @return false if the stack is empty or operation is not supported
 */
bool dupArrayStackVal(ArrayStack *stack);

/**
 * Deletes top value from the stack.
 * @param stack the ArrayStack
 * @return false if the stack is empty or operation is not supported
 */
bool dropArrayStackVal(ArrayStack *stack);

/**
 * Drops all array stack values.
 * @param list the array list
 */
void dropAllArrayStackVals(ArrayStack *stack);

/**
 * Returns number of items in the array stack.
 * @param stack the array stack
 * @return the number of items in the array stack.
 */
size_t arrayStackSize(ArrayStack *stack);

/**
 * Determines whether array stack is empty.
 * @param stack the array stack
 * @return true if array stack is empty, false otherwise
 */
bool isArrayStackEmpty(ArrayStack *stack);

/**
 * Delete the array stack . Frees copies of all strings,
 * then the array stack, and finally the stack itself.
 *
 * @param stack the array stack
 */
void deleteArrayStack(ArrayStack *stack);

/**
 * Print array stack for diagnostic purposes.
 *
 * @param stack the array stack
 */
void printArrayStack(ArrayStack *stack);

#endif /* ARRAY_STACK_H_ */
