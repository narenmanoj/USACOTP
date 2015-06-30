import java.io.*;
import java.util.*;

public class January3 {
	public static void main(String[] args) throws IOException, FileNotFoundException {
		// balanced teams
		Scanner scan = new Scanner(new File("bteams.in"));
		int[] skills = new int[12];
		int totalSkill = 0;
		int averageSkill;
		for(int i = 0; i < 12; i++ ) {
			skills[i] = s.nextInt();
			totalSkill += skills[i];
		}
		if(totalSkill%12 == 0) averageSkill = totalSkill/12;
		else averageSkill = 1 + totalSkill/12;
		PrintWriter p = new PrintWriter(new File("bteams.out"));
		p.close();
	}
}