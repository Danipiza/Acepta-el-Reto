import java.util.Scanner;

public class Solution {
	
    public static int cuenta_vocales(String s) {
        int ret =0;
        int n   =s.length();
        char c;
		char sA[]=s.toCharArray();
		
        for (int i=0;i<n;i++) {
            c=sA[i];
			
            if (Character.isLowerCase(c)) {
                if (c=='a' || c=='e' || c=='i' || 
					c=='o' || c=='u') ret++;
            } 
			else {
                if (c=='A' || c=='E' || c=='I' || 
					c=='O' || c=='U') ret++;
            }
        }

        return ret;
    }

    public static String decodificar(String s) {
        StringBuilder ret = new StringBuilder();
		
        int n=s.length();
		char sA[]=s.toCharArray();
		
        int desplazamiento='p'-sA[0];
        char c;

        for (int i=1;i<n;i++) {
            c=sA[i];
			
            if (Character.isUpperCase(c)) {
                int tmp=c+desplazamiento;
                if (tmp<'A') 	  tmp='Z'+1-('A'-tmp);
                else if (tmp>'Z') tmp='A'-1 +(tmp-'Z');
                
				ret.append((char) tmp);				
            } 
			else if (Character.isLowerCase(c)) {
                int tmp=c+desplazamiento;
                if (tmp<'a') 	  tmp='z'+1-('a'-tmp);
                else if (tmp>'z') tmp='a'-1+(tmp-'z');
                
				ret.append((char) tmp);
            }
        }

        return ret.toString();
    }

    public static boolean resuelveCaso(Scanner scanner) {
        String s=scanner.nextLine();
		
        String s_decodificado=decodificar(s);
        if (s_decodificado.equals("FIN")) return false;

        System.out.println(cuenta_vocales(s_decodificado));

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (resuelveCaso(scanner));
    }
}