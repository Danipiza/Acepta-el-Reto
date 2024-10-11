import java.util.Scanner;

public class Solution {
    static int divisores_fact(int N, 
		int x1, int x2, 
		int y1, int y2) {
        if (x1==x2 && y1==y2) return 0;

        int ret=0;

		// No tienen la misma paridad, 
		//  el destino esta en una celda que nunca podra visitarse
		if ((x1+y1)%2!=(x2+y2)%2) ret=-1;
		else {
			// Si tienen la misma diferencia de distancias es por que esta
			//  en la misma diagonal, por lo que solo tiene que dar un paso.
            if (Math.abs(x1-x2)==Math.abs(y1-y2)) ret=1;
            else ret = 2;
        }

        return ret;
    }

    static boolean resuelveCaso(Scanner scanner) {
        int N=scanner.nextInt();
        if (N<=0) return false;
        
        int x1=scanner.nextInt();
        int y1=scanner.nextInt();
        int x2=scanner.nextInt();
        int y2=scanner.nextInt();

        int salida=divisores_fact(N, x1, x2, y1, y2);

        if (salida==-1) System.out.println("IMPOSIBLE");
        else System.out.println(salida);

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while (resuelveCaso(scanner));
		
        scanner.close();
    }
}