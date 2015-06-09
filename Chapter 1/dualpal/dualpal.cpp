/*
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

float logbase(float base, float param) {
	return log(param)/log(base);
}

bool intIsPalindrome(long long x) {
	int i = 0;
	long long val = 0;
	long long y = x;
	int numDigits = (int)logbase(10, x) + 1;
	while(x > 0) {
		val += (x%10)*(long long)pow(10, numDigits - i - 1);
		x /= 10;
		i++;
	}
	return (val == y);
}

long long convert(int basetennum, int newbase) {
	if(basetennum < newbase) return basetennum;
	int largestpower = (int)logbase(newbase, basetennum);
	int val = basetennum/((int)pow(newbase, largestpower));
	long long x = (long long)pow(10, largestpower)*val;
	basetennum-=(val*(long long)pow(newbase, largestpower));
	return x + convert(basetennum, newbase);
}

int main() {
	FILE* infile;
	infile = fopen("dualpal.in", "r");
	int N; int S;
	fscanf(infile, "%d %d", &N, &S);
	fclose(infile);
	int found = 0;
	int xy = 0;
	ofstream outfile("dualpal.out");
	for(int i = S + 1; i <= 2147483647; i++ ) {
		for(int j = 2; j <= 10; j++ ) {
			if(i % j == 0) continue;
			if(intIsPalindrome(convert(i, j))) {
				xy++;
			}
			if(xy == 2) {
				xy = 0;
				outfile << i << endl;
				found++;
				break;
			}
		}
		xy = 0;
		if(found == N) break;
	}
	// for(int i = 2; i <= 10; i++ ) {
	// 	int test = 10333;
	// 	long long x = convert(test, i);
	// 	cout << x << " " << intIsPalindrome(x) << endl;
	// }
	return 0;
}
