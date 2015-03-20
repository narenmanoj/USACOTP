/*
PROG: gift1
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class gift1 {
	public static void main(String[] args) throws FileNotFoundException,IOException {
		Scanner s = new Scanner(new File("gift1.in"));
		int np = s.nextInt();
		System.out.println(np);
		String[] nameList = new String[np];
		int[] moneys = new int[np];
		s.nextLine();
		for(int i = 0; i < np; i++ ) {
			nameList[i] = s.nextLine();
		}
		int m;
		int n;
		String na;
		int index = -1;
		String giver;
		int giverIndex;
		while(s.hasNext()) {
			giver = s.nextLine();
			giverIndex = -1;
			do {
				giverIndex++;
			} while(!giver.equals(nameList[giverIndex]));
			m = s.nextInt();
			n = s.nextInt();
			s.nextLine();
			moneys[giverIndex] += m;
			for(int i = 0; i < n; i++ ) {
				na = s.nextLine();
				do {
					index++;
				} while(!na.equals(nameList[index]));
				moneys[index] += m/n;
				moneys[giverIndex] -= m/n;
				index = -1;
			}
		}
		PrintWriter p = new PrintWriter(new File("gift1.out"));
		for(int i = 0; i < np; i++ ) {
			p.println(nameList[i] + " " + moneys[i]);
		} p.close();
	}
}