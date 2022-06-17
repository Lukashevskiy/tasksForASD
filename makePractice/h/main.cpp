#include <iostream>
#include <bitset>

char volatile_hash(std::string str){
	char h(0);
	for(char el: str){
		h ^= el;	
	}
	return h;
}

int main(){
	std::cout << std::bitset<8>(volatile_hash("asdqwerty"));
}
