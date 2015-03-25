/*
PROG: gift1
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class gift1 {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner s = new Scanner(new File("gift1.in"));
        
        int np = s.nextInt();
        s.nextLine();
        String[] namesList = new String[np];
        int[] givenList = new int[np];
        int[] receivedList = new int[np];
        for(int i = 0; i < np; i++ ) {
            namesList[i] = s.nextLine();
            givenList[i] = 0;
            receivedList[i] = 0;
        }
        int giverIndex;
        String giverName;
        int moneyToGive;
        int numPeopleToGive;
        int receiverIndex;
        String receiverName;
        while(s.hasNext()) {
            giverName = s.nextLine();
            giverIndex = indexOf(giverName, namesList);
            moneyToGive = s.nextInt();
            System.out.println(moneyToGive);
            numPeopleToGive = s.nextInt();
            System.out.println(numPeopleToGive);
            s.nextLine();
            if(numPeopleToGive == 0) givenList[giverIndex] += 0;
            else givenList[giverIndex] += (moneyToGive - moneyToGive%numPeopleToGive);
            for(int i = 0; i < numPeopleToGive; i++ ) {
                receiverName = s.nextLine();
                receiverIndex = indexOf(receiverName, namesList);
                receivedList[receiverIndex] += moneyToGive/numPeopleToGive;
            }
        }
        PrintWriter p = new PrintWriter(new File("gift1.out"));
        for(int i = 0; i < np; i++ ) {
            p.println(namesList[i] + " " + (receivedList[i] - givenList[i]));
        }
        p.close();
    }
    
    public static int indexOf(String n, String[] arr) {
        int index = -1;
        do {
            index++;
        } while(!arr[index].equals(n));
        return index;
    }
}