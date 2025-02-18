import java.io.*;
import java.util.*;

public class Main {
    
    static int voraz(int num, List<Integer> integrantes) {
        int ret=0;
        int i=num-1, n=integrantes.size();

        while (i < n) {
            if (integrantes.get(i)-integrantes.get(i-num+1)<=15) {
                ret++;
                i+=num-1;
            }
            i++;
        }

        return ret;
    }

    static void resuelveCaso(BufferedReader br, BufferedWriter bw) throws IOException {
        String[] input=br.readLine().split(" ");
        int num=Integer.parseInt(input[0]);
        int N=Integer.parseInt(input[1]);
        
        List<Integer> integrantes=new ArrayList<>();
        input=br.readLine().split(" ");
        for (int i=0;i<N;i++) {
            integrantes.add(Integer.parseInt(input[i]));
        }

        Collections.sort(integrantes);

        bw.write(String.valueOf(voraz(num, integrantes)));
        bw.newLine();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
            
        int nCase=Integer.parseInt(br.readLine());
        for (int i=0;i<nCase;i++) resuelveCaso(br, bw);
        bw.flush();
    }
}
