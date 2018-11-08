/*
 * @file linked_list_iterator.h
 *
 * This file provides the structure and function definitions for an
 * iterator for a singly linked list.
 *
 *  @date Nov 8, 2018
 *  @author: Nam H. Nguyen
 */

#ifndef LINKED_LIST_ITERATOR_H_
#define LINKED_LIST_ITERATOR_H_

#include <stdbool.h>
#include "linked_list.h"

/**
 * An iterator for a singly-linked list.
 */
typedef struct {
  LinkedList *theList;
  LinkedNode *curNode;
  size_t count;
} LinkedListIterator;

/**
 * Value returned by getLinkedListIteratorAvailable if count unavailable
 */
extern const size_t UNAVAILABLE;

/**
 * Create and initialize new iterator.
 *
 * @param theList the LinkedList to iterate
 * @return an iterator for the list
 */
LinkedListIterator* newLinkedListIterator(LinkedList* theList);

/**
 * Delete the iterator by freeing its storage.
 *
 * @param itr the LinkedListIterator to delete
 */
void deleteLinkedListIterator(LinkedListIterator* itr);

/**
 * Gets next link value in the linked list.
 *
 * @param itr the LinkedListIterator
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if next value returned, false if iterator is at end of list
 */
bool getNextLinkedListIteratorVal(LinkedListIterator* itr, const char **value);

/**
 * Determines whether there is another value in the linked list.
 *
 * @param itr the LinkedListIterator
 * @return true if there is another value, false otherwise
 */
bool hasNextLinkedListIteratorVal(LinkedListIterator* itr);

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
 * @return true if previous value returned, false if iterator is at end of list
 */
 bool getPrevLinkedListIteratorVal(LinkedListIterator* itr, const char **val);

 /**
  * Determines whether there is a previous value in the linked list.
  *
  * The previous value is the one prior to the value returned by a call
  * to getNextLinkListVal(). In other words, it is the value returned
  * by the last call to getNextLinkListVal(). If the iterator is at
  * the beginning of the list, there is no previous value.
  *
  * @param itr the LinkedListIterator
  * @return true if there is a previous node, false otherwise
  */
bool hasPrevLinkedListIteratorVal(LinkedListIterator* itr);

/**
 * Resets the linked list iterator to the head of the list.
 *
 * @param itr the LinkedListIterator
 * @return true if successful, false if not supported
 */
bool resetLinkedListIterator(LinkedListIterator* itr);

/**
 * Returns the number of values returned so far.
 *
 * @param itr the LinkedListIterator
 * @return the number of values returned so far
 */
size_t getLinkedListIteratorCount(LinkedListIterator* itr);

/**
 * Returns the number of values available.
 *
 * @param itr the LinkedListIterator
 * @return available number of values or UNAVAILABLE if cannot perform operation.
 */
size_t getLinkedListIteratorAvailable(LinkedListIterator* itr);

#endif /* LINKED_LIST_ITERATOR_H_ */
