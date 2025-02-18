import java.util.*;

public class Main {
	static final Map<Character, String> mapa = new HashMap<Character, String>() {{
		put('D', "DESAYUNOS");
		put('A', "COMIDAS");
		put('M', "MERIENDAS");
		put('I', "CENAS");
		put('C', "COPAS");
	}};

	static String conversion(char categoria) {
		if	  (categoria=='D') return "DESAYUNOS";
		else if (categoria=='A') return "COMIDAS";
		else if (categoria=='M') return "MERIENDAS";
		else if (categoria=='I') return "CENAS";
		else if (categoria=='C') return "COPAS";
		else return "";
	}

	static String categoria_maximo(Map<Character, Double> ventas) {
		String ret="EMPATE";
		double maximo_valor =-Double.MAX_VALUE;
		int count			=0;

		for (Map.Entry<Character, Double> categoria: ventas.entrySet()) {
			if (maximo_valor<categoria.getValue()) {
				maximo_valor=categoria.getValue();
				ret=conversion(categoria.getKey());
				count=1;
			} 
			else if (categoria.getValue()==maximo_valor) count++;
		}
		
		if (count > 1) ret = "EMPATE";
		return ret;
	}

	static String categoria_minimo(Map<Character, Double> ventas) {
		String ret="EMPATE";
		double minimo_valor =Double.MAX_VALUE;
		int count 			=0;

		for (Map.Entry<Character, Double> categoria: ventas.entrySet()) {
			if (minimo_valor>categoria.getValue()) {
				minimo_valor=categoria.getValue();
				ret=conversion(categoria.getKey());
				count=1;
			} 
			else if (minimo_valor==categoria.getValue()) count++;
		}

		if (count>1) ret="EMPATE";
		return ret;
	}

	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		
		Map<Character, Double> ventas=new HashMap<>();
		ventas.put('D', 0.0); ventas.put('A', 0.0);
		ventas.put('M', 0.0); ventas.put('I', 0.0);
		ventas.put('C', 0.0);

		double total=0;
		int num_ventas_comidas=0, num_ventas_total=0;

		while (scanner.hasNext()) {
			char categoria=scanner.next().charAt(0);
			double valor=scanner.nextDouble();

			if (categoria=='N' && valor==0) {
				String aux="NO";
				if (ventas.get('A')/num_ventas_comidas>(total/num_ventas_total)) aux="SI";

				System.out.println(categoria_maximo(ventas)+"#"+categoria_minimo(ventas)+"#"+aux);
				
				for (char key : ventas.keySet()) ventas.put(key, 0.0);

				total			   =0;
				num_ventas_total   =0;
				num_ventas_comidas =0;
			} 
			else {
				ventas.put(categoria, ventas.get(categoria)+valor);
				if (categoria=='A') num_ventas_comidas++;
				total+=valor;
				num_ventas_total++;
			}
		}
	}
}