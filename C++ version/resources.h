#pragma once

void greet(){ 

	printf("\t\t\t Welcome to the Damn Powerful calculator 2.0\n");
	printf("_________________________________________________________________________\n\n");

	printf("->Enter your equation with no spaces down below\n");
	printf("->Enter q to Quit the DPC\n\n");
}

char *getInput(){

	char *input;

	cout << "$ ";
	scanf("%s", input);
	int len = strlen(input);

	// if(input[0] == 'q')
	// 	throw //pass

	for(int i=0; i<len; i++){

		if(input[i] > 57 || input[i] < 40 || input[i] == ',' || input[i] == '.'){
			if(input[i] == '^')
				continue;
			else{
				printf("str Error\n");
				throw runtime_error("Invalide input");
			}
		}
	}

	return input;
}

bool isDigit(char c){

	if(c >= '0' && c <= '9')
		return true;
	else
		return false;
}

int priorityOf(char c){

	if(c == '(' || c == ')')
		return 0;
	else if(c == '-' || c == '+')
		return 1;
	else if(c == '/' || c == '*')
		return 2;
	else
		return -1;
}

char *toPF(char *input, Stack<char> operators, int len){

	char *pf = new char[len]; // why not use vectors? ->>> because it will solve an imaginary problem
	int count = 0;

	for(int i=0; i<len; i++){

		if(isDigit(input[i]))
			pf[count++] = input[i];

		else{

			while(priorityOf(input[i]) < priorityOf(operators.peek())){ // catch them errors bitch
				pf[count++] = operators.pop();
			}

			operators.push(input[i]);
		}
	}

	while(operators.notEmpty()){
		pf[count++] = operators.pop();
	}

	return pf;
}