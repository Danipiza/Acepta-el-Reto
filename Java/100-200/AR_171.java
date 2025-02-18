import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class AR_171 {
    
    static int numAbadias(List<Integer> v) {
        int ret=1, max=v.get(v.size()-1);
        
        for (int i=v.size()-2;i>=0;i--) {
            if (v.get(i)>max) {
                ret++;
                max=v.get(i);
            }
        }

        return ret;
    }

    static boolean resuelveCaso(Scanner scanner) {
        int n=scanner.nextInt();

        if (n==0) return false;

        List<Integer> v=new ArrayList<>();
        for (int i=0;i<n;i++) v.add(scanner.nextInt());

        System.out.println(numAbadias(v));

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while (resuelveCaso(scanner));

        scanner.close();
    }
}