import java.io.*;
import java.util.*;

public class AR_242 {
    
    // Pre: true
    public static long erasmus(int[] v) {
        long ret =0;
        int n    =v.length;
        
        if (n!=1) {
            long sum=v[n-1];
            for (int i=n-2;i>=0;i--) {
                ret+=(long)v[i]*sum;
                sum+=v[i];
            }
        }

        return ret;
    }
    // Pos: r = Sum k: 0 <= k < v.size(): v[k]
    
    public static boolean resuelveCaso(BufferedReader br, BufferedWriter bw) throws IOException {
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        if (n==0) return false;

        int[] v=new int[n];
        st=new StringTokenizer(br.readLine());
        for (int i=0;i<n;i++) v[i]=Integer.parseInt(st.nextToken());

        bw.write(Long.toString(erasmus(v)));
        bw.newLine();

        return true;
    }

    // Usando buffered en vez de scanner se consigue reducir el tiempo de ejecucion
    // considerablemente.
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        

        while (resuelveCaso(br, bw));

        bw.flush();
        bw.close();
        br.close();
    }
}