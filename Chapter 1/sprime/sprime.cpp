/*
TASK: sprime
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> superPrime;

void fill_set() {
  superPrime.push_back(2);
  superPrime.push_back(3);
  superPrime.push_back(5);
  superPrime.push_back(7);
  superPrime.push_back(23);
  superPrime.push_back(29);
  superPrime.push_back(31);
  superPrime.push_back(37);
  superPrime.push_back(53);
  superPrime.push_back(59);
  superPrime.push_back(71);
  superPrime.push_back(73);
  superPrime.push_back(79);
  superPrime.push_back(233);
  superPrime.push_back(239);
  superPrime.push_back(293);
  superPrime.push_back(311);
  superPrime.push_back(313);
  superPrime.push_back(317);
  superPrime.push_back(373);
  superPrime.push_back(379);
  superPrime.push_back(593);
  superPrime.push_back(599);
  superPrime.push_back(719);
  superPrime.push_back(733);
  superPrime.push_back(739);
  superPrime.push_back(797);
  superPrime.push_back(2333);
  superPrime.push_back(2339);
  superPrime.push_back(2393);
  superPrime.push_back(2399);
  superPrime.push_back(2939);
  superPrime.push_back(3119);
  superPrime.push_back(3137);
  superPrime.push_back(3733);
  superPrime.push_back(3739);
  superPrime.push_back(3793);
  superPrime.push_back(3797);
  superPrime.push_back(5939);
  superPrime.push_back(7193);
  superPrime.push_back(7331);
  superPrime.push_back(7333);
  superPrime.push_back(7393);
  superPrime.push_back(23333);
  superPrime.push_back(23339);
  superPrime.push_back(23399);
  superPrime.push_back(23993);
  superPrime.push_back(29399);
  superPrime.push_back(31193);
  superPrime.push_back(31379);
  superPrime.push_back(37337);
  superPrime.push_back(37339);
  superPrime.push_back(37397);
  superPrime.push_back(59393);
  superPrime.push_back(59399);
  superPrime.push_back(71933);
  superPrime.push_back(73331);
  superPrime.push_back(73939);
  superPrime.push_back(233993);
  superPrime.push_back(239933);
  superPrime.push_back(293999);
  superPrime.push_back(373379);
  superPrime.push_back(373393);
  superPrime.push_back(593933);
  superPrime.push_back(593993);
  superPrime.push_back(719333);
  superPrime.push_back(739391);
  superPrime.push_back(739393);
  superPrime.push_back(739397);
  superPrime.push_back(739399);
  superPrime.push_back(2339933);
  superPrime.push_back(2399333);
  superPrime.push_back(2939999);
  superPrime.push_back(3733799);
  superPrime.push_back(5939333);
  superPrime.push_back(7393913);
  superPrime.push_back(7393931);
  superPrime.push_back(7393933);
  superPrime.push_back(23399339);
  superPrime.push_back(29399999);
  superPrime.push_back(37337999);
  superPrime.push_back(59393339);
  superPrime.push_back(73939133);
}


int main() {
  ofstream outfile("sprime.out");
  FILE* myFile = fopen("sprime.in", "r");
  int N;
  fscanf(myFile, "%d", &N);

  fill_set();

  int higher = 1;
  for(int i = 0; i < N; i++ ) {
    higher *= 10;
  }
  int write = 0;
  int l = higher / 10;
  int h = higher;
  cout << l << endl << h << endl;
  for(int i = 0; i < superPrime.size(); i++ ) {
    if(superPrime[i] >= l && !write) {
      write = 1;
    }
    if(superPrime[i] > h) {
      write = 0;
    }
    if(write) {
      outfile << superPrime[i] << endl;
    }
  }
  outfile.close();
  return 0;
}
