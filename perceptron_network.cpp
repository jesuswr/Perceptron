/*
	Simple Implementation of a Perceptron Network Class
*/

#include <time.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "perceptron.hpp"
#include "perceptron_network.hpp"

/*
	Class constructor
		Reserves space for the perceptrons and calls their constructor
*/
perceptron_network::perceptron_network(int n, long double etha, 
	                                   long double w_r, int inp_sz){
	srand(time(NULL));
	for (int i = 0; i < n; ++i){
		perceptron aux(inp_sz, etha, w_r);
		perc.push_back(aux);
	}
}

/*
	train function
		Trains each perceptron with the given data if needed
*/
void perceptron_network::train(const std::vector<long double>& inp, 
	                           const std::vector<int>& ans){
	int n = perc.size();
	for (int i = 0; i < n; ++i){
		int out = perc[i].sigma( inp );
		perc[i].train(inp, out, ans[i]);
	}
}

/*
	train_set function
		Given a set of training data, trains each perceptron with each test
*/
void perceptron_network::train_set(const std::vector< std::pair<std::vector<int>, 
	                                                            std::vector<long double> > >& data, 
	                                                            int cycles){
	int n = data.size();
	for (int k = 0; k < cycles; ++k){
		for (int i = 0; i < n; ++i){
			(*this).train(data[i].second, data[i].first);
		}
		printf("Training cycle #%d complete\n", k+1);
	}
}

/*
	test function
		Compares the output of the perceptron and the expected output, returns
		false if they are different and true otherwise
*/
bool perceptron_network::test(const std::vector<long double>& inp, 
	                          const std::vector<int>& ans){
	int n = ans.size();
	for (int i = 0; i < n; ++i){
		if ( ans[i] != perc[i].sigma(inp) )
			return false;
	}
	return true;
}

/*
	test_set function
		Counts how much data is classified correctly
*/
std::pair<int,int> perceptron_network::test_set(const std::vector< std::pair<std::vector<int>, 
	                                                                         std::vector<long double> > >& data){
	int n = data.size();
	int correct = 0;
	for (int i = 0; i < n; ++i){
		if ( (*this).test(data[i].second, data[i].first) )
			correct++;
	}
	return {correct, n};
}
