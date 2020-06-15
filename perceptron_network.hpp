/*
	Signatures of a Simple Perceptron Network Class
*/

#include <vector>
#include "perceptron.hpp"

#ifndef _PERCEPTRON_NETWORK_HPP
#define _PERCEPTRON_NETWORK_HPP

class perceptron_network{
	/*
		perc:
			vector of perceptrons representing the layer of perceptrons
			in a single layer model
	*/
	std::vector<perceptron> perc;

public:
	/*
		Class constructor

		Receives:
			n:
				int representing the number of perceptrons
			etha:
				long double representing the value of etha in the class
			weights_range:
				long double representing the range of the value of the  
				weights [-weights_range, weights_range]
			inp_size:
				int representing the size of the input incoming
	*/
	perceptron_network(int n, long double etha, long double w_range, int inp_size);

	/*
		train function
			This function trains the perceptron layer

		Receives:
			inp:
				vector of long double representing the input data
			ans:
				vector of int representing the expected output of the layer
	*/
	void train(const std::vector<long double>& inp, const std::vector<int>& ans);

	/*
		train_set function
			This function trains the perceptron layer with a set of data

		Receives:
			data:
				vector of pairs, first element of the pair is a vector of ints
				that represents the expected output for the layer and the
				second element is a vector of long double representing the input
			cycles:
				int that represents the number of epochs for the training,
				if not set then = 1

	*/
	void train_set(const std::vector< std::pair<std::vector<int>, 
		                                        std::vector<long double> > >& data, 
		                                        int cycles = 1);

	/*
		test function
			Receives input and expected output and returns true if the 
			output of the layer is the same as the expected output

		Receives:
			inp:
				vector of long double representing the input data
			ans:
				vector of int representing the expected output

		Returns:
			true if the output equals the expected output or false otherwise
	*/
	bool test(const std::vector<long double>& inp, const std::vector<int>& ans);

	/*
		test_set function
			This function tests the perceptron layer with a set of data

		Receives:
			data:
				vector of pairs, first element of the pair is a vector of ints
				that represents the expected output for the layer and the
				second element is a vector of long double representing the input
		
		Returns:
			A pair of int, the first element is the number of testing elements
			that were classified correctly and the second element is the total
			number of testing elements
	*/
	std::pair<int,int> test_set(const std::vector< std::pair<std::vector<int>, 
		                                                     std::vector<long double> > >& data);
};

#endif