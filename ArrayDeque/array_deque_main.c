/*
 * @file array_dequeue_main.c
 *
 * Code example of ArrayDeque for lecture 8.
 *
 *  @since Oct 24, 2018
 *  @author philip gust
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_deque.h"

/**
 * Test ArrayDeque as Deque
 */
void testArrayDequeAsDeque(void) {
    printf("\nTesting ArrayDeque as Deque\n");

    printf("Creating array deque\n");
    ArrayDeque *queue = newArrayDeque(5);
    bool empty = isArrayDequeEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size_t size = arrayDequeSize(queue);
    printf("queue size: %ld\n", size);

    printf("\nadding 5 values\n");

    addFirstArrayDequeVal(queue, "A");
    printf("\nadd first \"A\"\n");
    addLastArrayDequeVal(queue, "B");
    printf("add last \"B\"\n");
    addFirstArrayDequeVal(queue, "C");
    printf("add first \"C\"\n");
    addLastArrayDequeVal(queue, "D");
    printf("add last \"D\"\n");
    addFirstArrayDequeVal(queue, "E");
    printf("add first \"E\"\n");
    empty = isArrayDequeEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(queue);
    printf("queue size: %ld\n", size);
    printArrayDeque(queue);

    const char *val;
    bool status = peekFirstArrayDequeVal(queue, &val);
    if (status) {
        printf("\npeek value: %s\n", val);
    } else {
        printf("\ncannot peek at head\n");
    }

    status = pokeFirstArrayDequeVal(queue, "Z");
    if (status) {
        printf("\npoked first: Z\n");
        printArrayDeque(queue);
    } else {
        printf("\ncannot poke first\n");
    }

    status = dropFirstArrayDequeVal(queue);
    if (status) {
        printf("\ndropped head\n");
        printArrayDeque(queue);
    } else {
        printf("\ncannot drop first\n");
    }

    empty = isArrayDequeEmpty(queue);
    printf("\nqueue empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(queue);
    printf("queue size: %ld\n", size);

    char *val2;
    status = deleteLastArrayDequeVal(queue, &val2);
    if (status) {
        printf("\ndelete last: %s\n", val2);
        printArrayDeque(queue);
        free(val2);
    } else {
        printf("\ncannot delete last\n");
    }

    printf("\ndropping all array queue values\n");
    dropAllArrayDequeVals(queue);
    empty = isArrayDequeEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(queue);
    printf("queue size: %ld\n", size);
    printArrayDeque(queue);

    printf("\ndeleting array queue\n");
    deleteArrayDeque(queue);

    printf("\nDone testing ArrayDeque as Deque\n");
}

/**
 * Test ArrayDeque as Queue
 */
void testArrayDequeAsQueue(void) {
    printf("\nTesting ArrayDeque as Queue\n");

    printf("Creating array ArrayDeque\n");
    ArrayDeque *queue = newArrayDeque(5);
    bool empty = isArrayDequeEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size_t size = arrayDequeSize(queue);
    printf("queue size: %ld\n", size);

    printf("\nadding 5 values\n");
    enqueueArrayDequeVal(queue, "A");
    enqueueArrayDequeVal(queue, "B");
    enqueueArrayDequeVal(queue, "C");
    enqueueArrayDequeVal(queue, "D");
    enqueueArrayDequeVal(queue, "E");
    empty = isArrayDequeEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(queue);
    printf("queue size: %ld\n", size);
    printQueueArrayDeque(queue);

    const char *val;
    bool status = peekHeadArrayDequeVal(queue, &val);
    if (status) {
        printf("\npeek value: %s\n", val);
    } else {
        printf("\ncannot peek at head\n");
    }

    status = pokeHeadArrayDequeVal(queue, "Z");
    if (status) {
        printf("\npoked head: Z\n");
        printQueueArrayDeque(queue);
    } else {
        printf("\ncannot poke head\n");
    }

    status = dropHeadArrayDequeVal(queue);
    if (status) {
        printf("\ndropped head\n");
        printQueueArrayDeque(queue);
    } else {
        printf("\ncannot drop head\n");
    }

    empty = isArrayDequeEmpty(queue);
    printf("\nqueue empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(queue);
    printf("queue size: %ld\n", size);

    printf("\ndropping all array queue values\n");
    dropAllArrayDequeVals(queue);
    empty = isArrayDequeEmpty(queue);
    printf("queue empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(queue);
    printf("queue size: %ld\n", size);
    printQueueArrayDeque(queue);

    printf("\ndeleting array queue\n");
    deleteArrayDeque(queue);

    printf("\nDone testing ArrayDeque as Queue\n");
}

/**
 * Test ArrayDeque as a stack
 */
void testArrayDequeAsStack(void) {
    printf("\nTesting ArrayDeque as Stack\n");

    printf("Creating array stack\n");
    ArrayDeque *deque = newArrayDeque(5);
    bool empty = isArrayDequeEmpty(deque);
    printf("stack empty? %s\n", empty ? "true" : "false");
    size_t size = arrayDequeSize(deque);
    printf("stack size: %ld\n", size);

    printf("\nadding 5 values\n");
    pushArrayDequeVal(deque, "A");
    pushArrayDequeVal(deque, "B");
    pushArrayDequeVal(deque, "C");
    pushArrayDequeVal(deque, "D");
    pushArrayDequeVal(deque, "E");
    empty = isArrayDequeEmpty(deque);
    printf("stack empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(deque);
    printf("stack size: %ld\n", size);
    printStackArrayDeque(deque);

    const char *val;
    bool status = peekTopArrayDequeVal(deque, &val);
    if (status) {
        printf("\npeek value: %s\n", val);
    } else {
        printf("\ncannot peek at top\n");
    }

    // swap top two stack values
    status = swapTopArrayDequeVal(deque);
    if (status) {
        printf("\nswapped top\n");
        printStackArrayDeque(deque);
    } else {
        printf("\ncannot swap\n");
    }

    status = pokeTopArrayDequeVal(deque, "Z");
    if (status) {
        printf("\npoked top: Z\n");
        printStackArrayDeque(deque);
    } else {
        printf("\ncannot poke top\n");
    }

    status = dropTopArrayDequeVal(deque);
    if (status) {
        printf("\ndropped top\n");
        printStackArrayDeque(deque);
    } else {
        printf("\ncannot drop top\n");
    }

    status = dupTopArrayDequeVal(deque);
    if (status) {
        printf("\ndup value\n");
        printStackArrayDeque(deque);
    } else {
        printf("\ncannot dup value\n");
    }

    char *val2;
    status = popArrayDequeVal(deque, &val2);
    if (status) {
        printf("\npop value: %s\n", val2);
        printStackArrayDeque(deque);
        free(val2);
    } else {
        printf("\ncannot pop at top\n");
    }

    empty = isArrayDequeEmpty(deque);
    printf("\nstack empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(deque);
    printf("stack size: %ld\n", size);

    printf("\ndropping all array deque values\n");
    dropAllArrayDequeVals(deque);
    empty = isArrayDequeEmpty(deque);
    printf("stack empty? %s\n", empty ? "true" : "false");
    size = arrayDequeSize(deque);
    printf("stack size: %ld\n", size);
    printStackArrayDeque(deque);

    printf("\ndeleting array deque\n");
    deleteArrayDeque(deque);

    printf("\nDone Testing ArrayDeque as Stack\n");
}

/**
 * Test functions.
 */
int main(void) {
    testArrayDequeAsDeque();
    testArrayDequeAsQueue();
    testArrayDequeAsStack();

    return EXIT_SUCCESS;
}
