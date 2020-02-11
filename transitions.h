/*
 * Ben Mikailenko
 *
 * transitions.h
 *
 * Interface for a simple, dynamically allocated linked list
 *
 */

#ifndef TRANSITIONS_H
#define TRANSITIONS_H

struct TransitionNode{
	int state1;
	int state2;
	char symbol;
	struct TransitionNode* next;
};


// returns a new dynamically allocated transition node
struct TransitionNode* createTransitionNode(int state1, int state2, char symbol);

// prints transitions in (q1, a) -> q2 form in a TransitionNode
void printTransitions(struct TransitionNode* TransitionNode);

// concats two linked lists
struct TransitionNode* concatTransitionNode(struct TransitionNode* a, struct TransitionNode* b);


#endif
