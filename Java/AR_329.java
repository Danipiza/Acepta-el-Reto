import java.io.*;
import java.util.*;

public class AR_329 {
    static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first  =first;
            this.second =second;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(this.first, other.first);
        }
    }

    static int voraz(List<Pair> edificios) {
        int ret=1;
        int fin=edificios.get(0).second;

        for (int i=1;i<edificios.size();i++) {
            if (edificios.get(i).first < fin) {
                if (fin>edificios.get(i).second) fin=edificios.get(i).second;
            } else {
                ret++;
                fin=edificios.get(i).second;
            }
        }
        return ret;
    }

    static boolean resuelveCaso(BufferedReader br, BufferedWriter bw) throws IOException {
        int N=Integer.parseInt(br.readLine().trim());
        if (N==0) return false;

        List<Pair> edificios=new ArrayList<>();
        for (int i=0;i<N;i++) {
            String[] parts=br.readLine().trim().split("\\s+");
            int ini=Integer.parseInt(parts[0]);
            int fin=Integer.parseInt(parts[1]);

            edificios.add(new Pair(ini, fin));
        }
        Collections.sort(edificios);

        bw.write(String.valueOf(voraz(edificios)));
        bw.newLine();

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreambr(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreambw(System.out));

        while (resuelveCaso(br, bw));
        bw.flush();        
    }
}