#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacks.h"


int main(){

	char equation[20]; //user entered equation
	char *pf; //postfix
	// char x; //buffer for pf characters
	int index;
	int eq_size;
	int calculating = 1;
	int multidigit;

	char_stack_t operators;
	if(!init_stackc(&operators, 10))
		failed();

	float_stack_t results;
	if(!init_stackf(&results, 10))
		failed();

	greet();

	while(calculating){

		printf("$ ");
		scanf("%s", equation);
		eq_size = strlen(equation);
		index = 0;
		multidigit = 0;

		if(equation[0] == 'q')
			break;

		pf = (char*)malloc(sizeof(char)*30); //postfix

		// loop to check validity of expression
		eq_size = check_input(eq_size, equation);


		// loop to place all characters in postfix notation
		for(int i=0; i<eq_size; i++){

			if(is_digit(equation[i]) ){
				
				multidigit = (multidigit * 10) + atoi(equation[i]);

			}
			else{

				pf[index] = multidigit; // SERIOUS BUG HERE
				index++;
				multidigit = 0;

				while(priority_of(equation[i]) < priority_of(check_stackc(&operators))){

					if(!popc(&operators, &pf[index]))
						break;

					index++;
				}

				if(!pushc(&operators, equation[i])) printf("push error\n");
			}

		}


		while(operators.sp > -1){
			if(!popc(&operators, &pf[index]))
				break;
			index++;
		}

		printf("pf = %s\n\n", pf);

		free(pf);
	}

	free_stackc(&operators);
	free_stackf(&results);
	printf("---------------------------------------\n->Thank you for trying me out, Good bye.\n");

	return 0;
}

/*

TO DO:

	-translate to postfix
		-add numbers to pf. [Done]
		-put operators to char stack according to priority. [Done]
		-pop operators if lower priority is present. [Done]
		-pop all when expression ends. [Done]
		-implement brackets in character stack

	-init float stack [Done]

	-place numbers in float stack

	-move along the pf notation string to add the last 2 operands in the float stack

	-push result in the float stack again

	-finish when strlen(pf) == 0 and only one result left in the float stack 

	-implement multiple digit number in stacks

	-debugging stacks is a nightmare

*/