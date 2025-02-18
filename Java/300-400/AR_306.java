import java.io.*;

public class AR_306 {
    static final int K = 46337;

    public static void matrixMult(long[][] v1, long[][] v2, long[][] ret) {
        ret[0][0]=(v1[0][0]*v2[0][0]+v1[0][1]*v2[1][0])%K;
        ret[0][1]=(v1[0][0]*v2[0][1]+v1[0][1]*v2[1][1])%K;
        ret[1][0]=(v1[1][0]*v2[0][0]+v1[1][1]*v2[1][0])%K;
        ret[1][1]=(v1[1][0]*v2[0][1]+v1[1][1]*v2[1][1])%K;
    }

    public static void fibonacci(long n, long[][] ret) {
        if (n==2) {
            ret[0][0]=1; ret[0][1]=1;
            ret[1][0]=1; ret[1][1]=2;
        } 
        else if (n==1) {
            ret[0][0]=0; ret[0][1]=1;
            ret[1][0]=1; ret[1][1]=1;
        } 
        else {
            long[][] mitad=new long[2][2];
            fibonacci(n/2, mitad);
            if (n%2==0) matrixMult(mitad, mitad, ret);
            else {
                long[][] unidad ={ {0, 1}, {1, 1} };
                long[][] temp   =new long[2][2];

                matrixMult(mitad, mitad, temp);
                matrixMult(temp, unidad, ret);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        
        String line;
        while ((line=br.readLine()) != null) {
            long n=Long.parseLong(line);
            if (n==0) break;
            
            long[][] ret = new long[2][2];
            fibonacci(n, ret);
            bw.write(ret[0][1] + "\n");
        }
        
        bw.flush();
        bw.close();
        br.close();
    }
}
    