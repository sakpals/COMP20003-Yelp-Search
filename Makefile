# Assignment 1: Yelp
# Algorithms and Data Structures
# Created by Sampada Sakpal (sakpals@student.unimelb.edu.au) 2/09/16
# Updated till 10/09/16 
# Reference: Anh Vir's Makefile 4 is used as template

# defines C compiler & flags
CC = gcc
CFLAGS = -Wall

HDR = create_bst.h
HDRY = create_bst_list.h

SRC = main_yelp1.c yelp1_bst.c
SRCY = main_yelp2.c yelp2_bst.c

# OBJ is the same as SRC, just replace .c with .h
OBJ    = $(SRC:.c=.o)
OBJY   = $(SRCY:.c=.o)
# the executable name
EXE = yelp1
EXEY = yelp2

# for yelp1
$(EXE): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

# for yelp2
$(EXEY): $(OBJY) Makefile
	$(CC) $(CFLAGS) -o $(EXEY) $(OBJY)

# removes any compilation for yelp1 and yelp2
clean:: 
	rm -f $(OBJ) $(EXE)
	rm -f $(OBJY) $(EXEY)

$(OBJ): $(HDR)
$(OBJ): $(HDRY)
