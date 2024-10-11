import java.util.Scanner;

public class Solution {
	static int trolls(int fuerza, int n) {
		// CASO BASE
		if (fuerza*2>=n) return 0;

		// CASO RECURSIVO
		int auxI=n/3;
		int auxD=n-auxI;
		
		if (auxD>=fuerza*2) {
			if (auxI>=fuerza*2) return trolls(fuerza, auxI)+ 
									   trolls(fuerza, auxD)+ 1;
			else return trolls(fuerza, auxD)+ 1;
		}
		else return 1;
	}

	static boolean solve(Scanner scanner) {
		int fuerza=scanner.nextInt();
		int n=scanner.nextInt();
		
		if (fuerza==0) return false;

		int r=trolls(fuerza, n);

		System.out.println(r);

		return true;
	}

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		while (solve(scanner));
		
		scanner.close();
	}
}