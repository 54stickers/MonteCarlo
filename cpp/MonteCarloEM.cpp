#include <iostream>
#include <cmath>
#include <random>

//*******************************************************************
//	Author: Evan M. Cornuelle
//	
//	Description: Estimate Euler's constant, gamma, by Monte Carlo
//
//*******************************************************************

double randomNumber(double from, double to){

	std::random_device device;
	std::mt19937 seed(device());
	std::uniform_real_distribution<double> number(from,to);

	return number(seed);

}

void monteCarloEM(int iterations, double &gamma, int &zeroesHit){

	double total,random,Xi;
	int index = 0;

	while(index < iterations){

		random = randomNumber(0,1);
		
		if (random != 0){

			Xi = 1/random - floor(1/random);										//decimal part

			total += Xi;

			index++;

		}else{

			zeroesHit++;
		}

	}

	gamma = 1 - total/double(iterations);

}

int main(){

	int iterations,zeroesHit=0;
	double gamma;

	std::cout << "How many iterations do you want to perform?" << std::endl;
	std::cin >> iterations;

	monteCarloEM(iterations, gamma, zeroesHit);

	std::cout << "You estimated value of gamma is: " << gamma << "\n";

	std::cout << "Random number zeroes hit: " <<  zeroesHit << "\n";

	return 0;


}