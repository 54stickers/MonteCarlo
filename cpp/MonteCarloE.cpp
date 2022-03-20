#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

//*******************************************************************
//	Author: Evan M. Cornuelle
//	
//	Description: Calculate Euler's Number by Monte Carlo "sum to 1"
//
//*******************************************************************

double randomNumber(double from, double to){

	std::random_device device;
	std::mt19937 seed(device());
	std::uniform_real_distribution<double> number(from,to);

	return number(seed);

}

double estimatorEuler(int iterations){

	double e1,sum,count;

	for(int i=0;i<iterations;i++){

		sum = 0;

		while(sum <= 1){

			sum += randomNumber(0,1);
			count++;
			// std::cout << "sum = " << sum << std::endl;
		}

		// std::cout << "e = "<< count/(i+1) << std::endl;
	}

	e1 = count/iterations;

	return e1;

}

double twoEstimatorEuler(int iterations){


	double e2,S1,S2,count1,count2,X1,X2;

	for(int i=0;i<iterations;i++){

		S1=0;
		S2=0;

		while(S1 <= 1 || S2 <= 1){

			X1 = randomNumber(0,1);
			X2 = 1.0 - X1;

			if(S1 <= 1){
				
				S1 += X1;
				count1++;

			}
			
			if(S2 <= 1){
				
				S2 += X2;
				count2++;

			}
		}
	}

	e2 = (count1+count2)/(2*iterations);

	return e2;

}

int main(){

	int iterations;
	double Euler,EulerTwo;

	std::cout << "How many iterations do you want to perform?" << std::endl;
	std::cin >> iterations;

	Euler = estimatorEuler(iterations);
	EulerTwo = twoEstimatorEuler(iterations);
	
	std::cout << std::setprecision(8) << std::fixed;

	std::cout << "After " << iterations << " iterations " << " your value for e is: " << Euler << std::endl;
	std::cout << "After " << iterations << " iterations " << " your value for e by antithetic variables is: " << EulerTwo << std::endl;

	return 0;

}

