#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

//********************************************************************
//	Author: Evan M. Cornuelle
//	
//	Description: Estimate the golden ratio by Monte Carlo integration
//
//********************************************************************

double randomNumber(double from, double to){

	std::random_device device;
	std::mt19937 seed(device());
	std::uniform_real_distribution<double> number(from,to);

	return number(seed);

}


double goldenRatioIntegral(int iterations){

	double integral, point, functionValue, total;

	for(int i = 0; i< iterations;i++){

		point = randomNumber(0.0,0.5);

		functionValue = 1.0/(sqrt(pow(point,2)+1));

		total += functionValue;

	}

	integral = 0.5*total/double(iterations);

	return exp(integral);
}

int main(){

	int iterations;
	double goldenRatioInt;

	std::cout << std::setprecision(8) << std::fixed;

	std::cout << "How many iterations do you want to perform?" << std::endl;
	std::cin >> iterations;

	goldenRatioInt = goldenRatioIntegral(iterations);

	std::cout << "You estimated value of gamma is: " << goldenRatioInt << "\n";

	return 0;
}