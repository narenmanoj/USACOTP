/*
TASK: holstein
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAX_INT 2147483647

using namespace std;

vector<int> allPossibleSets;

void zero(vector<int> &victim) {
  for(int i = 0; i < victim.size(); i++ ) victim[i] = 0;
}

int bit(int target, int index, int G) {
  // suppose the integer is 00...index
  vector<int> bits(G);
  for(int i = G - 1; i >= 0; i-- ) {
    bits[i] = target % 2;
    target /= 2;
  }
  return bits[index];
}

int test(vector<int> &requirements, vector< vector<int> > &feeds, int used, int V, int G) {
  vector<int> totalCount(V);
  for(int i = 0; i < G; i++ ) {
    if(bit(used, i, G)) {
      for(int j = 0; j < V; j++ ) {
        totalCount[j] += feeds[i][j];
      }
    }
  }
  for(int i = 0; i < V; i++ ) {
    if(totalCount[i] < requirements[i]) return -1;
  }
  return 1; // this means it worked!
}

pair<int, int> solve(vector<int> &requirements, vector< vector<int> > &feeds, int V, int G) {
  int possibleAns = G + 1;
  // for(possibleAns = 1; possibleAns <= G; possibleAns++ ) {
  //   if(test(requirements, feeds, used, V, G, possibleAns) == 1) {
  //     // this means possibleAns is possible
  //     break;
  //   }
  //   zero(used);
  // }
  int index = -1;
  for(int i = allPossibleSets.size() - 1; i >= 0; i-- ) {
    if(allPossibleSets[i] < possibleAns) {
      if(test(requirements, feeds, i, V, G) == 1) {
        possibleAns = allPossibleSets[i];
        index = i;
        // cout << "new possible answer: " << possibleAns << endl;
        // cout << "binary encoding: " << i << endl;
      }
    }
  }
  return make_pair(possibleAns, index);
}

int numOnes(int test) {
  int ans = 0;
  while(test > 0) {
    ans += (test % 2);
    test = test >> 1;
  }
  return ans;
}

int main() {
  ifstream infile("holstein.in");
  ofstream outfile("holstein.out");

  int V;
  infile >> V;
  vector<int> requirements(V);
  for(int i = 0; i < V; i++ ) {
    infile >> requirements[i];
  }
  int G;
  infile >> G;
  // fill allPossibleSets
  int h = 1 << G;
  cout << "h = " << h << endl;
  for(int i = 0; i < h; i++ ) {
    allPossibleSets.push_back(numOnes(i));
  }
  vector< vector<int> > feeds(G, vector<int>(V));
  for(int i = 0; i < G; i++ ) {
    for(int j = 0; j < V; j++ ) {
      infile >> feeds[i][j];
    }
  }
  pair<int, int> ans = solve(requirements, feeds, V, G);
  outfile << ans.first << " ";
  cout << ans.second << endl;
  vector<int> answers;
  for(int i = 0; i < G; i++ ) {
    if(bit(ans.second, i, G)) {
      answers.push_back(i + 1);
    }
  }
  for(int i = 0; i < answers.size(); i++ ) {
    outfile << answers[i];
    if(i != answers.size() - 1) outfile << " ";
  }
  outfile << endl;
  outfile.close();
  return 0;
}
