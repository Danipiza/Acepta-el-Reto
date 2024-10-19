import java.util.*;

public class AR_282 {

    static int voraz(int L, List<Integer> v) {
        int ret=0;
        int i=1, n=v.size();
        
        int act;
        while (i<n) {
            act=v.get(i-1);
            while (i<n && v.get(i)-act<=L) i++;
            
            ret++;
            i++;
        }

        if (i==n) ret++;

        return ret;
    }

    static boolean resuelveCaso(Scanner sc) {
        if (!sc.hasNextInt()) return false;
        int N=sc.nextInt();
        int L=sc.nextInt();

        List<Integer> v=new ArrayList<>();
        for (int i=0;i<N;i++) v.add(sc.nextInt());

        System.out.println(voraz(L, v));
        return true;
    }

    // Usando Buffered reader/writer da Memory limit exceeded.
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while (resuelveCaso(sc));
        
        sc.close();
    }
}