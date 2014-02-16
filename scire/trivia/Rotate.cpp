#include <exception>

template<class type>
type RotateRight(type num, int bits, int len){
	if (bits > len) throw exception("bits cannot be larger than len\n");
	type rorMusk = 1;
	rorMusk = rorMusk << bits;
	type rorBuff = num%rorMusk;
	rorBuff = rorBuff << (len - bits);
	type rorNum = num >> bits;
	return rorNum + rorBuff;
}

template<class type>
type RoR(type num, int bits, int len){
	return RotateRight(num, bits, len);
}

template<class type>
type RotateLeft(type num, int bits, int len){
	if (bits > len) throw exception("bits cannot be larger than len\n");
	type rolMusk = 1;
	rolMusk = rolMusk << (len - bits);
	type rolBuff = num / rolMusk;
	type rolNum = num << bits;
	return rolNum + rolBuff;
}

template<class type>
type RoL(type num, int bits, int len){
	return RotateLeft(num, bits, len);
}


//test codes
#include <iostream>
#include <bitset>
using namespace std;
#define LEN 16
int main(){
	try {
		_Uint32t a = 1024;
		_Uint32t b = RotateLeft<_Uint32t>(a, 10, LEN);
		bitset<LEN> bitsa(a);
		bitset<LEN> bitsb(b);
		cout << bitsa << endl << bitsb << endl;
	}
	catch (exception e){
		cout << e.what();
	}
	return 0;
}