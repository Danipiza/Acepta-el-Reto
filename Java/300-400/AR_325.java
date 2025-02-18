import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class AR_325 {
    public static void cucurucho(
        String prefix, 
        int C, int V, 
        // SOLUCION PARCIAL
        int kC, int kV, 
        // SOLUCION
        List<String> ret) {

        if (kC==C && kV==V) {
            ret.add(prefix);
            return;
        }

        if (kC<C) cucurucho(prefix+"C", C, V, kC+1, kV, ret);
        if (kV<V) cucurucho(prefix+"V", C, V, kC, kV+1, ret);
    }

    public static void resuelveCaso(BufferedReader br, BufferedWriter bw) throws IOException {
        String[] input=br.readLine().split(" ");
        
        int C=Integer.parseInt(input[0]);
        int V=Integer.parseInt(input[1]);

        List<String> ret=new ArrayList<>();
        cucurucho("", C, V, 0, 0, ret);

        for (int i=0;i<ret.size();i++) {
            bw.write(ret.get(i));
            if (i<ret.size()-1) bw.write(" ");
        }
        bw.newLine();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        int n=Integer.parseInt(br.readLine());
        for (int i=0;i<n;i++) resuelveCaso(br, bw);
        
        bw.flush(); 
        br.close();
        bw.close();
    }
}
