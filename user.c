// Ben Mikailenko

// user.c

// dynamically allocated code to turn an RE to an NFA

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "nfa.h"
#include "transitions.h"

int main(int argc, char *argv[]) {

	// open the file

	FILE *in;
	if (argc == 1) {
		in = stdin;
	}
	else if (argc == 2) {
		in = fopen(argv[1], "r");
		if (!in) {
			perror(argv[1]);
			return 1;
		}
	}

	// error message
	else {
		fprintf(stderr, "Usage: %s [input-file]\n", argv[0]);
		return 1;
	}

	// variables
	char buffer[1024];
	int bufferMax;
	int i = 0;
	char c;


	// save the file to buffer
	c = fgetc(in);
    while (c != EOF)
    {
			buffer[i] = c;
			i++;
			c = fgetc(in);
    }
	fclose(in);
	bufferMax = i;
	i = 0;


	// while not at end of all expressions
	while (i != bufferMax){

		//printf("new expression!\n");

		struct StackNode* root = NULL;
		int states = 0;
		int successfulRun = 0;


		// while not end of one postfix expression
		while (buffer[i] != 10 && buffer[i] != 13){

			successfulRun = 1;
			printf("%c",buffer[i]);

			if (buffer[i] == '&') {

				struct NfaNode* NfaNode2 = pop(&root);
				struct NfaNode* NfaNode1 = pop(&root);

				struct TransitionNode* NullTransitionNode = createTransitionNode(NfaNode1->TransitionNode->state2,NfaNode2->TransitionNode->state1,'E');
				//NullTransitionNode->next = NfaNode2->TransitionNode;
				//NfaNode1->TransitionNode->next = NullTransitionNode;

				NfaNode1->TransitionNode = concatTransitionNode(NfaNode1->TransitionNode, NullTransitionNode);
				NfaNode1->TransitionNode = concatTransitionNode(NfaNode1->TransitionNode, NfaNode2->TransitionNode);

				struct NfaNode* NfaNode = createNfaNode(NfaNode1->start, NfaNode2->final, NfaNode1->TransitionNode);

				push(&root, NfaNode);

			}

			else if (buffer[i] == '|') {

				struct NfaNode* NfaNode2 = pop(&root);
				struct NfaNode* NfaNode1 = pop(&root);

				struct TransitionNode* NullTransitionNode1 = createTransitionNode(NfaNode1->final,states + 1,'E');
				struct TransitionNode* NullTransitionNode2 = createTransitionNode(NfaNode2->final,states + 1,'E');
				struct TransitionNode* NullTransitionNode3 = createTransitionNode(states, NfaNode1->start,'E');
				struct TransitionNode* NullTransitionNode4 = createTransitionNode(states, NfaNode2->start,'E');

				//NullTransitionNode1->next = NullTransitionNode2;
				//NullTransitionNode2->next = NullTransitionNode3;
				//NullTransitionNode3->next = NullTransitionNode4;
				//NullTransitionNode4->next = NfaNode1->TransitionNode;
				//NfaNode1->TransitionNode->next = NfaNode2->TransitionNode;

				NullTransitionNode1 = concatTransitionNode(NullTransitionNode1, NullTransitionNode2);
				NullTransitionNode1 = concatTransitionNode(NullTransitionNode1, NullTransitionNode3);
				NullTransitionNode1 = concatTransitionNode(NullTransitionNode1, NullTransitionNode4);
				NullTransitionNode1 = concatTransitionNode(NullTransitionNode1, NfaNode1->TransitionNode);
				NullTransitionNode1 = concatTransitionNode(NullTransitionNode1, NfaNode2->TransitionNode);

				struct NfaNode* NfaNode = createNfaNode(states, states + 1, NullTransitionNode1);

				states = states + 2;

				push(&root, NfaNode);



			}

			else if (buffer[i] == '*') {

				struct NfaNode* NfaNode1 = pop(&root);

				struct TransitionNode* TransitionNode1 = createTransitionNode(NfaNode1->final,states,'E');
				struct TransitionNode* TransitionNode2 = createTransitionNode(states, NfaNode1->start,'E');


				//TransitionNode1->next = TransitionNode2;
				//TransitionNode2->next = NfaNode1->TransitionNode;


				TransitionNode1 = concatTransitionNode(TransitionNode1, TransitionNode2);

				TransitionNode1 = concatTransitionNode(TransitionNode1, NfaNode1->TransitionNode);

				struct NfaNode* NfaNode = createNfaNode(states, states, TransitionNode1);

				states = states + 1;

				push(&root, NfaNode);

			}

			else if (buffer[i] == 'a' || buffer[i] == 'b' || buffer[i] == 'c' || buffer[i] == 'd' || buffer[i] == 'e' || buffer[i] == 'E') {

				struct TransitionNode* TransitionNode = createTransitionNode(states, states + 1, buffer[i]);
				struct NfaNode* NfaNode = createNfaNode(states, states + 1, TransitionNode);
				states = states + 2;
				push(&root, NfaNode);

			}

			i++;


		}

		if (successfulRun == 1) {
			// print the nfa
			struct NfaNode* NfaNode = pop(&root);
			printf("\n");
			printTransitions(NfaNode->TransitionNode);
			printf("S (q%d)\n", NfaNode->start);
			printf("F (q%d)\n", NfaNode->final);
			printf("\n");
		}

		// repeat
		i++;
	}

	return 0;
}
