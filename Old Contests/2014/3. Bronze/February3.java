import java.io.*;
import java.util.*;

public class February3 {
	public static void main(String[] args) throws IOException, FileNotFoundException {
		Scanner s = new Scanner(new File("scode.in"));
		String end = s.nextLine();
		PrintWriter p = new PrintWriter(new File("scode.out"));
		p.println(numWays(end));
		p.close();
	}

	public static int numWays(String s) {
		int n = 0;
		int x = s.length();
		if(x <= 1) return 0;
		if(x%2 == 0) return 0;
		int lengthOriginal = (x + 1)/2;
		// two cases: either original is on left or on right

		// CASE 1: ORIGINAL IS ON LEFT
		String org = s.substring(0, lengthOriginal); // length is lengthOriginal
		String mod = s.substring(lengthOriginal); // length is lengthOriginal - 1
		if(org.contains(mod)) { // if there exists such a string
			n += (1 + numWays(org));
		}

		// CASE 2: ORIGINAL IS ON RIGHT
		mod = s.substring(0, lengthOriginal - 1);
		org = s.substring(lengthOriginal - 1);
		if(org.contains(mod)) {
			n += (1 + numWays(org));
		}
		return n;
	}
}