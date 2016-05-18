/*
TASK: ariprog
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool wayToSort(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return (lhs.second < rhs.second);
  };

string solve(int N, int M) {
  string ans = "";
  unordered_set<int> possibleElementsSet;
  vector<int> possibleElementsVector;
  for(int p = 0; p <= M; p++ ) {
    for(int q = 0; q <= p; q++ ) {
      possibleElementsSet.insert(p * p + q * q);
      // possibleElementsVector.push_back(p * p + q * q);
    }
  }
  for(int x : possibleElementsSet) {
    possibleElementsVector.push_back(x);
  }
  sort(possibleElementsVector.begin(), possibleElementsVector.end());
  vector< pair<int, int> > answers;
  int upperLimit = possibleElementsVector[possibleElementsVector.size() - 1];
  for(int i = 0; i < possibleElementsVector.size(); i++ ) {
    int start = possibleElementsVector[i];
    // int end = possibleElementsVector[i];
    int j = 0;
    for(int k = i + 1; k < possibleElementsVector.size(); k++ ) {
      if((possibleElementsVector[k] - start) % (N - 1) == 0) {
        j = (possibleElementsVector[k] - start) / (N - 1);
        for(int l = 1; l < N; l++ ) {
          if(possibleElementsSet.find(start + l * j) == possibleElementsSet.end()) break;
          if(l == N - 1) {
            answers.push_back(make_pair(start, j));
          }
        }
      }
    }
  }
  if(answers.size() == 0) return "NONE";
  sort(answers.begin(), answers.end(), wayToSort);
  for(int i = 0; i < answers.size(); i++ ) {
    ans += (to_string(answers[i].first) + " " + to_string(answers[i].second));
    if(i != answers.size() - 1) {
      ans += "\n";
    }
  }
  return ans;
}

int main() {
  ifstream infile("ariprog.in");
  ofstream outfile("ariprog.out");
  int N, M;
  infile >> N >> M;
  string ans = solve(N, M);
  outfile << ans << endl;
  outfile.close();
  return 0;
}
