import java.util.Scanner;

public class AR_346 {
    
    // Pre: true
    static int dedos(int[] v, int A) {
        int maximo =0;
        int a      =0;
        int b      =1;
        int aux    =1;
       
        while (b<v.length) {
            if (v[b]<=v[a]+A-1) {
                aux++;
                b++;
            }
            else {
                a++;
                maximo=Math.max(maximo, aux);
                aux--;
            }
        }

        maximo=Math.max(maximo, aux);

        return maximo;
    }
    // Pos: r = Sum k: 0 <= k < v.size(): v[k]

    static boolean solve(Scanner sc) {
        
        int N=sc.nextInt();
        int A=sc.nextInt();
        if (N==0 && A==0) return false;

        int[] v=new int[N];
        for (int i=0;i<N;i++) v[i]=sc.nextInt();

        // compute solution
        int r=dedos(v, A);

        // write solution
        System.out.println(r);

        return true;
    }

    // usar buffered reader/writer da memory limit exceeded
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while (solve(sc));

        sc.close();
    }
}