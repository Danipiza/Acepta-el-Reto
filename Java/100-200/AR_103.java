import java.util.Scanner;

public class Solution {
	
	
	static double calcula_altura(double x, int[] f) {
		double ret=0;
		
		double exponente=1;
		int n=f.length;

		for (int i=0;i<n;i++) {
			ret+=f[i]*exponente;
			exponente*=x;
		}
		
		return ret;
	}

	static double calcula_area(int area, int[] f) {
		double ret=0.0;
		double base, altura;
		for (int i=0;i<area;i++) {
			base=1.0/(double)area;
			altura=calcula_altura(i*base,f);

			if (altura<0) continue;
			else if (altura>1) altura=1;

			ret+=base*altura;
		}
		
		return ret;
	}

	static boolean resuelveCaso(Scanner scanner) {
		int grado=scanner.nextInt();
		if (grado==20) return false;

		int[] f=new int[grado+1];
		for (int i=0;i<=grado;i++) f[grado-i]=scanner.nextInt();

		int n=scanner.nextInt();
		double area_cain=calcula_area(n, f);

		if (area_cain<0.4999) System.out.println("ABEL");
		else if (area_cain>0.5001) System.out.println("CAIN");
		else System.out.println("JUSTO");

		return true;
	}

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		while (resuelveCaso(scanner));
	}
}