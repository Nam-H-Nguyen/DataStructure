/**
 * @file array_list.h
 *
 * Declarations for variable-size array list.
 *
 * @date Oct 22, 2018
 * @author philip gust
 */

#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include <stdbool.h>
#include <stdlib.h>

/** Array List data structure */
typedef struct {
	/** Allocated array storage */
	char** vals;
	/** The current size */
	size_t size;
	/** Capacity of allocated array */
	size_t capacity;
	/** Maximum capacity of allocated array */
	size_t maxCapacity;
} ArrayList;

/**
 * Create an array list with a fixed capacity.
 *
 * @param maxCapacity maximum capacity of the ArrayList.
 * @return the allocated array list
 */
ArrayList *newArrayList(size_t maxCapacity);

/**
 * Add value to list at index.
 *
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to insert; value will be copied to store
 * @return false if index out of bounds, exceeds capacity
 */
bool addArrayListValAt(ArrayList *list, size_t index, const char *val);

/**
 * Add value to start of list. Cannot add NULL string to the list.
 *
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store
 * @return false if exceeds capacity
 */
bool addFirstArrayListVal(ArrayList *list, const char *val);

/**
 * Add value to end of list.
 *
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store
 * @return false if exceeds capacity
 */
bool addLastArrayListVal(ArrayList *list, const char *val);

/**
 * Get value at index.
 *
 * @param list the ArrayList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be NULL
 * @return false if index out of bounds
 */
bool getArrayListValAt(ArrayList *list, size_t index, const char **val);

/**
 * Get value at first index.
 *
 * @param list the ArrayList
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if list is empty
 */
bool getFirstArrayListVal(ArrayList *list, const char **val);

/**
 * Get value at last index.
 *
 * @param list the ArrayList
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if list is empty
 */
bool getLastArrayListVal(ArrayList *list, const char **val);

/**
 * Set value at index.
 *
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to set
 * @return false if index out of bounds
 */
bool setArrayListValAt(ArrayList *list, size_t index, const char *val);

/**
 * Set value at first index.
 *
 * @param list the ArrayList
 * @param val the value to set
 * @return false if list is empty
 */
bool setFirstArrayListVal(ArrayList *list, const char *val);

/**
 * Set value at last index.
 *
 * @param list the ArrayList
 * @param val the value to set
 * @return false if list is empty
 */
bool setLastArrayListVal(ArrayList *list, const char *val);

/**
 * Returns number of items in the array list.
 * @param list the ArrayList
 * @return the number of items in the array list.
 */
size_t arrayListSize(ArrayList *list);

/**
 * Determines whether array list is empty.
 *
 * @param list the ArrayList
 * @return true if array list is empty, false otherwise
 */
bool isArrayListEmpty(ArrayList *list);

/**
 * Delete the array list value at the specified index.
 *
 * @param list the ArrayList
 * @param index the index
 * @return if index out of bounds
 */
bool deleteArrayListValAt(ArrayList *list, size_t index);

/**
 * Delete the fist array list value.
 * @param list the ArrayList
 * @return if list is empty
 */
bool deleteFirstArrayListVal(ArrayList *list);

/**
 * Delete the last array list value.
 *
 * @param list the ArrayList
 * @return if list is empty
 */
bool deleteLastArrayListVal(ArrayList *list);

/**
 * Deletes all array list values.
 *
 * @param list the ArrayList
 */
void deleteAllArrayListVals(ArrayList *list) ;


/**
 * Delete the array list . Frees copies of all strings,
 * then the array list, and finally the list itself.
 * Strongly recommend resetting all struct fields to
 * default {NULL, 0, 0, 0} before freeing struct in case
 * this function is called twice with same array list
 *
 * @param list the ArrayList
 */
void deleteArrayList(ArrayList *list);

/**
 * Print the array list.
 * @param list the ArrayList
 */
void printArrayList(ArrayList *list);


#endif /* ARRAY_LIST_H_ */
