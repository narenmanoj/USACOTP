/*
LANG: C++
TASK: transform
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

bool equal(int N, vector<string> &b1, vector<string> &b2) {
	for(int i = 0; i < N; i++ ) {
		for(int j = 0; j < N; j++ ) {
			if(b1[i][j] != b2[i][j]) return false;
		}
	} return true;
}

int main() {
	ifstream infile("transform.in");
	ofstream outfile("transform.out");
	int N;
	infile >> N;
	vector<string> original(N);
	vector<string> final(N);
	string x;
	getline(infile, x);
	for(int i = 0; i < N; i++ ) {
		getline(infile, x);
		original[i] = x;
	}
	for(int i = 0; i < N; i++ ) {
		getline(infile, x);
		final[i] = x;
	}
	
	// now check if one board is a rotation of the other - first we'll check 90 degrees clockwise
	string tomove;
	string blanks(N, ' ');
	vector<string> ninetydegrot(N);
	for(int i = 0; i < N; i++ ) {
		ninetydegrot[i] = blanks;
	}
	for(int i = N - 1; i >= 0; i-- ) {
		tomove = original[i];
		for(int j = 0; j < N; j++ ) {
			ninetydegrot[j][N - 1 - i] = tomove[j];
		}
	}
	if(equal(N, ninetydegrot, final)) {
		outfile << "1" << endl;
		return 0;
	}
	// done rotating 90 degrees clockwise

	// now we rotate 180 degrees - just rotate the ninety degree one
	vector<string> oneeightydegrot(N);
	for(int i = 0; i < N; i++ ) {
		oneeightydegrot[i] = blanks;
	}
	for(int i = N - 1; i >= 0; i-- ) {
		tomove = ninetydegrot[i];
		for(int j = 0; j < N; j++ ) {
			oneeightydegrot[j][N - 1 - i] = tomove[j];
		}
	}
	if(equal(N, oneeightydegrot, final)) {
		outfile << "2" << endl;
		return 0;
	}
	// done rotating 180 degrees

	// now we rotate 270 degrees
	vector<string> twoseventydegrot(N);
	for(int i = 0; i < N; i++ ) {
		twoseventydegrot[i] = blanks;
	}
	for(int i = N - 1; i >= 0; i-- ) {
		tomove = oneeightydegrot[i];
		for(int j = 0; j < N; j++ ) {
			twoseventydegrot[j][N - 1 - i] = tomove[j];
		}
	}
	if(equal(N, twoseventydegrot, final)) {
		outfile << "3" << endl;
		return 0;
	}
	// if we get this far then there could be a reflection involved
	vector<string> reflection(N);
	for(int i = 0; i < N; i++ ) {
		reflection[i] = blanks;
		for(int j = 0; j < N; j++ ) {
			reflection[i][j] = original[i][N - 1 - j];
		}
	}
	if(equal(N, reflection, final)) {
		outfile << "4" << endl;
		return 0;
	}
	// now we have to check all the rotations

	/////////////////////////////////////////
	for(int i = 0; i < N; i++ ) {
		ninetydegrot[i] = blanks;
	}
	for(int i = N - 1; i >= 0; i-- ) {
		tomove = reflection[i];
		for(int j = 0; j < N; j++ ) {
			ninetydegrot[j][N - 1 - i] = tomove[j];
		}
	}
	if(equal(N, ninetydegrot, final)) {
		outfile << "5" << endl;
		return 0;
	}
	// done rotating 90 degrees clockwise

	// now we rotate 180 degrees - just rotate the ninety degree one
	for(int i = 0; i < N; i++ ) {
		oneeightydegrot[i] = blanks;
	}
	for(int i = N - 1; i >= 0; i-- ) {
		tomove = ninetydegrot[i];
		for(int j = 0; j < N; j++ ) {
			oneeightydegrot[j][N - 1 - i] = tomove[j];
		}
	}
	if(equal(N, oneeightydegrot, final)) {
		outfile << "5" << endl;
		return 0;
	}
	// done rotating 180 degrees

	// now we rotate 270 degrees
	for(int i = 0; i < N; i++ ) {
		twoseventydegrot[i] = blanks;
	}
	for(int i = N - 1; i >= 0; i-- ) {
		tomove = oneeightydegrot[i];
		for(int j = 0; j < N; j++ ) {
			twoseventydegrot[j][N - 1 - i] = tomove[j];
		}
	}
	if(equal(N, twoseventydegrot, final)) {
		outfile << "5" << endl;
		return 0;
	}
	if(equal(N, original, final)) {
		outfile << "6" << endl;
		return 0;
	}
	//////////////////////////////
	outfile << "7" << endl;
	return 0;
}
