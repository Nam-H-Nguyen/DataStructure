/*
 * @file linked_list_iterator.c
 *
 * This file provides implements the functions of an iterator
 * for a singly linked list.
 *
 * Initializes the iterator curNode to the dummy head node rather
 * than to the first array node in the list. At the end of forward
 * iteration, curNode points to the last node in the list, rather
 * than to NULL. This simplifies backward iteration when using a
 * doubly-linked node back pointer.
 *
 *
 *  @date Oct 3, 2018
 *  @author: Nam H. Nguyen
 */

#include <stdlib.h>
#include <stdbool.h>
#include "linked_list_iterator.h"

/**
 * Value returned by getLinkedListIteratorAvailable if count unavailable.
 */
const size_t UNAVAILABLE = SIZE_MAX;

/**
 * Create and initialize new iterator.
 *
 * @param list the LinkedList to iterate
 * @return an iterator for the list
 */
LinkedListIterator* newLinkedListIterator(LinkedList *list) {
	LinkedListIterator* itr = malloc(sizeof(LinkedListIterator));

	itr->theList = list;
	itr->curNode = list->head;
	itr->count = 0;

	return itr;
}

/**
 * Delete the iterator by freeing its storage.
 *
 * @param itr the LinkedListIterator to delete
 */
void deleteLinkedListIterator(LinkedListIterator* itr) {
	itr->count = 0;
	itr->curNode = NULL;
	itr->theList = NULL;
	free(itr);
}

/**
 * Gets next link value in the linked list.
 *
 * @param itr the LinkedListIterator
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if next value returned, false if iterator is at end of list
 */
 bool getNextLinkedListIteratorVal(LinkedListIterator* itr, const char **val) {
	if (hasNextLinkedListIteratorVal(itr)) {
		itr->curNode = itr->curNode->next;
		itr->count++;
		*val = itr->curNode->data;
		return true;
	}
	return false;
}

/**
 * Determines whether there is another value in the linked list.
 *
 * @param itr the LinkedListIterator
 * @return true if there is another value, false otherwise
 */
bool hasNextLinkedListIteratorVal(LinkedListIterator* itr) {
	return itr->curNode->next != NULL;
}

/**
 * Gets previous link value in the linked list.
 *
 * The previous value is the one prior to the value returned by a
 * call to getNextLinkListVal(). In other words, it is the value
 * returned by the last call to getNextLinkListVal(). The count
 * will be decremented by 1, so that the sum of the count and the
 * available values is the length of list. If the iterator is at
 * the beginning of the list, there is no previous value.
 *
 * @param itr the LinkedListIterator
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if previous value returned, false if iterator is at
 *  the start of list
 */
bool getPrevLinkedListIteratorVal(LinkedListIterator* itr, const char **val) {
//  for loop duplicates functionality in getLinkedNodeAt().
//	if (hasPrevLinkedListIteratorVal(itr)) {
//		// find previous node in chain
//		for (LinkedNode* node = itr->theList->head;
//			node->next != NULL; node = node->next) {
//			if (node->next == itr->curNode) {
//				*val = itr->curNode->data;  // return the data
//				// decrement so that count+available == list size
//				itr->count--;
//				// point to previous node
//				itr->curNode = node;
//				return true;
//			}
//		}
//	}
	if (itr->count > 1) {
		// get previous node;
		// If count == 2, curNode is at node index 1 in chain after head,
		// so we need predecessor node at index 0 after head. If we pass
		// in head, need to pass in 1 to get node at index 0.
		LinkedNode *node = getLinkedNodeAt(itr->theList->head,itr->count-1);
		if (node != NULL) {
			*val = itr->curNode->data;  // return the data
			// decrement so that count+available == list size
			itr->count--;
			// point to previous node
			itr->curNode = node;
			return true;
		}
	}
	return false;
}

/**
 * Determines whether there is a previous value in the linked list.
 *
 * The previous value is the one prior to the value returned by a call
 * to getNextLinkListVal(). In other words, it is the value returned
 * by the last call to getNextLinkListVal(). If the iterator is at
 * the beginning of the list, there is no previous value.
 *
 * @param itr the LinkedListIterator
 * @return true if there is a previous value, false otherwise
 */
bool hasPrevLinkedListIteratorVal(LinkedListIterator* itr) {
	return (itr->theList->head != itr->curNode);
}

/**
 * Resets the linked list iterator to the start of the list.
 *
 * @param itr the LinkedListIterator
 * @return true if successful, false if not supported
 */
bool resetLinkedListIterator(LinkedListIterator* itr) {
	itr->curNode = itr->theList->head;
	itr->count = 0;
	return true;
}

/**
 * Returns the number of values returned so far.
 *
 * @param itr the LinkedListIterator
 * @return the number of values returned so far
 */
size_t getLinkedListIteratorCount(LinkedListIterator* itr) {
	return itr->count;
}


/**
 * Returns the number of values available.
 *
 * @param itr the LinkedListIterator
 * @return available number of values or UNAVAILABLE if cannot perform operation.
 */
size_t getLinkedListIteratorAvailable(LinkedListIterator* itr) {
	return itr->theList->size - itr->count;
}
