/*
 * array_queue.h
 *
 *  @date Oct 30, 2018
 *  @author: Nam H. Nguyen
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"

/** array queue data structure */
typedef struct {
    /** Uses ArrayList as backing store */
    ArrayList *list;
} ArrayQueue;

/**
 * Create an array queue with a max capacity.
 *
 * @param maxCapacity maximum capacity of ArrayQueue.
 *     Use SIZE_MAX for unlimited capacity
 * @return the allocated array queue
 */
ArrayQueue *newArrayQueue(size_t maxCapacity);

/**
 * Enqueue value onto the queue. Cannot add NULL string to the queue.
 * @param queue the ArrayQueue
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool enqueueArrayQueueVal(ArrayQueue *queue, const char *val);

/**
 * Get the top queue value without removing it.
 * @param queue the ArrayQueue
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekArrayQueueVal(ArrayQueue *queue, const char **val);

/**
 * Set the queue top to a new value.
 * @param queue the ArrayQueue
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeArrayQueueVal(ArrayQueue *queue, const char *val);

/**
 * Dequeue the array queue value at the specified index.
 * @param queue the array queue
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return if queue is empty
 */
bool dequeueArrayQueueVal(ArrayQueue *queue, char **val);

/**
 * Deletes top value from the queue.
 * @param queue the ArrayQueue
 * @return false if the queue is empty or operation is not supported
 */
bool dropArrayQueueVal(ArrayQueue *queue);

/**
 * Drops all array queue values.
 * @param list the array list
 */
void dropAllArrayQueueVals(ArrayQueue *queue);

/**
 * Returns number of items in the array queue.
 * @param queue the array queue
 * @return the number of items in the array queue.
 */
size_t arrayQueueSize(ArrayQueue *queue);

/**
 * Determines whether array queue is empty.
 * @param queue the array queue
 * @return true if array queue is empty, false otherwise
 */
bool isArrayQueueEmpty(ArrayQueue *queue);

/**
 * Delete the array queue . Frees copies of all strings,
 * then the array queue, and finally the queue itself.
 *
 * @param queue the array queue
 */
void deleteArrayQueue(ArrayQueue *queue);

/**
 * Print array queue for diagnostic purposes.
 *
 * @param queue the array queue
 */
void printArrayQueue(ArrayQueue *queue);

#endif /* ARRAY_QUEUE_H_ */
