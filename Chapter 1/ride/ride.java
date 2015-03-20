/*
PROB: ride
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class ride {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		Scanner s = new Scanner(new File("ride.in"));
		String w1 = s.nextLine();
		String w2 = s.nextLine();
		int p1 = 1, p2 = 1;
		for(int i = 0; i < w1.length(); i++ ) {
			p1 *= ((int)w1.charAt(i) - 64);
		}
		for(int i = 0; i < w2.length(); i++ ) {
			p2 *= ((int)w2.charAt(i) - 64);
		}
		System.out.println(p1);
		System.out.println(p2);
		PrintWriter p = new PrintWriter(new File("ride.out"));
		if(p1 % 47 == p2 % 47) {
			p.println("GO");
		} else p.println("STAY");
		p.close();
	}
}