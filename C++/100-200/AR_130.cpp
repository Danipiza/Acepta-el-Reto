#include <iostream>

using namespace std;


// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...


int divisores_fact(int N,
    int x1, int x2,
    int y1, int y2) {
    if (x1==x2 && y1==y2) return 0;

    int ret=0;

    
    // No tienen la misma paridad, 
    //  el destino esta en una celda que nunca podra visitarse
    if ((x1+y1)%2!=(x2+y2)%2) ret=-1;
    else {
        // Si tienen la misma diferencia de distancias es por que esta
        //  en la misma diagonal, por lo que solo tiene que dar un paso.
        if (abs(x1-x2)==abs(y1-y2)) ret=1;
        else ret=2;
    }

    return ret;
}

bool resuelveCaso() {
    int N, x1, x2, y1, y2;
    cin >> N;
    if (N<=0) return false;
    cin >> x1 >> y1 >> x2 >> y2;

    int salida=divisores_fact(N,x1,x2,y1,y2);

    if (salida==-1) cout << "IMPOSIBLE\n";
    else cout << salida << "\n";

    return true;
}


int main() {
    //ios_base::sync_with_stdio(false);

    while (resuelveCaso());


    return 0;
}