import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;


public class P329 {

	static Scanner sc;	
	
	static protected class pair{		
		int first;
		int second;
		
		public pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
	

	// Enunciado: Tenemos "N" edificios, y nos piden calcular
	//  el numero minimo de tuneles necesarios para que todos los 
	//  edicifios esten a primera linea de playa. Para conseguir esto,
	//  tienen que crear los tuneles sabiendo cuanto ocupan los edificios.
	//  Si 2 edificios tienen una parte en comun se puede usar el mismo 
	//  tunel para ambos edificios.
	// El enunciado nos proporciona las dimensiones de los "N" edificios.
	// "N" lineas con (ini,fin) del edificio i-esimo.
	
	// Explicacion: Para resolver el problema implementamos un algoritmo
	//  voraz para calcular el menor numero de tuneles necesarios.
	// Ordenamos los edificios en orden ascendente del comienzo de estos. "ini"
	// Una vez ordenado recorremos el vector de edificios y con el final del 
	//  actual avanzamos en el vector hasta que un edificio empiece mas tarde
	//  que el "fin" actual. Si el edificio entra en el intervalo pero su final
	//  es menor que el actual se actualiza.
	
	// Complejidad:
	// Preprocesado: O(nlogn) ordenado usando un algoritmo de divide y venceras
	//  como puede ser QuickSort
	// - Temporal: O(n), recorre todo el vector de edificios
	// - Espacial: O(2n+4) = O(n), 2n ya que es un vector con n elementos y 
	//  cada elemento tiene 2 valores.
	static private int voraz(pair edificios[]){
	    int ret = 1; // valor de retorno
	    int fin = edificios[0].second; // fin actual (el primero en este caso)
	    int i = 1, n = edificios.length; // iteradores
		/*int tunel[] = new int[n];
		for(int i=0;i<n;i++){ tunel[i]=-1; }
		*/
	    while (i < n) { // O(n)
	        // Si el inicio del siguiente entra en el intervalo
	        //  no se incrementa los tuneles
	        if (edificios[i].first < fin) { // O(1) comparacion
	            // Si el final del edificio i-esimo es menor que el fin actual
	            //  se actualiza
				//tunel[i] = ret;
	            if (fin > edificios[i].second) fin = edificios[i].second;
	        }
	        else {
	            ret++; // incrementa el numero de tuneles
				//tunel[i] = ret;
	            fin = edificios[i].second; // cambia el fin actual
	        }
	        i++;
	    }
	
	    return ret;
	}
	// Demostracion de optimalidad por reduccion de diferencias
	// X es el vector calculado por el algoritmo voraz
	// Y es el vector optimo
	// Recorremos los vectores, comparando los valores, hasta encontrar
	//  una diferencia. 
	// Si no son iguales X(i) != Y(i) es porque se asigna otro tunel 
	//  al edificio i-esimo. Se mueve a la izquierda el valor de Y, actualizando
	//  su valor por el de X. Por definicion del algoritmo voraz se puede hacer
	//  ya que esta en el intervalo de los anteriores. Se sigue recorriendo
	//  los vectores con el mismo proceso.
	// Cuando llega el final, ambos vectores son iguales, por lo que se 
	//  el algoritmo voraz es optimo.
	
	static private boolean resuelveCaso() {
	    int N; // numero de edificios
	    N = sc.nextInt();
	    // no hay mas edificios, se termina el caso
	    if (N == 0) return false; 
	    
	    pair edificios[] = new pair[N]; // vector de parejas de los edificios (ini,fin)
	    int ini, fin;
	    for (int i = 0; i < N; i++) {
	    	ini = sc.nextInt();
	    	fin = sc.nextInt();
	    	edificios[i] = new pair(ini, fin);
	    }
	    // Se ordena el vector en orden ascendente
	 // Sorting the array of pairs by the 'first' variable in ascending order
        Arrays.sort(edificios, new Comparator<pair>() {
            @Override
            public int compare(pair pair1, pair pair2) {
                return Integer.compare(pair1.first, pair2.first);
            }
        });
	    
	    
	    System.out.println(voraz(edificios));
	    return true;
	}
	
	/* N [1-100.000]
	ini y fin [0,1.000.000.000] se puede usar int
	
	Entrada:
	4
	1 4
	6 15
	2 10
	12 20
	
	2
	1 4
	4 8
	
	2
	1 4
	3 8
	
	2
	0 0
	0 0
	
	2
	0 1
	1 1
	
	3
	1000000000 1000000000
	900000000 1000000000
	500000000 1000000000
	
	3
	1000000000 1000000000
	999999999 99999999
	999999998 99999998
	
	0
	
	Salida: 
	2
	2
	1
	2
	2
	2
	3
	*/

	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
	    while(resuelveCaso());
	}
	
}
