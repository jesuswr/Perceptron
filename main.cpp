#include <iostream>
#include <vector>
#include <stdio.h>
#include "perceptron.hpp"
#include "perceptron_network.hpp"

// learning rate value
const long double etha = 0.001;
const int num_pixels = 784;
const int output_size = 10;
const int num_cycles = 50;

int main(){
	FILE *input = fopen("mnist_train.csv", "r");

	std::vector< std::pair< std::vector<int> , std::vector<long double> > > data;
	int ans;
	while(fscanf(input, "%d", &ans) != EOF){
		std::vector<int> aux_ans(output_size,0);
		aux_ans[ans] = 1;

		std::vector<long double> pixels(num_pixels);

		for (int i = 0; i < num_pixels; ++i){
			int aux;
			fscanf(input, ",%d", &aux);
			pixels[i] = (long double)aux/255;
		}

		data.push_back({aux_ans, pixels});
	}
	fclose(input);

	perceptron_network my_perceptron(output_size, etha, 0.05, num_pixels);

	my_perceptron.train_set(data, num_cycles);

	data.clear();

	input = fopen("mnist_test.csv", "r");
	while(fscanf(input, "%d", &ans) != EOF){
		std::vector<int> aux_ans(output_size,0);
		aux_ans[ans] = 1;

		std::vector<long double> pixels(num_pixels);

		for (int i = 0; i < num_pixels; ++i){
			int aux;
			fscanf(input, ",%d", &aux);
			pixels[i] = (long double)aux/255;
		}

		data.push_back({aux_ans, pixels});
	}
	fclose(input);

	std::pair<int, int> results = my_perceptron.test_set(data);
	printf("%d correct of %d, %.2Lf%% \n", results.first, results.second, (long double)(100*results.first)/results.second);
	return 0;
}