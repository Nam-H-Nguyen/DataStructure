/*
 * @file linked_list.c
 *
 * This file implements a linked list of strings.
 *
 * @since 2018-02-08
 * @author philip gust
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "linked_list.h"

/**
 * Create and initialize a new linked list.
 *
 * @param maxCapacity the maximum capacity of the list
 * @return the new linked list
 */
LinkedList *newLinkedList(size_t maxCapacity) {
	LinkedList *list = malloc(sizeof(LinkedList));
	list->size = 0;
	list->maxCapacity = maxCapacity;
	list->head = newLinkedNode(NULL);  // dummy node
	return list;
}

/**
 * Add value to list at index.
 *
 * @param list the LinkedList
 * @param index the index for the new value
 * @param val the value to insert; value will be copied to store
 * @return false if index out of bounds
 */
bool addLinkedListValAt(LinkedList *list, size_t index, const char *val) {
	// cannot add NULL to list
	if (list->size == list->maxCapacity) {
		return false;
	}
	// find node to insert after
	LinkedNode *node = getLinkedNodeAt(list->head, index);
	if (node == NULL) {
		return false;
	}

	// create and add new node
	LinkedNode *newNode = newLinkedNode(val);
	addAfterLinkedNode(node, newNode);
	list->size++;

	return true;
}

/**
 * Add value to start of list. Cannot add null string to the list.
 *
 * @param list the LinkedList
 * @param val the value to insert; value will be copied to store
 * @return false if index out of bounds
 */
bool addFirstLinkedListVal(LinkedList *list, const char *val) {
	return addLinkedListValAt(list, 0, val);
}

/**
 * Add value to end of list.
 * @param list the LinkedList
 * @param val the value to insert; value will be copied to store
 * @return false if index out of bounds
 */
bool addLastLinkedListVal(LinkedList *list, const char *val) {
	return addLinkedListValAt(list, list->size, val);
}

/**
 * Get value at index.
 * @param list the LinkedList
 * @param the index for the value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getLinkedListValAt(LinkedList *list, size_t index, const char **val) {
	return getLinkedNodeValAt(list->head->next, index, val);
}

/**
 * Get value at first index.
 * @param list the LinkedList
 * @param the index for the value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getFirstLinkedListVal(LinkedList *list, const char **val) {
	return getLinkedListValAt(list, 0, val);
}

/**
 * Get value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getLastLinkedListVal(LinkedList *list, const char **val) {
	if (list->size == 0) {
		return NULL;
	}
	return getLinkedListValAt(list, list->size-1, val);
}

/**
 * Set value at index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set
 * @return false if index out of bounds
 */
bool setLinkedListValAt(LinkedList *list, size_t index, const char *val) {
	if (val == NULL) {
		return false;
	}
	return setLinkedNodeValAt(list->head->next, index, val);
}

/**
 * Set value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set
 * @return false if index out of bounds
 */
bool setFirstLinkedListVal(LinkedList *list, const char *val) {
	return setLinkedListValAt(list, 0, val);
}

/**
 * Set value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds
 */
bool setLastLinkedListVal(LinkedList *list, const char *val) {
	if (list->size == 0) {
		return false;
	}
	return setLinkedListValAt(list, list->size-1, val);
}

/**
 * Returns number of items in the linked list.
 * @param list the LinkedList
 * @return the number of items in the linked list.
 */
size_t linkedListSize(LinkedList *list) {
    return list->size;
}

/**
 * Determines whether linked list is empty.
 * @param list the LinkedList
 * @return true if linked list is empty, false otherwise
 */
bool isLinkedListEmpty(LinkedList *list) {
	return list->size == 0;
}

/**
 * Delete the linked list value at the specified index.
 * @param list the LinkedList
 * @param index the index
 * @return false if index out of bounds
 */
bool deleteLinkedListValAt(LinkedList *list, size_t index) {
	// node before one to delete
	LinkedNode *node = getLinkedNodeAt(list->head, index);
	if (node != NULL) {
		// delete node from linked array
		node = deleteAfterLinkedNode(node);
		if (node != NULL) {
			// free node and decrement count if deleted
			deleteLinkedNode(node);
			list->size--;
			return true;
		}
	}
	return false;
}

/**
 * Delete the first linked list value.
 * @param list the LinkedList
 * @return false if list is empty
 */
bool deleteFirstLinkedListVal(LinkedList *list) {
	return deleteLinkedListValAt(list, 0);
}

/**
 * Delete the last linked list value.
 * @param list the LinkedList
 * @return false if list is empty
 */
bool deleteLastLinkedListVal(LinkedList *list) {
	if (list->size == 0) {
		return false;
	}
	return deleteLinkedListValAt(list, list->size-1);
}

/**
 * Deletes all linked list values.
 * @param list the LinkedList
 */
void deleteAllLinkedListVals(LinkedList *list) {
	deleteAllLinkedNodes(list->head->next);
	list->head->next = NULL;
	list->size = 0;
}

/**
 * Delete the linked list. Frees copies of all strings,
 * then the node chain, and finally the list itself.
 *
 * @param list the LinkedList
 */
void deleteLinkedList(LinkedList *list) {
	deleteAllLinkedListVals(list);
	deleteLinkedNode(list->head);
	list->maxCapacity = 0;
	free(list);
}

/**
 * Print the linked list.
 * @param list the LinkedList
 */
void printLinkedList(LinkedList *list) {
	printLinkedNodes(list->head);
}
