/*
 * Ben Mikailenko
 *
 * transitions.h
 *
 * Interface for a simple, dynamically allocated structure
 *
 */

#ifndef NFA_H
#define NFA_H

struct NfaNode {
	int start;
	int final;
	struct TransitionNode* TransitionNode;
};

// returns a new dynamically allocated nfa node
struct NfaNode* createNfaNode(int start, int final, struct TransitionNode* TransitionNode);

#endif
