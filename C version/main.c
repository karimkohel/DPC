#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stacks.h"


int main(){

	char equation[20]; //user entered equation
	char *pf; //postfix
	int eq_size;
	int calculating = 1;
	float result;

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

		if(equation[0] == 'q')
			break;

		pf = (char*)malloc(sizeof(char)*30); //postfix memory assignment

		// check validity of expression and return the equation size or a 0
		eq_size = check_input(eq_size, equation);

		// place all characters in postfix notation
		set_pf(&operators, equation, pf, eq_size);

		// getting results by stacking the postfix equation in a float stack
		result = get_result(&results, pf, eq_size);

		printf("pf = %s\n\n", pf);

		printf("result is = %f\n", result);

		free(pf);
	}

	free_stackc(&operators);
	free_stackf(&results);
	printf("---------------------------------------\n->Thank you for trying me out, Good bye.\n\n");

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