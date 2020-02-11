/*
 * Ben Mikailenko
 *
 * transitions.c
 *
 * Implementation of a simple, dynamically allocated linked list
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "transitions.h"


// returns a new dynamically allocated transition node
struct TransitionNode* createTransitionNode(int state1, int state2, char symbol) {

  struct TransitionNode* TransitionNode = (struct TransitionNode*)malloc(sizeof(struct TransitionNode));

  TransitionNode->state1 = state1;
  TransitionNode->state2 = state2;
  TransitionNode->symbol = symbol;
  TransitionNode->next = NULL;

  return TransitionNode;

}

void printTransitions(struct TransitionNode* TransitionNode) {
  if (TransitionNode == NULL) {
    return;
  }
  printf("(q%d, %c) -> q%d\n", TransitionNode->state1, TransitionNode->symbol, TransitionNode->state2);
  if (TransitionNode->next != NULL)
    printTransitions(TransitionNode->next);
}

struct TransitionNode* concatTransitionNode(struct TransitionNode* a, struct TransitionNode* b) {

  if (a->next != NULL)
    a->next = concatTransitionNode(a->next, b);
  else {
    a->next = b;
  }
  return a;
}
