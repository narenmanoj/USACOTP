/*
TASK: castle
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <pthread.h>

#define DEBUG(__args__) printf(__args__);

using namespace std;

int hasNorth(int test) {
  return (test >> 1) & 0x01;
}

int hasSouth(int test) {
  return (test >> 3) & 0x01;
}

int hasEast(int test) {
  return (test >> 2) & 0x01;
}

int hasWest(int test) {
  return test & 0x01;
}

void solve(vector< vector<int> > &castle, ofstream &outfile) {
  int N = castle.size();
  int M = castle[0].size();
  vector< vector<int> > floodfill(N, vector<int>(M));
  int roomCount = 1;
  int sizeOfLargestRoom = -1;
  for(int i = 0; i < N; i++ ) {
    for(int j = 0; j < M; j++ ) {
      if(floodfill[i][j] >= 1) continue;
      stack< pair<int, int> > toVisit;
      toVisit.push(make_pair(i, j));
      // int sizeOfRoom = 0;
      while(!toVisit.empty()) {
        pair<int, int> currentPair = toVisit.top();
        toVisit.pop();
        // sizeOfRoom++;
        int i1 = currentPair.first; int j1 = currentPair.second;
        int squareCode = castle[i1][j1];
        floodfill[i1][j1] = roomCount;
        if(!hasNorth(squareCode) || squareCode == 0 ) {
          if(floodfill[i1 - 1][j1] == 0) toVisit.push(make_pair(i1 - 1, j1));
        }
        if(!hasSouth(squareCode) || squareCode == 0 ) {
          if(floodfill[i1 + 1][j1] == 0) toVisit.push(make_pair(i1 + 1, j1));
        }
        if(!hasEast(squareCode) || squareCode == 0 ) {
          if(floodfill[i1][j1 + 1] == 0) toVisit.push(make_pair(i1, j1 + 1));
        }
        if(!hasWest(squareCode) || squareCode == 0 ) {
          if(floodfill[i1][j1 - 1] == 0) toVisit.push(make_pair(i1, j1 - 1));
        }
      }
      // if(sizeOfRoom > sizeOfLargestRoom) sizeOfLargestRoom = sizeOfRoom;
      roomCount++;
    }
  }
  vector<int> freqCount(roomCount + 1);
  for(int i = 0; i < N; i++ ) {
    for(int j = 0; j < M; j++ ) {
      freqCount[floodfill[i][j]]++;
    }
  }
  roomCount--;
  sizeOfLargestRoom = -1;
  for(int i = 1; i <= roomCount; i++ ) {
    if(freqCount[i] > sizeOfLargestRoom) sizeOfLargestRoom = freqCount[i];
  }
  outfile << roomCount << endl << sizeOfLargestRoom << endl;
  for(int i = 0; i < N; i++ ) {
    for(int j = 0; j < M; j++ ) {
      printf("%2d ", floodfill[i][j]);
    }
    printf("\n");
  }
  printf("\n\n\n");
  int maxPotentialSize = -1;
  pair<int, int> ansCoords(-1, -1);
  char direction = 0;
  for(int i = 0; i < N; i++ ) {
    for(int j = 0; j < M; j++ ) {
      if(j < M - 1 && floodfill[i][j] != floodfill[i][j + 1]) {
        int currentPotentialSize = freqCount[floodfill[i][j]] + freqCount[floodfill[i][j + 1]];
        if(currentPotentialSize >= maxPotentialSize) {
          if(currentPotentialSize == maxPotentialSize) {
            if(j + 1 < ansCoords.second) {
              ansCoords = make_pair(i + 1, j + 1);
              direction = 'E';
            }
            else if(j + 1 == ansCoords.second) {
              if(i + 1 > ansCoords.first) {
                ansCoords = make_pair(i + 1, j + 1);
                direction = 'E';
              }
            }
          }
          else {
            maxPotentialSize = currentPotentialSize;
            ansCoords = make_pair(i + 1, j + 1);
            direction = 'E';
          }
        }
      }
      if(i < N - 1 && floodfill[i][j] != floodfill[i + 1][j]) {
        int currentPotentialSize = freqCount[floodfill[i][j]] + freqCount[floodfill[i + 1][j]];
        if(currentPotentialSize >= maxPotentialSize) {
          if(currentPotentialSize == maxPotentialSize) {
            if(j + 1 < ansCoords.second) {
              ansCoords = make_pair(i + 2, j + 1);
              direction = 'N';
            }
            else if(j + 1 == ansCoords.second) {
              if(i + 2 > ansCoords.first) {
                ansCoords = make_pair(i + 2, j + 1);
                direction = 'N';
              }
            }
          }
          else {
            maxPotentialSize = currentPotentialSize;
            ansCoords = make_pair(i + 2, j + 1);
            direction = 'N';
          }
        }
      }
    }
  }
  outfile << maxPotentialSize << endl;
  outfile << ansCoords.first << " " << ansCoords.second << " " << direction << endl;
}

int main() {
  ifstream infile("castle.in");
  ofstream outfile("castle.out");

  // read input and set up the vars
  int M, N;
  infile >> M >> N;
  vector< vector<int> > castle(N, vector<int>(M));
  for(int i = 0; i < N; i++ ) {
    for(int j = 0; j < M; j++ ) {
      infile >> castle[i][j];
    }
  }
  // done reading input
  solve(castle, outfile);
  outfile.close();
  return 0;
}
