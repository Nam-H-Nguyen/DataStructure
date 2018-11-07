/**
 * @file array_list.c
 *
 * Implementation for variable-size array list.
 *
 * @date Nov 13, 2018
 * @author Nam H Nguyen
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

/**
 * Create an array list with a fixed capacity.
 *
 * @param maxCapacity capacity of the ArrayList.
 * @return the allocated array list
 */
ArrayList *newArrayList(size_t maxCapacity) {
    ArrayList *list = malloc(sizeof(ArrayList));
    list->size = 0;
    list->capacity = (maxCapacity < 2) ? maxCapacity : 2;  // small power of 2
    list->maxCapacity = maxCapacity;
    list->vals = calloc(list->capacity, sizeof(char*)); // nulls ptrs

    return list;
}

/**
 * Ensure array has sufficient capacity to add a new element. If
 * it currently does not, grow the array so that it does, up to
 * the maximum capacity.
 *
 * @param list the array list
 * @return true if list has sufficient size for a new element,
 *   false if at maximum capacity or there is no room to grow it
 */
static bool ensureArrayCapacity(ArrayList *list) {
    // need to grow array if size is at capacity
    if (list->size == list->capacity) {
        // done if already at maxCapacity
        if (list->capacity == list->maxCapacity) {
            return false;
        }

        // if over, use maxCapacity
        size_t newCapacity;
        if (list->maxCapacity - list->capacity < list->capacity) {
            // no room to double: set to maxCapacity
            newCapacity = list->maxCapacity;
        } else {
            // double current capacity
            newCapacity = list->capacity * 2;
        }

        // realloc memory to new capacity
        char **newVals = realloc(list->vals, newCapacity * sizeof(char*));
        if (newVals == NULL) { // not enough memory to reallocate
            return false;
        }
        // initialize new memory to NULL
        for (int i = list->capacity; i < newCapacity; i++) {
            newVals[i] = NULL;
        }
        list->capacity = newCapacity;
        list->vals = newVals;
    }
    return true;
}

/**
 * Add value to list at index. Cannot add NULL string to the list.
 *
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to insert; value will be copied to store
 * @return false if index out of bounds, exceeds max capacity
 */
bool addArrayListValAt(ArrayList *list, size_t index, const char *val) {
    // beyond end of list
    if (index > list->size) {
        return false;
    }

    // ensure that array has sufficient capacity to add an element
    if (!ensureArrayCapacity(list)) {
        return false;
    }

    // move elements down to make room for new element at index position
    for (size_t i = list->size; i > index; i--) {
        list->vals[i] = list->vals[i-1];
    }
    list->vals[index] = NULL;  // now empty
    list->size++;

    // set value at index position
    setArrayListValAt(list, index, val);

    return true;
}

/**
 * Add value to start of list.
 *
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store
 * @return false if exceeds capacity
 */
bool addFirstArrayListVal(ArrayList *list, const char *val) {
    return addArrayListValAt(list, 0, val);
}

/**
 * Add value to end of list.
 *
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store
 * @return false if exceeds capacity
 */
bool addLastArrayListVal(ArrayList *list, const char *val) {
    return addArrayListValAt(list, list->size, val);
}

/**
 * Get value at index.
 *
 * @param list the ArrayList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be NULL
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
 *
 * @param list the ArrayList
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
 *
 * @param list the ArrayList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be NULL
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
 *
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to set
 * @return false if index out of bounds
 */
bool setArrayListValAt(ArrayList *list, size_t index, const char *val) {
    if (index < list->size) {
        free(list->vals[index]);
        list->vals[index] = strdup(val);  // must copy input string
        return true;
    }
    return false;
}

/**
 * Set value at first index.
 *
 * @param list the ArrayList
 * @param val the value to set
 * @return false if list is empty
 */
bool setFirstArrayListVal(ArrayList *list, const char *val) {
    return setArrayListValAt(list, 0, val);
}

/**
 * Set value at last index.
 *
 * @param list the ArrayList
 * @param val the value to set
 * @return false if list is empty
 */
bool setLastArrayListVal(ArrayList *list, const char *val) {
    if (list->size == 0) { // prevent negative size_t index
        return false;
    }
    return setArrayListValAt(list, list->size-1, val);
}

/**
 * Returns number of values in the array list.
 *
 * @param list the ArrayList
 * @return the number of values in the array list.
 */
size_t arrayListSize(ArrayList *list) {
    return list->size;
}

/**
 * Determines whether array list is empty.
 *
 * @param list the ArrayList
 * @return true if array list is empty, false otherwise
 */
bool isArrayListEmpty(ArrayList *list) {
    return list->size == 0;
}

/**
 * Delete the array list value at the specified index.
 *
 * @param list the ArrayList
 * @param index the index
 * @return false if index out of bounds
 */
bool deleteArrayListValAt(ArrayList *list, size_t index) {
    if (index >= list->size) {
        return false;
    }

    // free string before overwriting location
    free(list->vals[index]);

    // move elements down
    list->size--;
    for (size_t i = index; i < list->size; i++) {
        list->vals[i] = list->vals[i+1];
    }
    list->vals[list->size] = NULL; // clear last pointer

    return true;
}

/**
 * Delete the first array list value.
 *
 * @param list the ArrayList
 * @return false if list is empty
 */
bool deleteFirstArrayListVal(ArrayList *list) {
    return deleteArrayListValAt(list, 0);
}

/**
 * Delete the last array list value.
 *
 * @param list the ArrayList
 * @return false if list is empty
 */
bool deleteLastArrayListVal(ArrayList *list) {
    if (list->size > 0) {
        return deleteArrayListValAt(list, list->size-1);
    }
    return false;
}


/**
 * Deletes all array list values.
 *
 * @param list the ArrayList
 */
void deleteAllArrayListVals(ArrayList *list) {
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
 * @param list the ArrayList
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

/**
 * Print the array list.
 * @param list the ArrayList
 */
void printArrayList(ArrayList *list) {
    printf("( ");
    const char *val;
    for (size_t i = 0; 		getArrayListValAt(list, i, &val); i++) {
        printf("\"%s\" ", val);
    }
    printf(")\n");
}

