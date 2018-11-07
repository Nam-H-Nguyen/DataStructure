/*
 * @file linked_list.h
 *
 * This file provides the structure and function definitions for a
 * linked list.
 *
 * @since 2017-02-08
 * @author philip gust
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>
#include <stdlib.h>
#include "linked_node.h"

/** Linked List data structure */
typedef struct {
	/** The head node of the linked node chain */
	LinkedNode *head;
	/** The size of the linked list */
	size_t size;
	/** The maximum capacity of the linked list */
	size_t maxCapacity;
} LinkedList;

/**
 * Create and initialize a new linked list
 *
 * @param maxCapacity the maximum capacity of the list
 */
LinkedList *newLinkedList(size_t maxCapacity);

/**
 * Add value to list at index. Cannot add null string to the list.
 * @param list the LinkedList
 * @param index the index for the new value
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or val is null
 */
bool addLinkedListValAt(LinkedList *list, size_t index, const char *val);

/**
 * Add value to start of list. Cannot add null string to the list.
 * @param list the LinkedList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or val is null
 */
bool addFirstLinkedListVal(LinkedList *list, const char *val);

/**
 * Add value to end of list. Cannot add null string to the list.
 * @param list the LinkedList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or val is null
 */
bool addLastLinkedListVal(LinkedList *list, const char *val);

/**
 * Get value at index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getLinkedListValAt(LinkedList *list, size_t index, const char **val);

/**
 * Get value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getFirstLinkedListVal(LinkedList *list, const char **val);

/**
 * Get value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getLastLinkedListVal(LinkedList *list, const char **val);

/**
 * Set value at index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds or value is null
 */
bool setLinkedListValAt(LinkedList *list, size_t index, const char *val);

/**
 * Set value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds
 */
bool setFirstLinkedListVal(LinkedList *list, const char *val);

/**
 * Set value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds
 */
bool setLastLinkedListVal(LinkedList *list, const char *val);

/**
 * Returns number of items in the linked list.
 * @param list the LinkedList
 * @return the number of items in the linked list.
 */
size_t linkedListSize(LinkedList *list);

/**
 * Determines whether linked list is empty.
 * @param list the LinkedList
 * @return true if linked list is empty, flase otherwise
 */
bool isLinkedListEmpty(LinkedList *list);

/**
 * Delete the linked list value at the specified index.
 * @param list the LinkedList
 * @param index the index
 * @return false if index out of bounds
 */
bool deleteLinkedListValAt(LinkedList *list, size_t index);

/**
 * Delete the first linked list value.
 * @param list the LinkedList
 * @return false if list is empty
 */
bool deleteFirstLinkedListVal(LinkedList *list);

/**
 * Delete the last linked list value.
 * @param list the LinkedList
 * @return false if list is empty
 */
bool deleteLastLinkedListVal(LinkedList *list);

/**
 * Deletes all linked list values.
 * @param list the LinkedList
 */
void deleteAllLinkedListVals(LinkedList *list);

/**
 * Delete the linked list. Frees copies of all strings,
 * then the node chain, and finally the list itself.
 *
 * @param list the linked list
 */
void deleteLinkedList(LinkedList *list);

/**
 * Print the linked list.
 * @param list the linked list
 */
void printLinkedList(LinkedList *list);

#endif /* LINKED_LIST_H_ */
