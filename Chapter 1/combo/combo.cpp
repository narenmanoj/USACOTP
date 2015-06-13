/*
LANG: C++
TASK: combo
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

int abso(int x) {
	if(x < 0) return -1 * x;
	return x;
}

int computeIntersections(vector<int> &combo1, vector<int> &combo2, int maxDial) {
	if(maxDial == 1) return 249;
	for(int i = 0; i < 3; i++ ) {
		int big;
		int small;
		if(combo1[i] < combo2[i]) {
			small = combo1[i];
			big = combo2[i];
			if(big - small > maxDial/2) {
				small+=maxDial;
				int temp;
				temp = big;
				big = small;
				small = temp;
			}
		} else if(combo1[i] > combo2[i]) {
			small = combo2[i];
			big = combo1[i];
			if(big - small > maxDial/2) {
				small+=maxDial;
				int temp;
				temp = big;
				big = small;
				small = temp;
			}
		}
		if(big - small > 4) {
			return 0;
		}
	}
	int count = 1;
	int small; int big;
	for(int i = 0; i < 3; i++ ) {
		if(combo1[i] < combo2[i]) {
			small = combo1[i];
			big = combo2[i];
			if(big - small > maxDial/2) {
				small+=maxDial;
				int temp;
				temp = big;
				big = small;
				small = temp;
			}
			int multiplier = 0;
			for(int j = small - 2; j <= big + 2; j++ ) {
				if(abso(small - j) <= 2 && abso(big - j) <= 2) multiplier++;
			}
			count *= (multiplier);
		} else if(combo1[i] > combo2[i]) {
			small = combo2[i];
			big = combo1[i];
			if(big - small > maxDial/2) {
				small+=maxDial;
				int temp;
				temp = big;
				big = small;
				small = temp;
			}
			int multiplier = 0;
			for(int j = small - 2; j <= big + 2; j++ ) {
				if(abso(small - j) <= 2 && abso(big - j) <= 2) multiplier++;
			}
			count *= (multiplier);
		} else {
			count *= 5;
		}
	}
	return count;
}

int main() {
	int N;
	ifstream infile("combo.in");
	ofstream outfile("combo.out");
	infile >> N;
	vector<int> fJohnCombo(3);
	vector<int> masterCombo(3);
	infile >> fJohnCombo[0] >> fJohnCombo[1] >> fJohnCombo[2];
	infile >> masterCombo[0] >> masterCombo[1] >> masterCombo[2];
	int ans;
	if(N < 5) ans = N * N * N;
	else ans = 250 - computeIntersections(fJohnCombo, masterCombo, N);
	outfile << ans << endl;
	return 0;
}
