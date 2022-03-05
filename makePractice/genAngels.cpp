#include <iostream>
#include <cmath>
using namespace std;

double rand_angles(double min, double max){
	return min + ((double)rand()/RAND_MAX)*max;
}

int main(int args, char* argv[]){
	const unsigned int n = *argv[0];
	for(unsigned int i = 0; i < n; i++){
		cout << rand_angles(-M_PI, M_PI) << " "
			 << rand_angles(-M_PI, M_PI) << " "
			 << rand_angles(-M_PI, M_PI) << "\n";

	}

}
