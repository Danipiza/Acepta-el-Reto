#include <stdio.h>
#include <string.h>

int sumaClave(const char *cadena, int clave)
{
    int ret = 0;
    int suma = 0; // suma de la ventana
    int i = 0, j; // punteros

    for (j = 0; cadena[j] != '\0'; j++) {
        suma += (cadena[j] - '0'); // suma el ultimo digito de la ventana

        // reduce la venana asta que (suma <= clave)
        while (suma > clave && i <= j) {
            suma -= (cadena[i] - '0');
            i++;
        }

        // Si la suma es igual aumenta el numero a retornar
        if (suma == clave) ret++;
    }

    return ret;
}

void solve() {
    int clave;
    char cadena[250001]; // 250.000 digits + null

    scanf("%d %s", &clave, cadena);

    int suma = sumaClave(cadena, clave);


    printf("%d\n", suma);
}

int main() {
    int i, n;
    scanf("%d", &n);

    for (i = 0; i < n; ++i) solve();

    return 0;
}