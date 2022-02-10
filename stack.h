/*
 * stack.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dchiu
 *
*/
#ifndef STACK_H_
#define STACK_H_

struct Node;
void printList(struct Node *n);
void push(struct Node **prevHead, double newData);
double pop(struct Node **node);
int size();

#endif /* STACK_H_ */

