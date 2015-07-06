/*
LANG: C++
TASK: friday
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>

using namespace std;

bool isLeap(int yr) {
	/*if(yr%400 == 0) return true;
	if(yr%100 == 0) return false;
	if(yr%4 == 0) return true;
	return false;*/
	if(yr%4 != 0) return false;
	if(yr%100 == 0 && yr%16 != 0) return false;
	return true;
}

int compute(int yr, int firstDay, int desiredDay) {
	vector<int> c0unts(7);
	c0unts[0] = c0unts[1] = c0unts[2] = c0unts[3] = c0unts[4] = c0unts[5] = c0unts[6] = 0;
	if(isLeap(yr)) {
		c0unts[(12 + firstDay)%7]++;
		// february 13
		c0unts[(31 + 12 + firstDay)%7]++;
		// march 13
		c0unts[(31 + 12 + 29 + firstDay)%7]++;
		// april 13
		c0unts[(31 + 12 + 29 + 31 + firstDay)%7]++;
		// may 13
		c0unts[(31 + 12 + 29 + 31 + 30 + firstDay)%7]++;
		// june 13
		c0unts[(31 + 12 + 29 + 31 + 30 + 31 + firstDay)%7]++;
		// july 13
		c0unts[(31 + 12 + 29 + 31 + 30 + 31 + 30 + firstDay)%7]++;
		// august 13
		c0unts[(31 + 12 + 29 + 31 + 30 + 31 + 30 + 31 + firstDay)%7]++;
		// september 13
		c0unts[(31 + 12 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + firstDay)%7]++;
		// october 13
		c0unts[(31 + 12 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + firstDay)%7]++;
		// november 13
		c0unts[(31 + 12 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + firstDay)%7]++;
		// december 13
		c0unts[(31 + 12 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + firstDay)%7]++;
	}
	else {
		// january 13
		c0unts[(12 + firstDay)%7]++;
		// february 13
		c0unts[(31 + 12 + firstDay)%7]++;
		// march 13
		c0unts[(31 + 12 + 28 + firstDay)%7]++;
		// april 13
		c0unts[(31 + 12 + 28 + 31 + firstDay)%7]++;
		// may 13
		c0unts[(31 + 12 + 28 + 31 + 30 + firstDay)%7]++;
		// june 13
		c0unts[(31 + 12 + 28 + 31 + 30 + 31 + firstDay)%7]++;
		// july 13
		c0unts[(31 + 12 + 28 + 31 + 30 + 31 + 30 + firstDay)%7]++;
		// august 13
		c0unts[(31 + 12 + 28 + 31 + 30 + 31 + 30 + 31 + firstDay)%7]++;
		// september 13
		c0unts[(31 + 12 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + firstDay)%7]++;
		// october 13
		c0unts[(31 + 12 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + firstDay)%7]++;
		// november 13
		c0unts[(31 + 12 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + firstDay)%7]++;
		// december 13
		c0unts[(31 + 12 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + firstDay)%7]++;
	}
	return c0unts[desiredDay];
}

int main() {
	ifstream inFile;
	inFile.open("friday.in");
	int N;
	inFile >> N;
	inFile.close();
	FILE* outFile;
	outFile = fopen("friday.out", "w");
	vector<int> counts(7); // saturday is indexed at 0, last day of week puts friday
	counts[0] = counts[1] = counts[2] = counts[3] = counts[4] = counts[5] = counts[6] = 0;
	vector<int> firstDays(N); // puts first day (sat = 0) in the vector
	firstDays[0] = 2; // first day of 1900 put monday which is index 2
	for(int i = 1; i < N; i++ ) { //
		firstDays[i] = firstDays[i-1] + 365;
		if(isLeap(1900+i-1)) firstDays[i]++;
		firstDays[i]%=7;
	}
	for(int i = 0; i < N; i++ ) {
		for(int j = 0; j < 7; j++ ) {
			counts[j] += compute(1900 + i, firstDays[i],j);
		}
	}
	printf("%d, %d, %d, %d, %d, %d, %d", counts[0], counts[1], counts[2], counts[3], counts[4], counts[5], counts[6]);
	fprintf(outFile, "%d %d %d %d %d %d %d\n", counts[0], counts[1], counts[2], counts[3], counts[4], counts[5], counts[6]);
	fclose(outFile);
	return 0;
}
