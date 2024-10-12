import java.util.Scanner;

public class AR_138 {

    
    // los numeros factoriales tiene ceros en los multiplos de 5
    // por lo que 5, 10, 15 y 20 tienen 1, 2, 3 y 4 ceros respectivamente.
    // pero con multiplos de 25 tiene 2 ceros extra 25 -> 6
    // por eso, al numero factorial se suma la potencia de 5 mas cercana redondeada hacia abajo
    // 5^x -> 5^1 = 5, 5^2 = 25, 5^3 = 125, 
    // se suma x por cada division.
    public static int contarCerosFact(int n) {
        int ret=0;
        int x=n/5;
        
        // se suman los multiplos de la potencia de 5 en cada iteracion
        /* EJEMPLO
        n = 50
        en el numero 50 hay 10 multiplos de 5. 50 / 5 = 10
        en el numero 50 hay 2 multiplos de 25. 50 / 25 = 2
        */
        
        while (x>0) {
            ret+=x;
            x/=5;
        }

        return ret;
    }

    public static boolean resuelveCaso(Scanner scanner) {
        int n=scanner.nextInt();

        System.out.println(contarCerosFact(n));

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        for (int i=0;i<N;i++) resuelveCaso(scanner);

        scanner.close();
    }
}