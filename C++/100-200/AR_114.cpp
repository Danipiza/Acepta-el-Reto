#include <iostream>
#include <vector>       // libreria para almacenar los datos
// tambien se puede usar arrays de enteros = int[]


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

// Solo pide el ultimo digito, al llegar a 5 el ultimo digito es 0. 0 * x = 0.
int factorial(int num) {
    if (num<=1) return 1;
    else if (num==2) return 2;
    else if (num==3)return 6;
    else if (num==4)return 4;
    else return 0;
}

void resuelveCaso() {
    int num;
    cin >> num;

    cout << factorial(num) << "\n";    
}


int main() {
    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) resuelveCaso();
    

    return 0;
}