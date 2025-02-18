import java.util.Scanner;

public class Solution {
	private static final int INF=Integer.MAX_VALUE;

	static int llenando_piscinas(int pisc_yo, int barr_yo, int viaje_yo, 
								 int pisc_vec, int barr_vec, int viaje_vec,
								 boolean[] empate) {
		// 10 4 1
		// 4 + 3 + 3 = 3 viajes necesita
		// 
		// primer viaje no pierde agua
		int yo=1, vecino=1;
		
		pisc_yo -=barr_yo;
		pisc_vec-=barr_vec;
		
		// en cada viaje se gana el agua que trae, menos lo que pierde la piscina.
		int agua_viaje_yo	 =barr_yo-viaje_yo;
		int agua_viaje_vecino=barr_vec-viaje_vec;

		// si en cada viaje consigue traer algo entra
		if (agua_viaje_yo>0 && pisc_yo>0) {		
			yo+=pisc_yo/agua_viaje_yo;// numero de viajes necesarios
			// se suma 1 si la division no es entera. para llenar 
			//  una piscina de 50L con cubos de 4L se necesitan 12.5 viajes = 13.
			if (pisc_yo%agua_viaje_yo!=0) yo++;		
		}	
		// si no consigue traer agua y la piscina le falta por llenar entonces es imposible
		else if(pisc_yo>0) yo=INF; 
		
		// lo mismo para el vecino
		if (agua_viaje_vecino>0 && pisc_vec>0) {		
			vecino+=pisc_vec/agua_viaje_vecino; 
			if ((pisc_vec%agua_viaje_vecino)!=0) vecino++;		
		}
		else if (pisc_vec>0) vecino=INF;

		if (yo==vecino) empate[0]=true;

		return (yo<=vecino) ? yo:-vecino;
	}

	static boolean resuelveCaso(Scanner scanner) {
		int pisc_yo   =scanner.nextInt();
		int barr_yo   =scanner.nextInt();
		int viaje_yo  =scanner.nextInt();
		int pisc_vec  =scanner.nextInt();
		int barr_vec  =scanner.nextInt();
		int viaje_vec =scanner.nextInt();
		
		if (pisc_yo==0 || pisc_vec==0) return false;
		
		boolean[] empate={false};
		int salida=llenando_piscinas(pisc_yo, barr_yo, viaje_yo, 
									 pisc_vec, barr_vec, viaje_vec,
									 empate);

		if(empate[0]) System.out.println("EMPATE "+salida);
		else if (salida>=0) System.out.println("YO "+salida);
		else System.out.println("VECINO "+(-salida));
		
		return true;
	}

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		while (resuelveCaso(scanner));
		
		scanner.close();
	}
}