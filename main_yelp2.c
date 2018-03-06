/* Assignment 1: Yelp
Algorithms and Data Structures
Created by Sampada Sakpal (sakpals@student.unimelb.edu.au) 31/08/16
Updated till 10/09/16 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create_bst_list.h"

/* Used to initialise tree, open files and call necessary functions to implement
the yelp2 bst method.
To run the program compile yelp2 with makefile, and type
./yelp2 [input csv filename] [output file name] [keys]
OR
./yelp2 [input csv filename] [output file name] < [key filename]
*/
int
main(int argc, char **argv) {

	/* creates an empty tree */
	listTree_t root = NULL;

	/* pointers to file names*/
	char *inputFile = NULL;
	char *outputFile = NULL;

	/* variables to read csv file */
	char s1[NAME_MAX];
	char s2[DATA_MAX];

	/* used to count the number of comparisons needed to find/not find key*/
	int comparisons;
	/* initialises so that key has not been found yet */
	int found = 0;

	FILE *fInput;
	FILE *fOutput;

	/* number of keys from stdin on the command line */
	int numKeys = 0;

	/* number of comparisons to find last instance of key in search_tree_list() */
	int numCorrectComp = 0;

	/* number of total comparisons performed in search_tree_list() */
	int numTotalComp = 0;

	/* checks if there are too few command line specifications */
	if(argc < 3) {
		printf("Error, need to specify input file and output file!\n");
		exit(EXIT_FAILURE);
	}

	inputFile = argv[1];
	outputFile = argv[2];

	/* safeguards against failure to open input file */
	if((fInput = fopen(inputFile, "r")) == NULL) {
		printf("Error in reading the file\n");
		exit(EXIT_FAILURE);
	}

	/* safeguards against failre to open output file */
	if((fOutput = fopen(outputFile, "w")) == NULL) {
		printf("Error in writing to the file\n");
		exit(EXIT_FAILURE);
	}

	/* reads data from input file and inserts key and data values into bst */
	while(!feof(fInput)) {
		fscanf(fInput," %[^,] , %[^\n]", s1, s2);
		insert_bst_list(&root, s1, s2);
	}

	/* finds keys in bst based on command line arguments */
	if (argc > 3) {
		numKeys = argc - 3;
		while(numKeys > 0) {
			comparisons = search_tree_list(&root, outputFile, fOutput, argv[argc-numKeys], found, numCorrectComp, numTotalComp);
			printf("%s --> %d\n", argv[argc-numKeys], comparisons);
			numKeys--;
		}
	}

	/* finds keys in bst based on redirected input file containing keys */
	else {
		redirected1(root, outputFile, fOutput);
	}
	
	/* frees all nodes in bst */
	post_order_traversal1(&root);

	return 0;
}