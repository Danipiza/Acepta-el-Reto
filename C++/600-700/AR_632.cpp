#include <iostream>
#include <vector>


using namespace std;

using vi=vector<int>;
using vl=vector<long long>;


/*EJEMPLO
se come por la parte derecha de cada hilera (0 representa ningun turron)
0 1 2 2     acumulado1 -> 0 1 3 5
0 1 2       acumulado2 -> 0 1 3

1ra iteracion, no come ninguno de la hilera 1
(empieza con j = 2)
mientras que el valor acumulado sea mayor que el tiempo,
se reduce el numero de turrones que se come de la segunda hilera.
acumulado2[2] + 0 = 3 > tiempo -> j--
acumulado2[1] + 0 = 1 < tiempo -> termina esta iteracion
ret = max(1,ret) = 1

2da iteracion, come un turron de la hilera 1
(empieza con j = 1) que es el numero de turrones maximos comidos
en la iteracion anterior, por lo que se podra comer dicho numero de turrones o menos
acumulado2[1] + acumulado1[1] = 1 + 1 = 2 == tiempo -> termina esta iteracion
ret = max(2,ret) = 2
*/

int maximos_turrones(int tiempo, vl h1_acum, vl h2_acum) {
    int ret=0, tmp;
      
    int n= h1_acum.size(),m=h2_acum.size(), j=m-1;
    for (int i=0;i<n;i++) {
        if (h1_acum[i] > tiempo) break;

        // encontramos el máximo de numero de turrones en la hilera 2
        // que podemos comer habiendo comido i turrones de la hilera 1
        while (j>0 && h1_acum[i]+h2_acum[j]>tiempo) j--;       
        

        tmp=i+j;
        if(ret<tmp)ret=tmp;
    }
   

    return ret;
}

bool resuelveCaso() {
    int n, m, t;
    
    cin >> n >> m >> t;
    if (!cin) return false;

    vi hilera1(n,0), hilera2(m, 0);    
    for (int i=0;i<n;i++) cin >> hilera1[i];
    for (int i=0;i<m;i++) cin >> hilera2[i];


    // se añade 1 mas a cada hilera representando que no se come ningun turron en dicha hilera
    vl acumulado1(n+1, 0), acumulado2(m+1, 0); 
    for (int i=n-1;i>=0;i--) acumulado1[n-i]=acumulado1[n-i-1]+hilera1[i];
    for (int i=m-1;i>=0;i--) acumulado2[m-i]=acumulado2[m-i-1]+hilera2[i];
    
    int salida=maximos_turrones(t, acumulado1, acumulado2);    
    cout << salida << "\n";
    

    return true;
}

int main() {
    
    while(resuelveCaso());

    return 0;
}
