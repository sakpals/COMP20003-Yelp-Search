/* Assignment 1: Yelp
Algorithms and Data Structures
Created by Sampada Sakpal (sakpals@student.unimelb.edu.au) 2/09/16
Updated till 10/09/16 
*/ 

#ifndef _BST_LIST_H_
#define _BST_LIST_H_
/* stores the constants, function prototypes and struct declarations
for functions main_yelp2.c and yelp2_bst.c */

/* maximum size of key name string + 1 for nullbyte*/
#define NAME_MAX 65 
/* maximum size of data string + 1 for nullbyte */
#define DATA_MAX 1466


typedef struct node *listTree_t;

/* node for bst with a linked list implementation */
struct node {
	char *nodeName;
	char *nodeData;
	listTree_t left;
	listTree_t right;
	listTree_t next;
	int found;
};

/* function prototypes */
void insert_bst_list(listTree_t *rootRef, char *name, char *data);
int search_tree_list(listTree_t *rootRef, char *outputFile, FILE *fOutput, char *key, int found, int numCorrectComp, int numTotalComp);
void post_order_traversal1(listTree_t *rootRef);
void redirected1(listTree_t root, char *outputFile, FILE *fOutput);
	
#endif