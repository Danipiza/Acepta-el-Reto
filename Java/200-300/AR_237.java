import java.util.Scanner;

public class AR_237 {
    
    static boolean poliDivisible(long num, int tamano) {
        boolean ret;
        
        if      (tamano==1)     ret=true;
        else if (num%tamano==0) ret=poliDivisible(num/10, tamano-1);
        else                    ret=false;
        
        return ret;
    }

    static boolean solve(Scanner scanner) {
        if (!scanner.hasNextLong()) return false;
        
        long num     =scanner.nextLong();               
        String numero=Long.toString(num);
        
        boolean poli=poliDivisible(num, numero.length());        
        if (poli) System.out.println("POLIDIVISIBLE");
        else      System.out.println("NO POLIDIVISIBLE");
        
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while (solve(scanner));

        scanner.close();
    }
}