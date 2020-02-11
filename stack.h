/*
 * Ben Mikailenko
 *
 * stack.h
 *
 * Interface for a simple, dynamically allocated stack
 *
 */

#ifndef STACK_H
#define STACK_H


struct StackNode {
	struct NfaNode* NfaNode;
	struct StackNode* next;
};

// return a new dynamically allocated stack node
struct StackNode* createStackNode(struct NfaNode* NfaNode);

// checks if stack is empty
int isEmpty(struct StackNode* root);

// pushes a new dynamically allocated stack node to stack
void push(struct StackNode** root, struct NfaNode* NfaNode);

// returns the nfa node that is on the top of the stack
struct NfaNode* pop(struct StackNode** root);

#endif
