/*
 * messagepriorityqueue.h
 *
 * This file declares the MessagePriorityQueue and its functions.
 *
 *  @since Nov 13, 2018
 *  @author Nam H Nguyen
 */

#ifndef MESSAGEPRIORITYQUEUE_H_
#define MESSAGEPRIORITYQUEUE_H_

#include <stdbool.h>
#include "array_deque.h"

/**
 * The priorities for the MessagePriorityQueue
 */
typedef enum {
    highest,
    high,
    low,
    lowest
} Priority;

/**
 * The MessagePriorityQueue is an array of ArrayDeque pointers
 * for each Priority
 */
typedef struct {
    /** array of message queues */
    ArrayDeque** msgQueues;
    /** maximum capacity of queue */
    size_t maxCapacity;
} MessagePriorityQueue;

/**
 * Create new message priority queue
 *
 * @param maxCapacity the maximum capacity of the queue
 * @return a new MessagePriorityQueue
 */
MessagePriorityQueue* newMPQ(size_t maxCapacity);

/**
 * Deallocate memory for message priority queue.
 *
 * @param queue the MessagePriorityQueue
 */
void deleteMPQ(MessagePriorityQueue* queue);

/**
 * Enque a message with given priority.
 *
 * @paam queue the message priority queue
 * @param message the message to enqueue
 * @param priority the message priority
 */
bool enqueueMessageMPQ(MessagePriorityQueue* queue, const char* message, Priority priority);

/**
 * Dequeue highest priority message from the queue.
 *
 * @param queue the message priority queue
 * @param the message to return;
 * @return true if message was returned, false otherwise
 */
bool dequeueMessageMPQ(MessagePriorityQueue* queue, char** val);

/**
 * Peek highest priority message from the queue.
 *
 * @param queue the message priority queue
 * @param the message to return
 * @return true if message was returned, false otherwise
 */
bool peekMessageMPQ(MessagePriorityQueue* queue, const char** val);

/**
 * Get total number of messages in the priority queue
 *
 * @param queue the MessagePriorityQueue
 * @return total number of messages
 */
size_t messageSizeMPQ(MessagePriorityQueue* queue);

/**
 * Get number of messages with a given priority in the queue.
 *
 * @param queue the MessagePriorityQueue
 * @param priority the message priority
 * @return number of messages for given priority
 */
size_t messageSizeForPriorityMPQ(MessagePriorityQueue* queue, Priority priority);

/**
 * Determines whether queue is empty
 *
 * @param queue the MessagePriorityQueue
 * @return true if queue is empty, false otherwise
 */
bool isEmptyMPQ(MessagePriorityQueue* queue);

/**
 * Determines whether queue for given priority is empty
 *
 * @param queue the MessagePriorityQueue
 * @param priority the message priority
 * @return true if queue is empty for priority, false otherwise
 */
bool isEmptyForPriorityMPQ(MessagePriorityQueue* queue, Priority priority);

#endif /* MESSAGEPRIORITYQUEUE_H_ */
