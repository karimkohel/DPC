#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stacks.h"


int main(){

	char equation[20]; //user entered equation
	char *pf; //postfix
	int eq_size;
	float result;
	int remove_brackets;
	int the_earth_is_flat = 1;

	char_stack_t operators;
	if(!init_stackc(&operators, 10))
		failed();

	float_stack_t results;
	if(!init_stackf(&results, 10))
		failed();

	greet();

	while(the_earth_is_flat){

		printf("$ ");
		scanf("%s", equation);
		eq_size = strlen(equation);

		if(equation[0] == 'q')
			break;

		pf = (char*)malloc(sizeof(char)*30);

		eq_size = check_input(eq_size, equation);

		remove_brackets = set_pf(&operators, equation, pf, eq_size);

		result = get_result(&results, pf, eq_size - remove_brackets);

		printf("\nresult is = %.2f\n\n", result);

		free(pf);
		remove_brackets = 0;
	}

	free_stackc(&operators);
	free_stackf(&results);
	printf("\n---------------------------------------\n");
	printf("->Thank you for trying me out, Good bye.\n");
	printf("----------------------------------------\n");

	return 0;
}

/*

TO DO:
	-implement brackets in character stack

DONE:

	-translate to postfix
		-add numbers to pf. [Done]
		-put operators to char stack according to priority. [Done]
		-pop operators if lower priority is present. [Done]
		-pop all when expression ends. [Done]

	-init float stack [Done]

	-place numbers in float stack

	-move along the pf notation string to add the last 2 operands in the float stack

	-push result in the float stack again

	-finish when strlen(pf) == 0 and only one result left in the float stack 
*/