import java.io.*;

public class AR_272 {
    private static final int BASE_CONVERSION = 6;

    private static void valorDivision(int numBaseDiez, BufferedWriter bw) throws IOException {
        if (numBaseDiez/BASE_CONVERSION==0) {
            bw.write(String.valueOf(numBaseDiez));
        }
        else if (numBaseDiez/BASE_CONVERSION<=5) {
            bw.write(String.valueOf(numBaseDiez/BASE_CONVERSION));
            bw.write(String.valueOf(numBaseDiez%BASE_CONVERSION));
        }
        else {
            valorDivision(numBaseDiez/BASE_CONVERSION, bw);
            bw.write(String.valueOf(numBaseDiez % BASE_CONVERSION));
        }
    }

    private static void solve(BufferedReader br, BufferedWriter bw) throws IOException {
        int numBaseDiez=Integer.parseInt(br.readLine());

        valorDivision(numBaseDiez, bw);
        bw.newLine();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
            
        int numCasos=Integer.parseInt(br.readLine());
        for (int i=0;i<numCasos;i++) solve(br, bw);
            
        bw.flush();        
    }
}