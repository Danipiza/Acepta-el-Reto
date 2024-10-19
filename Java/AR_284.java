import java.util.*;

public class AR_284 {
    static final int MAX_SIZE=8;


    // Enunciado: TODO

    // Explicacion: TODO

    // Complejidad:
    // - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
    //  puede ser QuickSort
    // - Temporal: O(n), recorre el vector de n elementos
    // - Espacial: O(2n+4) = O(n) vector de n pares.
    static void voraz(int cambio, int[] dinero, int[] vuelta) {
        int i=0;

        while (i<MAX_SIZE-1) {
            if (dinero[i]<=cambio) {
                vuelta[i]++;
                cambio-=dinero[i];
            }
            else i++;
        }   

        vuelta[i]=cambio;
    }
    // Demostracion por reduccion de diferencias. TODO

    static void resuelveCaso(Scanner sc) {
        int coste =sc.nextInt();
        int pago  =sc.nextInt();

        int cambio=pago-coste;  
        if (cambio<0) {
            System.out.println("DEBE " + (-cambio));
            return;
        }

        int[] dinero={200, 100, 50, 20, 10, 5, 2, 1};
        int[] vuelta=new int[MAX_SIZE];
        voraz(cambio, dinero, vuelta);

        for (int i=0;i<MAX_SIZE-1;i++) {
            System.out.print(vuelta[i]+" ");
        }
        System.out.println(vuelta[MAX_SIZE-1]);
    }
    /*
    TODO
    Entrada:


    Salida:

    */

    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int nCase  =sc.nextInt();

        for (int i=0;i<nCase;i++) resuelveCaso(sc);

        sc.close();
    }
}