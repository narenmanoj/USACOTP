import java.io.*;
import java.util.*;

public class paper {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		long a = s.nextLong();
		long b = s.nextLong();
		System.out.println(getShips(a, b));
	}

	public static long getShips(long l, long w) {
		// // long x = gcd(l, w);
		// // l/=x;
		// // w/=x;
		// if(l%2==0 && w%2==0) {
		// 	l/=2; w/=2;
		// }
		// if(l%3==0 && w%3==0) {
		// 	l/=3; w/=3;
		// }
		// if(l%w == 0) return l/w;
		// if(w%l == 0) return w/l;
		// if(l == 1) return w;
		// if(w == 1) return l;
		// if(l > w) return 1 + getShips(l-w, w);
		// if(l < w) return 1 + getShips(w-l, l);
		// return 1;
		if(w ==0 || l == 0) return 0;
		if(w == 1) return l;
		if(l == 1) return w;
		if(w == l) return 1;
		if(l > w) {
			long x = l/w;
			return x + getShips(l-w*x, w);
		}
		else {
			long x = w;
			w = l;
			l = x;
			return getShips(l, w);
		}
	}

	public static long gcd(long p, long q) {
        if (q == 0) return p;
        else return gcd(q, p % q);
    }
}