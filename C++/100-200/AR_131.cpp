#include <iostream>
#include <climits>

using namespace std;


// ----------------------------------------------------------

using namespace std; // libreria standard
// para poder usar cin, cout, string, otras librerias...

#define INF INT_MAX

int llenando_piscinas(int pisc_yo, int barr_yo, int viaje_yo, 
                        int pisc_vec, int barr_vec, int viaje_vec,
                        bool& empate) {
    // 10 4 1
    // 4 + 3 + 3 = 3 viajes necesita
    // 
    // primer viaje no pierde agua
    int yo=1, vecino=1;
    pisc_yo-=barr_yo;
    pisc_vec-=barr_vec;
    
    // en cada viaje se gana el agua que trae, menos lo que pierde la piscina.
    int agua_viaje_yo=barr_yo-viaje_yo;
    int agua_viaje_vecino=barr_vec-viaje_vec;

    
    // si en cada viaje consigue traer algo entra
    if (agua_viaje_yo>0 && pisc_yo>0) {        
        yo+=pisc_yo/agua_viaje_yo; // numero de viajes necesarios
        // se suma 1 si la division no es entera. para llenar 
        //  una piscina de 50L con cubos de 4L se necesitan 12.5 viajes = 13.
        if ((pisc_yo%agua_viaje_yo)!=0) yo++;        
    }    
    // si no consigue traer agua y la piscina le falta por llenar entonces es imposible
    else if(pisc_yo>0) yo=INF; 
    
    // lo mismo para el vecino
    if (agua_viaje_vecino>0 && pisc_vec>0) {        
        vecino+=pisc_vec/agua_viaje_vecino; 
        if ((pisc_vec%agua_viaje_vecino)!=0) vecino++;        
    }
    else if (pisc_vec>0) vecino=INF;

    if (yo==vecino) empate=true;

    if (yo<=vecino) return yo;
    else return vecino*-1;
}

bool resuelveCaso() {
    int pisc_yo, barr_yo, viaje_yo;
    int pisc_vec, barr_vec, viaje_vec;
    
    cin >> pisc_yo >> barr_yo >> viaje_yo
        >> pisc_vec >> barr_vec >> viaje_vec;
    if (pisc_yo==0 || pisc_vec==0) return false;
    
    bool empate=false;
    int salida=llenando_piscinas(pisc_yo,barr_yo,viaje_yo, 
                                    pisc_vec,barr_vec,viaje_vec,
                                    empate);

    if(empate) cout << "EMPATE " << salida << "\n";
    else if (salida>=0) cout << "YO " << salida << "\n";
    else cout << "VECINO " << salida*-1 << "\n";
    
    return true;
}


int main() {
    //ios_base::sync_with_stdio(false);

    while (resuelveCaso());


    return 0;
}