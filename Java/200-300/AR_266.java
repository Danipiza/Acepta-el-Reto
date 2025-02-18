import java.util.Scanner;

public class AR_266 {
    
    static void obra_final(String[] v_obra, int filas, int columnas, char[] transformacion) {

        for(int i=0;i<filas;i++) {
            char[] row=v_obra[i].toCharArray();

            for(int j=0; j < columnas; j++) {
                row[j]=transformacion[row[j]-'A'];
            }
            v_obra[i]=new String(row);
        }
    }

    static boolean resuelveCaso(Scanner scanner) {
        int filas    =scanner.nextInt();
        int columnas =scanner.nextInt();
        if (filas==0 && columnas==0) return false;

        String[] v_obra=new String[filas];
        for(int i=0;i<filas;i++) v_obra[i]=scanner.next();

        int copistas=scanner.nextInt();

        char[] transformacion=new char[26];
        // rellenar cada pixel con su transformacion.
        // inicialmente A->A, B->B, ... Z->Z
        for(int i=0;i<26;i++) transformacion[i] = (char)('A' + i);

        for(int i=0;i<copistas;i++) {
            char color1=scanner.next().charAt(0);
            char color2=scanner.next().charAt(0);
            
            // recorrer la transformacion buscando, coincidencias
            for(int j=0;j<26;j++) {
                // si coincide se cambia al nuevo valor
                /* EJEMPLO
                A -> R
                color1 = 'R' color2 = 'Y'

                Al llegar a R se cambia por Y, y asi con todas las ocurrencias
                */
                if (transformacion[j]==color1) transformacion[j]=color2;
            }
        }

        obra_final(v_obra, filas, columnas, transformacion);
        
        for(int i=0;i<filas;i++) System.out.println(v_obra[i]);

        return true;
    }

    // Usando buffered reader/writer da memory limit exceeded.
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while (resuelveCaso(scanner));
        
        scanner.close();
    }
}