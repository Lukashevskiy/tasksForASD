#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int n_exp = 8; 

int main(){
	cout << "size of Allocator - " << sizeof(map<int,int>::allocator_type) << endl;
	cout << "size of Reference - " << sizeof(map<int, int>::reference) << endl;
	cout << "size of value_type - " << sizeof(map<int,int>::value_type) << endl;
	cout << "size of mapped+key type - " << sizeof(map<int,int>::mapped_type)
						+sizeof(map<int,int>::key_type) << endl;
	for(int i = 0; i < n_exp; i++){
		int n = floor(pow(10, i)+0.5);
		map<int,int> test_m;
		for(int j = 0; j < n; j++){
			test_m.insert({j,j});		
		}
		cout << test_m.size()*sizeof(map<int,int>::value_type) << endl;
	}	
	cout << "FUCK yourself" << endl;
	return 0;
}
