import java.io.*;
import java.util.*;

public class AR_444 {
    
    // Pre: true
    public static int serpientes(int[] v, int k) {
        int maximo = 0;
        int a = 0, b = 1;
        int kAux = k;

        if (v[a] == 1) maximo = 1;

        if (v.length > 1) {
            while (b < v.length - 1) {
                if (v[a] == 0) {
                    a++;
                    if (a == b) {
                        kAux = k;
                        if (v[a] == 1) maximo = Math.max(maximo, 1);
                        b++;
                    }
                } else if (v[b] == 1) {
                    maximo = Math.max(maximo, (b - a + 1));
                    b++;
                    kAux = k;
                } else if (v[b] == 0 && kAux > 0) {
                    b++;
                    kAux--;
                } else {
                    a++;
                    maximo = Math.max(maximo, 1);
                    if (a == b) b++;
                }
                if (v[a] == 1 && v[b] == 1) maximo = Math.max(maximo, (b - a + 1));
            }
            if (v[b] == 1) maximo = Math.max(maximo, 1);
            if (v[a] == 1 && v[b] == 1) maximo = Math.max(maximo, (b - a + 1));
        }
        return maximo;
    }

    // Pos: r = Sum k: 0 <= k < v.size(): v[k]
    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        
        if (n == 0) return false;
        
        int[] v = new int[n];
        st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(st.nextToken());
        }
        
        int r = serpientes(v, k);
        bw.write(r + "\n");
        bw.flush();
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (solve(reader, bw));
        br.close();
        bw.close();
    }
}
