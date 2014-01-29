#include <iostream>
int callcount = 0;
int classiccount = 0;

__int64 IntMul(int x, int y, int n){
	callcount++;
	if (n == 1) return x*y;
	__int64 a, b, c, xl, xr, yl, yr;
	n = n >> 1;

	//split x;
	xl = x; 	xl = xl >> n; 	xr = xl;
	xr = xr << n; 	xr = x - xr;

	//split y;
	yl = y; 	yl = yl >> n; 	yr = yl;
	yr = yr << n; 	yr = y - yr;

	//multiplication by recursive call
	a = IntMul(xl, yl, n);
	b = IntMul(xr, yr, n);
	c = IntMul(xl + xr, yl + yr, n);

	c = c - a - b; c = c << n;
	n = n << 1;  a = a << n;

	return a + b + c;
}

__int64 IntMulClassic(int x, int y, int n){
	classiccount++;
	if (n == 1) return x*y;
	__int64 a, b, c, d, xl, xr, yl, yr;
	n = n >> 1;

	//split x;
	xl = x; 	xl = xl >> n; 	xr = xl;
	xr = xr << n; 	xr = x - xr;

	//split y;
	yl = y; 	yl = yl >> n; 	yr = yl;
	yr = yr << n; 	yr = y - yr;

	//multiplication by recursive call
	a = IntMulClassic(xl, yl, n);
	b = IntMulClassic(xr, yr, n);
	c = IntMulClassic(xl, yr, n);
	d = IntMulClassic(xr, yl, n);

	c = c + d; c = c << n;
	n = n << 1;  a = a << n;

	return a + b + c;
}

/*
int main(){
	__int64 a = IntMul(100, 10, 32);
	std::cout << a << "in " << callcount << " steps\n";
	a = IntMulClassic(100, 10, 32);
	std::cout << a << "in " << classiccount<< " steps\n";
	return 0;
}*/