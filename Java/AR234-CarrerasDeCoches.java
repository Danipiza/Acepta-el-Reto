import java.util.Arrays;
import java.util.Scanner;

public class P234 {

	static Scanner sc;

	// Enunciado: 
	// Nos dan primero un entero "nCasos" con el numero de casos
	// Caso especifico:
	// La primera linea tiene 2 enteros "N" numero de baterias y "V" 
	//  voltaje minimo para que funcione un coche
	// La segunda linea tiene "N" enteros con los voltajes de las baterias
	//  disponibles.
	// Nos piden calcular mayor numero de coches que se pueden poner
	//  en funcionamiento. Para que un coche funcione tiene que tener 2 baterias
	//  y la suma debe de ser >= V.


	/* 
	N [1, 100.000]
	voltajes de las baterias = [0, 1.000.000]
	Entrada:
	6

	1 1
	10

	2 2
	0 2

	4 1
	1 1 1 1

	4 20
	1 2 18 19

	4 20
	1 2 19 18

	4 20
	1 4 18 18

	Salida:
	0
	1
	2
	2
	2
	1
	*/

	// Explicacion:
	// Solo tenemos que calcular cuales son las posibles parejas que sumen mas que V.
	// Para ello implementamos un algoritmo voraz. Preprocesamos el vector de baterias
	//  ordenandolo de manera creciente, con coste O(nlogn) como puede ser el algoritmo QuickSort.
	// Una vez ordenado utilizamos las baterias no procesadas de los extremos, si suman mas que V
	//  se juntan las baterias y marcamos como usadas (X[i]=j y X[j]=i).
	// Si no suman mas que V utilizamos la bateria siguiente a la mas peque�a. Asi hasta que i>=j
	// ya habran sido procesadas todas las baterias.

	// Complejidad Espacial: O(n+4) = O(n) almacenamos las n baterias y 4 variables enteras.
	// Complejidad Temporal: O(n) en el caso peor mira todas las tareas.
	static int voraz(int V, int baterias[]) {
	    int ret = 0;
	    // Punteros para el procesado del algoritmo
	    int i = 0, j = baterias.length - 1;
	    //vi usados(baterias.size(),-1); se marcan inicialmente como no usados
	    while (i<j) {
	        // Suma de las baterias de los extremos no procesados suma mas que V
	        if (baterias[i] + baterias[j] >= V) {
	            ret++; // incrementa la salida
	            i++; j--; // reducie los punteros
	            //usados[i] = j;
	            //usados[j] = i;
	        }
	        else i++; // No suma por lo que la bateria i-esima se descarta
	    }
	    
	    return ret;
	}
	// Demostracion de optimalidad:
	// Por reduccion de diferencias.
	// X vector calculado con el algortimo voraz
	// Y vector optimo
	// Recorremos los vectores, hasta que el valor de X[i]!=Y[i]
	// X[i]==-1 && Y[i]!=-1, imposible, el algoritmo voraz hubiera encontrado la pareja de X[i]
	// X[i]!=-1 && Y[i]==-1, imposible sino Y no seria optima.
	// X[i]!=-1 && Y[i]!=-1, si son iguales continua si no
	// Se cambia el valor de Y[i] con el de X[i], y sigue siendo optimo.
	// Sigue siendo solucion y optima.
	// Procedemos asi hasta que el vector Y sea igual al X. Por lo que si es optimo.

	static void resuelveCaso() {
	    int N, V; // N numero de baterias, V voltaje para que un coche funcione
	    N = sc.nextInt();
	    V = sc.nextInt();
	    //List<Integer> baterias = new ArrayList<Integer>();
	    int baterias[] = new int[N];
	    int v;
	    for (int i = 0; i < N; i++) {
	        v=sc.nextInt();
	        baterias[i] = v;
	    }
	    // Ordenar de manera creciente 
	    // Coste O(nlogn)
	    Arrays.sort(baterias);

	    System.out.print(voraz(V, baterias) +"\n");	    
	}
	
	public static void main(String[] args) {		
	    int nCase;	    
	    sc= new Scanner(System.in);
	    nCase = sc.nextInt();
	    for (int i = 0; i < nCase; i++) resuelveCaso();
	}
	
}