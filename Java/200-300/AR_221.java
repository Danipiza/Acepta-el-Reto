import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class AR_221 {
    
    // Enunciado: El enunciado nos pide comprobar si Ramiro puede abrir la
    //  segunda puerta para que los vecinos no se quejen de la espera.
    // La puerta solo se puede abrir si las personas que van al lado impar
    //  estan todas juntas al final de la fila.
    // Nos dan un entero "N", el numero de personas, y en la siguiente linea 
    //  aparecen los "N" numeros de cada persona, representando la butaca,
    //  para saber que la persona i-esima va a la derecha (par) o izquierda (impar).
    // Nos piden si puede abrir la puerta y cuantas personas se cambian de lado.
    // Si puede abrir la puerta imprime "SI x" (numero de personas que pasan)
    // Si no puede imprime "NO"

    // Explicacion: Es un problema iterativo puesto que hay que recorrer todos las 
    //  personas, comprobando su butaca para saber si es par o impar. 
    // Inserto las personas en un vector de enteros para verlo mejor.
    //  pero tambien se puede ir comprobando conforme se lee con cin >>
    // Recorro el vector, cuando encuentro un impar incremento el numero de impares
    //  y pongo a true (usando un entero) para marcar que ahora vienen los impares,
    // Si aparece un impar se incrementa el numero de retorno, si aparece un par
    //  no se puede abrir la puerta y termina el recorrido imprimiendo "NO".
    // Si llega al final con la variable "puede" a true es porque cumple con la 
    //  restriccion y se puede abrir la puerta.

    // Complejidad: 
    // - Espacial: O(n) hay n boletos que se almacenan en un vector de enteros.
    // - Temporal: O(n) se recorre todo el vector.
    static int puertaExtra(List<Integer> personas) {
        int i=1, n=personas.size(); // iteradores
        if (n==0) return 0; // 0 personas

        
        boolean puede=true; // variable que comprueba que si puede abrir la puerta
        // persona actual, comprueba si es par o impar y lo marca.
        boolean act=(personas.get(0)%2==0);
        // si la primera persona es impar quiere decir que solo pueden 
        // aparecer impares, y pone a 1 la variable de retorno.
        int ret=(personas.get(0)%2!=0)?1:0; // variable de retorno
        boolean tmp;

        while (i<n && puede) { // O(n)
            // par o impar de la persona i-esima
            tmp=(personas.get(i)%2==0);
            // Solo han salido pares 
            if (act && !tmp) { 
                if (!tmp) { // impar
                    ret++; // incrementa el numero de impares
                    // pone a false y apartir de ahora solo pueden salir impares
                    act=false;
                }
                // par no hace nada, pasa al siguiente
            }
            // ya ha salido el primer impar
            else if (!act) {
                // i-esimo par, termina la ejecucion, no cumple con
                //  la restriccion del problema
                if (tmp) puede=false;
                else ret++; // i-esimo impar, incrementa y continua
            }                 

            i++; // pasa al siguiente boleto
        }

        if (!puede) return -1;
        else return ret;
    }

    static void resuelveCaso(Scanner scanner) {
        int N=scanner.nextInt();
        List<Integer> personas=new ArrayList<>();

        for (int i=0;i<N;i++) personas.add(scanner.nextInt());

        int ret=puertaExtra(personas);
        if (ret==-1) System.out.println("NO");
        else System.out.println("SI "+(N-ret));
    }
    /*
    * N [0-10.000]

    Entrada:
    10
    2 4 6 8 10 1 3 5 7 9

    5
    6 2 3 0 1

    5
    1 3 5 7 9

    10
    1 3 5 7 10 1 3 5 7 9

    5
    2 4 6 8 10

    Salida:
    SI 5
    NO
    SI 5
    NO
    SI 0

    */

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);

        int numCasos=scanner.nextInt();
        for (int i=0;i<numCasos;i++) resuelveCaso(scanner);

        scanner.close();
    }
}