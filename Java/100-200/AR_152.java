import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class AR_152 {
    static Scanner scanner=new Scanner(System.in);

    public static boolean solve() {
        int n=scanner.nextInt();
        if (n==0) return false;

        int moda   =0;
        int nombre =0;
        
        int value, count;
        Map<Integer, Integer> m=new HashMap<>();
        for (int i=0;i<n;i++) {
            value=scanner.nextInt();
            count=1; 
            if(m.containsKey(value)) count=m.get(value)+1;
            
            m.put(value, count);
            if (count>moda) {
                nombre=value;
                moda  =count;
            }
        }

        System.out.println(nombre);
        return true;
    }

    public static void main(String[] args) {
        while (solve());
        
        scanner.close();
    }
}