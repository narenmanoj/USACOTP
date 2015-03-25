import java.util.*;

public class b {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int l = scan.nextInt();
		scan.nextLine();
		String s = scan.nextLine();
		String t = scan.nextLine();
		ArrayList<Character> dne = new ArrayList<Character>();
		ArrayList<Character> sh = new ArrayList<Character>();
		ArrayList<Character> th = new ArrayList<Character>();
		ArrayList<Integer> indexList = new ArrayList<Integer>();
		int swap1 = 0, swap2 = 0;
		int subtractor = 1;
		boolean none = true;
		for(int i = 0; i < l; i++ ) {
			char s_1 = s.charAt(i);
			char t_1 = t.charAt(i);
			if(s_1!=t_1) {
				sh.add(s_1);
				th.add(t_1);
				indexList.add(i);
				int x = th.indexOf(s_1);
				if(x!=-1) none = false;
				if(x == -1) {}
				else if(sh.get(x) == t_1) {
					swap1 = indexList.get(x);
					swap2 = i;
					subtractor = 2;
				}
			}
		}
		System.out.println(sh);
		System.out.println(th);
		if(subtractor == 1 && !none) {
			int y = -1;
			int z;
			do {
				y++;
				z = th.indexOf(sh.get(y));
			} while(z == -1);
			swap1 = indexList.get(y);
			swap2 = z;
		}
		if(none) {
			System.out.println(indexList.size());
			System.out.println("-1 -1");
		} else {
			System.out.println(indexList.size()-subtractor);
			System.out.println(swap1 + " " + swap2);
		}
	}
}