/*
LANG: C++
TASK: milk2
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

struct mystruct {
	int start;
	int end;
};

bool wayToSort(mystruct s1, mystruct s2) {
	return (s1.start < s2.start);
}

int main() {
	FILE* infile;
	infile = fopen("milk2.in", "r");
	int N;
	fscanf(infile, "%d", &N);
	if(N == 1) {
		ofstream outfile("milk2.out");
		int x; int y;
		fscanf(infile, "%d %d", &x, &y);
		outfile << y - x << " " << 0 << endl;
		return 0;
	}
	vector<mystruct> startends(N);
	// vector<mystruct> startendstemp(N);
	for(int i = 0; i < N; i++ ) {
		int x; int y;
		fscanf(infile, "%d %d", &x, &y);
		// startendstemp[i].start = x;
		// startendstemp[i].end = y;
		startends[i].start = x;
		startends[i].end = y;
	}
	// now we need to sort startends by starting time
	// sort(startendstemp.begin(), startendstemp.end(), wayToSort);
	sort(startends.begin(), startends.end(), wayToSort);
	// end sort
	int starttime; int endtime;
	starttime = startends[0].start; endtime = startends[0].end;
	bool done = false;
	int i = 1;
	int maxLenMilk = -1;
	int maxLenNoMilk = 0;
	while(!done) {
		if(starttime <= startends[i].start && startends[i].start <= endtime && startends[i].end >= endtime) {
			endtime = startends[i].end;
		} else if(starttime <= startends[i].start && startends[i].start <= endtime && startends[i].end <= endtime) {
			// keep going
		} else {
			if(maxLenMilk < endtime - starttime) {
				maxLenMilk = endtime - starttime;
			}
			// if(maxLenNoMilk < startends[i].start - startends[i].end) {
			// 	maxLenNoMilk = startends[i].start - startends[i].end;
			// }
			starttime = startends[i].start;
			endtime = startends[i].end;

			// let's try doing the end here as well
		}
		if(i == N - 1) {
			if(maxLenMilk < endtime - starttime) {
				maxLenMilk = endtime - starttime;
			}
			done = true;
		}
		else i++;
	}
	// cout << maxLenMilk;
	// // if a start time is bigger than all previous end times then this was a phase of no milk
	
	// assuming that its sorted by increasing start time
	
	int maxEndTime = -1;
	for(int i = 1; i < N; i++ ) {
		for(int j = 0; j < i; j++ ) {
			if(startends[i].start < startends[j].end) break;
			if(maxEndTime < startends[j].end) maxEndTime = startends[j].end;
			if(j == i - 1) { // we reached end of loop
				if(maxLenNoMilk < startends[i].start - maxEndTime) maxLenNoMilk = startends[i].start - maxEndTime;
				maxEndTime = -1;
			}
		}
	}
	// cout << maxLenNoMilk;
	ofstream outfile("milk2.out");
	outfile << maxLenMilk << " " << maxLenNoMilk << endl;
	return 0;
}
