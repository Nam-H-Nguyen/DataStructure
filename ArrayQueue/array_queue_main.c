/*
 * @file array_queue_main.c
 *
 * Code example of ArrayQueue for lecture 8.
 *
 *  @since Oct 24, 2018
 *  @author philip gust
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_queue.h"

/**
 * Test functions.
 */
int main(void) {
    printf("Creating array queue\n");
    ArrayQueue *queue = newArrayQueue(5);
    bool empty = isArrayQueueEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size_t size = arrayQueueSize(queue);
    printf("queue size: %ld\n", size);

    printf("\nadding 5 values\n");
    enqueueArrayQueueVal(queue, "A");
    enqueueArrayQueueVal(queue, "B");
    enqueueArrayQueueVal(queue, "C");
    enqueueArrayQueueVal(queue, "D");
    enqueueArrayQueueVal(queue, "E");
    empty = isArrayQueueEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size = arrayQueueSize(queue);
    printf("queue size: %ld\n", size);
    printArrayQueue(queue);

    const char *val;
    bool status = peekArrayQueueVal(queue, &val);
    if (status) {
        printf("\npeek value: %s\n", val);
    } else {
        printf("\ncannot peek at top\n");
    }

    status = pokeArrayQueueVal(queue, "Z");
    if (status) {
        printf("\npoked top: Z\n");
        printArrayQueue(queue);
    } else {
        printf("\ncannot poke top\n");
    }

    status = dropArrayQueueVal(queue);
    if (status) {
        printf("\ndropped top\n");
        printArrayQueue(queue);
    } else {
        printf("\ncannot drop top\n");
    }

    empty = isArrayQueueEmpty(queue);
    printf("\nqueue empty? %s\n", empty ? "true" : "false");
    size = arrayQueueSize(queue);
    printf("queue size: %ld\n", size);

    printf("\ndropping all array queue values\n");
    dropAllArrayQueueVals(queue);
    empty = isArrayQueueEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size = arrayQueueSize(queue);
    printf("queue size: %ld\n", size);
    printArrayQueue(queue);

    printf("\ndeleting array queue\n");
    deleteArrayQueue(queue);

    printf("program exiting\n");

    return EXIT_SUCCESS;
}
