/*
 * @file linked_node.h
 *
 * This file provides the structure for a linked node that carries
 * data, and function declarations for operations that operate on
 * chains of linked nodes. Methods can be used in one of two ways.
 *
 * If the empty chain of nodes is represented by a NULL pointer,
 * then add the first item by setting the pointer to the first item.
 * Delete the final node by freeing it and setting the pointer to NULL.
 *
 * If the empty node chain is represented by a dummy first node,
 * then add the first item by calling addAfterLinkedNode() with the
 * dummy node and the first node, delete the last item by calling
 * deleteAfterLinkedNode() with the dummy first node, and get
 * the size excluding the dummy node by passing the dummy node's
 * next pointer to getLinkedSize().
 *
 *  @since Oct 24, 2018
 *  @author: Nam H. Nguyen
 */

#ifndef LINKED_NODE_H_
#define LINKED_NODE_H_

/**
 * Singly linked node
 * Note how "C" requires node next field to be declared
 */
typedef struct LinkedNode {
	/** node data for a string array */
	char* data;
	/** link to next node */
	struct LinkedNode* next;
} LinkedNode;

/**
 * Create and initialize new node.
 *
 * @param data the node data
 * @return Node with fields set to NULL
 */
LinkedNode* newLinkedNode(const char* data);

/**
 * Free node storage.  The node must be removed from its chain
 * by calling deleteLinkedNode() first.
 *
 * @param node the LinkedNode to delete
 */
void deleteLinkedNode(LinkedNode* node);

/**
 * Deletes all linked array nodes in the chain.
 * @param node the starting linked array node
 */
void deleteAllLinkedNodes(LinkedNode *node);

/**
 * Return the size of the chain. If the chain has a dummy
 * first node, pass its next pointer to this function.
 *
 * @param node the chain to be measured
 * @return the size of the chain
 */
size_t linkedNodeSize(LinkedNode* node);

/**
 * Return the node at the Kth position in the chain relative to the
 * input node. If there are fewer than K items in the list, returns NULL.
 *
 * @param list the list to be measured
 * @param k the index
 * @return the Kth node from input node or NULL if fewer than K items
 */
LinkedNode *getLinkedNodeAt(LinkedNode *list, size_t k);

/**
  * Return the value of the node at the Kth position in the chain relative to
  * the input node. If there are fewer than K items in the list, returns false.
  *
  * @param node the chain
  * @param k the index
  * @param val the result parameter for  the value of the Kth node from input node
  * @return true if returned value of kth node as val, or false if index out of bounds
  */
 bool getLinkedNodeValAt(LinkedNode *node, size_t k, const char **val);

 /**
  * Returns last node in the chain, or NULL if node is NULL.
  *
  * @param node first node in chain of LinkedListNodes
  * @return the last node in the chain or NULL
  */
 LinkedNode* getLastLinkedNode(LinkedNode* node);

	 /**
  * Set the value of the node at the Kth position relative to the input
  * node. If there are fewer than K items in the chain, returns false.
  *
  * @param node the chain to be measured
  * @param k the index
  * @param val the value to set.
  * @return true if set value of kth node as val, or false if index out of bounds
  */
 bool setLinkedNodeValAt(LinkedNode *node, size_t k, const char *val);

 /**
 * Add new node after the specified node in the chain.
 *
 * @param chain the chain node after which new node will be added
 * @param the new node to insert
 */
void addAfterLinkedNode(LinkedNode* node, LinkedNode* newNode);

/**
 * Delete node after specified chain node. Caller is responsible for
 * freeing the deleted node by calling deleteLinkedNode().
 *
 * @param node the chain node after which node will be deleted
 * @return the deleted node that the caller must free, or NULL if
 *   chain has no next node
 */
LinkedNode* deleteAfterLinkedNode(LinkedNode* node);

/**
 * Print the linked node chain data.
 *
 * @param node the chain to print
 */
void printLinkedNodes(LinkedNode *node);


#endif /* LINKED_NODE_H_ */
