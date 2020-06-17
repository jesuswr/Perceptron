/*
	Simple Perceptron Class Implementation
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include "perceptron.hpp"

/*
	Class constructor
		Reserves the size for the weights of the perceptron and
		asigns random values to them in the given range.
	 	The bias is in the last space of the vector.
*/
perceptron::perceptron(int size, long double etha, 
	                   long double weights_range) : etha(etha) {
	weights.resize(size+1);
	for (int i = 0; i <= size; ++i){
		long double rnd = (long double)rand()*2/RAND_MAX -1;
		weights[i] = (long double)rnd*weights_range;
	}
}

/*
	Operator *
		Basic dot product implementation
*/
long double perceptron::operator*(const std::vector<long double>& input){
	long double acum = 0;
	int n = input.size();
	for (int i = 0; i < n; ++i){
		acum += weights[i]*input[i];
	}
	// Add the bias value
	acum += weights[n];
	return acum;
}

/*
	sigma function
		Calculates the doct product and returns 1 if its >= 0
		or 0 otherwise
*/
int perceptron::sigma(const std::vector<long double>& input){
	return ( (*this)*input >= 0 ? 1 : 0 );
}

/*
	train function
		Trains the perceptor by changing the weights depending on the
		difference between output and expected output
*/
void perceptron::train(const std::vector<long double>& inp, 
	                   int outp, int exp_outp){
	int err = exp_outp - outp;
	// if exp_outp == outp no need to update
	if ( err == 0 )
		return;
	
	int n = inp.size();
	for (int i = 0; i < n; ++i){
		weights[i] += err*inp[i]*etha;
	}
	// Adjust bias value
	weights[n] += err*etha;
}