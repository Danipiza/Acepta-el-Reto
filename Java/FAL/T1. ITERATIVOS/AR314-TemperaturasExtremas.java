import java.util.Scanner;

public class P314 {

	static Scanner sc;	
	
	static protected class pair{
		int first, second;
		
		pair(int first, int second){
			this.first=first;
			this.second=second;
		}
	}
		
	// Enunciado: El enunciado nos pide calcular cuantos picos y valles hay en
	//  unos datos de la AEMET. 
	// Se considera pico (resp. valle) en una secuencia cuando la anterior y la 
	//  siguiente en la secuencia son estrictamente menores (resp. mayores). 
	// Nos dan un entero "N", el numero de datos, y en la siguiente linea 
	//  aparecen los "N" puntos en la grafica.
	
	// Explicacion: Es un problema iterativo puesto que hay que recorrer todos los 
	//  datos comprobando es un pico o un valle.
	// Inserto los datos en un vector de enteros para comprobarlos.
	//  pero tambien se puede ir comprobando conforme se lee con cin >> con 3
	//  variables locales.
	// Si datos[i-1] y datos[i+1]   son menores que datos[i] es un pico
	//                              son mayores que datos[i] es un valle.
	
	// Complejidad: 
	// - Espacial: O(n) hay n datos que se almacenan en un vector de enteros.
	// - Temporal: O(n) se recorre todo el vector comprobando condiciones.
	
	// Precondicion: Cuando se puede ejecutar la funcion
	// Pre = { 0 <= boletos.size() <= 10.000 && v[i] >= -50 && v[i] <= 60 }
	static private pair picos_valles(int datos[]) { // variables de entrada/salida
	    int i = 1, n = datos.length; // iteradores
	    int picos = 0, valles = 0;
	    // Funcion cota: n-i (decrece hasta llegar a 0)
	    // INV: 1 ≤ k < n-1 ∧ 
	    //      picos = (# k : 1 ≤ k < i : datos[k-1] < datos[k] && datos[k] > datos[k+1]).
	    //      valles = (# k : 1 ≤ k < i : datos[k-1] > datos[k] && datos[k] < datos[k+1]).
	    // picos y valles contiene el numero de picos y valles que se han procesado 
	    // hasta el momento. Se cumple antes durante y al final del bucle.
	    while (i < n - 1) {
	        if (datos[i - 1] < datos[i] && datos[i] > datos[i + 1]) picos++;
	        else if (datos[i - 1] > datos[i] && datos[i] < datos[i + 1]) valles++;
	        ++i;
	    }    
	    return new pair(picos,valles);
	}
	// Postcondicion: Lo que devuelve el algoritmo
	// picos =  (# k : 1 ≤ k < boletos.size() : datos[k-1] < datos[k] && datos[k] > datos[k+1]).
	// valles = (# k : 1 ≤ k < boletos.size() : datos[k-1] > datos[k] && datos[k] < datos[k+1]).
	
	static private void resuelveCaso() {
	    int N;
	    N=sc.nextInt();
	    int datos[] = new int[N];
	    for (int i = 0; i < N; ++i) {
	    	datos[i]=sc.nextInt();
	    }
	    pair ret = picos_valles(datos);
	    System.out.println(ret.first + " " + ret.second);
	}
	/*
	N [0,10.000]
	datos[i] [-50,60]
	Entrada:
	4
	
	5
	7 5 3 8 9
	
	8
	8 9 7 6 5 3 4 2
	
	2
	3 -5
	
	8
	4 -1 5 3 7 7 6 8
	
	Salida:
	0 1
	2 1
	0 0
	1 3
	*/
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int nCasos = sc.nextInt();
		for(int i=0;i<nCasos;i++) resuelveCaso();
	}
	
}
