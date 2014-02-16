//#include <iostream>
#include <vector>
#include <time.h>
#include "..\Typedefs.h"
//#include <Windows.h>

using namespace std;

vector<uInt64> AllPrime(uInt64 n){
	vector<uInt64> primes;
	int primeCount = 0;
	
	if (n < 2) return primes;
	
	primes.push_back(2); 	primeCount++;
	if (n < 3) return primes;
	primes.push_back(3);	primeCount++;
	if (n < 5) return primes;
	primes.push_back(5);	primeCount++;


	if (n < 7) return primes;
	uInt64 x = 7;

	while (x<=n)
	{
		//if x prime
		register int i = 0;
		uInt64 bound = sqrt(x);
		register bool mayBePrime = true;
		while (mayBePrime && i <= primeCount && primes[i] <= bound)
		{
			if (x%primes[i] == 0) mayBePrime = false;
			i++;
		}
		if (mayBePrime){
			primes.push_back(x); primeCount++;
		}
		//next candidate
		x += 2;
	}

	return primes;
}

//int main(){
//	DWORD tm = GetTickCount();
//	vector<uInt64> pr = AllPrime(100000000);
//	cout << GetTickCount() - tm << endl;
//
//
//	/*for (int i = 0; i < pr.size(); i++)
//		cout << pr[i] << " ";*/
//
//	return 0;
//}