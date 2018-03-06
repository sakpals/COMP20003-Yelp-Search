/* Assignment 1: Yelp
Algorithms and Data Structures
Created by Sampada Sakpal (sakpals@student.unimelb.edu.au) 2/09/16
Updated till 10/09/16 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create_bst.h"

/* Inserts name and data read from stdin into bst 
Takes as input the address of the root of BST, and 
name,data fields from csv file */
void
insert_bst(tree_t *rootRef, char *name, char *data) {
	
	/* inserts a new node into a vacant position in bst */
	if((*rootRef) == NULL) {
		tree_t new = (tree_t)malloc(sizeof(struct node));

		/* safeguards against possible failure to allocate memory */
		if(new == NULL) {
			printf("failure to allocate memory for node\n");
			exit(EXIT_FAILURE);
		}

		new->nodeName = (char *)malloc(strlen(name)+1);
		new->nodeData = (char *)malloc(strlen(data)+1);
		strcpy(new->nodeName, name);
		strcpy(new->nodeData, data);
		new->left = NULL;
		new->right = NULL;
		/* the node has not been found yet using the search_tree function */
		new->found = 0;
		*rootRef = new;
	}

	/* if name to be inserted is less than or equal to current node name 
	then go left */
	else if(strcasecmp(name, ((*rootRef)->nodeName)) <= 0) { 
		insert_bst((&((*rootRef)->left)), name, data);
	}

	/* else go right */
	else if(strcasecmp(name, ((*rootRef)->nodeName)) > 0){
		insert_bst((&((*rootRef)->right)), name, data);	
	}
}

/* Reads data from files that have been redirected from stdin using < operator.
Searched for these keys in the bst.
Takes as input the root of BST, name of output file and pointer to output
file. */
void 
redirected(tree_t root, char *outputFile, FILE *fOutput) {

	char key[NAME_MAX];

	/* used to count the number of comparisons to find key from output of 
	search_tree() */
	int comparisons;
	int numCorrectComp = 0;
	int numComparisons = 0;
	/* assumes key has not been found yet */
	int found = 0;

	while(fgets(key, NAME_MAX, stdin)) {
		/* since fgets automatically assigns newline character to string
		it is removed for desired format in stdout */
		if(key[strlen(key) - 1] == '\n') {
			key[strlen(key)-1] = '\0';
		}

		comparisons = search_tree(&root, outputFile, fOutput, key, found, 
			numCorrectComp, numComparisons);
		printf("%s --> %d\n", key, comparisons);
	}
	
}

/* Searches the bst for key name, and prints out the data stored 
(or NOTFOUND if key is absent) to a seperate output file.
Returns the number of key comparisons to find/not find key to stdout. */
/* Takes as input the address of the root, name of output file, 
pointer to output file, key to be searched, a found boolean variable,
the number of Comparison to find key and total comparisons. */
int 
search_tree(tree_t *rootRef, char *outputFile, FILE *fOutput, 
	char *key, int found, int numCorrectComp, int numTotalComp) {

	tree_t tmp;
	tmp = *rootRef;
	
	/* if search has reached leaf node */
	if (tmp == NULL) {
		
		// if no instance of the key was found 
		if(!found) {
			numCorrectComp = numTotalComp;
			fprintf(fOutput, "%s --> ", key);
			fprintf(fOutput, "NOTFOUND\n\n");	
			return numCorrectComp;
		}
		return numCorrectComp;
	}

	/* if a key that has not been found previously is found */
	else if(strcasecmp(key,tmp->nodeName) == 0 && !(tmp->found)) {
		tmp->found = 1;
		numTotalComp ++; 
		numCorrectComp = numTotalComp;
		fprintf(fOutput, "%s --> ", tmp->nodeName);
		fprintf(fOutput, "%s\n\n", tmp->nodeData);

		/*  key has now been 'found' at least once */
		found = 1;
		tmp = tmp->left;
		numCorrectComp = search_tree(&tmp, outputFile, fOutput, key,
		 found, numCorrectComp, numTotalComp);
	}

	/* if key value is less than or equal to the key name of the current node */
	else if(strcasecmp(key, tmp->nodeName) <= 0) {
		numTotalComp ++;
		tmp = tmp->left;
		numCorrectComp = search_tree(&tmp,outputFile,fOutput,key, 
			found, numCorrectComp, numTotalComp);
		
	}

	/* if key is greater than current key.
	 NOTE: no computation is required since this is the last option. 
	 Improve efficiency.*/
    else {	
    	numTotalComp ++;
    	tmp = tmp->right;
		numCorrectComp = search_tree(&tmp,outputFile,fOutput,key,
		 found, numCorrectComp, numTotalComp);
    	
	}

	return numCorrectComp;
} 
/* Frees all the nodes in the bst through post order traversal technique.
Takes the address of root as input. */
void 
post_order_traversal(tree_t *rootRef) {

	if(*rootRef != NULL) {
		post_order_traversal(&((*rootRef)->left));
		post_order_traversal(&((*rootRef)->right));
		free(*rootRef);

	}
}