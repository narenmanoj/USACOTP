
/*
LANG: C++11
TASK: skidesign
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <algorithm> 

using namespace std;

struct hill {
	int originalHeight;
	int change;
};

int ab(int x) {
	if(x < 0) return x*-1;
	return x;
}

int maxDiff(vector<hill> &v) {
	int min = v[0].originalHeight + v[0].change;
	int max = min;
	max = v[v.size() - 1].originalHeight + v[v.size() - 1].change;
	// for(int i = 1; i < v.size(); i++ ) {
	// 	int x = v[i].originalHeight + v[i].change;
	// 	if(min > x) min = x;
	// 	if(max < x) max = x;
	// }
	return max - min;
}

bool sort1(const hill &lhs, const hill &rhs) {
	if(lhs.originalHeight + lhs.change < rhs.originalHeight + rhs.change) return true;
	if(lhs.originalHeight + lhs.change > rhs.originalHeight + rhs.change) return false;
	if(lhs.change > rhs.change) return true;
	return false;
}

int compute(int minHeight, int maxHeight, vector<hill> &hills, int N) {
	for(int i = 0; i < N; i++ ) {
		if(hills[i].originalHeight + hills[i].change < minHeight) {
			hills[i].change = minHeight - hills[i].originalHeight;
		}
		if(hills[i].originalHeight + hills[i].change > maxHeight) {
			hills[i].change = maxHeight - hills[i].originalHeight;
		}
	}
	int sum = 0;
	for(int i = 0; i < N; i++ ) {
		sum += (hills[i].change * hills[i].change);
		cout << hills[i].originalHeight << " " << hills[i].change << " " << hills[i].originalHeight + hills[i].change << endl;
	}
	return sum;
}

int main() {
	ifstream infile("skidesign.in");
	ofstream outfile("skidesign.out");
	int N;
	infile >> N;
	vector<hill> hills(N);
	for(int i = 0; i < N; i++ ) {	
		infile >> hills[i].originalHeight;
		hills[i].change = 0;
	}
	sort(hills.begin(), hills.end(), sort1);
	int minHeight;
	int maxHeight;
	int s = 0;
	for(int i = 0; i < N; i++ ) {
		s += hills[i].originalHeight;
	}
	s /= N;
	maxHeight = s + 8;
	minHeight = s - 9;
	minHeight -= 8;
	maxHeight -= 8;
	int minSum = 2147483647;
	int a = 0;
	for(int i = 0; i < 20; i++ ) {
		a = compute(minHeight, maxHeight, hills, N);
		for(int i = 0; i < N; i++ ) {
			hills[i].change = 0;
		}
		if(minSum > a) {
			minSum = a;
		}
		minHeight++;
		maxHeight++;
	}
	
	outfile << minSum << endl;
	return 0;
}
