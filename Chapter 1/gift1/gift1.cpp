/*
PROG: gift1
LANG: C++
*/

#include <stdio.h>
#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
	FILE *in, *out;

	in = fopen("gift1.in", "r");
	out = fopen("gift1.out", "w");

	int np = 1;
	fscanf(in, "%d", &np);
	cout << np;
	

	char *namesList [np][80];
	for (int i = 0; i < np; i++) {
		fscanf(in, "%s", namesList[i]);
	}
	for (int i = 0; i < np; i++) {
		for (int j = 0; j < 80; j++) {
			cout << namesList[i][j];
		} cout << "\n";
	}
	

	fclose(in);
	fclose(out);

	return 0;
}