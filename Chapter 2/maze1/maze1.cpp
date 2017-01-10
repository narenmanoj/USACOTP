#if 0
TASK: maze1
LANG: C++11
#endif

#include <bits/stdc++.h>

using namespace std;

ifstream infile("maze1.in");
ofstream outfile("maze1.out");

int W, H;

char maze[203][80];
int d1[203][80];
int d2[203][80];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  string p;
  getline(infile, p);
  stringstream ss(p);
  ss >> W >> H;
  for(int i = 0; i < 2 * H + 1; i++ ) {
    string hi;

    getline(infile, hi);
    // cout << hi << endl;
    for(int j = 0; j < 2 * W + 1; j++ ) {
      maze[i][j] = hi[j];
    }
  }
  // return 0;
  for(int i = 0; i < 2 * H + 1; i++ ) {
    for(int j = 0; j < 2 * W + 1; j++ ) {
      cout << maze[i][j];
    }
    cout << endl;
  }
  pair<int, int> exits[2];
  int c = 0;
  for(int i = 0; i < 2 * H + 1; i++ ) {
    if(c == 2) break;
    if(maze[i][0] == ' ') {
      exits[c] = make_pair(i, 1);
      c++;
    }
    if(maze[i][2 * W] == ' ') {
      exits[c] = make_pair(i, 2 * W - 1);
      c++;
    }
  }
  for(int j = 0; j < 2 * W + 1; j++ ) {
    if(c == 2) break;
    if(maze[0][j] == ' ') {
      exits[c] = make_pair(1, j);
      c++;
    }
    if(maze[2 * H][j] == ' ') {
      exits[c] = make_pair(2 * H - 1, j);
      c++;
    }
  }
  cout << exits[0].first << " " << exits[0].second << endl;
  queue< pair<int, int> > toVisit;
  toVisit.push(exits[0]);
  d1[exits[0].first][exits[0].second] = 1;
  while(!toVisit.empty()) {
    pair<int, int> current = toVisit.front();
    toVisit.pop();
    for(int i = 0; i < 4; i++ ) {
      int testR = current.first + dx[i];
      int testC = current.second + dy[i];
      if(testR < 0 || testR >= 2 * H + 1 || testC < 0 || testC >= 2 * W + 1) continue;
      if(maze[testR][testC] != ' ') continue;
      testR += dx[i];
      testC += dy[i];
      if(testR < 0 || testR >= 2 * H + 1 || testC < 0 || testC >= 2 * W + 1) continue;
      if(d1[testR][testC] != 0) continue;
      toVisit.push(make_pair(testR, testC));
      d1[testR][testC] = d1[current.first][current.second] + 1;
    }
    // cout << "processing" << endl;
  }

  toVisit.push(exits[1]);
  d2[exits[1].first][exits[1].second] = 1;
  while(!toVisit.empty()) {
    pair<int, int> current = toVisit.front();
    toVisit.pop();
    for(int i = 0; i < 4; i++ ) {
      int testR = current.first + dx[i];
      int testC = current.second + dy[i];
      if(testR < 0 || testR >= 2 * H + 1 || testC < 0 || testC >= 2 * W + 1) continue;
      if(maze[testR][testC] != ' ') continue;
      testR += dx[i];
      testC += dy[i];
      if(testR < 0 || testR >= 2 * H + 1 || testC < 0 || testC >= 2 * W + 1) continue;
      if(d2[testR][testC] != 0) continue;
      toVisit.push(make_pair(testR, testC));
      d2[testR][testC] = d2[current.first][current.second] + 1;
    }
  }

  for(int i = 0; i < 2 * H + 1; i++ ) {
    for(int j = 0; j < 2 * W + 1; j++ ) {
      cout << d2[i][j] << " ";
    }
    cout << endl;
  }

  int ans = -1;
  for(int i = 0; i < 203; i++ ) {
    for(int j = 0; j < 80; j++ ) {
      if(d1[i][j] == 0) continue;
      if(d2[i][j] == 0) continue;
      ans = max(ans, min(d1[i][j], d2[i][j]));
    }
  }
  outfile << ans << endl;
  outfile.close();
  return 0;
}
