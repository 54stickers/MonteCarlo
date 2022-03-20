#include <iostream>
#include <cmath>
#include <random>

//*******************************************************************
//	Author: Evan M. Cornuelle
//	
//	Description: Calculate Pi by random walk
//
//*******************************************************************

int randomNumber(int from, int to){

	std::random_device device;
	std::mt19937 seed(device());
	std::uniform_int_distribution<int> number(from,to);

	return number(seed);

}

int randomWalk(int steps){

	int initialPosition = 0;
	int position = initialPosition;
	int stepSize[2] = {-1,1};

	for(int i = 0 ; i < steps; i++){

		position += stepSize[randomNumber(0,1)];

	}
  
	return position;
}

double randomWalkPi(int steps, int walks){

	double pi;
	double averageWalkingDelta;
	double totalWalkingDelta;

	for(int i = 0; i < walks; i++){

		totalWalkingDelta += abs(randomWalk(steps));

	}

	averageWalkingDelta = totalWalkingDelta/double(walks);


	pi = 2*double(steps)/pow(averageWalkingDelta,2);

	return pi;
}



int main(){

	int walks,steps;
	double pi;

	std::cout << "How many walks do you want to go on?" << std::endl;
	std::cin >> walks;
	std::cout << "How many steps do you want to take on a walk?" << std::endl;
	std::cin >> steps;

	pi = randomWalkPi(steps,walks);

	std::cout << "After taking " << steps << " steps on " << walks << " walks, your value for pi is: " << pi << std::endl;
	std::cout << "your error is: " << 100*(M_PI - pi)/M_PI <<"%" << std::endl;

	return 0;

}