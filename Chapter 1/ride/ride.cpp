/*
PROG: ride
LANG: C++
*/

#include <stdio.h>
#include <iostream>
#include <ctype.h>

using namespace std;

int hashH(char *s)
{
	int i, h;

	h = 1;
	for (i = 0; s[i] && isalpha(s[i]); i++)
		h = ((s[i] - 'A' + 1)*h) % 47;
	return h;
}

void main(void)
{
	FILE *in, *out;
	char comet[100], group[100];  /* bigger than necessary, room for newline */

	in = fopen("ride.in", "r");
	out = fopen("ride.out", "w");

	fgets(comet, sizeof comet, in);
	fgets(group, sizeof group, in);

	if (hashH(comet) == hashH(group))
		fprintf(out, "GO\n");
	else
		fprintf(out, "STAY\n");
	exit(0);
}