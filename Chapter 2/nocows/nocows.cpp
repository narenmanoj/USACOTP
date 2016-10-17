/*
TASK: nocows
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll mt[200][100];

ll solve(ll N, ll K) {
  if(K < 0 || N < 0) return 0;
  if(mt[N][K] != -1) {
    return mt[N][K];
  }
  if(K == 0) {
    if(N == 0) {
      mt[0][0] = 1;
      return 1;
    } else {
      mt[N][K] = 0;
      return 0;
    }
  }
  if(K == 1) {
    if(N == 1) {
      mt[N][K] = 1;
      return 1;
    } else {
      mt[N][K] = 0;
      return 0;
    }
  }
  if(K == 2) {
    if(N == 3) {
      mt[N][K] = 1;
      return 1;
    } else {
      mt[N][K] = 0;
      return 0;
    }
  }
  if(N == 0) {
    return (K == 0);
  }
  if(N == 1) {
    return (K == 1);
  }
  if(N == 2) {
    return 0;
  }
  ll nodesToArrange = N - 1;
  ll heightToAttain = K - 1;
  ll ans = 0;
  for(ll i = 1; i < nodesToArrange; i++ ) {
    ll nodesInLeft = i;
    ll nodesInRight = nodesToArrange - nodesInLeft;
    ll leftIsMax = solve(nodesInLeft, heightToAttain);
    ll rightIsMax = solve(nodesInRight, heightToAttain);
    if(leftIsMax) {
      ll a = 0;
      for(ll j = 0; j <= heightToAttain; j++ ) {
        a += solve(nodesInRight, j);
      }
      a *= leftIsMax;
      ans += a;
    }
    if(rightIsMax) {
      ll a = 0;
      for(ll j = 0; j <= heightToAttain; j++ ) {
        a += solve(nodesInLeft, j);
      }
      a *= rightIsMax;
      ans += a;
    }
    if(leftIsMax && rightIsMax) {
      ans -= leftIsMax * rightIsMax;
    }
  }
  mt[N][K] = ans % 9901;
  return mt[N][K]; 
}

int main() {
  ifstream infile("nocows.in");
  ll N, K;
  infile >> N >> K;
  for(ll i = 0; i < 200; i++ ) {
    for(ll j = 0; j < 100; j++ ) {
      mt[i][j] = -1;
    }
  }
  cout << solve(N, K) << endl;
  ofstream outfile("nocows.out");
  outfile << solve(N, K) << endl;
  outfile.close();
  return 0;
}
