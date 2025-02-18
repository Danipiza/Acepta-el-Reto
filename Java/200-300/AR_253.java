import java.util.*;
import java.io.*;

public class AR_253 {
    
    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first  =first;
            this.second =second;
        }
    }

    static int bfs(int N, int K, Map<Integer, Integer> serpientes, Map<Integer, Integer> escaleras) {
        boolean[] visited=new boolean[N*N+1];
        Queue<Pair> Q=new LinkedList<>();

        Q.offer(new Pair(1, 0));
        visited[1]=true;
        int v, d, tmp;
        
        while (!Q.isEmpty()) {
            Pair current=Q.poll();
            v=current.first;
            d=current.second+1;
            
            for (int i=1;i<=K;i++) {
                tmp=v+i;
                if      (escaleras.containsKey(tmp))  tmp=escaleras.get(tmp);
                else if (serpientes.containsKey(tmp)) tmp=serpientes.get(tmp);
                
                if (tmp==N*N) return d;
                if (!visited[tmp]) {
                    visited[tmp]=true;
                    Q.offer(new Pair(tmp, d));
                }
            }
        }
        return 0;
    }

    static boolean resuelveCaso(BufferedReader br, BufferedWriter bw) throws IOException {
        String[] input=br.readLine().split(" ");

        int N =Integer.parseInt(input[0]);
        int K =Integer.parseInt(input[1]);
        int S =Integer.parseInt(input[2]);
        int E =Integer.parseInt(input[3]);
        
        if (N==0 && K==0 && S==0 && E==0) return false;

        Map<Integer, Integer> serpientes =new HashMap<>();
        Map<Integer, Integer> escaleras  =new HashMap<>();

        for (int i=0;i<S;i++) {
            input=br.readLine().split(" ");

            serpientes.put(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
        }

        for (int i=0;i<E;i++) {
            input=br.readLine().split(" ");

            escaleras.put(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
        }

        bw.write(String.valueOf(bfs(N, K, serpientes, escaleras)));
        bw.newLine();
        bw.flush();

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        
        while (resuelveCaso(br, bw));
        
        br.close();
        bw.close();
    }
}