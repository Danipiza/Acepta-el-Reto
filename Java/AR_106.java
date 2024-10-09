import java.util.*;

public class Solution {
    
    
    static void comprueba_pais(String num, 
							   StringBuilder pais) {
        Map<String, String> mapa=new HashMap<>();
        mapa.put("0", "EEUU"); mapa.put("380", "Bulgaria"); 
		mapa.put("50", "Inglaterra"); mapa.put("539", "Irlanda"); 
		mapa.put("560", "Portugal"); mapa.put("70", "Noruega");
        mapa.put("759", "Venezuela"); mapa.put("850", "Cuba"); 
		mapa.put("890", "India");
        
        pais.setLength(0);
        pais.append("Desconocido");
        String id="";
        for (int i=0;i<3;i++) {
            id+=num.charAt(i);
            
			if (mapa.containsKey(id)) {
                pais.setLength(0);
                pais.append(mapa.get(id));
                break;
            }
        }
    }

    static boolean EAN(int digitos, String num, 
					   StringBuilder salida) {
        int codigo_error=num.charAt(digitos-1)-'0';
        int suma		=0;

        int tmp=0, aux=(digitos==8) ? 1:0;
        for (int i=digitos-2;i >=0;i--) {
            tmp=1;
            if ((i+aux)%2==1) tmp=3;
            
            suma+=(num.charAt(i)-'0')*tmp;
        }

        int sum_multiplo=suma%10;
        if (sum_multiplo!=0) sum_multiplo=10-sum_multiplo;        
        boolean ret=sum_multiplo==codigo_error;

        if (ret && digitos==13) comprueba_pais(num, salida);

        return ret;
    }


    static boolean resuelveCaso() {    
		Scanner sc=new Scanner(System.in);
        String num=sc.next();
        if (num.equals("0")) return false;

        int digitos=num.length();    
        if (digitos<8) { // si es inferior a 8 hay que añadir 0s
            num=String.format("%08d", Integer.parseInt(num));
            digitos=8;
        }
        else if (digitos>8 && digitos<13) { // si distinto de 8 e inferior a 13 hay que añadir 0s
            num=String.format("%013d", Long.parseLong(num));
            digitos = 13;
        }

        StringBuilder pais=new StringBuilder();
        boolean salida=EAN(digitos, num, pais);

        if (salida) {
            System.out.print("SI");
            if (digitos==13) System.out.print(" "+pais);
        }
        else System.out.print("NO");
        System.out.println();
        
        return true;    
    }

    public static void main(String[] args) {        
        while (resuelveCaso());        
    }
}