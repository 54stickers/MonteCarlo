#include <iostream>
#include <cmath>
#include <random>

//***************************************************************
//	Author: Evan M. Cornuelle
//	
//	Description: Estimate Pi by Monte Carlo circle in square
//
//***************************************************************


double randomNumber(double from, double to){					// Generate random number with mersenne twister

	std::random_device device;
	std::mt19937 seed(device());
	std::uniform_real_distribution<double> number(from,to);

	return number(seed);

}

int inCircle(double abscissa, double ordinate){					// Determine if the random point is within the unit circle

	int state = 0;
	double norm = pow(abscissa,2) + pow(ordinate,2);

	if (norm <= 1){

		state = 1;

	}

	return state;
}

double calculatePi(int N){										// Calculate Pi by counting the number of points inside the circle

	double Pi;
	int n;

	for(int i=0; i < N; i++){

		n += inCircle(randomNumber(0,1),randomNumber(0,1));

	}

	Pi = 4.0*n/N;

	return Pi;
}

int main(){
	
	int iterations;
	double Pi;

	std::cout << "How many iterations do you want to perform?" << std::endl;
	std::cin >> iterations;

	Pi = calculatePi(iterations);

	std::cout << "Pi = " << Pi << "\n";

	return 0;

}
