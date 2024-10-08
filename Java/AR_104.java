import java.util.Scanner;

public class Solution {
    static Scanner scanner = new Scanner(System.in);

    static class Result {
        int sumNodos;
        boolean fin;
        boolean balanced;

        Result(int sumNodos, boolean fin, boolean balanced) {
            this.sumNodos =sumNodos;
            this.fin 	  =fin;
            this.balanced =balanced;
        }
    }

    static Result movil() {
        int pi =scanner.nextInt();
        int di =scanner.nextInt();
        int pd =scanner.nextInt();
        int dd =scanner.nextInt();
        if (pi==0 && di==0 && pd==0 && dd==0) {
            return new Result(0, true, false);
        }

        // CASO BASE
        if (pi!=0 && pd!=0) { // MOVIL SIN SUBMOVILES
            return new Result(pi+pd, false, pi*di==pd*dd);
        }

        // CASO RECURSIVO    
        // IZQ
        Result izq= pi==0? movil():new Result(pi, false, true);

        // DERECHA
        Result der= pd==0? movil():new Result(pd, false, true);

        int sumNodos    =izq.sumNodos+der.sumNodos;
        boolean balanced=(izq.sumNodos*di==der.sumNodos*dd) && izq.balanced && der.balanced;

        return new Result(sumNodos, izq.fin || der.fin, balanced);
    }

    static boolean solve() {
        Result result=movil();

        if (result.fin) return false;
        System.out.println(result.balanced ? "SI":"NO");
        
        return true;
    }

    public static void main(String[] args) {
        while (solve());
    }
}