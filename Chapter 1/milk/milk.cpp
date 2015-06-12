/*
LANG: C++
TASK: milk
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <algorithm> 

using namespace std;

struct milk {
	int unitPrice;
	int maxAmount;
};

bool wayToSort(milk m1, milk m2) {
	return (m1.unitPrice < m2.unitPrice);
}

int main() {
	ifstream infile("milk.in");
	int N; int M;
	infile >> N >> M;
	vector<milk> inputs(M);
	int temp1; int temp2;
	for (int i = 0; i < M; i++ ) {
		infile >> temp1 >> temp2;
		inputs[i].unitPrice = temp1;
		inputs[i].maxAmount = temp2;
	}
	sort(inputs.begin(), inputs.end(), wayToSort);
	for(int i = 0; i < M; i++ ) {
		cout << inputs[i].unitPrice << " " << inputs[i].maxAmount << endl;
	}
	int milkRemaining = N;
	int totalPrice = 0;
	int j = 0;
	while(milkRemaining > 0) {
		if(milkRemaining >= inputs[j].maxAmount) {
			milkRemaining -= inputs[j].maxAmount;
			totalPrice += (inputs[j].maxAmount * inputs[j].unitPrice);
			j++;
		}
		else {
			totalPrice += (inputs[j].unitPrice * milkRemaining);
			milkRemaining = 0;
		}
	}
	ofstream outfile("milk.out");
	outfile << totalPrice << endl;
	return 0;
}
