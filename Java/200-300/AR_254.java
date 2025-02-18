import java.util.Arrays;
import java.util.Scanner;

public class AR_254 {
    
    // Enunciado: 

    // Explicacion: 

    // Complejidad:
    // - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
    //  puede ser QuickSort
    // - Temporal: O(n), recorre el vector de n elementos
    // - Espacial: O(2n+4) = O(n) vector de n pares.
    static int voraz(int[] esquiadores, int[] esquis) {
        int ret=0;

        for(int i=0;i<esquis.length;i++) {
            ret+=Math.abs(esquiadores[i]-esquis[i]);
        }
        
        return ret;
    }
    // Demostracion por reduccion de diferencias. TODO

    static boolean resuelveCaso(Scanner scanner) {
        int N=scanner.nextInt();
        if (N==0) return false;

        int[] esquiadores =new int[N];
        int[] esquis      =new int[N];

        for(int i=0;i<N;i++) esquiadores[i] =scanner.nextInt();
        for(int i=0;i<N;i++) esquis[i]      =scanner.nextInt();

        Arrays.sort(esquiadores);
        Arrays.sort(esquis);

        System.out.println(voraz(esquiadores, esquis));

        return true;
    }
    /*
    TODO
    Entrada:


    Salida:

    */

    // Usando buffered reader/writer da memory limit exceeded.
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while (resuelveCaso(scanner));

        scanner.close();
    }
}