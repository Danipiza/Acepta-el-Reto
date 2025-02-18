import java.util.Scanner;

public class AR_349 {
    static Scanner sc=new Scanner(System.in);

    public static int operar() {
        char valor=sc.next().charAt(0);

        if (Character.isLetterOrDigit(valor)) return valor-'0';
        else {
            int sum1=operar();
            int sum2=operar();

            if      (valor=='+') return sum1+sum2;
            else if (valor=='-') return sum1-sum2;
            else if (valor=='*') return sum1*sum2;
            else                 return sum1/sum2;
        }
    }

    public static void solve() {

        System.out.println(operar());
    }

    public static void main(String[] args) {
        int numCasos=sc.nextInt();

        for (int i=0;i<numCasos;i++) solve();
    }
}