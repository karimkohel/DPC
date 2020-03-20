#ifndef STACKS_H
#define STACKS_H

// // // Char stack structer and functions // // // 

typedef struct {

	char *array;
	int sp;
	int size;

	// no constructors in c
}char_stack_t ;

int pushc(char_stack_t *stack, char item){

	if(stack->sp + 1 == stack->size)
		return 0; //stackoverflow :D

	stack->sp++;
	stack->array[stack->sp] = item;

	return 1;
}

int popc(char_stack_t *stack, char *item){

	if(stack->sp < 0)
		return 0;

	*item = stack->array[stack->sp];
	stack->array[stack->sp] = 0;
	stack->sp--;

	return 1;
}

int init_stackc(char_stack_t *stack, int size){

	stack->array = (char *)malloc(size * sizeof(char));

	if(stack->array == NULL)
		return 0;

	stack->size = size;
	stack->sp = -1;


	return 1;
}

// checks last item in char stack
char check_stackc(char_stack_t *stack){
	if(stack->sp == -1)
		return 'k'; //random character
	else
		return stack->array[stack->sp];
}

void free_stackc(char_stack_t *stack){
	free(stack->array);
}





// // // float stack structer and functions // // // 

typedef struct {

	float *array;
	int sp;
	int size;

	// no constructors in c
}float_stack_t ;


int pushf(float_stack_t *stack, float item){

	if(stack->sp + 1 == stack->size)
		return 0; //stackoverflow :D

	stack->sp++;
	stack->array[stack->sp] = item;

	return 1;
}

int popf(float_stack_t *stack, float *item){

	if(stack->sp == -1)
		return 0;

	*item = stack->array[stack->sp];
	stack->array[stack->sp] = 0;
	stack->sp--;

	return 1;
}

int init_stackf(float_stack_t *stack, int size){

	stack->array = (float *)malloc(size * sizeof(float));

	if(stack->array == NULL)
		return 0;

	stack->size = size;
	stack->sp = -1;

	return 1;
}

// check last item in float stack
float check_stackf(float_stack_t *stack){
	return stack->array[stack->sp];
}

void free_stackf(float_stack_t *stack){
	free(stack->array);
}







// // // General functions // // //


//return the priority of an operator
int priority_of(char operator){

	if(operator == '(' || operator == ')')
		return 0;

	else if(operator == '-' || operator == '+')
		return 1;

	else if(operator == '/' || operator == '*')
		return 2;

	else if(operator == '^')
		return 3;

	else
		return -1;
}

//exit program as any memory error occurs
void failed(){
	printf("Memory fault, Exiting now\n");
	exit(0);
}

void greet(){
	printf("------Welcome to the Damn Powerful Calculator------\n");
	printf("->Enter your equation with no spaces or invalide characters below\n");
	printf("->Enter q to exit the DPC\n\n");
}

int check_input(int eq_size, char *equation){

	for(int i=0; i<eq_size; i++){

		if(equation[i] > 57 || equation[i] < 40 || equation[i] == ',' || equation[i] == '.'){
			if(equation[i] == '^')
				break;
			printf("Try again but smarter\n");
			eq_size = 0;
			break;
		}
	}

	return eq_size;
}

int is_digit(char num){
	if(num > 47 && num < 58)
		return 1;
	else
		return 0;
}

void set_pf(char_stack_t *operators, char *equation, char *pf, int eq_size){

	int index = 0;

	for(int i=0; i<eq_size; i++){

		if(is_digit(equation[i])){
			
			pf[index] = equation[i]; // SERIOUS BUG HERE
			index++;

		}
		else{

			while(priority_of(equation[i]) <= priority_of(check_stackc(operators))){

				if(!popc(operators, &pf[index]))
					break;

				index++;
			}

			if(!pushc(operators, equation[i])) printf("push error\n");
		}

	}


	while(operators->sp > -1){
		if(!popc(operators, &pf[index]))
			break;
		index++;
	}
}

float evaluate(float val1, float val2, char operator){


	if(operator == '-')
		return val2 - val1;

	else if(operator == '+')
		return val2 + val1;

	else if(operator == '/')
		return val2 / val1;

	else if(operator == '*')
		return val2 * val1;

	else
		return pow(val2, val1);
}

float get_result(float_stack_t *vlus, char *pf, int eq_size){

	float num;
	float val1;
	float val2;
	float result = 0;
	char chr;

	for(int i=0; i<eq_size; i++){

		if(is_digit(pf[i])){

			chr = pf[i];
			num = atof(&chr);

			pushf(vlus, num);

		}else{

			popf(vlus, &val1);
			popf(vlus, &val2);

			result = evaluate(val1, val2, pf[i]);

			pushf(vlus, result);
		}
	}

	popf(vlus, &result);

	return result;
}


#endif //STACKS_H