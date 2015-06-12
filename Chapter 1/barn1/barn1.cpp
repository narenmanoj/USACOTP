/*
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <algorithm> 

using namespace std;

bool wayToSort(int i1, int i2) {return (i1 > i2);}

int main() {
	ifstream infile("barn1.in");
	ofstream outfile("barn1.out");
	int m; int s; int c; int temp; int length = 0;
	infile >> m >> s >> c;
	if(m > c) m = c;
	vector<int> gaps(c - 1);
	vector<int> stalls(c);
	infile >> temp;
	stalls[0] = temp;
	for(int i = 1; i < c; i++ ) {
		infile >> temp;
		stalls[i] = temp;
	}
	sort(stalls.begin(), stalls.end());
	for(int i = 0; i < c; i++ ) {
		cout << stalls[i] << endl;
	}
	for(int i = 1; i < c; i++ ) {
		gaps[i - 1] = stalls[i] - stalls[i - 1] - 1;
	}
	sort(gaps.begin(), gaps.end(), wayToSort);
	int minStall = 201;
	int maxStall = -1;
	for(int i = 0; i < c; i++ ) {
		if(minStall > stalls[i]) minStall = stalls[i];
		if(maxStall < stalls[i]) maxStall = stalls[i];
	}
	int totalLength = maxStall - minStall + 1;
	cout << "total length: " << totalLength << endl;
	int numToSubtract = 0;
	for(int i = 0; i < m - 1; i++ ) {
		numToSubtract += gaps[i];
	}
	length = totalLength - numToSubtract;
	outfile << length << endl;
	return 0;
}
