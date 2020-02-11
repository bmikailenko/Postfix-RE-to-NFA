/*
 * Ben Mikailenko
 *
 * stack.c
 *
 * Implementation of a simple, dynamically allocated stack
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


struct StackNode* createStackNode(struct NfaNode* NfaNode){
    struct StackNode* StackNode = (struct StackNode*)malloc(sizeof(struct StackNode));

    StackNode->NfaNode = NfaNode;
    StackNode->next = NULL;

    return StackNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}

void push(struct StackNode** root, struct NfaNode* NfaNode) {
    struct StackNode* StackNode = createStackNode(NfaNode);
    StackNode->next = *root;
    *root = StackNode;
}

struct NfaNode* pop(struct StackNode** root){
    if (isEmpty(*root))
        return NULL;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    struct NfaNode* popped = temp->NfaNode;
    free(temp);

    return popped;
}
