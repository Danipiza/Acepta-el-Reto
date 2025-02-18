import java.util.Scanner;

public class AR_194 {
    

    // Enunciado: 

    // Explicacion: 

    // Complejidad:
    // - Preprocesaod: O(nlogn) ordenar por un algoritmo de divide y venceras como
    //  puede ser QuickSort
    // - Temporal: O(n), recorre el vector de n elementos
    // - Espacial: O(2n+4) = O(n) vector de n pares.
    static int voraz(String carretera) {
        int ret=0;
        int i=0, n=carretera.length();
        char cA[]=carretera.toCharArray();

        while (i<n) {
            if (cA[i]=='.') {
                ret++;
                i+=2;
            }

            i++;
        }
        return ret;
    }

    static void resuelveCaso(Scanner scanner) {
        String carretera=scanner.next();
        System.out.println(voraz(carretera));
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int nCase=scanner.nextInt();

        for (int i=0;i<nCase;i++) resuelveCaso(scanner);

        scanner.close();
    }
}