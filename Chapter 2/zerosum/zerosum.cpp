/*
TASK: zerosum
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

int interpret(string s) {
  int currentAns = 0;
  int currentInt = 0;
  int currentSign = 1;
  vector<int> theNumbers;
  for(int i = 0; i < s.length(); i++ ) {
    
    if(isdigit(s[i])) {
      currentInt *= 10;
      currentInt += (s[i] - '0');
    }
    if(s[i] == ' ') {
      continue;
    }
    if(s[i] == '+') {
      theNumbers.push_back(currentSign * currentInt);
      currentInt = 0;
      currentSign = 1;
    }
    if(s[i] == '-') {
      theNumbers.push_back(currentSign * currentInt);
      currentInt = 0;
      currentSign = -1;
    }
  }
  theNumbers.push_back(currentSign * currentInt);
  for(int i = 0; i < theNumbers.size(); i++ ) {
    currentAns += theNumbers[i];
  }
  return currentAns;
}

void solve(vector<string> &ans, int N) {
  string s = "";
  unordered_set<string> stuffAlreadyDone;
  for(int i = 0; i < N; i++ ) {
    s += to_string(i + 1);
    if(i != N - 1) s += " ";
  }
  int upperLimit = 1;
  for(int i = 0; i < N; i++ ) {
    upperLimit *= 3;
  }
  for(int i = 0; i < upperLimit; i++ ) {
    int iCopy = i;
    // cout << iCopy << endl;
    for(int j = 1; j < 2 * N - 2; j += 2 ) {
      if(iCopy % 3 == 0) {
        s[j] = ' ';
      }
      if(iCopy % 3 == 1) {
        s[j] = '+';
      }
      if(iCopy % 3 == 2) {
        s[j] = '-';
      }
      iCopy /= 3;
    }
    if(interpret(s) == 0) {
      if(stuffAlreadyDone.find(s) == stuffAlreadyDone.end()) {
        ans.push_back(s);
        stuffAlreadyDone.insert(s);
      }
    }
    for(int j = 1; j < 2 * N - 2; j += 2) {
      s[j] = ' ';
    }
  }
}

int main() {
  int N;
  ifstream infile("zerosum.in");
  ofstream outfile("zerosum.out");
  infile >> N;
  vector<string> answers;
  solve(answers, N);
  // cout << interpret("1-2 3") << endl;
  sort(answers.begin(), answers.end());
  for(int i = 0; i < answers.size(); i++ ) {
    outfile << answers[i] << endl;
  }
  return 0;
}
