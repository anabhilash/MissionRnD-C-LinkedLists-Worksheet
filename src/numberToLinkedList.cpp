/*
OVERVIEW: Given a number convert that to single linked list (each digit
as a node).
E.g.: Input: 234, Output: 2->3->4.
INPUTS: A number.
OUTPUT: Create linked list from given number, each digit as a node.
ERROR CASES:
NOTES: For negative numbers ignore negative sign.
*/
#include <stdio.h> 
#include <malloc.h> 
struct node {
	int num;
	struct node *next;
};
struct node * numberToLinkedList(int N) {
	int temp;
	struct node *temp1 = NULL, *head = NULL, *tail = NULL;
	if (N < 0)
		N = -N;
	temp = N;
	if (temp == 0)
	{
		temp1 = (struct node *)malloc(sizeof(struct node));
		temp1->num = 0;
		temp1->next = NULL;
		return temp1;
	}
	while (N != 0)
	{
		temp = N % 10;
		temp1 = (struct node *)malloc(sizeof(struct node));
		temp1->num = temp;
		temp1->next = tail;
		tail = temp1;
		N = N / 10;
	}
	head = tail;
	return head;
}

