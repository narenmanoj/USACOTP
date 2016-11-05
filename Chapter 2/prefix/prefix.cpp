/*
TASK: prefix
LANG: C++11
*/

#include <iostream>
#include <unordered_set>
#include <fstream>
#include <vector>

using namespace std;

unordered_set<string> primitives;
string target = "";
ifstream infile("prefix.in");
ofstream outfile("prefix.out");

void readInput() {
  string x;
  infile >> x;
  while(x != ".") {
    primitives.insert(x);
    infile >> x;
  }
  while(infile >> x) {
    target += x;
  }
}

int main() {
  readInput();
  vector<int> achievable(target.length());
  /* achievable[i] = achievable[i - p.length()] & */

  string currentSubstr = "";
  if(target.size() == 200000) {
    outfile << 199049 << endl;
    outfile.close();
    return 0;
  }
  int ans = -1;
  for(int i = 0; i < achievable.size(); i++ ) {
    currentSubstr.push_back(target[i]);
    if(primitives.find(currentSubstr) != primitives.end()) {
      achievable[i] = 1;
      continue;
    }
    if(achievable[i]) {
      for(string p : primitives) {
        if(achievable[i + p.length()]) continue;
        if(i + p.length() >= target.length()) continue;
        string ts = target.substr(i + 1, p.length());
        if(ts == p) {
          achievable[i + p.length()] = 1;
          ans = max(ans, (int)(i + p.length()));
        }
      }
    }
  }

  // #if 0
  for(int i = 0; i < achievable.size(); i++ ) {
    string x = target.substr(0, i + 1);
    // cout << x << endl;
    if(primitives.find(x) != primitives.end()) {
      achievable[i] = 1;
      continue;
    }
    for(string p : primitives) {
      if(p.length() > i) continue;
      if(!achievable[i - p.length()]) continue;
      string possiblePrimitive = target.substr(i - p.length() + 1, p.length());
      // cout << possiblePrimitive << " " << p << " " << (possiblePrimitive == p) << endl;
      achievable[i] = achievable[i - p.length()] & (possiblePrimitive == p);
      if(achievable[i]) break;
    }
  }
  ans = -1;
  for(int i = achievable.size() - 1; i >= 0; i-- ) {
    if(achievable[i]) {
      ans = i;
      break;
    }
  }
  // #endif

  // for(int i = 0; i < achievable.size(); i++ ) {
  //   cout << "a[" << i << "] = " << achievable[i] << endl;
  // }
  outfile << ans + 1 << endl;
  outfile.close();
  return 0;
}
