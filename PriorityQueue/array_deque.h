/*
 * array_deque.h
 *
 *  @since Nov 13, 2018
 *  @author Nam H Nguyen
 */

#ifndef ARRAY_DEQUE_H_
#define ARRAY_DEQUE_H_

#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"

/** array deque data structure */
typedef struct {
    /** Uses ArrayList as backing store */
    ArrayList *list;
} ArrayDeque;

/**
 * Create an array deque with amax capacity.
 *
 * @param maxCapacity maximum capacity of ArrayDeque.
 *     Use SIZE_MAX for unlimited capacity
 * @return the allocated array deque
 */
ArrayDeque *newArrayDeque(size_t maxCapacity);

/**
 * Add value onto the deque first. Cannot add NULL string to the deque.
 * @param deque the ArrayDeque
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool addFirstArrayDequeVal(ArrayDeque *deque, const char *val);

/**
 * Add value onto the deque last. Cannot add NULL string to the deque.
 * @param deque the ArrayDeque
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool addLastArrayDequeVal(ArrayDeque *deque, const char *val);

/**
 * Enqeque value onto the deque. Cannot add NULL string to the deque.
 * @param deque the ArrayDeque
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool enqueueArrayDequeVal(ArrayDeque *deque, const char *val);

/**
 * Push value onto the deque. Cannot add NULL string to the deque.
 * @param deque the ArrayDeque
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool pushArrayDequeVal(ArrayDeque *deque, const char *val);

/**
 * Get the first deque value without removing it.
 * @param deque the ArrayDeque
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekFirstArrayDequeVal(ArrayDeque *deque, const char **val);

/**
 * Get the last deque value without removing it.
 * @param deque the ArrayDeque
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekLastArrayDequeVal(ArrayDeque *deque, const char **val);

/**
 * Get the head deque value without removing it.
 * @param deque the ArrayDeque
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekHeadArrayDequeVal(ArrayDeque *deque, const char **val);

/**
 * Get the top deque value without removing it.
 * @param deque the ArrayDeque
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekTopArrayDequeVal(ArrayDeque *deque, const char **val);

/**
 * Set the deque first to a new value.
 * @param deque the ArrayDeque
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeFirstArrayDequeVal(ArrayDeque *deque, const char *val);

/**
 * Set the deque last to a new value.
 * @param deque the ArrayDeque
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeLastArrayDequeVal(ArrayDeque *deque, const char *val);
/**
 * Set the deque head to a new value.
 * @param deque the ArrayDeque
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeHeadArrayDequeVal(ArrayDeque *deque, const char *val);
/**
 * Set the deque top to a new value.
 * @param deque the ArrayDeque
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeTopArrayDequeVal(ArrayDeque *deque, const char *val);

/**
 * Delete the first array deque value.
 * @param deque the array deque
 * @param val result parameter is pointer to result value location;
 *   cannot be null, must be freed
 * @return if deque is empty
 */
bool deleteFirstArrayDequeVal(ArrayDeque *deque, char **val);

/**
 * Delete the last array deque value.
 * @param deque the array deque
 * @param val result parameter is pointer to result value location;
 *   cannot be null, must be freed
 * @return if deque is empty
 */
bool deleteLastArrayDequeVal(ArrayDeque *deque, char **val);

/**
 * Dequeue the array deque value.
 * @param deque the array deque
 * @param val result parameter is pointer to result value location;
 *   cannot be null, must be freed
 * @return if deque is empty
 */
bool dequeueArrayDequeVal(ArrayDeque *deque, char **val);

/**
 * Pop the array deque value.
 * @param deque the array deque
 * @param val result parameter is pointer to result value location;
 *   cannot be null, must be freed
 * @return if deque is empty
 */
bool popArrayDequeVal(ArrayDeque *deque, char **val);

/**
 * Drops first value from the deque.
 * @param deque the ArrayDeque
 * @return false if the deque is empty or operation is not supported
 */
bool dropFirstArrayDequeVal(ArrayDeque *deque);

/**
 * Drops first value from the deque.
 * @param deque the ArrayDeque
 * @return false if the deque is empty or operation is not supported
 */
bool dropLastArrayDequeVal(ArrayDeque *deque);

/**
 * Drops head value from the deque.
 * @param deque the ArrayDeque
 * @return false if the deque is empty or operation is not supported
 */
bool dropHeadArrayDequeVal(ArrayDeque *deque);

/**
 * Drops top value from the deque.
 * @param deque the ArrayDeque
 * @return false if the deque is empty or operation is not supported
 */
bool dropTopArrayDequeVal(ArrayDeque *deque);

/**
 * Exchange the top two deque values.
 * @param stack the ArrayStack
 * @return false if the stack does not have two values or
 *   operation is not supported
 */
bool swapTopArrayDequeVal(ArrayDeque *stack);

/**
 * Pushes another copy of the top value onto the deque.
 * @param stack the ArrayStack
 * @return false if the stack is empty or operation is not supported
 */
bool dupTopArrayDequeVal(ArrayDeque *stack);

/**
 * Drops all array deque values.
 * @param list the array list
 */
void dropAllArrayDequeVals(ArrayDeque *deque);

/**
 * Returns number of items in the array deque.
 * @param deque the array deque
 * @return the number of items in the array deque.
 */
size_t arrayDequeSize(ArrayDeque *deque);

/**
 * Determines whether array deque is empty.
 * @param deque the array deque
 * @return true if array deque is empty, false otherwise
 */
bool isArrayDequeEmpty(ArrayDeque *deque);

/**
 * Delete the array deque . Frees copies of all strings,
 * then the array deque, and finally the deque itself.
 *
 * @param deque the array deque
 */
void deleteArrayDeque(ArrayDeque *deque);

/**
 *
 * @param deque the array deque
 */
void printArrayDeque(ArrayDeque *deque);

/**
 * Print array deque as queue for diagnostic purposes.
 *
 * @param deque the ArrayDeque
 */
void printQueueArrayDeque(ArrayDeque *deque);

/**
 * Print array deque as stack for diagnostic purposes.
 *
 * @param deque the array deque
 */
void printStackArrayDeque(ArrayDeque *deque);

#endif /* ARRAY_DEQUE_H_ */
