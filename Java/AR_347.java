import java.io.*;

public class AR_347 {
    static int pajaritas(int x, int y) {   
        // CASO BASE
        if (x<10 || y<10) return 0;
        
        // CASO RECURSIVO
        int minimo=0;
        int divAux=0;
        if (x > y) {
            minimo=y;
            divAux=x/y;

            return pajaritas(x-minimo*divAux, y)+divAux;
        }
        else if (x<y) {
            minimo=x;
            divAux=y/x;

            return pajaritas(x, y-minimo*divAux)+divAux;
        }
        else { // x == y SE HACE EL PAJARITO GRANDE
            return 1;
        }
    }

    static int pajaritasLineal(int x, int y) {
        int ret=0;
        
        int divAux;
        while (x>=10 && y>=10) {        
            divAux=0;

            if (x>y) {            
                divAux=x/y;
                ret +=divAux;
                x   -=y*divAux;            
            }
            else if (x<y) {            
                divAux=y/x;

                ret +=divAux;
                y   -=x*divAux;
            }
            else { // x == y SE HACE EL PAJARITO GRANDE
                ret+=1;
                
                x=0;
            }
        }    
        
        return ret;
    }

    static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        
        String[] input=br.readLine().split(" ");

        int x=Integer.parseInt(input[0]);
        int y=Integer.parseInt(input[1]);
        if (x==0 && y==0) return false;       
        
        int r=pajaritasLineal(x, y);

        bw.write(String.valueOf(r));
        bw.newLine();

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        while (solve(br, bw));
        bw.flush();
    }
}
