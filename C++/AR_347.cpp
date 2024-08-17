#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int pajaritas(int x, int y) {   
    // CASO BASE
    if (x < 10 || y < 10) return 0;
    
    // CASO RECURSIVO
    int minimo = 0;
    int divAux = 0;
    if (x > y) {
        minimo = y;
        divAux = x / y;
        return pajaritas(x - minimo*divAux, y) + divAux;
    }
    else if (x < y) {
        minimo = x;
        divAux = y / x;
        return pajaritas(x, y - minimo * divAux) + divAux;
    }
    else { // x == y SE HACE EL PAJARITO GRANDE
        return 1;
    }

}

int pajaritasLineal(int x, int y) {
    int ret = 0;
    
    while (x >= 10 && y >= 10) {        
        int divAux = 0;
        if (x > y) {            
            divAux = x / y;
            ret += divAux;
            x -= y * divAux;            
        }
        else if (x < y) {            
            divAux = y / x;
            ret += divAux;
            y -= x* divAux;
        }
        else { // x == y SE HACE EL PAJARITO GRANDE
            ret += 1;
            x = 0;
        }

    }    
    
    return ret;
}

bool solve() {
    // read case
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0)
        return false;       

    // compute solution
    int r = pajaritasLineal(x, y);

    // write solution
    cout << r << endl;

    return true;
}

int main() {
    while (solve());

    return 0;
}