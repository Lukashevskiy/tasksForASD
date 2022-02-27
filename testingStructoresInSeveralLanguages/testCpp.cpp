#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int n_exp = 8; 

typedef map<int, int> test_map;

int main(){
	/*
	cout << "size of Allocator - " << sizeof(test_map::allocator_type) << endl;
	cout << "size of Pointer - " << sizeof(test_map::pointer) << endl;
	cout << "size of value_type - " << sizeof(test_map::value_type) << endl;
	*/
	for(int i = 0; i < n_exp; i++){
		int n = floor(pow(10, i)+0.5);
		auto start = chrono::high_resolution_clock::now();
		test_map test_m;
		
		for(int j = 0; j < n; j++){
			test_m.insert({j,j});		
		}

		auto stop = chrono::high_resolution_clock::now();	
		
        cout << n << " ";

		cout << test_m.size() * sizeof(test_map::value_type)
		       	+sizeof(test_map::pointer) 
			    +sizeof(test_map::allocator_type) << " ";
		
		cout << chrono::duration<long long, nano>(stop-start).count() << "\n";
	}	
	return 0;
}
