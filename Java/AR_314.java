import java.util.Scanner;
import java.util.ArrayList;

public class AR_314 {
    
    
    public static void picosValles(ArrayList<Integer> datos, 
        int[] result) {

        int n=datos.size();
        int picos=0, valles=0;
        
        for (int i=1;i<n-1;i++) {
            if      (datos.get(i-1)<datos.get(i) && datos.get(i)>datos.get(i+1)) picos++;
            else if (datos.get(i-1)>datos.get(i) && datos.get(i)<datos.get(i+1)) valles++;
        }
        
        result[0]=picos;
        result[1]=valles;
    }
    
    public static void resuelveCaso(Scanner scanner) {
        int N=scanner.nextInt();
        ArrayList<Integer> datos=new ArrayList<>();
        
        for (int j=0;j<N;j++) datos.add(scanner.nextInt());
        
        int[] result=new int[2];
        picosValles(datos, result);
        System.out.println(result[0]+" "+result[1]);
    }
    
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);

        int numCasos=scanner.nextInt();
        for (int i=0;i<numCasos;i++) resuelveCaso(scanner);
        
        scanner.close();
    }
}