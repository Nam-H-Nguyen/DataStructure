/*
 * linked_list_crawler_main.c
 *
 * This file exercises the singly linked list and singly linked list
 * crawler functions.
 *
 *  @date Nov 8, 2018
 *  @author: Nam H. Nguyen
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include "linked_list_crawler.h"

/**
 * Print "visited" for each value in the list
 * @param crawler the crawler
 * @return true to continue crawling
 */
bool visitedCallback(LinkedListCrawler *crawler) {
	printf("visited\n");
	return true;
}

/**
 * Print the list values as a comma-separated list in parens.
 * @param crawler the crawler
 * @return true to continue crawling
 */
bool printListCallback(LinkedListCrawler *crawler) {
	// print start of list
	if (isFirstLinkedListCrawlerVal(crawler)) {
		printf("( ");
	}
	// print current value
	const char* val;
	getLinkedListCrawlerVal(crawler, &val);
	printf("\"%s\"", val);

	// print list item separator or end of list
	if (hasNextLinkedListCrawlerVal(crawler)) {
		printf(", ");
	} else {
		printf(" )\n");
	}
	return true;
}

/**
 * Finds the largest string in the list
 * @param crawler the crawler
 * @param true to continue crawling
 */
bool getMaxValCallback(LinkedListCrawler *crawler) {
	const char *maxVal = getLinkedListCrawlerCallbackData(crawler);
	const char *curVal;
	getLinkedListCrawlerVal(crawler, &curVal);
	// first value or larger value
	if (maxVal == NULL || strcmp(curVal, maxVal) > 0) {
		setLinkedListCrawlerCallbackData(crawler, (void*)curVal);
	}
	return true;
}

/**
 * Computes the aggregate length of the strings in the list
 * @param crawler the crawler
 * @param true to continue crawling
 */
bool getStrLenCallback(LinkedListCrawler *crawler) {
	size_t *len = getLinkedListCrawlerCallbackData(crawler);
	const char *curVal;
	getLinkedListCrawlerVal(crawler, &curVal);
	*len += strlen(curVal);
	return true;
}

/**
 * Finds the a string in the list
 * @param crawler the crawler
 * @param true to continue crawling
 */
bool findStrCallback(LinkedListCrawler *crawler) {
	char *targetVal = getLinkedListCrawlerCallbackData(crawler);
	const char *curVal;
	getLinkedListCrawlerVal(crawler, &curVal);
	bool found = (strcmp(targetVal, curVal) == 0);
	return (!found);  // continue if not found
}

/**
 * Transliterates characters in list strings
 * @param crawler the crawler
 * @param true to continue crawling
 */
bool translitCallback(LinkedListCrawler *crawler) {
	const char **xlit = getLinkedListCrawlerCallbackData(crawler);
	const char *fromChars = xlit[0];  // from transliteration chars
	const char *toChars = xlit[1];      // to transliteration chars

	// current string to transliterate
	const char *fromStr;
	getLinkedListCrawlerVal(crawler, &fromStr);

	// transliterate curVal chars found in fromChars to ones in toChars
	size_t len = strlen(fromStr);
	char toStr[len+1];	// transliterated string
	for (int i = 0; i < len; i++) {
		const char *p = strchr(xlit[0], fromStr[i]);
		toStr[i] = (p == NULL) ? fromStr[i] : toChars[p-fromChars];
	}
	toStr[len] = '\0';

	setLinkedListCrawlerVal(crawler, toStr);  // function allocates copy of local string
	return true;
}

/**
 * This function tests linked list crawler.
 */
void testLinkedListCrawler() {
	printf("\nstart testLinkedListCrawler\n");

	printf("Initial linked list\n");
	LinkedList *list = newLinkedList(SIZE_MAX);
	printLinkedList(list);
	printf("list size: %lu\n", linkedListSize(list));

	// add 5 nodes to the list
	printf("\nAdding 5 values to list\n");
	addLastLinkedListVal(list, "A");
	addLastLinkedListVal(list, "B");
	addLastLinkedListVal(list, "C");
	addLastLinkedListVal(list, "B");
	addLastLinkedListVal(list, "A");
	printLinkedList(list);

	printf("list size: %lu\n", linkedListSize(list));

	printf("\ncrawler with visitedCallback\n");
	LinkedListCrawler *crawler = newLinkedListCrawler(list, visitedCallback);
	printf("iterator count: %lu\n", getLinkedListCrawlerCount(crawler));
	printf("iterator avail: %lu\n", getLinkedListCrawlerAvailable(crawler));
	const char *val;
	if (getLinkedListCrawlerVal(crawler, &val)) {
		printf("error: got crawler val \"%s\" before crawler started\n", val);
	} else {
		printf("crawler val not available before crawler started\n");
	}
	bool result = startLinkedListCrawler(crawler, NULL);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printf("crawler count: %lu\n", getLinkedListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getLinkedListCrawlerAvailable(crawler));
	deleteLinkedListCrawler(crawler);

	// use callback to print list of strings in list
	printf("\ncrawler with printListCallback\n");
	crawler = newLinkedListCrawler(list, printListCallback);
	result = startLinkedListCrawler(crawler, NULL);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printf("crawler count: %lu\n", getLinkedListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getLinkedListCrawlerAvailable(crawler));
	deleteLinkedListCrawler(crawler);

	// use callback to get the maximum string in list
	printf("\ncrawler with getMaxValCallback\n");
	crawler = newLinkedListCrawler(list, getMaxValCallback);
	result = startLinkedListCrawler(crawler, NULL);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printf("callback found max value \"%s\"\n", getLinkedListCrawlerCallbackData(crawler));
	printf("crawler count: %lu\n", getLinkedListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getLinkedListCrawlerAvailable(crawler));
	deleteLinkedListCrawler(crawler);

	// use callback to get the aggregate length of strings in list
	printf("\ncrawler with getStrLenCallback\n");
	crawler = newLinkedListCrawler(list, getStrLenCallback);
	size_t count = 0;
	result = startLinkedListCrawler(crawler, &count);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printf("length of list strings: %lu\n", count);
	printf("crawler count: %lu\n", getLinkedListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getLinkedListCrawlerAvailable(crawler));
	deleteLinkedListCrawler(crawler);

	// use callback to find string in list
	printf("\ncrawler with findStrCallback\n");
	crawler = newLinkedListCrawler(list, findStrCallback);
	size_t found = 0;
	const char *lookingFor = "B";
	for ( ; startLinkedListCrawler(crawler, (void*)lookingFor) == false; found++) {
		size_t foundAt = getLinkedListCrawlerCount(crawler)-1;
		printf("index of \"%s\" is: %lu\n", lookingFor, foundAt);
	}
	printf("found %lu occurrences of \"%s\"\n", found, lookingFor);
	printf("crawler count: %lu\n", getLinkedListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getLinkedListCrawlerAvailable(crawler));
	deleteLinkedListCrawler(crawler);

	// use callback to transliterate characters in list strings
	printf("\ncrawler with translitCallback\n");
	crawler = newLinkedListCrawler(list, translitCallback);
	const char *toLowerCase[2] = {
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
			"abcdefghijklmnopqrstuvwxyz"
	};
	result = startLinkedListCrawler(crawler, toLowerCase);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printLinkedList(list);
	printf("crawler count: %lu\n", getLinkedListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getLinkedListCrawlerAvailable(crawler));

	printf("\ncrawler with translitCallback\n");
	const char *toUpperCase[2] = {
			"abcdefghijklmnopqrstuvwxyz",
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	};
	// must reset crawler to start at beginning of list
	resetLinkedListCrawler(crawler);
	result = startLinkedListCrawler(crawler, toUpperCase);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printLinkedList(list);
	printf("crawler count: %lu\n", getLinkedListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getLinkedListCrawlerAvailable(crawler));

	deleteLinkedListCrawler(crawler);

	printf("end testLinkedListCrawler\n");
}

/**
 * Test functions.
 */
int main(void) {
	testLinkedListCrawler();

	printf("program exiting\n");
}
