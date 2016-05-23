/*
TASK: frac1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int gcd(int a, int b) {
  if(b > a) {
    int temp = a;
    a = b;
    b = temp;
  }
  if(b == 0) return a;
  return gcd(b, a % b);
}

bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
  return ((double)lhs.first) / lhs.second < ((double)rhs.first) / rhs.second;
}

int main() {
  ifstream infile("frac1.in");
  ofstream outfile("frac1.out");

  int N;
  infile >> N;

  set< pair<int, int> > fractions;
  for(int i = 1; i <= N; i++ ) {
    if(i == 1) {
      fractions.insert(make_pair(0, 1));
      fractions.insert(make_pair(1, 1));
      continue;
    }
    for(int j = 1; j < i; j++ ) {
      int g = gcd(i, j);
      fractions.insert(make_pair(j/g, i/g));
    }
  }
  vector< pair<int, int> > fractionVec;
  for(const auto x : fractions) {
    fractionVec.push_back(x);
  }
  sort(fractionVec.begin(), fractionVec.end(), cmp);
  for(int i = 0; i < fractionVec.size(); i++ ) {
    outfile << fractionVec[i].first << "/" << fractionVec[i].second << endl;
  }
  return 0;
}
