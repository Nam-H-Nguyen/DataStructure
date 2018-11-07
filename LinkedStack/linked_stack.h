/*
 * @file linked_stack.h
 *
 * Declarations for a linked stack.
 *
 *  @since Oct 30, 2018
 *  @author philip gust
 */

#ifndef LINKED_STACK_H_
#define LINKED_STACK_H_

#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

/** Linked stack data structure */
typedef struct {
	/** Uses LinkedList as backing store */
	LinkedList *list;
} LinkedStack;

/**
 * Create an linked stack with a max capacity.
 *
 * @param maxCapacity the maximum capacity of the tack
 * @return the allocated linked stack
 */
LinkedStack *newLinkedStack(size_t maxCapacity);

/**
 * Push value onto the stack. Cannot add NULL string to the stack.
 * @param stack the LinkedStack
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool pushLinkedStackVal(LinkedStack *stack, const char *val);

/**
 * Get the top stack value without removing it.
 * @param stack the LinkedStack
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekLinkedStackVal(LinkedStack *stack, const char **val);

/**
 * Set the stack top to a new value.
 * @param stack the LinkedStack
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeLinkedStackVal(LinkedStack *stack, const char *val);

/**
 * Delete the linked stack value at the specified index.
 * @param stack the linked stack
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return if stack is empty
 */
bool popLinkedStackVal(LinkedStack *stack, const char **val);

/**
 * Exchange the top two stack values.
 * @param stack the LinkedStack
 * @return false if the stack does not have two values or
 *   operation is not supported
 */
bool swapLinkedStackVal(LinkedStack *stack);

/**
 * Pushes another copy of the top stack value onto the stack.
 * @param stack the LinkedStack
 * @return false if the stack is empty or operation is not supported
 */
bool dupLinkedStackVal(LinkedStack *stack);

/**
 * Deletes top value from the stack.
 * @param stack the LinkedStack
 * @return false if the stack is empty or operation is not supported
 */
bool dropLinkedStackVal(LinkedStack *stack);

/**
 * Drops all linked stack values.
 * @param list the array list
 */
void dropAllLinkedStackVals(LinkedStack *stack);

/**
 * Returns number of items in the linked stack.
 * @param stack the linked stack
 * @return the number of items in the linked stack.
 */
size_t linkedStackSize(LinkedStack *stack);

/**
 * Determines whether linked stack is empty.
 * @param stack the linked stack
 * @return true if linked stack is empty, false otherwise
 */
bool isLinkedStackEmpty(LinkedStack *stack);

/**
 * Delete the linked stack . Frees copies of all strings,
 * then the linked stack, and finally the stack itself.
 *
 * @param stack the linked stack
 */
void deleteLinkedStack(LinkedStack *stack);

/**
 * Print linked stack for diagnostic purposes.
 *
 * @param stack the linked stack
 */
void printLinkedStack(LinkedStack *stack);

#endif /* LINKED_STACK_H_ */
