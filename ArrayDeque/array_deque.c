/*
 * @file array_deque.c
 *
 * Code example of ArrayDeque for lecture 8.
 *
 * Operations add and delete from the front because
 * that is more efficient for linked lists.
 *
 *  @date Oct 24, 2018
 *  @author: Nam H. Nguyen
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_deque.h"


/**
 * Create an array deque with a max capacity.
 *
 * @param maxCapacity maximum capacity of ArrayDeque.
 *     Use SIZE_MAX for unlimited capacity
 * @return the allocated array deque
 */
ArrayDeque *newArrayDeque(size_t maxCapacity) {
    ArrayDeque *deque = malloc(sizeof(ArrayDeque));
    deque->list = newArrayList(maxCapacity);

    return deque;
}

/**
 * Add value onto the deque first. Cannot add NULL string to the deque.
 * @param deque the ArrayDeque
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool addFirstArrayDequeVal(ArrayDeque *deque, const char *val) {
    return addFirstArrayListVal(deque->list, val);
}

/**
 * Add value onto the deque last. Cannot add NULL string to the deque.
 * @param deque the ArrayDeque
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool addLastArrayDequeVal(ArrayDeque *deque, const char *val) {
    return addLastArrayListVal(deque->list, val);
}

/**
 * Enqeque value onto the deque. Cannot add NULL string to the deque.
 * @param deque the ArrayDeque
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool enqueueArrayDequeVal(ArrayDeque *deque, const char *val) {
    return addLastArrayDequeVal(deque, val);
}

/**
 * Push value onto the deque. Cannot add NULL string to the deque.
 * @param deque the ArrayDeque
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool pushArrayDequeVal(ArrayDeque *deque, const char *val) {
    return addLastArrayDequeVal(deque, val);
}

/**
 * Get the first deque value without removing it.
 * @param deque the ArrayDeque
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekFirstArrayDequeVal(ArrayDeque *deque, const char **val) {
    return getFirstArrayListVal(deque->list, val);
}

/**
 * Get the last deque value without removing it.
 * @param deque the ArrayDeque
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekLastArrayDequeVal(ArrayDeque *deque, const char **val) {
    return getLastArrayListVal(deque->list, val);
}

/**
 * Get the head deque value without removing it.
 * @param deque the ArrayDeque
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekHeadArrayDequeVal(ArrayDeque *deque, const char **val) {
    return peekFirstArrayDequeVal(deque, val);
}

/**
 * Get the top deque value without removing it.
 * @param deque the ArrayDeque
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekTopArrayDequeVal(ArrayDeque *deque, const char **val) {
    return peekLastArrayDequeVal(deque, val);
}

/**
 * Set the deque first to a new value.
 * @param deque the ArrayDeque
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeFirstArrayDequeVal(ArrayDeque *deque, const char *val) {
    return setFirstArrayListVal(deque->list, val);
}

/**
 * Set the deque last to a new value.
 * @param deque the ArrayDeque
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeLastArrayDequeVal(ArrayDeque *deque, const char *val) {
    return setLastArrayListVal(deque->list, val);
}
/**
 * Set the deque head to a new value.
 * @param deque the ArrayDeque
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeHeadArrayDequeVal(ArrayDeque *deque, const char *val) {
    return pokeFirstArrayDequeVal(deque, val);
}
/**
 * Set the deque top to a new value.
 * @param deque the ArrayDeque
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeTopArrayDequeVal(ArrayDeque *deque, const char *val) {
    return pokeLastArrayDequeVal(deque, val);
}

/**
 * Delete the first array deque value.
 * @param deque the array deque
 * @param val result parameter is pointer to result value location;
 *   cannot be null, must be freed
 * @return if deque is empty
 */
bool deleteFirstArrayDequeVal(ArrayDeque *deque, char **val) {
    const char* localVal;
    // copy first because drop causes returned value to be freed
    if (peekFirstArrayDequeVal(deque, &localVal)) {
        *val = strdup(localVal);
        dropFirstArrayDequeVal(deque);
        return true;
    }
    return false;
}

/**
 * Delete the last array deque value.
 * @param deque the array deque
 * @param val result parameter is pointer to result value location;
 *   cannot be null, must be freed
 * @return if deque is empty
 */
bool deleteLastArrayDequeVal(ArrayDeque *deque, char **val) {
    const char* localVal;
    // copy first because drop causes returned value to be freed
    if (peekLastArrayDequeVal(deque, &localVal)) {
        *val = strdup(localVal);
        dropLastArrayDequeVal(deque);
        return true;
    }
    return false;
}

/**
 * Dequeue the array deque value.
 * @param deque the array deque
 * @param val result parameter is pointer to result value location;
 *   cannot be null, must be freed
 * @return if deque is empty
 */
bool dequeueArrayDequeVal(ArrayDeque *deque, char **val) {
    const char* localVal;
    // copy first because drop causes returned value to be freed
    if (peekHeadArrayDequeVal(deque, &localVal)) {
        *val = strdup(localVal);
        dropHeadArrayDequeVal(deque);
        return true;
    }
    return false;
}

/**
 * Pop the array deque value.
 * @param deque the array deque
 * @param val result parameter is pointer to result value location;
 *   cannot be null, must be freed
 * @return if deque is empty
 */
bool popArrayDequeVal(ArrayDeque *deque, char **val) {
    const char* localVal;
    // copy first because drop causes returned value to be freed
    if (peekTopArrayDequeVal(deque, &localVal)) {
        *val = strdup(localVal);
        dropTopArrayDequeVal(deque);
        return true;
    }
    return false;
}

/**
 * Drops first value from the deque.
 * @param deque the ArrayDeque
 * @return false if the deque is empty or operation is not supported
 */
bool dropFirstArrayDequeVal(ArrayDeque *deque) {
    return deleteFirstArrayListVal(deque->list);
}

/**
 * Drops first value from the deque.
 * @param deque the ArrayDeque
 * @return false if the deque is empty or operation is not supported
 */
bool dropLastArrayDequeVal(ArrayDeque *deque)  {
    return deleteLastArrayListVal(deque->list);
}

/**
 * Drops head value from the deque.
 * @param deque the ArrayDeque
 * @return false if the deque is empty or operation is not supported
 */
bool dropHeadArrayDequeVal(ArrayDeque *deque) {
    return dropFirstArrayDequeVal(deque);
}

/**
 * Drops top value from the deque.
 * @param deque the ArrayDeque
 * @return false if the deque is empty or operation is not supported
 */
bool dropTopArrayDequeVal(ArrayDeque *deque) {
    return dropLastArrayDequeVal(deque);
}

/**
 * Exchange the top two deque values.
 * @param deque the ArrayDeque
 * @return false if the stack does not have two values or
 *   operation is not supported
 */
bool swapTopArrayDequeVal(ArrayDeque *deque) {
    size_t size = arrayDequeSize(deque);
    if (size >= 2) {
        char *val1, *val2;
        popArrayDequeVal(deque, &val1);
        popArrayDequeVal(deque,&val2);
        pushArrayDequeVal(deque, val1);
        pushArrayDequeVal(deque, val2);

        // must free because pop returns allocated storage
        free(val1);
        free(val2);
        return true;
    }
    return false;
}

/**
 * Pushes another copy of the top value onto the deque.
 * @param stack the ArrayStack
 * @return false if the stack is empty or operation is not supported
 */
bool dupTopArrayDequeVal(ArrayDeque *deque) {
    const char *val;
    if (peekTopArrayDequeVal(deque, &val)) {
        return pushArrayDequeVal(deque, val);
    }
    return false;
}

/**
 * Drops all array deque values.
 * @param deque the ArrayDeque
 */
void dropAllArrayDequeVals(ArrayDeque *deque) {
    deleteAllArrayListVals(deque->list);
}

/**
 * Returns number of items in the array deque.
 * @param deque the ArrayDeque
 * @return the number of items in the array deque.
 */
size_t arrayDequeSize(ArrayDeque *deque) {
    return arrayListSize(deque->list);
}

/**
 * Determines whether array deque is empty.
 * @param deque the ArrayDeque
 * @return true if array deque is empty, flase otherwise
 */
bool isArrayDequeEmpty(ArrayDeque *deque) {
    return isArrayListEmpty(deque->list);
}

/**
 * Delete the array deque. Frees copies of all strings,
 * then the array list, and finally the deque itself.
 *
 * @param deque the ArrayDeque
 */
void deleteArrayDeque(ArrayDeque *deque) {
    // free the strings in the array
    deleteArrayList(deque->list);
    deque->list = NULL;

    // free the deque itself
    free(deque);
}

/**
 * Print array deque for diagnostic purposes.
 *
 * @param deque the ArrayDeque
 */
void printArrayDeque(ArrayDeque *deque) {
    printArrayList(deque->list);
}

/**
 * Print array deque as queue for diagnostic purposes.
 *
 * @param deque the ArrayDeque
 */
void printQueueArrayDeque(ArrayDeque *deque) {
    printArrayList(deque->list);
}

/**
 * Print array deque as stack for diagnostic purposes.
 *
 * @param deque the array deque
 */
void printStackArrayDeque(ArrayDeque *deque) {
    size_t size = arrayListSize(deque->list);
    printf("stack (%lu):\n", size);
    const char *val;
    for (int i = size-1; i >= 0; i--) {
        getArrayListValAt(deque->list, i, &val);
        printf("%s\n", val);
    }
}
