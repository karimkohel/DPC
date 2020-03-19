#pragma once


template<typename Type>
class Stack {

private:

	Type *data;
	int sp;
	int size;

public:

	Stack(int stackSize){

		data = new Type[stackSize];
		size = stackSize;
		sp = -1;
	}

	void push(Type value){

		if(sp +1 == size)
			throw out_of_range("Pushing into an full stack.");
		else{
			sp++;
			data[sp] = value;
		}
	}

	Type peek(){
		if(sp <= -1)
			throw out_of_range("Peeking into an empty stack.");
		else
			return data[sp];
	}

	Type pop(){

		if(sp <= -1)
			throw out_of_range("Poping from an empty stack.");
		else{

			Type popped = data[sp];
			data[sp] = 0;
			sp--;

			return popped;
		}
	}

	bool notEmpty(){
		if(sp == -1)
			return false;
		else
			return true;
	}

	~Stack(){
		delete[] data;
	}

};