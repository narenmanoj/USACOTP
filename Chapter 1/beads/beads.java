/*
PROG: beads
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class beads {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner s = new Scanner(new File("beads.in"));
        int n = s.nextInt();
        s.nextLine();
        String beadsOriginal = s.nextLine();
        // consider the "looping" nature of the beads
        char last = beadsOriginal.charAt(n-1);
        int x = 0;
        while(beadsOriginal.charAt(x) == 'w' || 
                (x > 0 && beadsOriginal.charAt(x) == beadsOriginal.charAt(x-1) && x > 0) || 
                (x < n - 1 && beadsOriginal.charAt(x) == beadsOriginal.charAt(x+1) && x < n - 1)) {
            x++;
        }
        String end = beadsOriginal.substring(0, x);
        String consider = beadsOriginal.concat(end);
        System.out.println(beadsOriginal);
        System.out.println(consider);
        int maxLength = 0;
        for(int i = 1; i < consider.length(); i++ ) {
            if(maxLength < getLength(consider, i)) maxLength = getLength(consider, i);
        }
        PrintWriter p = new PrintWriter(new File("beads.out"));
        p.println(maxLength);
        p.close();
    }
    
    public static int getLength(String s, int p) { // breaking position
        int numForward = 0, numBackward = 0;
        // back: start at p-1
        // fwd: start at p
        int f = p; int b = p;
//        while(s.charAt(b) == s.charAt(p-1) || s.charAt(b) == 'w') {
//            numBackward++;
//            b--;
//            if(b == -1) break;
//        }
        if(s.charAt(p) == 'w') {
            int firstRed = p, firstBlue = p;
            do {
                firstRed++;
            } while(s.charAt(firstRed) != 'r' && firstRed < s.length() - 1);
            do {
                firstBlue++;
            } while(s.charAt(firstBlue) != 'b' && firstBlue < s.length() - 1);
            if(firstRed > firstBlue) {
                // then the whites are technically blues
                numForward = firstBlue - p + 1;
            }
            else numForward = firstRed - p + 1;    
        }
        else {
            while(s.charAt(f) == s.charAt(p) || s.charAt(f) == 'w') {          
                numForward++;
                f++;
                if(f == s.length()) break;
            }
        }
        if(s.charAt(p - 1) == 'w') {
            int firstRed = p - 1, firstBlue = p - 1;
            do {
                firstRed--;
                if(firstRed < 0) break;
            } while(s.charAt(firstRed) != 'r' && firstRed > 0);
            do {
                firstBlue--;
                if(firstBlue < 0) break;
            } while(s.charAt(firstBlue) != 'b' && firstBlue > 0);
            if(firstRed > firstBlue) {
                numBackward = p - 1 - firstRed + 1;
            }
            else numBackward = p - 1 - firstBlue + 1;
        }
        else {
            while(s.charAt(b) == s.charAt(p-1) || s.charAt(b) == 'w') {
                numBackward++;
                b--;
                if(b == -1) break;
            }
        }
        return numBackward + numForward;
    }
}