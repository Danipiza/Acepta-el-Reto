import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Solution {

	public static int conversion(char nivel) {
		int ret=2; // s

		if 		(nivel=='d') ret=6;
		else if (nivel=='p') ret=10;
		else if (nivel=='f') ret=14;

		return ret;
	}

	public static String configuracion_electronica(int electrones) {
		String[] niveles={ "1s", "2s", "2p", "3s", "3p", 
						   "4s", "3d", "4p", "5s", "4d", 
						   "5p", "6s", "4f", "5d", "6p", 
						   "7s", "5f", "6d", "7p" };

		Map<Character, Integer> mapa=new HashMap<>();
		mapa.put('s', 2);  mapa.put('p', 6);
		mapa.put('d', 10); mapa.put('f', 14);

		StringBuilder ret=new StringBuilder();
		int i=0, tmp;
		tmp=mapa.get(niveles[i].charAt(1));

		while (electrones>tmp) {
			electrones-=tmp;
			ret.append(niveles[i]).append(tmp).append(" ");

			i++;
			tmp=mapa.get(niveles[i].charAt(1));
		}
		
		ret.append(niveles[i]).append(electrones);
		return ret.toString();
	}

	public static boolean resuelveCaso() {
		Scanner sc=new Scanner(System.in);
		String elemento=sc.next();
		if (elemento.equals("Exit")) return false;

		int electrones=sc.nextInt();
		String salida =configuracion_electronica(electrones);
		
		System.out.println(salida);
		
		return true;
	}

	public static void main(String[] args) {	
		while (resuelveCaso());
	}
}
