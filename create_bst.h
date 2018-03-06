/* Assignment 1: Yelp
Algorithms and Data Structures
Created by Sampada Sakpal (sakpals@student.unimelb.edu.au) 2/09/16
Updated till 9/09/16 
*/

#ifndef _BST_H_
#define _BST_H_

/* stores the constants, function prototypes and struct declarations
for functions main_yelp1.c and yelp1_bst.c */

/* maximum size of key name string + 1 for nullbyte*/
#define NAME_MAX 65 
/* maximum size of data string + 1 for nullbyte */
#define DATA_MAX 1466

/* node for bst */
typedef struct node *tree_t;
struct node {
	char *nodeName;
	char *nodeData;
	tree_t left;
	tree_t right;
	int found;
	
};


/* function prototype */
void insert_bst(tree_t *rootRef, char *name, char *data);
int search_tree(tree_t *rootRef, char *outputFile, FILE *fOutput, char *key, int found, int numCorrectComp, int numTotalComp);
void post_order_traversal(tree_t *rootRef);
void redirected(tree_t root, char *outputFile, FILE *fOutput);

#endif