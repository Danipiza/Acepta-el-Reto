import java.util.*;

public class AR_419 {

    public static int voraz(int peso, int[] personas) {
        int ret=0;
        int i=0, j=personas.length-1;

        while (i <= j) {
            if (personas[i]+personas[j]<=peso) {
                i++;
                j--;
            } 
            else j--;

            ret++;
        }

        return ret;
    }

    public static boolean resuelveCaso(Scanner sc) {
        int peso = sc.nextInt();
        int N=sc.nextInt();
        if (peso==0 && N==0) return false;

        int[] personas=new int[N];
        for (int i=0;i<N;i++) personas[i]=sc.nextInt();

        Arrays.sort(personas);

        System.out.println(voraz(peso, personas));

        return true;
    }

    // Buffered da error. MemoryLimit
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (resuelveCaso(sc));
    }
}
