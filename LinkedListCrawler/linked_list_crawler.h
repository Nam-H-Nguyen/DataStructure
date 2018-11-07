/*
 * @file linked_list_crawler.h
 *
 * This file provides the structure and function definitions for a
 * crawler for a singly linked list.
 *
 * @since 2018-10-29
 * @author philip gust
 */

#ifndef LINKED_LIST_CRAWLER_H_
#define LINKED_LIST_CRAWLER_H_

#include <stdbool.h>
#include "linked_list_iterator.h"

/** Forward declaration for the LinkedListCrawler struct */
struct LinkedListCrawler;

/**
 * LinkedListCrawler callback function type.
 * Returns true to continue crawling, false to stop crawling
 */
typedef bool (*LinkedListCrawlerCallback)(struct LinkedListCrawler *crawler);

/**
 * A crawler for a singly-linked list.
 */
typedef struct LinkedListCrawler{
  /** The LinkedListIterator */
  LinkedListIterator *itr;

  /** The LinkedListCrawler callback */
  LinkedListCrawlerCallback callback;

  /** The LinkedListCrawler callback data */
  void *callbackData;
} LinkedListCrawler;

/**
 * Create and initialize new crawler with the given callback.
 *
 * @param list the LinkedList to crawl
 * @param cb the callback for this crawler
 * @return an crawler for the list
 */
LinkedListCrawler* newLinkedListCrawler(LinkedList* theList, LinkedListCrawlerCallback cb);

/**
 * Delete the crawler by freeing its storage.
 *
 * @param crawler the LinkedListCrawler to delete
 */
void deleteLinkedListCrawler(LinkedListCrawler* crawler);

/**
 * Start crawling the LinkedList with the specified data
 */
bool startLinkedListCrawler(LinkedListCrawler *crawler, void *data);

/**
 * Determines whether this is the first call from the crawler since last reset.
 *
 * @param crawler the LinkedListCrawler
 * @return true if successful, false if not supported
 */
bool isFirstLinkedListCrawlerVal(LinkedListCrawler *crawler);

/**
 * Determines whether there will be another call from the crawler
 *
 * @param itr the LinkedListIterator
 * @return true if there is another value, false otherwise
 */
bool hasNextLinkedListCrawlerVal(LinkedListCrawler *crawler);

/**
 * Returns the number of values returned so far.
 *
 * @param itr the LinkedListIterator
 * @return the number of values returned so far
 */
size_t getLinkedListCrawlerCount(LinkedListCrawler *crawler);

/**
 * Returns the number of values available.
 *
 * @param itr the LinkedListIterator
 * @return available number of values or UNAVAILABLE if cannot perform operation.
 */
size_t getLinkedListCrawlerAvailable(LinkedListCrawler *crawler);

/**
 * Resets the linked list crawler to the head of the list.
 *
 * @param crawler the LinkedListCrawler
 * @return true if successful, false if not supported
 */
bool resetLinkedListCrawler(LinkedListCrawler *crawler);

/**
 * Gets the crawler callback data.
 *
 * @param crawler the LinkedListCrawler
 * @return the crawler data
 */
void *getLinkedListCrawlerCallbackData(LinkedListCrawler *crawler);

/**
 * Sets the crawler callback data. Enables callback function
 * to update shared data across multiple callbacks.
 *
 * @param crawler the LinkedListCrawler
 * @param data the LinkedListCrawler data
 * @return the crawler data
 */
void setLinkedListCrawlerCallbackData(LinkedListCrawler *crawler, void *data);

/**
 * Gets current link value in the linked list.
 *
 * @param itr the LinkedListIterator
 * @param val result parameter is pointer to result value location;  cannot be null
 * @return the current linked list value
 */
bool getLinkedListCrawlerVal(LinkedListCrawler* crawler, const char **val);

/**
* Gets value in the linked list at the index.
*
* @param itr the LinkedListIterator
* @param index the index
* @param val result parameter is pointer to result value location; cannot be null
* @return true if previous value returned, false if iterator is at end of list
*/
bool getLinkedListCrawlerValAt(LinkedListCrawler* crawler, size_t index, const char **val);

/**
* Sets the current linked list value
*
* @param crawler the LinkedListCrawler
* @param val result parameter is pointer to result value location; cannot be null
* @return true if current value was set, false otherwise
*/
bool setLinkedListCrawlerVal(LinkedListCrawler* crawler, const char *val);

/**
* Sets the linked list value at the index
*
* @param crawler the LinkedListCrawler
* @param index the index
* @param val result parameter is pointer to result value location; cannot be null
* @return true if current value was set, false otherwise
*/
bool setLinkedListCrawlerValAt(LinkedListCrawler* crawler, size_t index, const char *val);

#endif /* LINKED_LIST_CRAWLER_H_ */
