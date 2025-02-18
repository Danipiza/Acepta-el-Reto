#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define INF INT_MAX

int llenando_piscinas(int pisc_yo, int barr_yo, int viaje_yo, 
                      int pisc_vec, int barr_vec, int viaje_vec,
                      int* empate) {

    // 10 4 1
    // 4 + 3 + 3 = 3 viajes necesita
    // 
    // primer viaje no pierde agua
    int yo=1, vecino=1;
    pisc_yo  -=barr_yo;
    pisc_vec -=barr_vec;
    
    // en cada viaje se gana el agua que trae, 
    //  menos lo que pierde la piscina.
    int agua_viaje_yo     =barr_yo-viaje_yo;
    int agua_viaje_vecino =barr_vec-viaje_vec;

    // si en cada viaje consigue traer algo entra
    if (agua_viaje_yo>0 && pisc_yo>0) {        
        yo+=pisc_yo/agua_viaje_yo; // numero de viajes necesarios
        // se suma 1 si la division no es entera. para llenar 
        //  una piscina de 50L con cubos de 4L se necesitan 12.5 viajes = 13.
        if ((pisc_yo % agua_viaje_yo)!=0) yo++;        
    }    
    // si no consigue traer agua y la piscina le falta por llenar entonces es imposible
    else if(pisc_yo>0) yo=INF; 
    
    // lo mismo para el vecino
    if (agua_viaje_vecino>0 && pisc_vec>0) {        
        vecino+=pisc_vec/agua_viaje_vecino; 
        if ((pisc_vec%agua_viaje_vecino)!=0) vecino++;        
    }
    else if (pisc_vec>0) vecino=INF;

    if (yo==vecino) *empate=1;

    return (yo<=vecino) ? yo:-vecino;
}

int resuelveCaso() {
    int pisc_yo, barr_yo, viaje_yo;
    int pisc_vec, barr_vec, viaje_vec;
    
    if (scanf("%d %d %d %d %d %d", 
        &pisc_yo, &barr_yo, &viaje_yo,
        &pisc_vec, &barr_vec, &viaje_vec)!=6) {
        return 0;
    }
    if (pisc_yo==0 || pisc_vec==0) return 0;
    
    int empate =0;
    int salida =llenando_piscinas(pisc_yo, barr_yo, viaje_yo, 
                                  pisc_vec, barr_vec, viaje_vec,
                                  &empate);

    if(empate) printf("EMPATE %d\n", salida);
    else if (salida>=0) printf("YO %d\n", salida);
    else printf("VECINO %d\n", -salida);
    
    return 1;
}

int main() {
    while (resuelveCaso());
    
    return 0;
}