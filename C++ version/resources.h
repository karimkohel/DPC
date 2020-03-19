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

	if(input[0] == 'q')
		throw

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