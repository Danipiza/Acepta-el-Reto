import java.util.Scanner;

public class AR_140 {
    static Scanner scanner=new Scanner(System.in);

    public static int sumDigitos(int numero) {
        int ret;

        if (numero/10==0) {
            ret=numero%10;
            System.out.print(numero);
        }
        else {
            ret=sumDigitos(numero/10)+(numero%10);
            System.out.print(" + "+(numero%10));
        }
        
        return ret;
    }

    public static boolean solve() {
        if (!scanner.hasNextInt()) return false;
        
        int n=scanner.nextInt();
        if (n<0) return false;

        int suma=sumDigitos(n);
        System.out.println(" = "+suma);

        return true;
    }

    public static void main(String[] args) {
        while (solve());

        scanner.close();
    }
}