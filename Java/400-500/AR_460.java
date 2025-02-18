import java.io.*;

public class AR_460 {
    
    public static String baseDiez(String n) {        
        StringBuilder ret = new StringBuilder();
        
        for (int i = 0; i < n.length(); ++i) {
            ret.append(n.charAt(i));
            if (i != n.length() - 1) {
                ret.append("0");
            }
        }
        return ret.toString();
    }

    public static boolean resuelveCaso(BufferedReader br, BufferedWriter bw) throws IOException {
        String n = br.readLine();
        if (n == null || n.isEmpty()) return false;
        
        bw.write(baseDiez(n) + "\n");
        bw.flush();
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        while (resuelveCaso(reader, bw));

        br.close();
        bw.close();
    }
}
