/*
TASK: milk3
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct triple {
  int A;
  int B;
  int C;
};

triple make_triple(int A, int B, int C) {
  triple ans;
  ans.A = A;
  ans.B = B;
  ans.C = C;
  return ans;
}

bool operator<(const triple &lhs, const triple &rhs) {
  return (lhs.C < rhs.C);
}

bool operator==(const triple &lhs, const triple &rhs) {
  return (lhs.A == rhs.A && lhs.B == rhs.B && lhs.C == rhs.C);
}

string make_string_from_triple(const triple &v) {
  return to_string(v.A) + " " + to_string(v.B) + " " + to_string(v.C);
}

string solve(int A, int B, int C) {
  queue<triple> myStack;
  set<string> visitedPossibilities;
  vector<int> possibleAnswers;
  set<int> duplicateVerification;
  // visitedPossibilities.insert(make_triple(0, 0, C));
  myStack.push(make_triple(0, 0, C));
  while(!myStack.empty()) {
    triple currentTriple = myStack.front();
    visitedPossibilities.insert(make_string_from_triple(currentTriple));
    int A1 = currentTriple.A; int B1 = currentTriple.B; int C1 = currentTriple.C;
    myStack.pop();
    if(currentTriple.A == 0) {
      if(duplicateVerification.find(currentTriple.C) == duplicateVerification.end()) {
        possibleAnswers.push_back(currentTriple.C);
        duplicateVerification.insert(currentTriple.C);
      }
      cout << "the next one is a possible answer" << endl;
    }
    cout << "currently, we are on: " << endl;
    cout << "A1 = " << A1 << ", B1 = " << B1 << ", C1 = " << C1 << endl;
    // simulate some pours
    triple AtoB;
    AtoB.A = C - C1 - min(A1 + B1, B);
    AtoB.B = min(A1 + B1, B);
    AtoB.C = C1;
    triple BtoA;
    BtoA.A = min(A1 + B1, A);
    BtoA.B = C - C1 - min(A1 + B1, A);
    BtoA.C = C1;

    triple AtoC;
    AtoC.A = C - B1 - min(A1 + C1, C);
    AtoC.B = B1;
    AtoC.C = min(A1 + C1, C);
    triple CtoA;
    CtoA.A = min(A1 + C1, A);
    CtoA.B = B1;
    CtoA.C = C - B1 - min(A1 + C1, A);

    triple BtoC;
    BtoC.A = A1;
    BtoC.B = C - A1 - min(B1 + C1, C);
    BtoC.C = min(B1 + C1, C);
    triple CtoB;
    CtoB.A = A1;
    CtoB.B = min(B1 + C1, B);
    CtoB.C = C - A1 - min(B1 + C1, B);

    int debugPush = 0;

    if(visitedPossibilities.find(make_string_from_triple(AtoB)) == visitedPossibilities.end()) {
      myStack.push(AtoB);
      cout << "pushed A to B" << endl;
      debugPush = 1;
    } if(visitedPossibilities.find(make_string_from_triple(BtoA)) == visitedPossibilities.end()) {
      myStack.push(BtoA);
      debugPush = 1;
    } if(visitedPossibilities.find(make_string_from_triple(AtoC)) == visitedPossibilities.end()) {
      myStack.push(AtoC);
      debugPush = 1;
    } if(visitedPossibilities.find(make_string_from_triple(CtoA)) == visitedPossibilities.end()) {
      myStack.push(CtoA);
      debugPush = 1;
    } if(visitedPossibilities.find(make_string_from_triple(BtoC)) == visitedPossibilities.end()) {
      myStack.push(BtoC);
      debugPush = 1;
    } if(visitedPossibilities.find(make_string_from_triple(CtoB)) == visitedPossibilities.end()) {
      myStack.push(CtoB);
      debugPush = 1;
    }

    if(debugPush) {
      // cout << "something was pushed just now" << endl;
    }
  }
  sort(possibleAnswers.begin(), possibleAnswers.end());
  string ans = "";
  for(int i = 0; i < possibleAnswers.size(); i++ ) {
    ans += to_string(possibleAnswers[i]);
    if(i != possibleAnswers.size() - 1) {
      ans += " ";
    }
  }
  cout << "answer: " << ans << endl;
  return ans;
}

int main() {
  int A, B, C;
  ifstream infile("milk3.in");
  ofstream outfile("milk3.out");
  infile >> A >> B >> C;
  outfile << solve(A, B, C) << endl;
  outfile.close();
  return 0;
}
