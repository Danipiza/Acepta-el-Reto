import java.util.*;

public class Solution {
	
	
	// El enunciado nos pide calcular cuantas iteraciones se necesitan para que un numero 
	//  de cuatro digitos alcance el valor 6174 (Constante de Kaprekar).
	// Para ello el digito tiene que tener al menos dos digitos distintos, sino no se 
	//  alcanza nunca el valor destino.
	// 
	// En cada iteracion:
	// Se ordena el numero de manera ascendente y descendente, y se resta el menor valor al mayor,
	//  obteniendo un numero que sera el numero para la siguiente iteracion.


	// Explicacion: Es un problema iterativo puesto que hay que recorrer un bucle x veces (x < 8) 
	//  para llegar al numero destino. 
	// 
	// Para alcanzar la solucion en cada iteracion:
	// - Se ordena con el metodo sort() de la libreria algorithm el vector de caracteres del numero actual.
	// - Se resta cada numero con su correspondiente, para realizar la resta del enunciado.
	// 
	// Se puede hacer con dos vectores y ordenar de manera ascendete y descendete, pero aumenta el tiempo 
	//  de ejecucion. Por eso solo se usa uno con dos punteros para realizar la resta.

	// Complejidad: 
	// - Espacial: O(n). Siendo n el numero de digitos.
	// - Temporal: O(x*n*nlogn)=O(nlogn) se recorre el numero x veces y se ordena 
	//      el vector de caracteres en cada iteracion.

	// Precondicion: Cuando se puede ejecutar la funcion
	// Pre = { 0 <= num.size() <= 4 }
    public static int kaprekar(String num) {
        char numA[]=num.toCharArray();
		
		// CASO ESPECIAL (repdigits). 
        // El numero introducido por terminal no tiene al menos dos digitos diferentes.
        if (numA[0]==numA[1] && numA[2]==numA[3] && numA[0]==numA[2]) {
            return 8;
        }

        int ret=0, resta=0, acarreo=0;
        StringBuilder tmp = new StringBuilder("0000");
        char[] v=new char[4];
		
		// Funcion cota: 7-ret (decrece hasta llegar a 0 si necesita 7 iteraciones)
		// INV: TODO
        while (!num.equals("6174")) {
            v=num.toCharArray();
            Arrays.sort(v);

            acarreo=0;
            for (int i=0;i<4;i++) {
                resta=v[i]-v[3-i]-acarreo;

                if (resta>=0) {
                    acarreo=0;
					// Al ser caracters ASCII, tienen su valor entero correspondiente
					// '0' -> 48. Por eso se suma 48 al valor obtenido,
					// para obtener el caracter ASCII correspondiente
                    tmp.setCharAt(3-i, (char) (48+resta));
                } 
				else {
                    acarreo=1;
                    tmp.setCharAt(3-i, (char) (48+10+resta)); // '0'+10+resta
                }
            }

            num = tmp.toString();
            ret++;
        }

        return ret;
    }
	// Postcondicion: Lo que devuelve el algoritmo TODO
	
    public static void resuelveCaso(Scanner scanner) {
        String num=scanner.next();
		
		// si num<1000, hay que concatenar los ceros de la izquierda  
        while (num.length()!=4) num="0"+num;

        System.out.println(kaprekar(num));
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int N=scanner.nextInt();
		
        for (int i = 0; i < N; i++) {
            resuelveCaso(scanner);
        }
    }
}