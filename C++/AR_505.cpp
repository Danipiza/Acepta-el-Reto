#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

/*
struct Pila {
    int duracion;

    bool operator<(Pila const &otro) const{
        return duracion < otro.duracion;
    }
};*/


// función que resuelve el problema
void drones(int N, priority_queue<int/*Pila*/> QA, priority_queue<int/*Pila*/> QB) {
    vector<pair<int, int>> usados; // second: 0 -> QA, 1 -> QB
    int a, b, sum = 0;
    int first = 1;
    while (!QA.empty() && !QB.empty()) {
        sum = 0;
        for (int i = 0; i < N && !QA.empty() && !QB.empty(); i++) {
            a = QA.top()/*.duracion*/; QA.pop();
            b = QB.top()/*.duracion*/; QB.pop();
            if (a < b) { usados.push_back({ b - a, 1 }); sum += a; }
            else if (a > b) { usados.push_back({ a - b, 0 });; sum += b; }
            else sum += a;
        }
        if (!first) cout << " ";
        else first = 0;
        cout << sum;
        while (!usados.empty()) {
            pair<int,int> tmp = usados.back(); usados.pop_back();
            if (tmp.second == 0) QA.push({ tmp.first });
            else QB.push({ tmp.first });
        }
    }
    cout << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, A, B;
    cin >> N >> A >> B;
    if (!std::cin) return false;

    int tmp;
    priority_queue<int/*Pila*/> QA;
    for (int i = 0; i < A; i++) { 
        cin >> tmp; 
        if(tmp!=0) QA.push({ tmp }); 
    }
    
    priority_queue<int/*Pila*/> QB;
    for (int i = 0; i < B; i++) { 
        cin >> tmp; 
        if (tmp != 0) QB.push({ tmp });
    }

    drones(N, QA, QB);

    return true;

}

int main() {


    while (resuelveCaso())
        ;



    return 0;
}