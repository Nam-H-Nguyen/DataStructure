/*
 * @file array_list.c
 *
 * Implementation for ArrayList functions for lecture 2
 *
 * @date Oct 20, 2018
 * @author philip gust
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

/**
 * Create an array list with a fixed capacity.
 *
 * @param capacity capacity of the ArrayList.
 * @return the allocated array list
 */
ArrayList *newArrayList(size_t capacity) {
	ArrayList *list = malloc(sizeof(ArrayList));
	list->size = 0;
	list->capacity = capacity;
	list->vals = calloc(list->capacity, sizeof(char*)); // nulls ptrs

	return list;
}

/**
 * Add value to list at index. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addArrayListValAt(ArrayList *list, size_t index, const char *val) {
	// cannot add NULL to list
	if (val == NULL) {
		return false;
	}

	// beyond end of list
	if (index > list->size) {
		return false;
	}

	// need to grow array if size is at capacity
	if (list->size == list->capacity) {
		return false;
	}

	// move elements down
	for (size_t i = list->size; i > index; i--) {
		// move string up
		list->vals[i] = list->vals[i-1];
	}

	// add copy of value at index position
	list->size++;
	list->vals[index] = strdup(val);  // must copy input string

	return true;
}

/**
 * Add value to start of list. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addFirstArrayListVal(ArrayList *list, const char *val) {
	 return addArrayListValAt(list, 0, val);
 }

/**
 * Add value to end of list. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addLastArrayListVal(ArrayList *list, const char *val) {
	 return addArrayListValAt(list, list->size, val);
 }

/**
 * Get value at index.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getArrayListValAt(ArrayList *list, size_t index, const char **val) {
	if (index < list->size) {
		*val = list->vals[index];
		return true;
	}
	return false;
}

/**
 * Get value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if list is empty
 */
bool getFirstArrayListVal(ArrayList *list, const char **val) {
	return getArrayListValAt(list, 0, val);
}

/**
 * Get value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if list is empty
 */
bool getLastArrayListVal(ArrayList *list, const char **val) {
	if (list->size == 0) { // prevent negative size_t index
		return NULL;
	}
	return getArrayListValAt(list, list->size-1, val);
}


/**
 * Set value at index.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds or value is null
 */
bool setArrayListValAt(ArrayList *list, size_t index, const char *val) {
	// cannot add NULL to list
	if (val == NULL) {
		return false;
	}
	if (index < list->size) {
		free(list->vals[index]);
		list->vals[index] = strdup(val);
		return true;
	}
	return false;
}

/**
 * Set value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if list is empty
 */
bool setFirstArrayListVal(ArrayList *list, const char *val) {
	return setArrayListValAt(list, 0, val);
}

/**
 * Set value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val value to setresult value location;
 *   cannot be null
 * @return false if list is empty
 */
bool setLastArrayListVal(ArrayList *list, const char *val) {
	if (list->size == 0) { // prevent negative size_t index
		return false;
	}
	return setArrayListValAt(list, list->size-1, val);
}

/**
 * Returns number of items in the array list.
 * @param list the array list
 * @return the number of items in the array list.
 */
size_t arrayListSize(ArrayList *list) {
    return list->size;
}

/**
 * Determines whether array list is empty.
 * @param list the array list
 * @return true if array list is empty, flase otherwise
 */
bool isArrayListEmpty(ArrayList *list) {
	return list->size == 0;
}

/**
 * Delete the array list value at the specified index.
 * @param list the array list
 * @param index the index
 * @return if index out of bounds
 */
bool deleteArrayListValAt(ArrayList *list, size_t index) {
	if (index >= list->size) {
		return false;
	}

	// free string before overwriting location
	free(list->vals[index]);

	// move elements down
	list->size--;
	for (int i = index; i < list->size; i++) {
		// move string down
		list->vals[i] = list->vals[i+1];
	}
	list->vals[list->size] = NULL; // clear last pointer

	return true;
}

/**
 * Delete the first array list value.
 * @param list the array list
 * @return if list is empty
 */
bool deleteFirstArrayListVal(ArrayList *list) {
	return deleteArrayListValAt(list, 0);
}

/**
 * Delete the last array list value.
 * @param list the array list
 * @return if list is empty
 */
bool deleteLastArrayListVal(ArrayList *list) {
	if (list->size > 0) {
		return deleteArrayListValAt(list, list->size-1);
	}
	return false;
}


/**
 * Deletes all array list values.
 * @param list the array list
 */
void deleteAllArrayListVals(ArrayList *list) {
//	for (int i = 0; i < list->size; i++) {
//		free(list->vals[i]);
//		list->vals[i] = NULL;
//	}
//	list->size = 0;
	// function returns false when list is empty
	while (deleteLastArrayListVal(list)) {}
}

/**
 * Delete the array list. Frees copies of all strings,
 * then the array list, and finally the list itself.
 * Strongly recommend resetting all struct fields to
 * default {NULL, 0, 0} before freeing struct in case
 * this function is called twice with same array list
 *
 * @param list the array list
 */
void deleteArrayList(ArrayList *list) {
	// free the strings in the array
	deleteAllArrayListVals(list);

	// free the list array
	free(list->vals);

	// set fields to safe values
	list->vals = NULL;
	list->capacity = 0;
	list->size = 0;

	// free the list itself
	free(list);
}
