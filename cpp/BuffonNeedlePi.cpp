#include <iostream>
#include <cmath>
#include <random>

//*******************************************************************
//	Author: Evan M. Cornuelle
//	
//	Description: Calculate Pi by Buffon's Needle
//
//*******************************************************************

double randomNumber(double from, double to){

	std::random_device device;
	std::mt19937 seed(device());
	std::uniform_real_distribution<double> number(from,to);

	return number(seed);

}

int randomNeedle(double boardWidth, double needleLength){

	double xPosition;
	double angle;
	double lengthPerp;
	int isOverlapped;

	xPosition = randomNumber(0,boardWidth/2);
	angle = randomNumber(0,M_PI/2);							//pi to estimate pi
	lengthPerp = (1.0/2.0)*needleLength*sin(angle);


	if(xPosition <= lengthPerp){
		
		isOverlapped = 1;
		

	}else{

		isOverlapped = 0;
		
	}

	return isOverlapped;

}

double buffonPi(int NEEDLES,double boardWidth, double needleLength){

	int overlaps=0;
	double pi;

	for(int i = 0; i < NEEDLES;i++){

		overlaps += randomNeedle(boardWidth,needleLength);
		
	}


	pi = 2*(double(NEEDLES)/double(overlaps))*(needleLength/boardWidth);


	return pi;
}


int main(){

	int NEEDLES;

	std::cout << "How many needles do you want to drop?" << std::endl;
	std::cin >> NEEDLES;

	std::cout << "The value of Pi is: " << buffonPi(NEEDLES,1,0.5) << std::endl;

	return 0;

}