#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(int id, vector<string> &spotsStr, vector< vector<int> > &spotsNum, vector< vector<bool> > &visited, int N, int M, int r, int c) {
	if(visited[r][c]) return false;
	if(spotsStr[r][c] == '.') return false;
	stack< pair<int, int> > mystack;
	pair<int, int> initial(r, c);
	mystack.push(initial);
	pair<int, int> currentCoord;
	while(!mystack.empty()) {
		currentCoord = mystack.top();
		mystack.pop();
		r = currentCoord.first;
		c = currentCoord.second;
		visited[r][c] = true; // mark the popped one as visited
		spotsNum[r][c] = id; // mark the popped one with the id specified
		// can we push the one directly above?
		if(r - 1 >= 0 && spotsStr[r - 1][c] == 'X' && !visited[r - 1][c]) {
			pair<int, int> topushN(r - 1, c);
			mystack.push(topushN);
		}
		// can we push the one directly below?
		if(r + 1 < N && spotsStr[r + 1][c] == 'X' && !visited[r + 1][c]) {
			pair<int, int> topushS(r + 1, c);
			mystack.push(topushS);
		}
		// can we push the one directly to the left?
		if(c - 1 >= 0 && spotsStr[r][c - 1] == 'X' && !visited[r][c - 1]) {
			pair<int, int> topushW(r, c - 1);
			mystack.push(topushW);
		}
		// can we push the one directly to the right?
		if(c + 1 < M && spotsStr[r][c + 1] == 'X' && !visited[r][c + 1]) {
			pair<int, int> topushE(r, c + 1);
			mystack.push(topushE);
		}
	}
	return true;
}

int countSpots(vector<string> &spotsStr, vector< vector<int> > &spotsNum, vector< vector<bool> > &visited, int N, int M) {
	int id = 0;
	for(int i = 0; i < N; i++ ) {
		for(int j = 0; j < M; j++ ) {
			if(spotsStr[i][j] == 'X' && spotsNum[i][j] == 0) {
				id++;
				dfs(id, spotsStr, spotsNum, visited, N, M, i, j);
			}
		}
	}
	return id;
}

void resetDFS(vector< vector<int> > &spotsNum, vector< vector<bool> > &visited, int N, int M) {
	for(int i = 0; i < N; i++ ) {
		for(int j = 0; j < M; j++ ) {
			visited[i][j] = false;
			spotsNum[i][j] = 0;
		}
	}
}

int main() {
	ifstream infile("pageant.in");
	ofstream outfile("pageant.out");
	int N, M;
	infile >> N;
	infile >> M;
	string t1;
	getline(infile, t1);
	vector<string> spotsStr(N);
	vector< vector<int> > spotsNum(N, vector<int>(M));
	vector< vector<bool> > visited(N, vector<bool>(M));
	for(int i = 0; i < N; i++ ) {
		for(int j = 0; j < M; j++ ) {
			visited[i][j] = false;
			spotsNum[i][j] = 0;
		}
	}
	for(int i = 0; i < N; i++ ) {
		getline(infile, spotsStr[i]);
	}
	int numSpots = countSpots(spotsStr, spotsNum, visited, N, M);
	// now all we need to do is find dist between 1 and 2, 2 and 3, 1 and 3. sum the least two and done

	// find the distance between 1 and 2
	int min12 = 101;
	int min13 = 101;
	int min23 = 101;
	for(int i = 1; i < N; i++ ) {
		for(int j = 1; j < M; j++ ) {
			for(int k = 0; k <= i; k++ ) {
				for(int l = 0; l <= j; l++ ) {
					if(spotsNum[i][j] == 1) {
						if(spotsNum[k][l] == 2) {
							int test = i - k + j - l - 1;
							if(min12 > test) min12 = test;
						}
						if(spotsNum[k][l] == 3) {
							int test = i - k + j - l - 1;
							if(min13 > test) min13 = test;
						}
					}
					if(spotsNum[i][j] == 2) {
						if(spotsNum[k][l] == 3) {
							int test = i - k + j - l - 1;
							if(min23 > test) min23 = test;
						}
						if(spotsNum[k][l] == 1) {
							int test = i - k + j - l - 1;
							if(min12 > test) min12 = test;
						}
					}
					if(spotsNum[i][j] == 3) {
						if(spotsNum[k][l] == 1) {
							int test = i - k + j - l - 1;
							if(min13 > test) min13 = test;
						}
						if(spotsNum[k][l] == 2) {
							int test = i - k + j - l - 1;
							if(min23 > test) min23 = test;
						}
					}
				}
			}
		}
	}
	cout << min12 << " " << min23 << " " << min13 << endl;
	int ans = min12 + min13 + min23 - max(max(min12, min13), min23);
	outfile << ans << endl;
	// for(int i = 0; i < N; i++ ) {
	// 	for(int j = 0; j < M; j++ ) {
	// 		cout << spotsNum[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}
