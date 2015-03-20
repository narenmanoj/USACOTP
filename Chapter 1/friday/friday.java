/*
PROG: friday
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class friday {
	public static void main(String[] args) throws FileNotFoundException,IOException {
		Scanner s = new Scanner(new File("friday.in"));
		int[] dayCounts = new int[6];
		// 0 is Saturday, 6 is Friday
		int n = s.nextInt();
		for(int i = 0; i < n; i++ ) {
			dayCounts[(13+1)%7]++; // Jan
			int j = 0;
			if((1900+i)%4 == 0) { // leap year
				if((1900+i)%400!=0 && (1900+i)%100==0) {}
				else {
					j = 1;
				}
			}
			dayCounts[(13+31+1)%7]++; // Feb
			dayCounts[(13+31+1+28+j)%7]++; // March
		}
		PrintWriter p = new PrintWriter(new File("friday.out"));
		for(int i = 0; i < np; i++ ) {
			p.println(dayCounts[i]);
		} p.close();
	}
}