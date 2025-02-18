import java.util.*;

public class AR_319 {
    private static final int MOD=10000;


    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first=first;
            this.second=second;
        }
    }

    private static int bfs(int ini, int fin) {
        if (ini==fin) return 0;

        Queue<Pair<Integer, Integer>> Q=new LinkedList<>();
        Q.offer(new Pair<>(ini, 0));
        
        int v, d, tmp;
        boolean[] visited=new boolean[MOD];
        
        while (!Q.isEmpty()) {
            Pair<Integer, Integer> front = Q.poll();
            v=front.first;
            d=front.second+1;
            
            // SUM
            tmp=(v+1)%MOD;
            if (!visited[tmp]) {
                if (tmp==fin) return d;
                else { 
                    visited[tmp]=true; 
                    Q.offer(new Pair<>(tmp, d)); 
                }
            }
            
            // MUL
            tmp=(v*2)%MOD;
            if (!visited[tmp]) {
                if (tmp==fin) return d;
                else { 
                    visited[tmp]=true; 
                    Q.offer(new Pair<>(tmp, d)); 
                }
            }
            
            // DIV
            tmp=(v/3)%MOD;
            if (!visited[tmp]) {
                if (tmp==fin) return d;
                else { 
                    visited[tmp]=true; 
                    Q.offer(new Pair<>(tmp, d)); 
                }
            }
        }
        
        return 0;
    }

    private static boolean resuelveCaso(Scanner sc) {
        if (!sc.hasNextInt()) return false;
        
        int ini=sc.nextInt();
        int fin=sc.nextInt();
        
        System.out.println(bfs(ini, fin));
        
        return true;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while (resuelveCaso(sc));

        sc.close();
    }    
}