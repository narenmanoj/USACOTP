/*
TASK: concom
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <inttypes.h>

using namespace std;

int N;

vector< set<int> > companiesOwned(101);
vector< vector<int> > ownagePercentages(101, vector<int>(101));
vector< vector<int> > owns(101, vector<int>(101));
ifstream infile("concom.in");
ofstream outfile("concom.out");

void fill(int x) {

}

void solve() {
  for(int i = 1; i <= 100; i++ ) {
    for(int j = 1; j <= 100; j++ ) {
      if(i == j) ownagePercentages[i][j] = 100;
      else if(ownagePercentages[i][j] > 50) {
        for(int k = 100; k >= 0; k-- ) {
          if(j != i) {
            ownagePercentages[i][k] += ownagePercentages[j][k];
          }
        }
      }
    }
  }
  // for(int i = 100; i >= 0; i++ ) {
  //   for(int j = 100; j > 100; j++ ) {
  //     if(i == j) ownagePercentages[i][j] = 100;
  //     else if(ownagePercentages[i][j] > 50) {
  //       for(int k = 100; k >= 0; k-- ) {
  //         if(j != i) {
  //           ownagePercentages[i][k] += ownagePercentages[j][k];
  //         }
  //       }
  //     }
  //   }
  // }
  for(int i = 1; i <= 100; i++ ) {
    for(int j = 1; j <= 100; j++ ) {
      if(ownagePercentages[i][j] > 50) {
        // companiesOwned[i].insert(j);
        owns[i][j] = 1;
      }
    }
  }
}

int main() {
  infile >> N;

  for(int i = 0; i < N; i++ ) {
    int a, b, p; infile >> a >> b >> p; ownagePercentages[a][b] = p;
    // cout << ownagePercentages[a][b] << endl;
  }
  for(int i = 1; i <= 100; i++ ) {
    for(int j = 1; j <= 100; j++ ) {
      if(ownagePercentages[i][j] > 50) {
        // companiesOwned[i].insert(j);
        // cout << "hi" << endl;
        owns[i][j] = 1;
      }
      if(i == j) {
        // companiesOwned[i].insert(j);
        owns[i][j] = 1;
      }
    }
  }
  for(int h = 0; h < 50; h++ ) {
  for(int i = 1; i <= 100; i++ ) {
    for(int j = 1; j <= 100; j++ ) {
      // if(i == j) continue;
      // if(companiesOwned[i].find(j) != companiesOwned[i].end()) continue;
      int x = 0;
      for(int k = 1; k <= 100; k++ ) {
        // if(i == k || k == j) continue;
        // if(companiesOwned[i].find(k) != companiesOwned[i].end()) {
        if(owns[i][k]) {
          x += ownagePercentages[k][j];
        }
        if(x > 50) {
          // companiesOwned[i].insert(j);
          owns[i][j] = 1;
        }
      }
    }
  }}
  // solve();
  for(int i = 1; i <= 100; i++ ) {
    for(int j = 1; j <= 100; j++ ) {
      // if(companiesOwned[i].find(j) != companiesOwned[i].end() && i != j) {
      if(owns[i][j] && i != j) {
        outfile << i << " " << j << endl;
      }    }
  }
  outfile.close();
  return 0;
}
