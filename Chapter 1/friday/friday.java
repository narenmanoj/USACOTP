/*
PROG: friday
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class friday {
    public static void main(String[] args) throws FileNotFoundException,IOException {
        Scanner s = new Scanner(new File("friday.in"));
        int[] dayCounts = {0, 0, 0, 0, 0, 0, 0};
        int[] daysIndices = {0, 1, 2, 3, 4, 5, 6}; // 0 is Saturday, 6 is Friday
        int[] mosLength = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // length of months in standard yr
        int[] dayOfThirteen = new int[12];
        int[] dayOfThirteenLeap = new int[12];
        dayOfThirteen[0] = 13;
        dayOfThirteenLeap[0] = 13;
        for(int j = 1; j < 12; j++ ) {
            dayOfThirteen[j] = dayOfThirteen[j-1] + mosLength[j-1];
            if(j == 2) {
                dayOfThirteenLeap[2] = dayOfThirteen[1] + 29;
            } else dayOfThirteenLeap[j] = dayOfThirteenLeap[j-1] + mosLength[j-1];
        }
        int n = s.nextInt();
        int indexFirstDay = 2;
        for(int i = 0; i < n; i++ ) {
            indexFirstDay+=1;
            if(isLeapYear(1899+n)) {
                indexFirstDay+=1;
            }
            if(isLeapYear(1900+n)) {
                for(int j = 0; j < 12; j++ ) {
                    dayCounts[(dayOfThirteenLeap[j] + indexFirstDay+699)%7]++;
                }
            }
            else {
                for(int j = 0; j < 12; j++ ) {
                    dayCounts[(dayOfThirteen[j] + indexFirstDay+699)%7]++;
                }
            }
        }
        PrintWriter p = new PrintWriter(new File("friday.out"));
        for(int i = 0; i < 7; i++ ) {
            p.print(dayCounts[i] + " ");
        } p.println();
        p.close();
    }
    
    public static boolean isLeapYear(int y) {
        if(y%4!=0) return false;
        if(y%100==0 && y%8!=0) return false;
        return true;
    }
} 