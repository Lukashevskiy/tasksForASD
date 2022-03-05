#include <iostream>
#include <cmath>

using namespace std;

double read_angle(double * angels){
	return 2 * sin(angels[0]) * sin(angels[1]) + cos(angels[2]);  
}

int main(){
	double *ang = new double[3];
	do{		
		cin >> ang[0] >> ang[1] >> ang[2];
		cout << read_angle(ang) << "\n";
	}while(cin);
	return 0;
}
