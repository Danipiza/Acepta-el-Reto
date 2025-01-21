import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AR_420 {
    public static int sumaClave(StringBuilder cadena, int clave) {
        int cont = 0;
        int suma = 0;
        int i = cadena.length() - 1;

        while (i >= 0) {
            suma += (cadena.charAt(i) - '0');
            while (suma > clave) {
                suma -= (cadena.charAt(cadena.length() - 1) - '0');
                cadena.deleteCharAt(cadena.length() - 1);
            }

            if (suma == clave) cont++;
            i--;
        }

        return cont;
    }

    public static void solve(BufferedReader br) throws IOException {
        String[] input = br.readLine().split(" ");
        int clave = Integer.parseInt(input[0]);
        StringBuilder cadena = new StringBuilder(input[1]);

        int ret = sumaClave(cadena, clave);

        System.out.println(ret);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter br = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            solve(br);
        }
    }
}
