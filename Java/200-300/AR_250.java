import java.util.Scanner;

public class AR_250 {
    

    private static int cambioCerradura(int[] v, int n, int t) {
        int k=0;    // empezamos a recorrer desde 0
        int i=v[0]; // en izq cargamos el primer valor del vector
        int d=t-i;  // en derecha cargamos el valor de la suma de todos los siguientes
        
        int dif=Math.abs(d)-Math.abs(i);
        int min=t;
        int pos=0;

        while (k<(n-1)) {
            d  =t-i;
            dif=Math.abs(d)-Math.abs(i);
            
            if (Math.abs(dif)<Math.abs(min) && Math.abs(dif)!=Math.abs(t)) {
                pos=k+1;
                min=Math.abs(dif);
            }

            k++;
            i+=v[k];
        }
        return pos;
    }


    // en este problema usar buffered reader/write da "memory limit"
    private static boolean solve(Scanner scanner) {
        int n=scanner.nextInt();
        if (n==0) return false;
        
        int t=0;
        int[] v=new int[n];
        for (int i=0;i<n;i++) {
            v[i]=scanner.nextInt();
            t+=v[i];
        }

        System.out.println(cambioCerradura(v, n, t));
        
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while (solve(scanner));

        scanner.close();
    }
}