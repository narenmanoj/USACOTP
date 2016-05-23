/*
TASK: sort3
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int align(vector<int> &original, const vector<int> &target, const vector<int> &counts, int N) {
  // base case ///////////////
  for(int i = 0; i < N; i++ ) {
    if(original[i] != target[i]) break;
    if(i == N - 1) return 0;
  }
  ////////////////////////////
  for(int i = 0; i < N; i++ ) {
    if(original[i] != target[i]) {
      // swap in first misplaced instance of target[i]
      for(int j = i + 1; j < N; j++ ) {
        if(original[j] == target[i] && original[j] != target[j] && original[i] == target[j]) {
          // swap original[i] and original[j]
          int temp = original[i];
          original[i] = original[j];
          original[j] = temp;
          return 1 + align(original, target, counts, N);
        }
      }
      for(int j = i + 1; j < N; j++ ) {
        if(original[j] == target[i] && original[j] != target[j]) {
          // swap original[i] and original[j]
          int temp = original[i];
          original[i] = original[j];
          original[j] = temp;
          return 1 + align(original, target, counts, N);
        }
      }
    }
  }
}

int main() {
  ifstream infile("sort3.in");
  int N;
  infile >> N;
  ofstream outfile("sort3.out");
  vector<int> original(N);
  vector<int> target(N);
  vector<int> counts(4);
  for(int i = 0; i < N; i++ ) {
    int x; infile >> x;
    counts[x]++;
    original[i] = x;
  }
  for(int i = 0; i < N; i++ ) {
    if(i < counts[1]) {
      target[i] = 1;
    } else if(i < counts[1] + counts[2]) {
      target[i] = 2;
    } else {
      target[i] = 3;
    }
  }
  outfile << align(original, target, counts, N) << endl;
  outfile.close();
  return 0;
}
