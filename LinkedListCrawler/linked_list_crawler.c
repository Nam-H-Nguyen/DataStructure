/*
 * @file linked_list_crawler.c
 *
 * This file implements the LinkedListCrawler functions.
 *
 * @since Oct 29, 2019
 * @author philip gust
 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list_crawler.h"

/**
 * Create and initialize new crawler with the given callback.
 *
 * @param list the LinkedList to crawl
 * @param cb the callback for this crawler
 * @return an crawler for the list
 */
LinkedListCrawler* newLinkedListCrawler(LinkedList* theList, LinkedListCrawlerCallback cb) {
	LinkedListCrawler *crawler = malloc(sizeof(LinkedListCrawler));

	crawler->callback = cb;
	crawler->itr = newLinkedListIterator(theList);
	crawler->callbackData = NULL;
	return crawler;
}

/**
 * Delete the crawler by freeing its storage.
 *
 * @param crawler the LinkedListCrawler to delete
 */
void deleteLinkedListCrawler(LinkedListCrawler* crawler) {
	deleteLinkedListIterator(crawler->itr);
	crawler->itr = NULL;
	crawler->callback = NULL;
	crawler->callbackData = NULL;

	free(crawler);
}

/**
 * Start crawling the LinkedList with the specified data
 *
 * @param crawler the LinkedListCrawler to start
 * @param the data for the callback function
 * @return true if crawler ran to completion, false if stopped early
 */
bool startLinkedListCrawler(LinkedListCrawler *crawler, void *data) {
	// initialize the callback data
	crawler->callbackData = data;

	// loop until iterator has completed
	const char *val;
	while (getNextLinkedListIteratorVal(crawler->itr, &val)) {
        // call callback to perform function
		if (!crawler->callback(crawler)) {
			return false;	// function signals early completion
		}
	}
	return true;
}

/**
 * Determines whether this is the first call from the crawler since last reset.
 *
 * @param crawler the LinkedListCrawler
 * @return true if successful, false if not supported
 */
bool isFirstLinkedListCrawlerVal(LinkedListCrawler *crawler) {
	return (getLinkedListCrawlerCount(crawler) == 1);
}

/**
 * Determines whether there will be another call from the crawler
 *
 * @param itr the LinkedListIterator
 * @return true if there is another value, false otherwise
 */
bool hasNextLinkedListCrawlerVal(LinkedListCrawler *crawler) {
	return hasNextLinkedListIteratorVal(crawler->itr);
}

/**
 * Returns the number of values returned so far.
 *
 * @param itr the LinkedListIterator
 * @return the number of values returned so far
 */
size_t getLinkedListCrawlerCount(LinkedListCrawler *crawler) {
	return getLinkedListIteratorCount(crawler->itr);
}

/**
 * Returns the number of values available.
 *
 * @param itr the LinkedListIterator
 * @return available number of values or UNAVAILABLE if cannot perform operation.
 */
size_t getLinkedListCrawlerAvailable(LinkedListCrawler *crawler) {
	return getLinkedListIteratorAvailable(crawler->itr);
}

/**
 * Resets the linked list crawler to the head of the list.
 * Allows the crawler to be restarted within the callback
 * or restarted outside the callback.
 *
 * @param crawler the LinkedListCrawler
 * @return true if successful, false if not supported
 */
bool resetLinkedListCrawler(LinkedListCrawler *crawler) {
	return resetLinkedListIterator(crawler->itr);
}

/**
 * Gets the crawler callback data. Enables callback function
 * to get shared data across multiple callbacks. Also enables
 * final data to be recovered after crawling has completed.
 *
 * @param crawler the LinkedListCrawler
 * @return the crawler data
 */
void *getLinkedListCrawlerCallbackData(LinkedListCrawler *crawler) {
	return crawler->callbackData;
}

/**
 * Sets the crawler callback data. Enables callback function
 * to update shared data across multiple callbacks.
 *
 * @param crawler the LinkedListCrawler
 * @param data the LinkedListCrawler data
 * @return the crawler data
 */
void setLinkedListCrawlerCallbackData(LinkedListCrawler *crawler, void *data) {
	crawler->callbackData = data;
}

/**
 * Gets current link value in the linked list.
 *
 * @param itr the LinkedListIterator
 * @param val result parameter is pointer to result value location;  cannot be null
 * @return true if value available, false otherwise
 */
bool getLinkedListCrawlerVal(LinkedListCrawler* crawler, const char **val) {
	// value only available if iterator has advanced past head node
	if (getLinkedListCrawlerCount(crawler) > 0) {
		return getLinkedNodeValAt(crawler->itr->curNode, 0, val); // need itr function?
	}
	return false;
}

/**
 * Gets value in the linked list at the index.
 *
 * @param itr the LinkedListIterator
 * @param index the index
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if previous value returned, false if iterator is at end of list
 */
bool getLinkedListCrawlerValAt(LinkedListCrawler* crawler, size_t index, const char **val) {
	return getLinkedListValAt(crawler->itr->theList, index, val);
}

/**
 * Sets the current linked list value
 *
 * @param crawler the LinkedListCrawler
 * @param val the value to set
 * @return true if current value was set, false otherwise
 */
bool setLinkedListCrawlerVal(LinkedListCrawler* crawler, const char *val) {
	// value can only be set if iterator has advanced past head node
	if (getLinkedListCrawlerCount(crawler) > 0) {
		return setLinkedNodeValAt(crawler->itr->curNode, 0, val); // need itr function?
	}
	return false;
}

/**
 * Sets the linked list value at the index
 *
 * @param crawler the LinkedListCrawler
 * @param index the index
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if current value was set, false otherwise
 */
bool setLinkedListCrawlerValAt(LinkedListCrawler* crawler, size_t index, const char *val) {
   return setLinkedListValAt(crawler->itr->theList, index, val);
}

