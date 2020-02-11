/*
 * Ben Mikailenko
 *
 * stack.c
 *
 * Implementation of a simple, dynamically allocated structure
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "nfa.h"

// returns a new dynamically allocated nfa node
struct NfaNode* createNfaNode(int start, int final, struct TransitionNode* TransitionNode){
  struct NfaNode* NfaNode = (struct NfaNode*)malloc(sizeof(struct NfaNode));

  NfaNode->start = start;
  NfaNode->final = final;
  NfaNode->TransitionNode = TransitionNode;

  return NfaNode;

}
