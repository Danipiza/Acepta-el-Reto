import java.util.ArrayList;
import java.util.Scanner;

public class AR_354 {
    public static int sum(ArrayList<Integer> v) {
        int ret=0;
        
        for (int val: v) {
            ret+=val;
        }
        
        return ret;
    }

    public static boolean solve(Scanner sc) {
        int n=sc.nextInt();
        if (n==0) return false;

        int x=sc.nextInt();
        int maxGlobal=x, maxNinos=x;
        int ninos=1;

        for (int i=1;i<n;i++) {
            x=sc.nextInt();

            if (x>maxGlobal) maxGlobal=x;
            if (x<=maxNinos) {
                ninos=i+1;
                maxNinos=maxGlobal;
            }
        }

        System.out.println(ninos);
        return true;
    }

    // Buffered reader/writer da error RUN_TIME ERROR
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        while (solve(sc));

        sc.close();
    }
}
