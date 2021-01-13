

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next, *prev;
}node;

typedef struct list {
	node *head, *tail;
	int len,sign;
}number;




