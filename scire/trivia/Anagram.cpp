#include <string>
#include "..\Typedefs.h"

using namespace std;

bool isTwoStringsAnagram(char* str1, char* str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	if (len1 != len2) return false;

	int alphCnt[26],i;
	for (i = 0; i < 26; i++){
		alphCnt[i] = 0;
	}

	for (i = 0; i < len1; i++){
		alphCnt[tolower(str1[i]) - 'a']++;
	}
	for (i = 0; i < len2; i++){
		alphCnt[tolower(str2[i]) - 'a']--;
	}


	for (i = 0; i < 26; i++){
		if (alphCnt[i] != 0) return false;
	}

	return true;
}

//#include <iostream>
//int main(){ cout << isTwoStringsAnagram("abcde","cebda"); }