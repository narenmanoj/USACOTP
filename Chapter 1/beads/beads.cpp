/*
LANG: C++
TASK: beads
*/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>

using namespace std;

bool contains(string str, char c) {
	for(int i = 0; i < str.length(); i++ ) {
		if(str[i] == c) return true;
	} return false;
}

int getCount(int l, string str) {
	if(contains(str, 'r') && contains(str, 'b')) {
		vector<int> x(l);
		for(int i = 0; i < l; i++ ) {
			int lcount, rcount; lcount = rcount = 0;
			int left, right; left = 1; right = l - 2;
			char lchar = str[0];
			while(((str[left] == lchar || str[left] == 'w') || (lchar == 'w' && str[left] != 'w')) && right - left >= 0) {
				if(lchar == 'w' && str[left] != 'w') {
					lchar = str[left];
				}
				left++;
				lcount++;
			}
			char rchar = str[l - 1];
			while((str[right] == rchar || str[right] == 'w' || (rchar == 'w' && str[right] != 'w')) && right - left >= 0) {
				if(rchar == 'w' && str[right] != 'w') {
					rchar = str[right];
				}
				right--;
				rcount++;
			}
			x[i] = rcount + lcount;
			str = rchar + str.substr(0, l-1);
		}
		int max = x[0];
		for(int i = 1; i < l; i++ ) {
			if(max < x[i]) max = x[i];
		}
		return max + 2;
	}
	return l;
}

int main() {
	string str;
	string st;
	int l;
	ifstream inFile("beads.in");
	inFile >> l;
	getline(inFile, st);
	getline(inFile, str);
	int n = getCount(l, str);
	FILE* output;
	output = fopen("beads.out", "w");
	fprintf(output, "%d\n", n);
	cout << l;
	cout << str;
	return 0;
}
