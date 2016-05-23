#include <iostream>
#include <fstream>
#include <vector>

#define UPPER_LIMIT 100000001

// #define UPPER_LIMIT 100

using namespace std;

vector<int> prime(UPPER_LIMIT, 1);
vector<int> superPrimes;

int reverse(int x) {
  int ans = 0;
  while(x > 0) {
    ans *= 10;
    ans += (x % 10);
    x /= 10;

  }
  return ans;
}

int isPal(int x) {
  return (reverse(x) == x);
}

int isSuperPrime(int x) {
  while(x > 0) {
    if(!prime[x]) return 0;
    x /= 10;
    if(x == 1) return 0;
  }
  return 1;
}


int main() {
  for(int i = 2; i < UPPER_LIMIT; i++ ) {
    if(prime[i]) {
      for(int j = i * 2; j < UPPER_LIMIT; j += i ) {
        prime[j] = 0;
      }
    }
  }
  for(int i = 2; i < UPPER_LIMIT; i++ ) {
    if(prime[i]) {
      if(isSuperPrime(i)) {
        superPrimes.push_back(i);
      }
    }
  }
  cout << "void fill_set() {" << endl;
  for(int i = 0; i < superPrimes.size(); i++ ) {
    cout << "  superPrime.push_back(" << superPrimes[i] << ");" << endl;
  }
  cout << "}" << endl;
  return 0;
}
