import java.util.*;

public class CoinChange {

	public static int[] C;
	public static int[] coinDenominations;
	public static int n;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter V: ");
		int v = scan.nextInt();
		C = new int[v+1];
		C[0] = 100000;
		for(int i = 1; i < v+1; i++ ) C[i] = -1;
		System.out.println("Enter the number of denominations: ");
		n = scan.nextInt();
		coinDenominations = new int[n];
		System.out.println("Enter the denominations");
		for(int i = 0; i < n; i++ ) {
			coinDenominations[i] = scan.nextInt();
		}
		minCoins(v);
		System.out.println(C[v]);
		for(int i = 0; i <= v; i++) System.out.print(C[i]+ " ");
	}

	public static void minCoins(int V) {
		// integer value V for which we find the min number of coins which will work
		for(int i = 0; i < n; i++ ) {
			if(V == coinDenominations[i]) {
				C[V] = 1; return;
			}
		} // if we get this far, then we must compute max(C[x] + C[V-x] for all x b/w 1 and V-1, inclusive)
		int min = 100000;
		for(int x = 1; x < V; x++ ) {
			if(C[x] == -1) {
				minCoins(x);
			}
			if(C[V-x] == -1) {
				minCoins(x);
			}
			if(min > C[x] + C[V-x]) {
				min = C[x] + C[V-x];
			}
		} C[V] = min;
	}
}