/*
LANG: C++
TASK: palsquare
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

using namespace std;

float logbase(float base, float param) {
	return log(param)/log(base);
}

/* is string s a palindrome? */
int
ispal(char *s)
{
    char *t;

    t = s+strlen(s)-1;
    for(t=s+strlen(s)-1; s<t; s++, t--)
	if(*s != *t)
	    return 0;

    return 1;
}

/* put the base b representation of n into s: 0 is represented by "" */
char*
numbconv(char *s, int n, int b)
{
    int len;

    if(n == 0) {
	strcpy(s, "");
	return s;
    }

    /* figure out first n-1 digits */
    numbconv(s, n/b, b);

    /* add last digit */
    len = strlen(s);
    s[len] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n%b];
    s[len+1] = '\0';
    return s;
}

int main() {
	ifstream infile("palsquare.in");
	int B;
	infile >> B;
	FILE* outfile;
	outfile = fopen("palsquare.out", "w");
	for(int i = 1; i <= 300; i++ ) {
		int isquare = i*i;
		char shr0k[30];
		// itoa(i, shr0k, 10);
		numbconv(shr0k, i, B);
		char meme[100]; // let's convert isquare into some base thing
		numbconv(meme, isquare, B);
		if(ispal(meme)) {
			fprintf(outfile, "%s %s\n", shr0k, meme);
		}
	}
	return 0;
}
