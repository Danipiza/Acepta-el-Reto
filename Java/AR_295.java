import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class AR_295 {
    private static final int K=31543;

    private static long eleva(long x, int n) {
        
        if (n == 0) return 1;
        else {
            long var = eleva(x, n/2);

            if (n%2==0) return (var*var)%K;
            else        return ((x%K)*var*var)%K;
        }
    }

    private static boolean resuelveCaso(BufferedReader br) throws IOException {
        String line=br.readLine();
        if (line==null) return false;
        
        String[] parts=line.split(" ");
        long x =Long.parseLong(parts[0]);
        int n  =Integer.parseInt(parts[1]);
        
        if (x==0 && n==0) return false;
        
        System.out.println(eleva(x, n));
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        while (resuelveCaso(br));

        br.close();
    }
}