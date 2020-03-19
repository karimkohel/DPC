#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

#include "stack.h"
#include "resources.h"


int main(int argc, char const *argv[]){

	char *input;
	char *pf;
	Stack<char> operators(10);

	greet();

	// start loop men hena

	input = getInput();

	pf = toPF(input, operators, strlen(input));

	cout << pf << endl;

	delete[] pf;
	return 0;
}



/*

TO DO:
	
	- translate user input to postfix 
	- add perentheses and multidigit features 
	- carry out the operations
	- display result 
	- free data
	- prettify code

Done:

	- get user input
	- check user input

*/