import java.util.Scanner;

public class AR_167 {
    private static final int LADOS_CUADRADO=4;

    private static int fractales(int longitud, int numeroCuadrados) {
        int ret;
        
        if (longitud==1) ret=LADOS_CUADRADO*numeroCuadrados;
        else {
            ret=fractales(longitud/2, LADOS_CUADRADO*numeroCuadrados) + 
                numeroCuadrados*LADOS_CUADRADO*longitud;
        }
        
        return ret;
    }

    private static boolean solve(Scanner scanner) {
        if (!scanner.hasNextInt()) return false;
        
        int longitud=scanner.nextInt();

        if (longitud==0) System.out.println("0");
        else {
            int sumaLongitud=fractales(longitud, 1);
            System.out.println(sumaLongitud);
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while (solve(scanner));

        scanner.close();
    }
}