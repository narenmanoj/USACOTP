
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
	while(maxDiff(hills) > 17) {
		// apply the change to whichever is smaller
		if(ab(hills[0].change) < ab(hills[N - 1].change)) {
			hills[0].change++;
		}
		else {
			hills[N - 1].change--;
		}
		sort(hills.begin(), hills.end(), sort1);
	}
	int sum = 0;
	for(int i = 0; i < N; i++ ) {
		sum += (hills[i].change * hills[i].change);
		cout << hills[i].originalHeight << " " << hills[i].change << " " << hills[i].originalHeight + hills[i].change << endl;
	}
	outfile << sum << endl;
	return 0;
}
