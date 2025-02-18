import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class AR_219 {
    
    // Enunciado: El enunciado nos pide calcular cuantos boletos pares se pueden
    //  comprar de una serie de boletos. 
    // Nos dan un entero "N", el numero de boletos, y en la siguiente linea 
    //  aparecen los "N" numeros de cada boleto.
    // Nos piden calcular el numero de boletos que pueden comprar, con la restriccion
    //  del problema (cuantos pares hay).

    // Explicacion: Es un problema iterativo puesto que hay que recorrer todos los 
    //  boletos comprobando si cada uno cumple con la restriccion de ser par.
    // Inserto los boletos en un vector de enteros para verlo mejor.
    //  pero tambien se puede ir comprobando conforme se lee con cin >>
    // Si el boleto i-esimo cumple con la restriccion se incrementa la variable 
    //  de salida. Si no lo cumple no se hace nada.

    // Complejidad: 
    // - Espacial: O(n) hay n boletos que se almacenan en un vector de enteros.
    // - Temporal: O(n) se recorre todo el vector.
    static int loteria(List<Integer> boletos) {
        int ret=0;
        int i=0, n=boletos.size();

        while (i<n) {
            if (boletos.get(i)%2==0) ret++;
            i++;
        }

        return ret;
    }

    static void resuelveCaso(Scanner scanner) {
        int N=scanner.nextInt();
        List<Integer> boletos=new ArrayList<>();

        for (int i=0;i<N;i++) boletos.add(scanner.nextInt());

        System.out.println(loteria(boletos));
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int numCasos=scanner.nextInt();

        for (int i=0;i<numCasos;i++) resuelveCaso(scanner);

        scanner.close();
    }
}