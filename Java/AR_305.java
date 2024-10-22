import java.util.Scanner;
import java.util.Arrays;

public class AR_305 {
    
    static int voraz(int[] inv, int[] def) {
        int ret=0;

        Arrays.sort(inv);
        Arrays.sort(def);
        
        int i=0, j=0, n=inv.length;        
        while (i<n) {
            
            if (inv[j]<=def[i]) {
                ret++;
                i++; j++;
            } else i++;
        }
        return ret;
    }
    
    static boolean resuelveCaso(Scanner sc) {
        if (!sc.hasNextInt()) return false;
        int N=sc.nextInt();
        
        int[] inv=new int[N];
        int[] def=new int[N];
        
        for (int i=0;i<N;i++) inv[i]=sc.nextInt();
        for (int i=0;i<N;i++) def[i]=sc.nextInt();
        
        System.out.println(voraz(inv, def));
        
        return true;
    }
    
    // Usar buffered reader/write da memory limit exceeded
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (resuelveCaso(sc));

        sc.close();
    }
}