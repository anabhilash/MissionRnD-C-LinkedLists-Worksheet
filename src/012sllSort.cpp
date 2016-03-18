/*
OVERVIEW: Given a single linked list of 0s 1s and 2s ,Sort the SLL such
that zeroes
will be followed by ones and then twos.
INPUTS: SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/
#include <stdio.h>
#include <malloc.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *find(struct node *, int);
void sll_012_sort(struct node *head)
{
	int now = 0;
	int t;
	struct node *temp, *temp1;
	temp = head;
	while (temp->next != NULL)
	{
		if (temp->data != now)
		{
			temp1 = find(temp->next, now);
			if (temp1 != NULL)
			{
				t = temp1->data;
				temp1->data = temp->data;
				temp->data = t;
			}
			else
			{
				if (now == 2)
				{
					break;
				}
				else
				{
					now++;
					if (temp->data != now)
						continue;
				}
			}
		}
		temp = temp->next;
	}
}
struct node *find(struct node *temp, int now)
{
	int found=0;
	struct node * temp1;
	temp1 = temp;
	while (temp1!= NULL)
	{
		if (temp1->data == now)
		{
			found = 1;
			break;
		}
		temp1 = temp1->next;
	}
	if (found == 1)
		return temp1;
	else
		return NULL;
}