#include <iostream>
#include <cmath>

using namespace std;

double read_angle(double * angles){
	return 2 * sin(angles[0]) * sin(angles[1]) + cos(angles[2]);  
}

int main(){
	double *ang = new double[3];
	do{		
		cin >> ang[0] >> ang[1] >> ang[2];
		cout << read_angle(ang) << "\n";
	}while(cin);
	return 0;
}
