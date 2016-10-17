/*
TASK: money
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

ifstream infile("money.in");
ofstream outfile("money.out");

vector<ll> coins;

vector< vector<ll> > answers;

ll solve(vector<ll> &coins, ll N, ll V) {
  // you can either use this existing coin and not use it again, use it with the option to reuse, or not use at all
  if(N < 0 || V < 0) {
    return 0;
  }
  if(N == 0 || V == 0) {
    return 1;
  }
  if(V == 1) {
    if(N % coins[0] == 0) {
      answers[N][V - 1] = 1;
      return 1;
    } else {
      answers[N][V - 1] = 0;
      return 0;
    }
  }
  if(answers[N][V - 1] != -1) {
    return answers[N][V - 1];
  }
  ll ans = solve(coins, N - coins[V - 1], V) + solve(coins, N, V - 1);
  answers[N][V - 1] = ans;
  return ans;
}

ll sum(vector<ll> &v) {
  ll x = 0;
  for(ll i = 0; i < v.size(); i++ ) {
    x += v[i];
  }
  return x;
}

int main() {
  ll V, N;
  infile >> V >> N;
  coins.resize(V);
  answers.resize(N + 1);
  for(ll i = 0; i <= N; i++ ) {
    answers[i].resize(V + 1, -1);
  }
  ll y = 0;
  for(ll i = 0; i < V; i++ ) {
    infile >> coins[i];
    y += coins[i];
  }
  ll x = solve(coins, N, V);
  cout << x << endl;
  for(ll i = 0; i <= N; i++ ) {
    // cout << "ways to make " << i << ": " << answers[i][V - 1] << endl;
    cout << i << " ";
    for(ll j = 0; j < V; j++ ) {
      cout << answers[i][j] << " ";
    }
    cout << endl;
  }
  outfile << x << endl;
  // outfile << solve(coins, N, V) << endl;
  outfile.close();
  return 0;
}
