import java.io.*;
import java.util.*;

public class November1 {
	public static void main(String[] args) throws IOException, FileNotFoundException {
		Scanner s = new Scanner(new File("combo.in"));
		PrintWriter p = new PrintWriter(new File("combo.out"));
		int N = s.nextInt();
		int[] jc = new int[3]; // john's combination
		jc[0] = s.nextInt(); jc[1] = s.nextInt(); jc[2] = s.nextInt();
		int[] mc = new int[3];
		mc[0] = s.nextInt(); mc[1] = s.nextInt(); mc[2] = s.nextInt();
		int intersections = 0;
		int[] m = {1, 1, 1};

		// use a PIE solution. the answer is 250 - #intersections
		// we just need to compute #intersections
		for(int i = 0; i < 3; i++ ) {
			// if they're more than 4 apart
			if(abs(m(mc[i]-jc[i], N))>4) {
				p.println(250);
				p.close();
				return;
			} // intersections is already 0
		}
		// mc + 2 - jc + 2
		for(int i = 0; i < 3; i++ ) {
			int jMax = jc[i]+2;
			jMax%=N;
			int jMin = jc[i]-2;
			jMin%=N;
			while(jMin > jMax) jMax+=N;

			int mMax = mc[i]+2;
			mMax%=N;
			int mMin = mc[i]-2;
			mMin%=N;
			while(mMin > mMax) mMax+=N;

			if(mMax > jMax) m[i] = jMax - mMin + 1;
			else if(jMax > mMax) m[i] = mMax - jMin + 1;
			else m[i] = 5;
		}
		p.println(250-m[0]*m[1]*m[2]);
		p.close();	
	}

	public static int abs(int n) {
		if(n < 0) return -1*n;
		return n;
	}

	public static int m(int x, int N) {
		x%=N;
		if(x > N/2) return x-N;
		return x;
	}
}