/*
TASK: lamps
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <inttypes.h>

using namespace std;

int N;
int C;

vector<int> finalLampState;
vector< vector<int> > allPossibleStates(16);

void readInput() {
  ifstream infile("lamps.in");
  infile >> N >> C;
  finalLampState.resize(N);
  for(int i = 0; i < N; i++ ) {
    finalLampState[i] = -1; // -1 is unknown
  }
  int x;
  infile >> x;
  // cout << x << endl;
  while(x != -1) {
    finalLampState[x - 1] = 1; // 1 is on
    infile >> x;
    // cout << x << endl;
  }
  infile >> x;
  // cout << x << endl;
  while(x != -1) {
    finalLampState[x - 1] = 0;
    infile >> x;
    // cout << x << endl;
  }
}

void fillAllPossibleStates() {
  for(int i = 0; i < 16; i++ ) {
    allPossibleStates[i].resize(N);
    for(int j = 0; j < N; j++ ) {
      allPossibleStates[i][j] = 1;
    }
  }
  for(uint8_t i = 0; i < 16; i++ ) {
    if((i & 0x01) == 1) {
      for(int j = 0; j < N; j++ ) {
        allPossibleStates[i][j] = !allPossibleStates[i][j];
      }
    }
    if(((i >> 1) & 0x01) == 1) {
      for(int j = 1; j <= N; j += 2) {
        allPossibleStates[i][j - 1] = !allPossibleStates[i][j - 1];
      }
    }
    if(((i >> 2) & 0x01) == 1) {
      for(int j = 2; j <= N; j += 2) {
        allPossibleStates[i][j - 1] = !allPossibleStates[i][j - 1];
      }
    }
    if(((i >> 3) & 0x01) == 1) {
      for(int j = 1; j <= N; j += 3) {
        allPossibleStates[i][j - 1] = !allPossibleStates[i][j - 1];
      }
    }
  }
}

int vecEqual(vector<int> &lhs, vector<int> &rhs ) {
  if(lhs.size() != rhs.size()) return 0;
  for(int i = 0; i < lhs.size(); i++ ) {
    if(rhs[i] == -1) continue;
    if(lhs[i] != rhs[i]) return 0;
  }
  return 1;
}

int getOnes(uint8_t x) {
  if(x == 0) return 0;
  if(x == 1) return 1;
  return (x % 2) + getOnes(x >> 1);
}

int wts(const string &lhs, const string &rhs) {
  for(int i = 0; i < lhs.size(); i++ ) {
    if(lhs[i] == '0' && rhs[i] == '1') {
      return 1;
    }
    if(lhs[i] == '1' && rhs[i] == '0') {
      return 0;
    }
  }
  return 0;
}

int main() {
  readInput();
  // for(int i = 0; i < N; i++ ) {
  //   cout << finalLampState[i] << " ";
  // } cout << endl;
  fillAllPossibleStates();
  vector<string> answers;
  for(uint8_t i = 0; i < 16; i++ ) {
    int numLampsPressed = getOnes(i);
    if(vecEqual(allPossibleStates[i], finalLampState)) {
      if((C - numLampsPressed) % 2 == 0 && C >= numLampsPressed) {
        // cout << (int)i << " " << numLampsPressed << endl;
        string ansString = "";
        for(int j = 0; j < N; j++ ) {
          ansString += to_string(allPossibleStates[i][j]);
        }
        answers.push_back(ansString);
      }
    }
  }
  sort(answers.begin(), answers.end(), wts);
  ofstream outfile("lamps.out");
  for(int i = 0; i < answers.size(); i++ ) {
    outfile << answers[i] << endl;
  }
  if(answers.size() == 0) outfile << "IMPOSSIBLE" << endl;
  outfile.close();
  return 0;
}
