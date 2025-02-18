import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class AR_361 {
    
    public static void operaciones(
        // DESCRIPCCION
        List<Integer> v, int num,
        // SOL PARCIAL
        int numP,
        // MARCAJE
        int k,
        // SOLUCION    
        boolean[] fin) {
        
        // CASO BASE
        if (k>=5) {
            if (numP==num) fin[0]=true;
            return;
        }

        // CASOS RECURSIVOS
        // SUMA
        if (!fin[0]) {
            operaciones(v, num, numP+v.get(k), k+1, fin);
        }

        // RESTA
        if (!fin[0]) {
            operaciones(v, num, numP-v.get(k), k+1, fin);
        }

        // MULTIPLICACION
        if (!fin[0]) {
            operaciones(v, num, numP*v.get(k), k+1, fin);
        }

        // DIVISION
        if (v.get(k)!=0 && !fin[0] && numP%v.get(k)==0) {
            operaciones(v, num, numP/v.get(k), k+1, fin);
        }
    }

    public static boolean resuelveCaso(BufferedReader br, BufferedWriter bw) throws IOException {
        String line=br.readLine();
        if (line==null || line.isEmpty()) return false;
        
        int n=Integer.parseInt(line.trim());

        List<Integer> v=new ArrayList<>(5);
        String[] numbers=br.readLine().trim().split("\\s+");
        for (int i=0; i<5; i++) {
            v.add(Integer.parseInt(numbers[i]));
        }

        boolean[] fin={ false };
        operaciones(v, n, v.get(0), 1, fin);

        if (!fin[0]) bw.write("NO\n");
        else bw.write("SI\n");

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
             
        while (resuelveCaso(br, bw));
        bw.flush();         
    }
}