/*
 * @file messagepriorityqueue.c
 *
 * This file implements the MessagePriorityQueue functions.
 *
 *  @since Nov 13, 2018
 *  @author Nam H Nguyen
 */
#include <stdlib.h>
#include "messagepriorityqueue.h"

/**
 * Create new message priority queue
 *
 * @param maxCapacity the maximum capacity of the queue
 * @return a new MessagePriorityQueue
 */
MessagePriorityQueue* newMPQ(size_t maxCapacity) {
    // Allocate queue size
	MessagePriorityQueue *queue = malloc(sizeof(MessagePriorityQueue));

    // Initialize queue to maxCapacity and priorities
    queue->maxCapacity = maxCapacity;
    queue->msgQueues = malloc(sizeof(ArrayDeque*) * 4);
    queue->msgQueues[highest] = newArrayDeque(maxCapacity);
    queue->msgQueues[high] = newArrayDeque(maxCapacity);
    queue->msgQueues[low] = newArrayDeque(maxCapacity);
    queue->msgQueues[lowest] = newArrayDeque(maxCapacity);

    return queue;
}

/**
 * Deallocate memory for message priority queue.
 *
 * @param queue the MessagePriorityQueue
 */
void deleteMPQ(MessagePriorityQueue* queue) {
    // free the msgQueues in deque
    deleteArrayDeque(*(queue->msgQueues));
    queue->msgQueues = NULL;

    // free the queue itself
    free(queue);
}

/**
 * Enqueue a message with given priority.
 *
 * @paam queue the message priority queue
 * @param message the message to enqueue
 * @param priority the message priority
 */
bool enqueueMessageMPQ(MessagePriorityQueue* queue, const char* message, Priority priority) {
    return enqueueArrayDequeVal(queue->msgQueues[priority], message);
}

/**
 * Dequeue highest priority message from the queue.
 *
 * @param queue the message priority queue
 * @param val the message to return; must be freed
 * @return true if message was returned, false otherwise
 */
bool dequeueMessageMPQ(MessagePriorityQueue* queue, char** val) {
    bool dequeued;

    for (Priority p = highest; p <= lowest ; p++) {
        dequeued = dequeueArrayDequeVal(queue->msgQueues[p], val);
        if (dequeued == false) {
        	continue;
        } else
        	break;
    }

    return dequeued;
}

/**
 * Peek highest priority message from the queue.
 *
 * @param queue the message priority queue
 * @param the message to return
 * @return true if message was returned, false otherwise
 */
bool peekMessageMPQ(MessagePriorityQueue* queue, const char** val) {
	bool peeked;

	for (Priority p = highest; p <= lowest ; p++) {
		peeked = peekFirstArrayDequeVal(queue->msgQueues[p], val);
	    if (peeked == false) {
	       	continue;
	    } else
	       	break;
	    }

	return peeked;
}

/**
 * Get total number of messages in the priority queue
 *
 * @param queue the MessagePriorityQueue
 * @return total number of messages
 */
size_t messageSizeMPQ(MessagePriorityQueue* queue) {

    return arrayDequeSize(queue->msgQueues[highest]) + arrayDequeSize(queue->msgQueues[high])
    	 + arrayDequeSize(queue->msgQueues[low]) + arrayDequeSize(queue->msgQueues[lowest]);
}

/**
 * Get number of messages with a given priority in the queue.
 *
 * @param queue the MessagePriorityQueue
 * @param priority the message priority
 * @return number of messages for given priority
 */
size_t messageSizeForPriorityMPQ(MessagePriorityQueue* queue, Priority priority) {
    return arrayDequeSize(queue->msgQueues[priority]);
}

/**
 *
 * Determines whether queue is empty
 *
 * @param queue the MessagePriorityQueue
 * @return true if queue is empty, false otherwise
 */
bool isEmptyMPQ(MessagePriorityQueue* queue) {
    return isArrayDequeEmpty(queue->msgQueues[highest]) + isArrayDequeEmpty(queue->msgQueues[high])
    	 + isArrayDequeEmpty(queue->msgQueues[low]) + isArrayDequeEmpty(queue->msgQueues[lowest]);
}
/**
 * Determines whether queue for given priority is empty
 *
 * @param queue the MessagePriorityQueue
 * @param priority the message priority
 * @return true if queue is empty for priority, false otherwise
 */
bool isEmptyForPriorityMPQ(MessagePriorityQueue* queue, Priority priority) {
    return isArrayDequeEmpty(queue->msgQueues[priority]);
}


