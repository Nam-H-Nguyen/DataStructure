/*
 * @file messagepriorityqueue_main.c
 *
 * This file contains unit tests for MessagePriorityQueue functions.
 *
 *  @date Nov 13, 2018
 *  @author Nam H Nguyen
 */
#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "messagepriorityqueue.h"

/**
 * Unit tests for empty MessagePriorityQueue.
 */
void testMessagePriorityQueue_empty(void) {
    //// test empty queue
    // create a message queue
    MessagePriorityQueue* mpq = newMPQ(SIZE_MAX);

    CU_ASSERT_PTR_NOT_NULL(mpq);
    CU_ASSERT_PTR_NOT_NULL(mpq->msgQueues);
    CU_ASSERT_TRUE(isEmptyMPQ(mpq));
    CU_ASSERT_EQUAL(messageSizeMPQ(mpq), 0);

    // dequeue message from empty queue
    char *val;
    CU_ASSERT_FALSE(dequeueMessageMPQ(mpq, &val));

    // delete message queue
    deleteMPQ(mpq);
}

/**
 * Unit tests for single message in MessagePriorityQueue.
 */
void testMessagePriorityQueue_single(void) {
    //// test single message on queue
    // create message queue and enqueue message
    MessagePriorityQueue *mpq = newMPQ(SIZE_MAX);
    const char* msg = "0.0";
    enqueueMessageMPQ(mpq, msg, high);
    CU_ASSERT_EQUAL(messageSizeMPQ(mpq), 1);
    CU_ASSERT_EQUAL(messageSizeForPriorityMPQ(mpq, high), 1);

    // peek at message
    const char *testMsg;
    CU_ASSERT_TRUE_FATAL(peekMessageMPQ(mpq, &testMsg));
    CU_ASSERT_STRING_EQUAL(testMsg, msg);

    // dequeue a message
    char *testMsg2;
    CU_ASSERT_TRUE_FATAL(dequeueMessageMPQ(mpq, &testMsg2));
    CU_ASSERT_PTR_NOT_NULL(testMsg2);
    CU_ASSERT_STRING_EQUAL(testMsg2, msg);
    CU_ASSERT_TRUE(isEmptyMPQ(mpq));
    CU_ASSERT_EQUAL(messageSizeMPQ(mpq), 0);
    free(testMsg2);

    // dequeue message from empty queue
    CU_ASSERT_FALSE(dequeueMessageMPQ(mpq, &testMsg2));
    CU_ASSERT_TRUE(isEmptyMPQ(mpq));
    CU_ASSERT_EQUAL(messageSizeMPQ(mpq), 0);

    // delete message queue
    deleteMPQ(mpq);
}

/**
 * Unit tests for multiple messages in MessagePriorityQueue.
 */
void testMessagePriorityQueue_multi(void) {
    //// Enqueue 3 messages for each priority
    MessagePriorityQueue *mpq = newMPQ(SIZE_MAX);
    char msgtext[10];
    for (Priority p = highest; p <= lowest; p++) {
        for (int i = 0; i < 3; i++) {
            sprintf(msgtext, "%d.%d", p, i);
            enqueueMessageMPQ(mpq, msgtext, p);
        }
    }

    // ensure that each queue has 3 messages
    CU_ASSERT_EQUAL(messageSizeMPQ(mpq), 12);

    CU_ASSERT_FALSE(isEmptyForPriorityMPQ(mpq, highest));
    CU_ASSERT_EQUAL(messageSizeForPriorityMPQ(mpq,highest), 3);

    CU_ASSERT_FALSE(isEmptyForPriorityMPQ(mpq, high));
    CU_ASSERT_EQUAL(messageSizeForPriorityMPQ(mpq,high), 3);

    CU_ASSERT_FALSE(isEmptyForPriorityMPQ(mpq, low));
    CU_ASSERT_EQUAL(messageSizeForPriorityMPQ(mpq,low), 3);

    CU_ASSERT_FALSE(isEmptyForPriorityMPQ(mpq, low));
    CU_ASSERT_EQUAL(messageSizeForPriorityMPQ(mpq,lowest), 3);

    // verify that the messages dequeue in the right order
    for (Priority p = highest; p <= lowest; p++) {
        for (int i = 0; i < 3; i++) {
            sprintf(msgtext, "%d.%d", p, i);

            // test peek
            const char *testMsg;
            CU_ASSERT_TRUE_FATAL(peekMessageMPQ(mpq, &testMsg));
            CU_ASSERT_STRING_EQUAL(testMsg, msgtext);

            // test dequeue
            char *testMsg2;
            CU_ASSERT_TRUE_FATAL(dequeueMessageMPQ(mpq, &testMsg2));
            CU_ASSERT_STRING_EQUAL(testMsg, msgtext);
            free(testMsg2);
        }
    }
    CU_ASSERT_TRUE(isEmptyMPQ(mpq));
    CU_ASSERT_EQUAL(messageSizeMPQ(mpq), 0);

    // delete message queue
    deleteMPQ(mpq);
}

/**
 * Test all the functions for this application.
 *
 * @return test error code
 */
static int test_all(void) {

    // initialize the CUnit test registry -- only once per application
    CU_initialize_registry();

    // add a suite to the registry with no init or cleanup
    CU_pSuite pSuite = CU_add_suite("function_tests", NULL, NULL);

    // add the tests to the suite
    CU_add_test(pSuite, "test_messagePriorityQueue_empty", testMessagePriorityQueue_empty);
    CU_add_test(pSuite, "test_messagePriorityQueue_single", testMessagePriorityQueue_single);
    CU_add_test(pSuite, "test_messagePriorityQueue_multi", testMessagePriorityQueue_multi);

    // run all test suites using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // display information on failures that occurred
    CU_basic_show_failures(CU_get_failure_list());

    // Clean up registry and return status
    CU_cleanup_registry();
    return CU_get_error();
}

/**
 * Main program to invoke test functions
 *
 * @return the exit status of the program
 */
int main(void) {

    // test all the functions
    CU_ErrorCode code = test_all();

    return (code == CUE_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}

