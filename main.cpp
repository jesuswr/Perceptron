#include <iostream>
#include <vector>
#include <stdio.h>
#include "perceptron.hpp"
#include "perceptron_network.hpp"

// learning rate value
const long double ETHA1 = 0.001;
const long double ETHA2 = 0.01;
const long double ETHA3 = 0.1;
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

	perceptron_network my_perceptron1(output_size, ETHA1, 0.05, num_pixels);
	perceptron_network my_perceptron2(output_size, ETHA2, 0.05, num_pixels);
	perceptron_network my_perceptron3(output_size, ETHA3, 0.05, num_pixels);

	printf("Training with 0.001\n");
	my_perceptron1.train_set(data, num_cycles);
	printf("Training with 0.01\n");
	my_perceptron2.train_set(data, num_cycles);
	printf("Training with 0.1\n");
	my_perceptron3.train_set(data, num_cycles);

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

	std::pair<int, int> results1 = my_perceptron1.test_set(data);
	std::pair<int, int> results2 = my_perceptron2.test_set(data);
	std::pair<int, int> results3 = my_perceptron3.test_set(data);
	printf("With 0.001: %d correct of %d, %.2Lf%% \n", results1.first, results1.second, (long double)(100*results1.first)/results1.second);
	printf("With 0.01: %d correct of %d, %.2Lf%% \n", results2.first, results2.second, (long double)(100*results2.first)/results2.second);
	printf("With 0.1: %d correct of %d, %.2Lf%% \n", results3.first, results3.second, (long double)(100*results3.first)/results3.second);
	return 0;
}