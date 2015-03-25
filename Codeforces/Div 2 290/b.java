import java.util.*;

public class b {
    
    public static int[][] adjacencyMatrix;
    public static int[][] tempAdjacencyMatrix;
    public static int rows, cols;
    public static boolean visited1[], visited2[];
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        rows = s.nextInt();
        cols = s.nextInt();
        s.nextLine();
        adjacencyMatrix = new int[rows*cols][rows*cols];
        tempAdjacencyMatrix = new int[rows*cols][rows*cols];
        visited1 = new boolean[rows*cols];
        visited2 = new boolean[rows*cols];
        for(int i = 0; i < rows*cols; i++ ) {
            visited1[i] = false;
            visited2[i] = false;
        }
        for(int i = 0; i < rows*cols; i++ ) {
            for(int j = 0; j < rows*cols; j++ ) {
                adjacencyMatrix[i][j] = 0;
                tempAdjacencyMatrix[i][j] = 0;
            }
        }
        char[][] board = new char[rows][cols];
        // positive is upwards and to the right, negative is everything else
        for(int i = 0; i < rows; i++ ) {
            String r = s.nextLine();
            for(int j = 0; j < cols; j++ ) {
                board[i][j] = r.charAt(j);
                if(i < rows - 1 && board[i+1][j] == board[i][j]) {
                    // item at (i+1)*cols+j is the same as item at i*cols+j
                    adjacencyMatrix[(i+1)*cols+j][i*cols+j] = (int)board[i][j];
                    adjacencyMatrix[i*cols+j][(i+1)*cols+j] = (int)board[i][j];
                }
                if(i > 0 && board[i][j] == board[i-1][j]) {
                    // item at (i-1)*cols+j is the same as item at i*cols+j
                    adjacencyMatrix[(i-1)*cols+j][i*cols+j] = (int)board[i][j];
                    adjacencyMatrix[i*cols+j][(i-1)*cols+j] = (int)board[i][j];
                }
                if(j > 0 && board[i][j] == board[i][j-1]) {
                    // item at i*cols+j is the same as item at i*cols+j-1
                    adjacencyMatrix[i*cols+j][i*cols+j-1] = (int)board[i][j];
                    adjacencyMatrix[i*cols+j-1][i*cols+j] = (int)board[i][j];
                }
                if(j < cols - 1 && board[i][j+1] == board[i][j]) {
                    // item at i*cols+j+1 is the same as item at i*cols+j
                    adjacencyMatrix[i*cols+j+1][i*cols+j] = (int)board[i][j];
                    adjacencyMatrix[i*cols+j][i*cols+j+1] = (int)board[i][j];
                }
            }
        }
        for(int i = 0; i < rows*cols; i++ ) {
            for(int j = 0; j < rows*cols; j++ ) {
                tempAdjacencyMatrix[i][j] = adjacencyMatrix[i][j];
                System.out.printf("%2d ", adjacencyMatrix[i][j]);
            } System.out.println();
        }
        System.out.println(leavesExist());
        System.out.println(isLeaf(5));
        System.out.println(isLeaf(6));
        // now we must determine if our graph is cyclic or not
        // find leaves and delete
        // printResult();
    }
    
    public static boolean leavesExist() {
        for(int i = 0; i < rows*cols; i++ ) {
            if(isLeaf(i)) return true;
        } return false;
    }
    
    public static boolean isLeaf(int n) {
        int numMaps = 0;
        for(int i = 0; i < rows*cols; i++ ) {
            if(tempAdjacencyMatrix[n][i] != 0) numMaps++;
            if(numMaps > 1) return false;
        }
        System.out.println(numMaps);
        return true;
    }

    public static void printResult() {
        if(!leavesExist()) {
            for(int i = 0; i < rows*cols; i++ ) {
                for(int j = 0; j < rows*cols; j++ ) {
                    if(tempAdjacencyMatrix[i][j]!=0) {
                        System.out.println("Yes");
                        return;
                    }
                }
            }
            System.out.println("No");
        }
        else {
            for(int i = 0; i < rows*cols; i++ ) {
                if(isLeaf(i)) {
                    for(int j = 0; j < rows*cols; j++ ) {
                        tempAdjacencyMatrix[i][j] = 0;
                        // tempAdjacencyMatrix[j][i] = 0;
                    }
                }
            }
            printResult();
        }
    }
}