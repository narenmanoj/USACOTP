/*
TASK: hamming
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>

#define MAX_INT 2147483647

using namespace std;

int hd(int x1, int x2) {
  int r = x1 ^ x2;
  int ans = 0;
  while(r > 0) {
    ans += (r % 2);
    r /= 2;
  }
  return ans;
}

int minHd(int test, unordered_set<int> &present) {
  int ans = MAX_INT;
  for(int x : present) {
    int y = hd(x, test);
    if(y < ans) ans = y;
  }
  return ans;
}

int solve(int start, int N, int max, int D, unordered_set<int> &present) {
  if(present.size() == N) {
    cout << "reached base" << endl;
    return 1;
  }
  if(present.size() == 0) present.insert(start);
  int large = -1;
  for(int x : present) {
    if(x > large) large = x;
  }
  cout << "large: " << large << endl;
  cout << "max: " << max << endl;
  for(int i = large + 1; i <= max; i++ ) {
    if(minHd(i, present) >= D) {
      cout << "found a candidate" << endl;
      present.insert(i);
      int t = solve(start, N, max, D, present);
      if(t == 1) return 1;
      present.erase(i);
    }
  }
  return 0;
}

int main() {
  ifstream infile("hamming.in");
  ofstream outfile("hamming.out");
  int N, B, D;
  infile >> N >> B >> D;
  int max = 1;
  max = max << (B);
  unordered_set<int> theSet;
  for(int i = 0; i <= max; i++ ) {
    if(solve(i, N, max, D, theSet)) break;
  }
  string ans = "";
  int j = 0;
  vector<int> ansVec;
  for(int x : theSet) {
    ansVec.push_back(x);
  }
  sort(ansVec.begin(), ansVec.end());
  for(int i = 0; i < ansVec.size(); i++ ) {
    ans += to_string(ansVec[i]);
    if(i != ansVec.size() - 1) {
      if(i % 10 == 9 && i != 0) ans += "\n";
      else ans += " ";
    }
  }
  outfile << ans << endl;
  outfile.close();
  return 0;
}
