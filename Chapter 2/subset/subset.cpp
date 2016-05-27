/*
TASK: subset
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAX_N 40

#define sumToN(__arg__) (__arg__ * (__arg__ + 1)) / 2

vector< vector<int> > dp(MAX_N, vector<int>(sumToN(MAX_N) / 2, -1 ));

int N;

int solve(int setMax, int desired) {
  if(desired == 1) {
    dp[setMax][1] = 1;
    return 1;
  }
  if(desired <= 0) return 0;
  if(setMax < 0) return 0;
  if(dp[setMax][desired] != -1) {
    return dp[setMax][desired];
  }
  if(sumToN(setMax) < desired) {
    dp[setMax][desired] = 0;
    return 0;
  }
  if(sumToN(setMax) == desired) {
    dp[setMax][desired] = 1;
    return 1;
  }
  int ansWithMax = solve(setMax - 1, desired - setMax);
  int ansWithoutMax = solve(setMax - 1, desired);
  int finalAns = ansWithMax + ansWithoutMax;
  dp[setMax][desired] = finalAns;
  return finalAns;
}

int main() {
  ifstream infile("subset.in");
  infile >> N;
  ofstream outfile("subset.out");
  if(N * (N + 1) % 4 != 0) {
    outfile << 0 << endl;
    return 0;
  }
  int target = N * (N + 1) / 4; // we want to construct a subset that sums to this
  outfile << solve(N, target) << endl;
  outfile.close();
  return 0;
}
