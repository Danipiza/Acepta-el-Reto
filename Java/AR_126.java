import java.util.Scanner;

public class Solution {
	public static boolean divisores_fact(int p, int n) {
		boolean ret=false;

		if ((p==1 || p<=n) && p>=0 && n>=0) ret=true;
		else ret=false;

		return ret;
	}

	public static boolean resuelveCaso(Scanner scanner) {
		long p, n;
		if (!scanner.hasNextLong()) return false;
		p=scanner.nextLong();
		n=scanner.nextLong();
		if (p<=0 && n<=0) return false;
		
		if (divisores_fact((int)p, (int)n)) System.out.println("YES"); 
		else System.out.println("NO");

		return true;
	}

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		while (resuelveCaso(scanner));
		
		scanner.close();
	}
}