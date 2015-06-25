/*
LANG: C++11
TASK: crypt1
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

bool isValid(int a, vector<int> &v, int size) {
	while(a > 0) {
		int test = a % 10;
		int i = 0;
		bool found = false;
		while(!found && i < size) {
			if(test == v[i]) found = true;
			i++;
		}
		if(!found) return false;
		a /= 10;
	} return true;
}

int main() {
	int N;
	ifstream infile("crypt1.in");
	infile >> N;
	int count = 0;
	vector<int> digitlist(N);
	for(int i = 0; i < N; i++ ) {
		infile >> digitlist[i];
	}
	for(int i : digitlist) {
		for(int j : digitlist) {
			for(int k : digitlist) {
				int top = 100 * i + 10 * j + k;
				for(int a : digitlist) {
					if(top * a >= 1000) continue;
					for(int b : digitlist) {
						int bottom = 10 * a + b;
						if(top * bottom >= 10000) continue;
						if(top * b >= 1000) continue;
						if(isValid(top * a, digitlist, N) && isValid(top * b, digitlist, N) && isValid(top * bottom, digitlist, N)) count++;
					}
				}
			}
		}
	}
	ofstream outfile("crypt1.out");
	outfile << count << endl;
}
