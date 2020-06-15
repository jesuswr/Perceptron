all : test_perceptron

test_perceptron : main.cpp perceptron.o perceptron_network.o
	g++ -o test_perceptron main.cpp perceptron.o perceptron_network.o

perceptron.o: perceptron.cpp perceptron.hpp
	g++ -c perceptron.cpp

perceptron_network.o: perceptron_network.cpp perceptron_network.hpp
	g++ -c perceptron_network.cpp

clean:
	rm *.o test_perceptron 

