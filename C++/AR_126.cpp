#include <iostream>


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


bool divisores_fact(int p, int n) {
    bool ret=0;

    if ((p==1 || p<=n) && p>=0 && n>=0) ret=true;
    else ret=false;

    return ret;
}

bool resuelveCaso() {
    long long int p, n;
    cin >> p >> n;
    if (p<=0 && n<=0) return false;
    
    if (divisores_fact(p,n)) cout << "YES\n";    
    else cout << "NO\n";

    return true;
}


int main() {
    //ios_base::sync_with_stdio(false);
    
    while (resuelveCaso());
    

    return 0;
}