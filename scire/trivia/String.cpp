size_t stringlen(char *str){
	size_t i = -1;
	while (str[++i] != '\0'){ ; }
	return i;
}

void stringrev(char* str){
	size_t n = stringlen(str)-1;
	size_t i = 0;
	register char c;
	while (i < n){
		c = str[i];
		str[i] = str[n];
		str[n] = c;
		i++; n--;
	}
}

#include <iostream>
#include <string>
using namespace std;
int main(){
	char str[50] = "abcde";
	stringrev(str);
	cout << str<<endl;
	return 0;
}