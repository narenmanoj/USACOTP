/*
TASK: numtri
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <inttypes.h>

using namespace std;

int main() {
  uint16_t R;
  ifstream infile("numtri.in");
  ofstream outfile("numtri.out");
  infile >> R;
  vector< vector<uint32_t> > triangle(R, vector<uint32_t>(R));
  for(uint16_t i = 1; i <= R; i++ ) {
    for(uint16_t j = 0; j < i; j++ ) {
      infile >> triangle[i - 1][j];
    }
  }
  for(uint16_t rm = 1; rm <= R; rm++ ) {
    uint16_t r = rm - 1;
    for(uint16_t c = 0; c < rm; c++ ) {
      if(r == c && c == 0) {
      } else if(c == 0) {
        triangle[r][c] += triangle[r - 1][c];
      } else if(c == R - 1) {
        triangle[r][c] += triangle[r - 1][c - 1];
      } else {
        // general case
        triangle[r][c] += max(triangle[r - 1][c], triangle[r - 1][c - 1]);
      }
    }
  }
  uint32_t ans = 0;
  for(uint16_t i = 0; i < R; i++ ) {
    if(triangle[R - 1][i] > ans) {
      ans = triangle[R - 1][i];
    }
  }
  for(uint16_t i = 0; i < R; i++ ) {
    for(uint16_t j = 0; j < R; j++ ) {
      cout << triangle[i][j] << " ";
    } cout << endl;
  }
  outfile << ans << endl;
  outfile.close();
  return 0;
}
