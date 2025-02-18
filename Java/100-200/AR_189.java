import java.util.*;

public class AR_189 {
    // Pre: true
    public static int embarque(List<Integer> v, int N) {
        
        for (int i=0;i<v.size(); ) {
            if (v.get(i)==N) v.remove(i);
            else i++;
        }
        return v.size();
    }

    // Pos: r = Sum k: 0 <= k < v.size(): v[k]
    public static boolean solve(Scanner sc) {
        // Read case
        int n=sc.nextInt();
        if (n==0) return false;

        List<Integer> v=new ArrayList<>();
        for (int i=0;i<n;i++) v.add(sc.nextInt());

        int nAcciones=sc.nextInt();
        for (int i=0;i<nAcciones;i++) {
            String accion=sc.next();
            int numAccion=sc.nextInt();

            if (accion.equals("EMBARQUE")) {
                System.out.println(embarque(v, numAccion));
            } else if (accion.equals("CONSULTA") && v.size()>0) {
                System.out.println(v.get(numAccion - 1));
            }
        }
        System.out.println("*");
        return true;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while (solve(sc));
        
        sc.close();
    }
}
