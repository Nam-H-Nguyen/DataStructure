/*
 * @file array_queue.c
 *
 * Code example of ArrayQueue for lecture 8.
 *
 * Operations add and delete from the front because
 * that is more efficient for linked lists.
 *
 *  @since Oct 24, 2017
 *  @author philip gust
 */
#include "array_queue.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Create an array queue with a max capacity.
 *
 * @param maxCapacity maximum capacity of ArrayQueue.
 *     Use SIZE_MAX for unlimited capacity
 * @return the allocated array queue
 */
ArrayQueue *newArrayQueue(size_t maxCapacity) {
    ArrayQueue *queue = malloc(sizeof(ArrayQueue));
    queue->list = newArrayList(maxCapacity);

    return queue;
}

/**
 * Enqueue value onto the queue. Cannot add NULL string to the queue.
 * @param queue the ArrayQueue
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool enqueueArrayQueueVal(ArrayQueue *queue, const char *val) {
    return addLastArrayListVal(queue->list, val);
}

/**
 * Get the head queue value without removing it.
 * @param queue the ArrayQueue
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if empty or operation is not supported
 */
bool peekArrayQueueVal(ArrayQueue *queue, const char **val) {
    return getFirstArrayListVal(queue->list, val);
}

/**
 * Set the queue head to a new value.
 * @param queue the ArrayQueue
 * @param val the value to set; cannot be null
 * @return false if value is null or operation is not supported
 */
bool pokeArrayQueueVal(ArrayQueue *queue, const char *val) {
    return setFirstArrayListVal(queue->list, val);
}

/**
 * Delete the array queue value.
 * @param queue the array queue
 * @param val result parameter is pointer to result value location;
 *   cannot be null; returned value must be freed
 * @return if queue is empty
 */
bool dequeueArrayQueueVal(ArrayQueue *queue, char **val) {
    const char* localVal;
    // copy first because drop causes returned value to be freed
    if (peekArrayQueueVal(queue, &localVal)) {
        *val = strdup(localVal);
        dropArrayQueueVal(queue);
        return true;
    }
    return false;
}

/**
 * Deletes top value from the queue.
 * @param queue the ArrayQueue
 * @return false if the queue is empty or operation is not supported
 */
bool dropArrayQueueVal(ArrayQueue *queue) {
    return deleteFirstArrayListVal(queue->list);
}

/**
 * Drops all array queue values.
 * @param queue the ArrayQueue
 */
void dropAllArrayQueueVals(ArrayQueue *queue) {
    deleteAllArrayListVals(queue->list);
}

/**
 * Returns number of items in the array queue.
 * @param queue the ArrayQueue
 * @return the number of items in the array queue.
 */
size_t arrayQueueSize(ArrayQueue *queue) {
    return arrayListSize(queue->list);
}

/**
 * Determines whether array queue is empty.
 * @param queue the ArrayQueue
 * @return true if array queue is empty, flase otherwise
 */
bool isArrayQueueEmpty(ArrayQueue *queue) {
    return isArrayListEmpty(queue->list);
}

/**
 * Delete the array queue. Frees copies of all strings,
 * then the array list, and finally the queue itself.
 *
 * @param queue the ArrayQueue
 */
void deleteArrayQueue(ArrayQueue *queue) {
    // free the strings in the array
    deleteArrayList(queue->list);
    queue->list = NULL;

    // free the queue itself
    free(queue);
}

/**
 * Print array queue for diagnostic purposes.
 *
 * @param queue the ArrayQueue
 */
void printArrayQueue(ArrayQueue *queue) {
    printArrayList(queue->list);
}
