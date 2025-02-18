import java.util.Scanner;

public class Solution {
	private static final int DAYS = 6;
	

	static class Result {
		int mejor_dia;
		int peor_dia;
		String domingo;

		Result(int mejor_dia, int peor_dia, String domingo) {
			this.mejor_dia =mejor_dia;
			this.peor_dia  =peor_dia;
			this.domingo   =domingo;
		}
	}

	static Result bar_javier(double[] v) {
		double suma_total  =v[0];
		double maxima_caja =v[0], minima_caja=v[0];
		
		int mejor_dia=0, peor_dia=0;
		double caja_diaria;
		
		for (int i=1;i<5;i++) {
			caja_diaria =v[i];
			suma_total +=caja_diaria;
			
			if (maxima_caja<caja_diaria) {
				maxima_caja=caja_diaria;
				mejor_dia=i;
			}
			else if (minima_caja>caja_diaria) {
				minima_caja=caja_diaria;
				peor_dia=i;
			}
		}
		
		double caja_domingo=v[5];
		suma_total+=caja_domingo;
		if (maxima_caja<caja_domingo) {
			maxima_caja =caja_domingo;
			mejor_dia   =5;
		}
		else if (minima_caja>caja_domingo) {
			minima_caja =caja_domingo;
			peor_dia 	=5;
		}
		
		String domingo=(suma_total/6.0<caja_domingo ? "SI":"NO");
		
		return new Result(mejor_dia, peor_dia, domingo);
	}

	static boolean resuelveCaso(Scanner scanner) {
		double caja_diaria=scanner.nextDouble();
		if (caja_diaria==-1) return false;
		
		double[] v=new double[DAYS];
		v[0]=caja_diaria;
		for (int i=1;i<DAYS;i++) v[i]=scanner.nextDouble();
		
		Result result=bar_javier(v);
		
		String[] DIAS={"MARTES", "MIERCOLES", "JUEVES", 
					   "VIERNES", "SABADO", "DOMINGO"};		
		System.out.printf("%s %s %s%n", 
			DIAS[result.mejor_dia], DIAS[result.peor_dia], result.domingo);

		return true;
	}

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		while (resuelveCaso(scanner));
	}
}