import java.util.Scanner;

public class Solution {
	
	public static void resuelveCaso() {
		System.out.println("Hola mundo.");
	}

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		
		int n=scanner.nextInt();
		for (int i=0;i<n;i++) resuelveCaso();
		
		scanner.close();
	}
}