#include <iostream>
#include <vector>       // libreria para almacenar los datos
// tambien se puede usar arrays de enteros = int[]

#include <algorithm>    // libreria para ordenar vectores


// Funciones para que el compilador tarde menos en ejecutarse
// no tenies que usarlo en clase
#pragma GCC optimize("O3,Ofast,unroll-loops")
static const int _ = []()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...




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
int kaprekar(string num) {
    // CASO ESPECIAL (repdigits). 
    // El numero introducido por terminal no tiene al menos dos digitos diferentes.
    if (num[0]==num[1] && num[2]==num[3] && num[0]==num[2]) return 8;

    int ret=0, resta=0, acarreo=0;
    string tmp="0000";       
    vector<char> v;
    
    // Funcion cota: 7-ret (decrece hasta llegar a 0 si necesita 7 iteraciones)
    // INV: TODO
    while (num != "6174") { // O(x)
        v.clear(); // borra los caracteres anteriores
        for (char c: num) v.push_back(c);
        sort(v.begin(), v.end()); // ordena los caracteres de menor a menor

        acarreo=0;
        for (int i=0;i<4;i++) { // O(N)          
            resta=v[i]-v[3-i]-acarreo;
            
            if (resta>=0) {
                acarreo=0;
                // Al ser caracters ASCII, tienen su valor entero correspondiente
                // '0' -> 48. Por eso se suma 48 al valor obtenido,
                // para obtener el caracter ASCII correspondiente
                tmp[3-i]=48+resta; // '0'+resta
            }
            else {
                acarreo = 1;
                tmp[3 - i] = 48 + 10 + resta; // '0'+10+resta
            }
        }

        num = tmp;
        ret++;
    }

    return ret;
}
// Postcondicion: Lo que devuelve el algoritmo TODO

void resuelveCaso() {
    string num;
    cin>>num;
    
    // si num<1000, hay que concatenar los ceros de la izquierda    
    while (num.size()!=4) num="0"+num;

    cout<<kaprekar(num)<<"\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    for (int i=0;i<N;i++) resuelveCaso();

    return 0;
}