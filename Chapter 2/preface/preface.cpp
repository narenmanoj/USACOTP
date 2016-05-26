/*
TASK: preface
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// #define N 60

int N;

int main() {
  ifstream infile("preface.in");
  infile >> N;
  vector<string> romans(N + 1);
  map<int, int> currentNum;
  currentNum[1000] = 0;
  currentNum[500] = 0;
  currentNum[100] = 0;
  currentNum[50] = 0;
  currentNum[10] = 0;
  currentNum[5] = 0;
  currentNum[1] = 0;
  for(int i = 1; i <= N; i++ ) {
    currentNum[1]++;
    if(currentNum[1] == 5) {
      currentNum[1] = 0;
      currentNum[5]++;
    }
    if(currentNum[5] == 2) {
      currentNum[10]++;
      currentNum[5] = 0;
    }
    if(currentNum[10] == 5) {
      currentNum[50]++;
      currentNum[10] = 0;
    }
    if(currentNum[50] == 2) {
      currentNum[100]++;
      currentNum[50] = 0;
    }
    if(currentNum[100] == 5) {
      currentNum[500]++;
      currentNum[100] = 0;
    }
    if(currentNum[500] == 2) {
      currentNum[1000]++;
      currentNum[500] = 0;
    }
    string cstring = "";
    for(int j = 0; j < currentNum[1000]; j++ ) {
      cstring += "M";
    }
    if(currentNum[500] == 1 && currentNum[100] == 4) {
      cstring += "CM";
    } else if(currentNum[500] == 0 && currentNum[100] == 4) {
      cstring += "CD";
    } else {
      for(int j = 0; j < currentNum[500]; j++ ) {
        cstring += "D";
      }
      for(int j = 0; j < currentNum[100]; j++ ) {
        cstring += "C";
      }
    }
    if(currentNum[50] == 1 && currentNum[10] == 4) {
      cstring += "XC";
    } else if(currentNum[50] == 0 && currentNum[10] == 4) {
      cstring += "XL";
    } else {
      for(int j = 0; j < currentNum[50]; j++ ) {
        cstring += "L";
      }
      for(int j = 0; j < currentNum[10]; j++ ) {
        cstring += "X";
      }
    }
    if(currentNum[5] == 1 && currentNum[1] == 4) {
      cstring += "IX";
    } else if(currentNum[5] == 0 && currentNum[1] == 4) {
      cstring += "IV";
    } else {
      for(int j = 0; j < currentNum[5]; j++ ) {
        cstring += "V";
      }
      for(int j = 0; j < currentNum[1]; j++ ) {
        cstring += "I";
      }
    }
    romans[i] = cstring;
    cout << i << " " << cstring << endl;
  }
  map<char, int> freqCount;
  freqCount['I'] = freqCount['V'] = freqCount['X'] = freqCount['C'] = freqCount['L'] = freqCount['D'] = freqCount['M'] = 0;
  for(int i = 1; i <= N; i++ ) {
    for(int j = 0; j < romans[i].length(); j++ ) {
      freqCount[romans[i][j]]++;
    }
  }
  ofstream outfile("preface.out");
  if(freqCount['I'] > 0) outfile << "I " << freqCount['I'] << endl;
  if(freqCount['V'] > 0) outfile << "V " << freqCount['V'] << endl;
  if(freqCount['X'] > 0) outfile << "X " << freqCount['X'] << endl;
  if(freqCount['L'] > 0) outfile << "L " << freqCount['L'] << endl;
  if(freqCount['C'] > 0) outfile << "C " << freqCount['C'] << endl;
  if(freqCount['D'] > 0) outfile << "D " << freqCount['D'] << endl;
  if(freqCount['M'] > 0) outfile << "M " << freqCount['M'] << endl;
  return 0;
}
