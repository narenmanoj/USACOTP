/*
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

long long nameToInt(string str) {
	int l = str.length();
	vector<int> digits(l);
	for(int i = 0; i < l; i++ ) {
		if(str[i] == 'Q' || str[i] == 'Z') {
			digits[i] = 1;
		}
		else if(str[i] == 'A' || str[i] == 'B' || str[i] == 'C') {
			digits[i] = 2;
		}
		else if(str[i] == 'D' || str[i] == 'E' || str[i] == 'F') {
			digits[i] = 3;
		}
		else if(str[i] == 'G' || str[i] == 'H' || str[i] == 'I') {
			digits[i] = 4;
		}
		else if(str[i] == 'J' || str[i] == 'K' || str[i] == 'L') {
			digits[i] = 5;
		}
		else if(str[i] == 'M' || str[i] == 'N' || str[i] == 'O') {
			digits[i] = 6;
		}
		else if(str[i] == 'P' || str[i] == 'R' || str[i] == 'S') {
			digits[i] = 7;
		}
		else if(str[i] == 'T' || str[i] == 'U' || str[i] == 'V') {
			digits[i] = 8;
		}
		else if(str[i] == 'W' || str[i] == 'X' || str[i] == 'Y') {
			digits[i] = 9;
		}
	}
	long long result = 0;
	for(int i = 0; i < l; i++ ) {
		result += ((long long)pow(10, l - 1 - i) * digits[i]);
	}
	return result;
}

int main() {
	vector<string> nameDict(4617);
	vector<string> intDict(4617);
	ifstream dictFile("dict.txt");
	for(int i = 0; i < 4617; i++ ) {
		getline(dictFile, nameDict[i]);
		stringstream ss; long long temp = nameToInt(nameDict[i]);
		ss << temp;
		intDict[i] = ss.str();
	}
	dictFile.close();
	ifstream inFile("namenum.in");
	// long long n;
	// inFile >> n;
	string nAsString;
	getline(inFile, nAsString);
	inFile.close();
	// stringstream ss1; ss1 << n;
	// string nAsString = ss1.str();
	ofstream outFile("namenum.out");
	int nameCount = 0;
	// now we need to ~put~ search of nAsString in intDict - intDict is in alpha order
	for(int i = 0; i < 4617; i++ ) {
		if(nAsString == intDict[i]) {
			outFile << nameDict[i] << endl;
			nameCount++;
		}
	}
	if(nameCount == 0) outFile << "NONE" << endl;
	outFile.close();
	return 0;
}
