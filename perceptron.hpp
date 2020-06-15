/*
	Simple Perceptron Class Signatures
*/

#include <vector>

#ifndef _PERCEPTRON_HPP
#define _PERCEPTRON_HPP

class perceptron{
	/*
		weights : 
			vector of long double representing the weights
			coming to that perceptron
		etha : 
			long double representing the learning rate
	*/
	std::vector<long double> weights;
	long double etha;
	
public:
	/*
		Class constructor

		Receives:
			size:
				int representing the size of the input incoming to the perceptron
			etha:
				long double representing the value of etha in the class
			weights_range:
				long double representing the range of the value of the incoming 
				weights [-weights_range, weights_range]
	*/
	perceptron(int size, long double etha, long double weights_range);

	/*
		Operator *

		Receives:
			input:
				vector of long double representing the input of the perceptron

		Returns:
			Long double representing the dot product of the weights and the input
	*/
	long double operator*(const std::vector<long double>& input);

	/*
		sigma function

		Receives:
			input:
				vector of long double representing the input of the perceptron

		Returns:
			1 if the dot product of the input and the weights is >= 0
			or 0 otherwise
	*/	
	int sigma(const std::vector<long double>& input);

	/*
		train function
			This function trains the perceptron by changing it's weights

		Reveives:
			input:
				vector of long double representing the input data
			output:
				value of the sigma function evaluated in the input
			exp_output:
				value of the expected output of the given input
	*/
	void train(const std::vector<long double>& input, 
		       int output, int exp_output);
};

#endif